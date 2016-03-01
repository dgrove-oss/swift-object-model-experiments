#include <stdio.h>

#include <swift/Runtime/HeapObject.h>
#include <swift/Runtime/Metadata.h>

using namespace swift;

struct Cell : HeapObject {
	int data;
	struct Cell* next;
};

static void deinitCell(HeapObject *_obj) {
	Cell* obj = static_cast<Cell*>(_obj);
    printf("DeinitCell called on Cell with data %d\n", obj->data);
}

static const FullMetadata<ClassMetadata> CellMetadata = {
	{ { &deinitCell }, { &_TWVBo } },
	{ { { MetadataKind::Class } }, 0, /*rodata*/ 1,
	  ClassFlags::UsesSwift1Refcounting, nullptr, 0, 0, 0, 0, 0 }
};


static Cell* allocCell(int x, Cell* n) {
	Cell* result = static_cast<Cell*>(swift_allocObject(&CellMetadata, sizeof(Cell), alignof(Cell)-1));
	result->data = x;
	_swift_retain_inlined(result);
	result->next = n;
	return result;
}

extern "C"
Cell*
 _swift_make_cell(int x, Cell* next) {
	// printf("Entered make_cell with next %p\n", next);
	Cell * tmp = allocCell(x, next);
	// printf("returning from make_cell with result %p and refcount %d\n",tmp, tmp->ho.refCount);
	return tmp;
}
