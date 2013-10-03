#ifndef DRIVESYS_C
#define DRIVESYS_C

void updateDriveSys (DriveSys t, int leftMotorPower, int rightMotorPower){
	motor[t.frontLeft] = leftMotorPower;
	motor[t.backLeft] = leftMotorPower;
	motor[t.frontRight] = rightMotorPower;
	motor[t.backLeft] = rightMotorPower;
	return;
}

#endif