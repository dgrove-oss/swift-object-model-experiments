SWIFT_TOOL_CHAIN=/home/vagrant/swift-local-install/usr
SWIFT_SRC=/home/vagrant/swift

SWIFTC=$(SWIFT_TOOL_CHAIN)/bin/swiftc

SWIFT_INCLUDES=-I$(SWIFT_SRC)/include -I$(SWIFT_SRC)/../llvm/include -I$(SWIFT_SRC)/../llbuild/include

SimpleTest: SimpleTest.swift stubs.o
	$(SWIFTC) -v SimpleTest.swift stubs.o -o SimpleTest

stubs.o:	stubs.cpp
	clang -std=c++11 -c $(SWIFT_INCLUDES) $< -o $@

clean:
	rm -f SimpleTest *.o
