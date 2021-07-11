#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

char blink_button_advance(char blink_count) //functions normal light  
{
   char changed = 0;

   if(switch_state_down_1){
     red_on=1;
     changed=1;
   }
   else if(switch_state_down_1 == 0){
     red_on = 0
       changed = 1;
  }
  led_changed = changed
    led_update();


  //half dim
  else if(switch_state_down_2){
      while(blink_count <=250){
	if(blink_count == 250){
	  turn_on_red();
	  blink_count=0;
	}
	else{
	  turn_off_red();
	  blink_count++;
	}
      }
    }
  
   //full dim
  else if (switch_state_down_3){
    turn_on_red();
    turn_off_red();
  }

   //off
  else{
    turn_off_red();
  }
}

   //turn off


void state_advance(){
  void turn_on_red(){
  red_on =1;
  led_changed = 1;
  led_update();
}


void state_advance_1(){
  void_off_red(){
  red_on =0;
  led_changed = 1;
  led_update();
}

}
}
