#ifndef CONVEYOR_H
#define CONVEYOR_H

typedef struct{
	//pointers to motors in the array motor[]
	tMotor driveMotor,
			turnMotor1,
			turnMotor2;
		unsigned long iterations;
}ConvSys;

#endif
