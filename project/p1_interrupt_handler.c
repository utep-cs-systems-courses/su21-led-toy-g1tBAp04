#include <msp430.h>
#include "switches.h"

void
_interrupt_vec(PORT2_VECTOR) Port_2(){

  if(P2IFG & SWITCHES){
    P2IFG &= ~SWITCHES;
    switched_interrupt_handler();
  }
}
