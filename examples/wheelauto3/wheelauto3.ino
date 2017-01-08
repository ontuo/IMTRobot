#include <PinChangeInt.h>
#include <PinChangeIntConfig.h>
#include <PID_Beta6.h>
#include <MotorWheel.h>
#ifndef MICROS_PER_SEC
#define MICROS_PER_SEC 1000000
#endif
char chr ;

#define _NEXUS_MOTOR 1  //Added by nightcat , for _NEXUS_MOTOR  3WD

irqISR(irq1,isr1);
MotorWheel wheel1(9,24,25,3,4,&irq1);  // Motor PWM:Pin9, DIR:Pin26, DIR B:Pin27, Encoder A:Pin3, B:Pin4

irqISR(irq2,isr2);
MotorWheel wheel2(5,26,27,10,11,&irq2);    // Motor PWM:Pin5, DIR:Pin24, DIR B:Pin25, Encoder A:Pin10, B:Pin11

irqISR(irq3,isr3);
MotorWheel wheel3(6,22,23,12,13,&irq3); // Motor PWM:Pin6, DIR:Pin22, DIR B:Pin23, Encoder A:Pin12, B:Pin13

void setup() {
  //TCCR1B=TCCR1B&0xf8|0x01;        // Pin9,Pin10 PWM 31250Hz, Silent PWM
  TCCR2B=TCCR2B&0xf8|0x01;        // Atmega1280/2560, Pin9-->PWM, Timer2 ChannelB
  TCCR3B=TCCR3B&0xf8|0x01;        // Atmega1280/2560, Pin5-->PWM, Timer3 ChannelA
  TCCR4B=TCCR4B&0xf8|0x01;        // Atmega1280/2560, Pin6-->PWM, Timer4 ChannelA

  
  wheel1.setSpeedMMPS(50,DIR_ADVANCE);
  wheel1.PIDEnable(KC,TAUI,TAUD,10);
  wheel2.setSpeedMMPS(50,DIR_ADVANCE);
  wheel2.PIDEnable(KC,TAUI,TAUD,10);
  wheel3.setSpeedMMPS(50,DIR_ADVANCE);
  wheel3.PIDEnable(KC,TAUI,TAUD,10);

  Serial.begin(19200);
}

void loop() {
  
   while (Serial.available() > 0) {
      chr = Serial.read();
      Serial.println(chr);
   }
  
   if(chr == 'a'){
        wheel1.PIDRegulate();
        wheel2.PIDRegulate();
        wheel3.PIDRegulate();
   }
  
  if( chr == 'a' ) {
    if(millis()%500==0) {
      Serial.print("Wheel1 speedRPM> ");
      Serial.println(wheel1.getSpeedRPM(),DEC);
                  Serial.print("Wheel2 speedRPM> ");
      Serial.println(wheel2.getSpeedRPM(),DEC);
                  Serial.print("Wheel3 speedRPM> ");
      Serial.println(wheel3.getSpeedRPM(),DEC);             
          //wheel1.debugger();
    }
  }

}

