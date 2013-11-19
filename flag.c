#ifndef FLAGSYS_C
#define FLAGSYS_C

void updateFlagSys (FlagSys t, int motorPower, int tophat){
	if(tophat == 0){
		motor[t.drive] = motorPower;
	} else if (tophat == 4){
		motor[t.drive] = - motorPower;
	} else {
		motor[t.drive] = 0;
		return;
	}
}

#endif
