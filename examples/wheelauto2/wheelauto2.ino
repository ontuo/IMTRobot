//#define _CLUB_MOTOR 1  //Added by nightcat , for _CLUB_MOTOR 

#include <PinChangeInt.h>
#include <PinChangeIntConfig.h>
#include <PID_Beta6.h>
#include <MotorWheel.h>
#ifndef MICROS_PER_SEC
#define MICROS_PER_SEC 1000000
#endif
char chr ;



irqISR(irq1,isr1);
MotorWheel wheel1(9,8,6,18,19,&irq1);  // Motor PWM:Pin9, DIR:Pin26, DIR B:Pin27, Encoder A:Pin3, B:Pin4

irqISR(irq2,isr2);
MotorWheel wheel2(10,11,7,2,3,&irq2);    // Motor PWM:Pin5, DIR:Pin24, DIR B:Pin25, Encoder A:Pin10, B:Pin11

int checked = 0;

void setup() {
  TCCR1B=TCCR1B&0xf8|0x01;    // Pin9,Pin10 PWM 31250Hz
  
  wheel1.PIDEnable(KC,TAUI,TAUD,10);
  wheel2.PIDEnable(KC,TAUI,TAUD,10);

  Serial.begin(19200);
}

void loop() {
  
   while (Serial.available() > 0) {
      chr = Serial.read();
      Serial.println(chr);
   }

   if(chr == 'f' && checked ==0 ) {
     wheel1.setSpeedMMPS(100,DIR_ADVANCE);
     wheel2.setSpeedMMPS(100,DIR_ADVANCE);
     checked == 1;
   }else if (chr == 'b' && checked ==0 ) {
     wheel1.setSpeedMMPS(100,DIR_BACKOFF);
     wheel2.setSpeedMMPS(100,DIR_BACKOFF);
     checked == 1;
   }
 
  if( chr == 'f' || chr == 'b' ) {
    wheel1.PIDRegulate();
    wheel2.PIDRegulate();
    
    if(millis()%500==0) {
      Serial.println("");
      Serial.print("Wheel1 speedRPM> ");
      Serial.println(wheel1.getSpeedRPM(),DEC);
      Serial.print("Wheel2 speedRPM> ");
      Serial.println(wheel2.getSpeedRPM(),DEC);
    }
  }

}

