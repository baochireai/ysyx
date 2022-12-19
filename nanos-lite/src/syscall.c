#include <common.h>
#include "syscall.h"

#define strace
void SYS_yield(){
  asm volatile("li a7, -1; ecall");
}


void do_syscall(Context *c) {
  uintptr_t a[4];
  a[0] = c->GPR1;//syscall number
  //printf("GPR2:%d")
#ifdef strace
  switch (a[0]) {
    case 0:
      printf("halt(a[0])\n");
      halt(a[0]);break;
    case 1:
      printf("SYS_yield()\t=");
      SYS_yield();c->GPRx=0;
      break;
    default: panic("Unhandled syscall ID = %d", a[0]);
  }
#elif
  switch (a[0]) {
    case 0:
      halt(a[0]);break;
    case 1:
      SYS_yield();c->GPRx=0;break;
    default: panic("Unhandled syscall ID = %d", a[0]);
  }
#endif
}
