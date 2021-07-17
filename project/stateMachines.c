#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"
#include "led.h"
#include "buzzer.h"

char interruptTime;
char button_four;

void blink_button_advance(char blink_count) //functions normal light  
{
   char changed = 0;

   if(switch_state_down_1){
     interruptTime=0;
     turn_on_red();
     buzzer_set_period(2551);
   }


  //half dim
  else if(switch_state_down_2){
    interruptTime=2;
    turn_on_red();
    buzzer_set_period(3822);
    }
  
   //full dim
  else if (switch_state_down_3){
    turn_on_red();
    turn_off_red();
    buzzer_set_period(3822);
  }
   //Order
  else if(switch_state_down_4){
    interruptTime = 150;
    button_four =1;
    buzzer_set_period(0);
    static char state =0;
    switch (state){
    case 0: buzzer_ser_period(0); red_on = 0; green_on =1; state++; break;
    case 1: buzzer_ser_period(0); red_on = 1; green_on =0; state++; break;
    case 2: buzzer_ser_period(0); red_on = 0; green_on =1; state++; break;
    case 3: buzzer_ser_period(0); red_on = 1; green_on =1; state = 0; break;
    default: state = 0;
    }
    led_changed=1;
    led_update();
  }

   // all off
  else{
    button_four =0;
    turn_off_green();
    turn_off_red();
    buzzer_set_period(0);
  }
}

// led on/off

void turn_on_red(){
  red_on =1;
  led_changed = 1;
  led_update();
}


void turn_off_red(){
  red_on =0;
  led_changed = 1;
  led_update();
}
 void turn_on_green(){
  green_on =1;
  led_changed = 1;
  led_update();
}

void turn_off_green(){
  green_on =0;
  led_changed = 1;
  led_update();
}

