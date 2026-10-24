// Step 05 · SC_MODULE, Ports, and Processes
//
// Finish the Counter module (declared in include/lab.h):
//   - register on_clk() as an SC_METHOD sensitive to clk.pos()
//   - on each rising edge: if reset is high, clear count_ (synchronous reset),
//     otherwise increment count_
//   - drive the count port with count_
#include "lab.h"
using namespace sc_core;

Counter::Counter(sc_module_name name) : sc_module(name) {
    // TODO: register on_clk()
}

void Counter::on_clk() {
    // TODO
}
