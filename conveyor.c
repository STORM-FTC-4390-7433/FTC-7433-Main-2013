#ifndef CONVEYOR_C
#define CONVEYOR_C

void updateConvSys (ConvSys t, int driveMotorPower, int turnMotorPower){
	motor[t.driveMotor] = driveMotorPower;
	motor[t.turnMotor] = turnMotorPower;
	return;
}

#endif
