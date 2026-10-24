// Step 07 · Signals, Events & Timing — sc_time, wait, Delta Cycles
//
// ClockGen::run() is already registered as an SC_THREAD (see include/lab.h).
// Drive clk forever: high for duty * period, then low for the rest of the period.
// The first rising edge must be at t = 0. Use two wait() calls per period.
#include "lab.h"
using namespace sc_core;

void ClockGen::run() {
    // TODO
}
