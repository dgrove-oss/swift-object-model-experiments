SWIFT_TOOL_CHAIN=/home/vagrant/swift-local-install/usr

SWIFTC=$(SWIFT_TOOL_CHAIN)/bin/swiftc

EXECUTABLES=Test1

all: libdispatch.so $(EXECUTABLES)

Test1:	Test1.swift libdispatch.so
	$(SWIFTC) -Xcc -fblocks -I . $< -o $@ -Xlinker -rpath -Xlinker . -Xlinker -L.

Test1.sil:	Test1.swift libdispatch.so
	$(SWIFTC) -Xcc -fblocks -I . -emit-sil $< -o $@ 

libdispatch.so: Dispatch.o DispatchStubs.o
	clang -shared -fPIC Dispatch.o DispatchStubs.o -o libdispatch.so

Dispatch.o: Dispatch.swift Dispatch.swiftmodule
	$(SWIFTC) -Xcc -fblocks -I . -parse-as-library -c -o $@ $<

Dispatch.swiftmodule: Dispatch.swift dispatchAPI.h 
	$(SWIFTC) -Xcc -fblocks -Xcc -fmodule-map-file=module.map -emit-module -emit-module-path $@ $<

%.o: %.c
	clang -fPIC -fblocks -c $< -o $@

clean:
	rm -f $(EXECUTABLES) *.o *.swiftmodule *.swiftdoc libdispatch.so
