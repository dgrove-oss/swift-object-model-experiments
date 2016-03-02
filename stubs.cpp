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
	swift_release(obj->next);
}

static const FullMetadata<ClassMetadata> CellMetadata = {
	{ { &deinitCell }, { &_TWVBo } },
	{ { { MetadataKind::Class } }, 0, /*rodata*/ 1,
	  ClassFlags::UsesSwift1Refcounting, nullptr, 0, 0, 0, 0, 0 }
};

static Cell* allocCell(int x, Cell* n) {
	auto result = static_cast<Cell*>(swift_allocObject(&CellMetadata, sizeof(Cell), alignof(Cell)-1));
	result->data = x;
	result->next = n;
	return result;
}

extern "C"
Cell*
 _swift_make_cell(int x, Cell* next) {
	return allocCell(x, next);
}

extern "C"
void
_swift_dump_list(Cell* head) {
	Cell* orig = head;
	printf("Start dump\n");
	while (head != NULL) {
		printf("\t%p data=%d, rc=%d\n", head, head->data, head->refCount);
		head = head->next;
	}
	printf("End dump\n");
	swift_release(orig);
}


			
