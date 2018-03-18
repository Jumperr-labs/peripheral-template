CC=g++
RM=rm

$(shell mkdir -p _build)

CFLAGS= -std=c++11 -Werror -Wall -Wfatal-errors -Wno-shift-count-overflow -Weffc++ -Wno-non-virtual-dtor -Wno-strict-aliasing -Wno-unused-private-field -O3 -pthread -lutil

all: _build/MY_PERIPHERAL.so

_build/MY_PERIPHERAL.o: MY_PERIPHERAL.cpp
	$(CC) -fPIC -c -o $@ $^ $(CFLAGS) -I./include -I./modeling-framework/include

_build/MY_PERIPHERAL.so: _build/MY_PERIPHERAL.o modeling-framework/obj/ModelingFramework.o
	$(CC) -shared -o $@ $^

.PHONY: clean
clean:
	$(RM) -rf _build