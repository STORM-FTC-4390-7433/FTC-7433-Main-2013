#ifndef DRIVESYS_C
#define DRIVESYS_C

void updateDriveSys (DriveSys t, int leftMotorPower, int rightMotorPower){
	motor[t.Left] = leftMotorPower;
	motor[t.Right] = rightMotorPower;
	return;
}

#endif
