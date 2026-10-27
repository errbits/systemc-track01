// Step 11 · Capstone — HM-10 SYS_TICK timer (01+ Complete)
//
// Ticket VP-1042: firmware bring-up is blocked until SYS_TICK is modelled.
// Implement the datasheet behaviour described above SysTick in include/lab.h:
//   - register on_clk() so it runs on every rising edge of clk
//   - synchronous reset, count enable, prescaler (count advances every prescale+1 edges)
//   - compare match: count runs 0..compare, then reloads to 0 and irq pulses for ONE clock
//   - drive count and irq after every edge
#include "lab.h"
using namespace sc_core;

SysTick::SysTick(sc_module_name name) : sc_module(name) {
    // TODO: register on_clk()
}

void SysTick::on_clk() {
    // TODO
}
