// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Implementation of DPI export functions.
//
// Verilator compiles this file in when DPI functions are used.
// If you have multiple Verilated designs with the same DPI exported
// function names, you will get multiple definition link errors from here.
// This is an unfortunate result of the DPI specification.
// To solve this, either
//    1. Call Vtop::{export_function} instead,
//       and do not even bother to compile this file
// or 2. Compile all __Dpi.cpp files in the same compiler run,
//       and #ifdefs already inserted here will sort everything out.

#include "Vtop__Dpi.h"
#include "Vtop.h"

#ifndef VL_DPIDECL_isEbreak_
#define VL_DPIDECL_isEbreak_
void isEbreak(const svLogicVecVal* inst, svLogic* IsEbreak) {
    // DPI export at /home/mrxue/ysyx-workbench/npc/vsrc/top.v:3:6
    return Vtop::isEbreak(inst, IsEbreak);
}
#endif
