#ifndef HANGSYS_C
#define HANGSYS_C
void updateHangSys (HangSys t, int motorPower, bool upButton, bool downButton){
	/*if(t.direction != 0){
		if(nSysTime - t.moveStartTime >= t.targetMoveTime ){
			t.direction = 0;
			motor[t.leftRaise] = 0;
			motor[t.rightRaise] = 0;
		}
	}
	if(t.direction == 0){
		if(upButton ^ downButton){
			if(upButton){
				t.moveStartTime = nSysTime;
				t.direction = 1;
				motor[t.leftRaise] = motorPower;
				motor[t.rightRaise] = motorPower;
			} else {
				t.moveStartTime = nSysTime;
				t.direction = -1;
				motor[t.leftRaise] = - motorPower;
				motor[t.rightRaise] = - motorPower;
			}
		}
	}
	return; */
		if(upButton){
		motor[t.rightRaise] = motorPower;
		motor[t.leftRaise] = motorPower;
	} else if (downButton){
		motor[t.rightRaise] = - motorPower;
		motor[t.leftRaise] = - motorPower;
	} else {
		motor[t.rightRaise] = 0;
		motor[t.leftRaise] = 0;
		return;
	}
}
#endif
