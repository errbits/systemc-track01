# ErrBits — SystemC Track 01
#
#   make build           compile everything (what the Codespace runs on start)
#   make play [STEP=05]  build and run the playground (play/main.cpp)
#   make clean
#
# Outside the Codespace, point SYSTEMC_HOME at your SystemC 2.3.3 install:
#   make play SYSTEMC_HOME=$HOME/systemc-2.3.3

SYSTEMC_HOME ?= /opt/systemc
SC_LIBDIR    ?= $(firstword $(wildcard $(SYSTEMC_HOME)/lib $(SYSTEMC_HOME)/lib-linux64 \
                  $(SYSTEMC_HOME)/lib-macosx64 $(SYSTEMC_HOME)/lib-macosarm64) $(SYSTEMC_HOME)/lib)

CXXFLAGS ?= -std=c++17 -Wall -g
CPPFLAGS += -Iinclude -isystem $(SYSTEMC_HOME)/include
LDFLAGS  += -L$(SC_LIBDIR) -Wl,-rpath,$(SC_LIBDIR)
LDLIBS   += -lsystemc

OBJS := $(patsubst src/%.cpp,out/%.o,$(wildcard src/*.cpp)) out/main.o

.PHONY: build play clean

build: out/play

play: out/play
	@SC_COPYRIGHT_MESSAGE=DISABLE ./out/play $(STEP)

out/play: $(OBJS)
	$(CXX) $^ $(LDFLAGS) $(LDLIBS) -o $@

out/%.o: src/%.cpp include/lab.h | out
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

out/main.o: play/main.cpp include/lab.h | out
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

out:
	@mkdir -p out

clean:
	rm -rf out
