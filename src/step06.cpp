// Step 06 · SC_THREAD vs SC_METHOD — The Real Difference
//
// Pick the right process type for each module (declared in include/lab.h):
//   AndGate  — y = a & b, updated whenever a or b changes
//   ResetSeq — drive rst high, keep it high for `cycles` rising edges of clk,
//              then drive it low and stop
#include "lab.h"
using namespace sc_core;

AndGate::AndGate(sc_module_name name) : sc_module(name) {
    // TODO: register eval() with the right process type and sensitivity
}

void AndGate::eval() {
    // TODO
}

ResetSeq::ResetSeq(sc_module_name name, int n) : sc_module(name), cycles(n) {
    // TODO: register run() with the right process type
}

void ResetSeq::run() {
    // TODO
}
