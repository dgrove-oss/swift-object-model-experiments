SWIFT_TOOL_CHAIN=/home/vagrant/swift-local-install/usr
SWIFT_SRC=/home/vagrant/swift

SWIFTC=$(SWIFT_TOOL_CHAIN)/bin/swiftc

EXECUTABLES=Test1

all: $(EXECUTABLES)

Test1:	Test1.swift DispatchLite.o DispatchLite.swiftmodule DispatchStubs.o
	$(SWIFTC) -I . $< DispatchLite.o DispatchStubs.o -o $@

%.o: %.cpp
	clang -std=c++11 -c -I$(SWIFT_SRC)/include $< -o $@

%.o: %.c
	clang -c -I$(SWIFT_SRC)/stdlib/public $< -o $@

%.o: %.swift
	$(SWIFTC) -c $< -o $@

%.swiftmodule: %.swift
	$(SWIFTC) -emit-module $< -o $@

clean:
	rm -f $(EXECUTABLES) *.o *.swiftmodule *.swiftdoc
