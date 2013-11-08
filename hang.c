#ifndef HANGSYS_C
#define HANGSYS_C
void updateHangSys (HangSys t, int motorPower){
	motor[t.rightRaise] = motorPower;
	motor[t.leftRaise] = motorPower;
	return;
}
#endif
