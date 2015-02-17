//#define _NAMIKI_MOTOR  //For Namiki 22CL-3501PG80:1

//#include <fuzzy_table.h>
#include <PID_Beta6.h>

#include <PinChangeInt.h>
#include <PinChangeIntConfig.h>

#include <MotorWheel.h>
#include <R2WD.h>
#include <Omni3WD.h>
#include <Omni4WD.h>


/*

            \                    /
   wheel1   \                    /   wheel4
   Left     \                    /   Right
    
    
    
    
            /                    \
   wheel2   /                    \   wheel3
   Right    /                    \   Left

 */

/*
irqISR(irq1,isr1);
MotorWheel wheel1(5,4,12,13,&irq1);

irqISR(irq2,isr2);
MotorWheel wheel2(6,7,14,15,&irq2);

irqISR(irq3,isr3);
MotorWheel wheel3(9,8,16,17,&irq3);

irqISR(irq4,isr4);
MotorWheel wheel4(10,11,18,19,&irq4);
 */

irqISR(irq1,isr1);
MotorWheel wheel1(3,2,4,5,&irq1);

irqISR(irq2,isr2);
MotorWheel wheel2(11,12,14,15,&irq2);

irqISR(irq3,isr3);
MotorWheel wheel3(9,8,16,17,&irq3);

irqISR(irq4,isr4);
MotorWheel wheel4(10,7,18,19,&irq4);


Omni4WD Omni(&wheel1,&wheel2,&wheel3,&wheel4);

void goAhead(unsigned int speedMMPS,int interval){
    if(Omni.getCarStat()!=Omni4WD::STAT_ADVANCE) Omni.setCarSlow2Stop(interval);
        Omni.setCarAdvance(0);
        Omni.setCarSpeedMMPS(speedMMPS, interval);
}

void turnLeft(unsigned int speedMMPS,int interval){
    if(Omni.getCarStat()!=Omni4WD::STAT_LEFT) Omni.setCarSlow2Stop(interval);
        Omni.setCarLeft(0);
        Omni.setCarSpeedMMPS(speedMMPS, interval);
}

void turnRight(unsigned int speedMMPS,int interval){
    if(Omni.getCarStat()!=Omni4WD::STAT_RIGHT) Omni.setCarSlow2Stop(interval);
        Omni.setCarRight(0);
        Omni.setCarSpeedMMPS(speedMMPS, interval);
}

void rotateRight(unsigned int speedMMPS,int interval){
    if(Omni.getCarStat()!=Omni4WD::STAT_ROTATERIGHT) Omni.setCarSlow2Stop(interval);
        Omni.setCarRotateRight(0);
        Omni.setCarSpeedMMPS(speedMMPS, interval);
}

void rotateLeft(unsigned int speedMMPS,int interval){
    if(Omni.getCarStat()!=Omni4WD::STAT_ROTATELEFT) Omni.setCarSlow2Stop(interval);
        Omni.setCarRotateLeft(0);
        Omni.setCarSpeedMMPS(speedMMPS, interval);
}

void allStop(unsigned int speedMMPS,int interval){
    if(Omni.getCarStat()!=Omni4WD::STAT_STOP) Omni.setCarSlow2Stop(interval);
	Omni.setCarSlow2Stop(100);
        Omni.setCarStop();
}

void backOff(unsigned int speedMMPS,int interval){
  if(Omni.getCarStat()!=Omni4WD::STAT_BACKOFF) Omni.setCarSlow2Stop(interval);
        Omni.setCarBackoff();
        Omni.setCarSpeedMMPS(speedMMPS, interval);
}


void setup() {

	//TCCR0B=TCCR0B&0xf8|0x01;    // warning!! it will change millis()
	TCCR1B=TCCR1B&0xf8|0x01;    // Pin9,Pin10 PWM 31250Hz
	TCCR2B=TCCR2B&0xf8|0x01;    // Pin3,Pin11 PWM 31250Hz
    
	Omni.PIDEnable(0.35,0.02,0,10);
 	Serial.begin(9600); 
}
#define CAR_MOVE_FORWARD                0x01
#define CAR_MOVE_BACKWARD               0x02
#define CAR_TURN_LEFT                   0x03
#define CAR_TURN_RIGHT                  0x04
#define CAR_STOP                        0x05

char message;
int  command;
void command_executer(int cmd, int vel, int interval){
        switch(cmd){
                case CAR_MOVE_FORWARD:
                        goAhead(vel, interval);
                break;
                case CAR_MOVE_BACKWARD:
                        backOff(vel, interval);
                break;
                case CAR_TURN_LEFT:
                        rotateLeft(vel, interval);
                break;
                case CAR_TURN_RIGHT:
                        rotateRight(vel, interval);
                break;
                case CAR_STOP:
                        allStop(0, 0);
                break;
        }
}

char command_interpreter(char message){
   char ret=0;
   switch (message){
      case 'w':
        ret=CAR_MOVE_FORWARD;
       break;
      case 'a':
        ret=CAR_TURN_LEFT;
        break;
      case 's':
      case 'b':
        ret=CAR_STOP;
        break;
      case 'd':
        ret=CAR_TURN_RIGHT;
        break;
      case 'x':
        ret=CAR_MOVE_BACKWARD;
        break;

/*Add your own command here.*/

    }
        return ret;
}

int speed=160;
int duration=100;
void loop() {
        if(Serial.available() > 0){
	message=Serial.read();
	}
	command=command_interpreter(message);
	command_executer(command,speed,duration);
	Omni.PIDRegulate();



    /*
	Omni.setCarLeft(0);
	Omni.setCarSpeedMMPS(200,500);
	Omni.delayMS(5000);
	Omni.setCarSlow2Stop(500);

	Omni.setCarRight(0);
	Omni.setCarSpeedMMPS(200,500);
	Omni.delayMS(5000);
	Omni.setCarSlow2Stop(500);    
    */
    
}

