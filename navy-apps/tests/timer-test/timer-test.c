#include <stdio.h>
//#include <sys/timer.h>

int main() {
  int half_sec = 1;
  struct timeval *tv;
  gettimeofday(tv);
  while(1){
    while (tv->tv_usec/500000<half_sec){
      gettimeofday(tv);
    }
    half_sec++;
    printf("%d half_secs pass \n",half_sec);
  }
}

