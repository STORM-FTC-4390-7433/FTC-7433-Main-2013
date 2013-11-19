#ifndef CONVEYOR_H
#define CONVEYOR_H

typedef struct{
	//pointers to motors in the array motor[]
	tMotor driveMotor,
			turnMotor;
		unsigned long long iterations;
}ConvSys;

#endif
