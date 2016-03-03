SWIFT_TOOL_CHAIN=/home/vagrant/swift-local-install/usr
SWIFT_SRC=/home/vagrant/swift

SWIFTC=$(SWIFT_TOOL_CHAIN)/bin/swiftc

EXECUTABLES=Test1

all: libdispatchLite.so $(EXECUTABLES)

Test1:	Test1.swift libdispatchLite.so
	$(SWIFTC) -Xcc -fblocks -I . $< -o $@ -Xlinker -rpath -Xlinker . -Xlinker -L.

libdispatchLite.so: DispatchLite.o DispatchStubs.o
	clang -shared -fPIC DispatchLite.o DispatchStubs.o -o libdispatchLite.so

DispatchLite.o: DispatchLite.swift DispatchLite.swiftmodule
	$(SWIFTC) -Xcc -fblocks -I . -parse-as-library -c -o $@ $<

DispatchLite.swiftmodule: DispatchLite.swift dispatchAPI.h 
	$(SWIFTC) -Xcc -fblocks -Xcc -fmodule-map-file=module.map \
		-emit-module -emit-module-path $@ $<

%.o: %.c
	clang -fPIC -fblocks -c -I$(SWIFT_SRC)/stdlib/public $< -o $@

clean:
	rm -f $(EXECUTABLES) *.o *.swiftmodule *.swiftdoc libdispatchLite.so
