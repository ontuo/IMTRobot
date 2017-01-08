####README

IMTRobot  (ROS智能车驱动库)

说明：

 - 创客智造维护的分支，修改自lin-zhang的omni4wd源代码.


修改：

 - 由原来的PWD/DIR的2pin模式，转为PWD/DIR/DIRB的3pin模式。
 - 独立出Motors.h头文件，便于设置不同电机
 - 精简代码
 - 增加ROS封装包
 - 增加Python通讯包
 

功能：

 - 支持2WD差速轮
 - 支持3WD全向轮
 - 支持4WD全向轮
 - 支持4WD万向轮
 
安装说明：

 - 参考examples/Arduino.MK
 - 参考examples/Common.MK
 

库测试例子：
 
 - 参考repos/libraries/类库下的例子
 







