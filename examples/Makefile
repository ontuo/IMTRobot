BOARD_TAG    = atmega328
LOCAL_CPP_SRCS = src/Omni4WD_test.cpp
ARDUINO_LIBS = Wire Servo LiquidCrystal_I2C MsTimer2 PID_Beta6 SONAR PinChangeInt MotorWheel
THIRD_PARTY_LIBS=${HOME}/sketchbook/libraries
CPPFLAGS+=      -I /usr/share/arduino/libraries/Servo                   \
                -I /usr/share/arduino/libraries/Wire                    \
                -I ${THIRD_PARTY_LIBS}/LiquidCrystal_I2C                \
                -I ${THIRD_PARTY_LIBS}/MsTimer2                         \
                -I ${THIRD_PARTY_LIBS}/PID_Beta6			\
                -I ${THIRD_PARTY_LIBS}/SONAR				\
                -I ${THIRD_PARTY_LIBS}/PinChangeInt			\
                -I ${THIRD_PARTY_LIBS}/MotorWheel			

include ./Arduino.mk
