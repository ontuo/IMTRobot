#define _CLUB_MOTOR 1  //Added by nightcat , for _CLUB_MOTOR 

#include <PinChangeInt.h>
#include <PinChangeIntConfig.h>
#include <PID_Beta6.h>
#include <MotorWheel.h>
#ifndef MICROS_PER_SEC
#define MICROS_PER_SEC 1000000
#endif
#define DEBUG  
char chr ;
int  a;
int  b;


irqISR(irq1,isr1);
MotorWheel wheel1(9,8,6,18,19,&irq1);  // Motor PWM:Pin9, DIR:Pin26, DIR B:Pin27, Encoder A:Pin3, B:Pin4

void setup() {
  TCCR1B=TCCR1B&0xf8|0x01;      // Pin9,Pin10 PWM 31250Hz 
   
  Serial.begin(19200);
  wheel1.setupInterrupt();
}
void loop() {
  
   while (Serial.available() > 0) {
      chr = Serial.read();
      Serial.println(chr);
   }
  
   if(chr == 'f'){
    wheel1.advancePWM(50);
    //Serial.println("advancePWM");
   }else if(chr == 'b') {
    wheel1.backoffPWM(50);
    //Serial.println("backoffPWM");
   } 
 
  if(chr == 'f' || chr == 'b'  || chr == 'a') {
    
    if(millis()%500==0) {    
    Serial.print("speedPPS -> ");
    Serial.println(wheel1.isr->speedPPS);        
    Serial.print("currDirection -> ");
    Serial.println(wheel1.isr->currDirection);    
    Serial.print("pulses -> ");
    Serial.println(wheel1.isr->pulses);
   
    Serial.print("speedRPM --> ");
    Serial.println(wheel1.getSpeedRPM(),DEC); //display the speed of the MotorWheel
    Serial.print("MMPS --> ");
    Serial.println(wheel1.getSpeedMMPS(),DEC); //display the speed of the motor

    //wheel1.debugger();
    }
  }

}

