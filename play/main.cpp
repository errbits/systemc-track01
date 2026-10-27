// Playground — try your code before you push.
//
//   make play            steps 01 and 04
//   make play STEP=05    Counter
//   make play STEP=06    AndGate + ResetSeq
//   make play STEP=07    ClockGen
//   make play STEP=11    SysTick (01+ Complete capstone)
//
// This is NOT the grader. Hidden tests check more cases (and use your own
// personal values), so passing here doesn't guarantee full marks.
// Feel free to edit this file; the grader never uses it.
#include "lab.h"
#include <iostream>
#include <string>
#include <vector>

using namespace sc_core;
using namespace sc_dt;

// Records every change of a bool signal so we can print a clean timeline afterwards.
SC_MODULE(EdgeLog) {
    sc_in<bool> in{"in"};
    std::vector<std::string> lines;
    SC_CTOR(EdgeLog) { SC_METHOD(log); sensitive << in; dont_initialize(); }
    void log() { lines.push_back(sc_time_stamp().to_string() + (in.read() ? "  rise" : "  fall")); }
    void show() const {
        for (auto& l : lines) std::cout << "         " << l << "\n";
        if (lines.empty()) std::cout << "         (no changes)\n";
    }
};

static void play_01_04() {
    std::cout << "Step 01  lab_systemc_version() = \"" << lab_systemc_version() << "\"\n"
              << "         kernel version         = \"" << sc_version() << "\"\n\n";

    sc_uint<8> x = 0xA7;
    std::cout << std::hex << std::uppercase
              << "Step 04  high_nibble(0xA7) = 0x" << high_nibble(x).to_uint() << "   (expect 0xA)\n"
              << "         low_nibble(0xA7)  = 0x" << low_nibble(x).to_uint() << "   (expect 0x7)\n"
              << std::dec
              << "         saturating_add(100, 50)  = " << saturating_add(100, 50).to_uint() << "   (expect 150)\n"
              << "         saturating_add(200, 100) = " << saturating_add(200, 100).to_uint() << "   (expect 255)\n\n"
              << "More: make play STEP=05 | 06 | 07 | 11\n";
}

static void play_05() {
    sc_clock clk("clk", 10, SC_NS);
    sc_signal<bool> reset;
    sc_signal<unsigned> count;
    Counter dut("counter");
    dut.clk(clk); dut.reset(reset); dut.count(count);

    reset = true;
    sc_start(15, SC_NS);                       // rising edges at 0 and 10 ns with reset high
    std::cout << "Step 05  after reset: count = " << count.read() << "   (expect 0)\n";
    reset = false;
    for (int i = 1; i <= 5; ++i) {
        sc_start(10, SC_NS);
        std::cout << "         " << sc_time_stamp() << "  count = " << count.read() << "\n";
    }
    std::cout << "         (expect 1, 2, 3, 4, 5)\n";
}

static void play_06() {
    sc_clock clk("clk", 10, SC_NS);
    sc_signal<bool> a, b, y, rst;
    AndGate gate("gate");
    gate.a(a); gate.b(b); gate.y(y);
    ResetSeq rs("rs", 3);
    rs.clk(clk); rs.rst(rst);
    EdgeLog rst_log("rst_log");
    rst_log.in(rst);

    std::cout << "Step 06  AndGate:\n";
    for (int i = 0; i < 4; ++i) {
        a = i & 2; b = i & 1;
        sc_start(1, SC_NS);                    // let the gate react
        std::cout << "         a=" << a.read() << " b=" << b.read() << "  y=" << y.read() << "\n";
    }
    sc_start(56, SC_NS);
    std::cout << "\n         ResetSeq(cycles = 3) on a 10 ns clock (rising edges at 0, 10, 20 ns ...):\n";
    rst_log.show();
    std::cout << "         (expect rise at 0 s, fall at 20 ns)\n";
}

static void play_07() {
    sc_signal<bool> clk;
    ClockGen gen("gen", sc_time(8, SC_NS), 0.25);
    EdgeLog logger("log");
    gen.clk(clk); logger.in(clk);

    std::cout << "Step 07  ClockGen(period = 8 ns, duty = 0.25), first 30 ns:\n";
    sc_start(30, SC_NS);
    logger.show();
    std::cout << "         (expect rise at 0 s, fall at 2 ns, rise at 8 ns, fall at 10 ns, ...)\n";
}

static void play_11() {
    sc_clock clk("clk", 10, SC_NS);                 // rising edges at 0, 10, 20 ... ns
    sc_signal<bool> rst, en, irq;
    sc_signal<sc_dt::sc_uint<8>> prescale;
    sc_signal<sc_dt::sc_uint<32>> compare, count;
    SysTick tick("systick");
    tick.clk(clk); tick.rst(rst); tick.en(en); tick.prescale(prescale); tick.compare(compare);
    tick.count(count); tick.irq(irq);

    rst = true; en = true; prescale = 1; compare = 3;
    sc_start(15, SC_NS);                           // edges at 0 and 10 ns with reset high
    rst = false;
    std::cout << "Step 11  SysTick(prescale = 1, compare = 3): count advances every 2 edges, irq every 8\n";
    for (int i = 0; i < 18; ++i) {
        sc_start(10, SC_NS);
        std::cout << "         " << sc_time_stamp() << "  count = " << count.read() << (irq.read() ? "  irq!" : "") << "\n";
    }
    std::cout << "         (expect count 0,1,1,2,2,3,3,0... and irq exactly when it reloads from 3 to 0)\n";
}

int sc_main(int argc, char* argv[]) {
    std::string step = argc > 1 ? argv[1] : "";
    if      (step == "05") play_05();
    else if (step == "06") play_06();
    else if (step == "07") play_07();
    else if (step == "11") play_11();
    else                   play_01_04();
    return 0;
}
