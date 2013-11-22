#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     HiTeGyro,       sensorI2CHiTechnicGyro)
#pragma config(Sensor, S3,     HiTeIR,         sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     hangLeft,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     conveyorDrive, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     conveyorTurn2, tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     conveyorTurn1, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     rightDrive,    tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C3_2,     leftDrive,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     hangRight,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     flagDrive,     tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//#define COMPETITION

#include "drive.h"
#include "drive.c"
#include "conveyor.h"
#include "conveyor.c"
#include "hang.h"
#include "hang.c"
#include "gyro.h"
gyroSys gyr;
#include "gyro.c"
#include "flag.h"
#include "flag.c"

DriveSys drive;
ConvSys conv;

void turnToAngle(DriveSys t, gyroSys g, float relHeading, int turnRate);
void driveToEncodeVal(DriveSys t, long targetVal, int motorPower);

void initializeRobot()
{
	drive.Left = leftDrive;
	drive.Right = rightDrive;

	//conv.driveMotor = conveyorDrive;
	//conv.turnMotor = conveyorTurn;

	gyr.gyroscope = HiTeGyro;
	initGyroSys(gyr, 1000);
	gyr.readFreq = 1;
	StartTask(findHeading, 6);
	wait1Msec(1000);
	return;
}

task main(){

	initializeRobot();
	PlayTone(3500, 500);
	while(bSoundActive);

	bool isDone = false;
	bool rightPath;
	while(!isDone){
		if(nNxtButtonPressed == 1){
			rightPath = true;
			isDone = true;

			PlayTone(2000, 100);
			while(bSoundActive);
		} else if(nNxtButtonPressed == 2){
			rightPath = false;
			isDone = true;

			PlayTone(5000, 100);
			while(bSoundActive);
		}
	}

	#ifdef COMPETITION
	waitForStart();   // wait for start of tele-op phase
	#endif

	//float compassOffset;
	//compassOffset = SensorValue[HiTeCompass];
	//writeDebugStreamLine("compass %f", compassOffset);

	driveToEncodeVal(drive, 1000, 50);
	return;

	if(rightPath){
		driveToEncodeVal(drive, 100, 50);
		turnToAngle(drive, gyr, 45.0, 25);
		driveToEncodeVal(drive, 10, 50);
		turnToAngle(drive, gyr, -90.0, 25);
		driveToEncodeVal(drive, 200, 50);
	} else {
		driveToEncodeVal(drive, 100, 50);
		turnToAngle(drive, gyr, 45.0, 25);
		driveToEncodeVal(drive, 10, 50);
		turnToAngle(drive, gyr, -90.0, 25);
		driveToEncodeVal(drive, 200, 50);
	}
}

void turnToAngle(DriveSys t, gyroSys g, float relHeading, int turnRate){
	float targetHeading = gyr.rotationsHeading + relHeading;
	if(relHeading < 0){
		motor[t.Right] = turnRate;
		motor[t.Left] = - turnRate;
		while(gyr.rotationsHeading > targetHeading);
		motor[t.Right] = 0;
		motor[t.Left] = 0;
	} else if (relHeading > 0){
		motor[t.Right] = - turnRate;
		motor[t.Left] =  turnRate;
		while(gyr.rotationsHeading < targetHeading);
		motor[t.Right] = 0;
		motor[t.Left] = 0;
	} else {
		return;
	}
	return;
}

void driveToEncodeVal(DriveSys t, long targetVal, int motorPower){
	nMotorEncoder[t.Right] = 0;
	nMotorEncoderTarget[t.Right] = targetVal;
	motor[t.Right] = motorPower;
	motor[t.Left] = motorPower;

	while(nMotorRunState[t.Right] != runStateIdle){
		writeDebugStreamLine("%d", nMotorEncoder[t.Right]);
	};

	motor[t.Right] = 0;
	motor[t.Left] = 0;

	return;
}
