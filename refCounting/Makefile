SWIFT_TOOL_CHAIN=/home/vagrant/swift-local-install/usr
SWIFT_SRC=/home/vagrant/swift

SWIFTC=$(SWIFT_TOOL_CHAIN)/bin/swiftc

EXECUTABLES=RefCountTest RefCountTestC

all: $(EXECUTABLES)

RefCountTest: RefCountTest.o RefCountStubs.o
	$(SWIFTC) RefCountTest.o RefCountStubs.o -o $@

RefCountTestC: RefCountTest.o RefCountStubsC.o
	$(SWIFTC) RefCountTest.o RefCountStubsC.o -o RefCountTestC

%.o: %.cpp
	clang -std=c++11 -c -I$(SWIFT_SRC)/include $< -o $@

%.o: %.c
	clang -c -I$(SWIFT_SRC)/stdlib/public $< -o $@

%.o: %.swift
	$(SWIFTC) -c $< -o $@

clean:
	rm -f $(EXECUTABLES) *.o
