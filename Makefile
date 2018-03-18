CC=g++
RM=rm

peripheral_name = MY_PERIPHERAL

$(shell mkdir -p _build)

CFLAGS= -std=c++11 -Werror -Wall -Wfatal-errors -Wno-shift-count-overflow -Weffc++ -Wno-non-virtual-dtor -Wno-strict-aliasing -Wno-unused-private-field -O3 -pthread -lutil

all: _build/$(peripheral_name).so

_build/$(peripheral_name).o: $(peripheral_name).cpp
	$(CC) -fPIC -c -o $@ $^ $(CFLAGS) -I./include -I./modeling-framework/include

_build/$(peripheral_name).so: _build/$(peripheral_name).o modeling-framework/obj/ModelingFramework.o
	$(CC) -shared -o $@ $^

.PHONY: clean
clean:
	$(RM) -rf _build
