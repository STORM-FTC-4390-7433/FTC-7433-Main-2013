#ifndef HANGSYS_C
#define HANGSYS_C
void updateHangSys (HangSys t, int motorPower){
	motor[t.rightRaise] = motorPower;
	motor[t.leftRaise] = motorPower;
	return;
}
#endif
//This code makes the arm go up and down.
//by:Justin
//also gives the power to the motors Lines(4,5)  