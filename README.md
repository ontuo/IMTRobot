#Embedded Control System Project 2015

The Arduino Makefile is from Sudar's project, check on GitHub for details:

[Arduino-Makefile](https://github.com/sudar/Arduino-Makefile.git)

The (adapted) third party libraries used in the project:

[1] [MsTimer2](http://playground.arduino.cc/Main/MsTimer2)

[2]  [PID_v1](http://playground.arduino.cc/Code/PIDLibrary)

[3] [LiquidCrystal_I2C](https://github.com/marcmerlin/NewLiquidCrystal.git)

[4] [Motor Shield](http://playground.arduino.cc/Main/AdafruitMotorShield)

[1]-[3] are in directory repos/libraries; some functions in hw_functions.cpp are adapted from [4].

###To compile the project:

####Install arduino
```
	sudo apt-get install arduino arduino-core arduino-mk
```

####Install serial port module for perl (needed by Arduino-Makefile)
```
	sudo apt-get install libdevice-serialport-perl
```
####Copy the third party repositories from repos to your sketchbook
```
	cp -r repos/libraries/* ~/sketchbook/libraries/
```
####Build the project
```
	make
```
####Upload to Arduino
```
	make upload
```
The default board is uno, you can change it in the Makefile.

#List of Materials
###Electronic modules and sensors

1. Arduino Uno [link](http://arduino.cc/en/Main/arduinoBoardUno)

2. Arduino MotorShield [link](http://playground.arduino.cc/Main/AdafruitMotorShield)

3. Photoresistor [link](http://en.wikipedia.org/wiki/Photoresistor)

4. Ultrasonic range finder (HC-SR04) [link](http://www.robotshop.com/eu/en/hc-sr04-ultrasonic-range-finder.html)

5. Accelerometer ADXL335/ADXL345 [link](http://www.robotshop.com/eu/en/sfe-3g-tripleaxis-accelerometer-breakout-board-adxl335.html)

6. LCD 1602 with I2C interface [link](http://www.robotshop.com/eu/en/dfrobot-i2c-twi-lcd1602-module.html) 

7. 2x Servo motors [link](http://www.robotshop.com/eu/en/hitec-hs-485hb-servo-motor.html)

8. 4x DC motors with gearbox [link](http://www.robotshop.com/eu/en/solarbotics-gm9-gear-motor-9.html)

9. 4x Tamiya Wheels (or two pairs) [link](http://www.robotshop.com/eu/en/tamiya-wheels-pair.html)

10. HC06 Bluetooth module (or HC-05) [link](http://www.robotshop.com/eu/en/electronic-brick-serial-bluetooth-module.html)

11. 1x LED and 2x resistors (220 Ohm and 1k Ohm)

###Bluetooth control interface (Android Studio project)

The Bluetooth control application for Android device is available on GitHub:

```
git clone https://github.com/lin-zhang/android_bluetooth.git
```
###Drawing of the car for laser cutting
The drawing is designed for 3mm plate, MDF is recommended.

```
git clone https://github.com/lin-zhang/lc_designs.git
```
