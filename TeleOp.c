#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
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

#define COMPETITION

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.
#include "drive.h"
#include "drive.c"
#include "conveyor.h"
#include "conveyor.c"
#include "hang.h"
HangSys hang;
#include "hang.c"
#include "gyro.h"
gyroSys gyr;
#include "gyro.c"
#include "flag.h"
#include "flag.c"

DriveSys drive;
ConvSys conv;
FlagSys flag;

void initializeRobot(){
	drive.Left = leftDrive;
	drive.Right = rightDrive;

	conv.driveMotor = conveyorDrive;
	conv.turnMotor1 = conveyorTurn1;
	conv.turnMotor2 = conveyorTurn2;

	hang.leftRaise = hangLeft;
	hang.rightRaise = hangRight;
	hang.autoActive = false;
	hang.autoTargetTime = 40000;

	flag.drive = flagDrive;

	gyr.gyroscope = HiTeGyro;
	initGyroSys(gyr, 1000);
	gyr.readFreq = 1;
	StartTask(findHeading, 10);
	wait1Msec(1000);

	return;
}

task main(){

	initializeRobot();

	#ifdef COMPETITION
	waitForStart();   // wait for start of tele-op phase
	#endif

	//float compassOffset;
	//compassOffset = SensorValue[HiTeCompass];
	//writeDebugStreamLine("compass %f", compassOffset);

	while (true){
		getJoystickSettings(joystick);

		updateGyroSys(gyr);
		nxtDisplayCenteredTextLine(0, "Enc: %d", nMotorEncoder[drive.Right]);
		nxtDisplayCenteredTextLine(1, "gyr: %d", gyr.rotationsHeading);
		if(joystick.joy1_TopHat == 1){
			nMotorEncoder[drive.Right] = 0;
			gyr.rotationsHeading = 0;
		}
		if(joy1Btn(10)){
			updateDriveSys(drive, joystick.joy1_y1 * (100.0/128.0), joystick.joy1_y1 * (100.0/128.0));
		} else if(joy1Btn(9)){
			updateDriveSys(drive, -joystick.joy1_y2 * (100.0/128.0), joystick.joy1_y2 * (100.0/128.0));
		} else {
			updateDriveSys(drive, joystick.joy1_y1 * (100.0/128.0), joystick.joy1_y2 * (100.0/128.0));
		}
		updateConvSys(conv, joystick.joy2_y1 * (100.0/128.0 * 1.5), joystick.joy2_y2 * (100.0/(128.0 * 1.5)));
		updateHangSys(hang, 100, joy2Btn(5), joy2Btn(7), joy2Btn(6), joy2Btn(8), joy2Btn(3));
		updateFlagSys(flag, 100, joystick.joy2_TopHat);
	}
}
