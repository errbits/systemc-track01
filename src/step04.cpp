// Step 04 · Data Types — sc_int, sc_logic, sc_fixed
//
// high_nibble(0xA7) == 0xA, low_nibble(0xA7) == 0x7  → use part-selects: x.range(hi, lo)
// saturating_add(200, 100) == 255                     → no wrap-around above 255
#include "lab.h"
using namespace sc_dt;

sc_uint<4> high_nibble(sc_uint<8> x) {
    return 0;  // TODO
}

sc_uint<4> low_nibble(sc_uint<8> x) {
    return 0;  // TODO
}

sc_uint<8> saturating_add(sc_uint<8> a, sc_uint<8> b) {
    return 0;  // TODO
}
