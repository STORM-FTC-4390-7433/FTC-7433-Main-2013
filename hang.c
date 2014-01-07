#ifndef HANGSYS_C
#define HANGSYS_C

task autoHangerDeploy(){
	writeDebugStreamLine("started");
	hang.autoActive = true;

	motor[hang.leftRaise] = 100;
	motor[hang.rightRaise] = 100;
	long long int startTime = nSysTime;
	writeDebugStreamLine("start time %d", startTime);
	writeDebugStreamLine("target time %d", hang.autoTargetTime);
	while(nSysTime - startTime < hang.autoTargetTime){
		if(joy2Btn(1)){
			break;
		}
	}

	motor[hang.leftRaise] = 0;
	motor[hang.rightRaise] = 0;

	hang.autoActive = false;
}

void updateHangSys (HangSys t, int motorPower, bool leftIndUp, bool leftIndDown, bool rightIndUp, bool rightIndDown, bool autoStart){
	if(!t.autoActive){
		if((!leftIndUp && !leftIndDown && !rightIndUp && !rightIndDown) && autoStart){
			writeDebugStreamLine("autoActive start");
			StartTask(autoHangerDeploy, 7);
		} else {
			if(leftIndUp){
				motor[t.leftRaise] = motorPower;
			} else if (leftIndDown){
				motor[t.leftRaise] = - motorPower;
			} else {
				motor[t.leftRaise] = 0;
			}
			if(rightIndUp){
				motor[t.rightRaise] = motorPower;
			}	else if(rightIndDown){
				motor[t.rightRaise] = -motorPower;
			} else {
				motor[t.rightRaise] = 0;
			}
		}
	}
}
#endif
