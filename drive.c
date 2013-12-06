#ifndef DRIVESYS_C
#define DRIVESYS_C

void updateDriveSys (DriveSys t, int leftMotorPower, int rightMotorPower){
	if((nSysTime - t.lastEncodRead) > 100){
		t.rightEncoder += nMotorEncoderTarget[t.Right];
		t.leftEncoder += nMotorEncoderTarget[t.Left];
		t.lastEncodRead = nSysTime;
	}
	motor[t.Left] = leftMotorPower;
	motor[t.Right] = rightMotorPower;
	return;
}

#endif
