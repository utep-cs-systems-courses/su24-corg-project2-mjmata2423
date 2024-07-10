#include <msp430.h>
#include "switches.h"
#include "buzzer.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){
  static char decisecond_count = 0;
  if(++decisecond_count == tempo){
    int repeat = 1;
    while(repeat <= 5){
      int cnt = 0;
      buzzer_set_period(0);
      while(cnt < 30000){
	cnt++;
      }
      repeat++;
    }
    switch_interrupt_handler();
    decisecond_count = 0;
  }
}
