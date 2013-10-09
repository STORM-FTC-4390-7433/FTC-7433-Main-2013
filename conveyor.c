#ifndef CONVEYOR_C
#define CONVEYOR_C

void updateConvSys (ConvSys t, int motorPower){
	motor[t.driveMotor] = motorPower;
	return;
}

#endif