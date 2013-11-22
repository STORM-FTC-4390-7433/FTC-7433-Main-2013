#ifndef CONVEYOR_C
#define CONVEYOR_C

void updateConvSys (ConvSys t, int driveMotorPower, int turnMotorPower){
	t.iterations++;
	if(t.iterations % 2 == 0){
		motor[t.driveMotor] = driveMotorPower;
		motor[t.turnMotor1] = turnMotorPower * 1.5;
		motor[t.turnMotor2] = turnMotorPower * 1.5;
	} else {
		motor[t.driveMotor] = driveMotorPower;
		motor[t.turnMotor1] = turnMotorPower * 0.5;
		motor[t.turnMotor2] = turnMotorPower * 0.5;
	}
	return;
}

#endif
