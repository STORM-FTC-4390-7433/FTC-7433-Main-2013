#ifndef CONVEYOR_C
#define CONVEYOR_C

void updateConvSys (ConvSys t, int driveMotorPower, int turnMotorPower){
	t.iterations++;
	if(t.iterations % 2 == 0){
		motor[t.driveMotor] = driveMotorPower * 1.5;
		motor[t.turnMotor] = turnMotorPower * 1.5;
	} else {
		motor[t.driveMotor] = driveMotorPower * 0.5;
		motor[t.turnMotor] = turnMotorPower * 0.5;
	}
	return;
}

#endif
