#ifndef HANGSYS_H
#define HANGSYS_H
typedef struct{
	//pointers to motors in the array motor[]
	tMotor leftRaise,
			rightRaise;
	//value to hold the current SysTime at the moment that a movement operation begins
	int moveStartTime;
	//target length of time for the lift mechanism to move per movement operation
	int targetMoveTime;
	//direction of current travel 1 = up, -1 = down, 0 = stationary
 int direction;
}HangSys;
#endif
