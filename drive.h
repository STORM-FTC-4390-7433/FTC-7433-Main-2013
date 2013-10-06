#ifndef DRIVESYS_H
#define DRIVESYS_H
#include "drive.h"

typedef struct DriveSys {
	//pointers to motors in the array motor[]
	tMotor frontLeft,
		   frontRight,
		   backLeft,
		   backRight;
	//pointers to motor encoders attached to motor at named location on bot
	tSensor frontLeftEnc, 
			frontRightEnc,
		    backLeftEnc,
			backRightEnc;
};

#endif