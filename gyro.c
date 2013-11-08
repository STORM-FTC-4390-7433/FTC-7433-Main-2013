#ifndef GYRO_C
#define GYRO_C

void updateGyroSys(gyroSys t){
		//t.dTOffset = ((float)(nSysTime - t.startTime) / (float)t.iterations) - t.readFreq;
		nxtDisplayString(2, "%f", (float)(nSysTime - t.startTime) / (float)t.iterations);
		t.dTOffset = 0;
}

void initGyroSys(gyroSys t, int initPeriod){
		long int startT = nSysTime;

		unsigned long long int sumGyroVals = 0;
		unsigned long long int iteration = 0;
		while((nSysTime - startT) < initPeriod){
			sumGyroVals += SensorValue[t.gyroscope];
			iteration++;
		}
		t.inOffset = (float)sumGyroVals / (float)iteration;
		writeDebugStreamLine("sum gyro %d", sumGyroVals);
		writeDebugStreamLine("gyro iters %d", iteration);
		writeDebugStreamLine("%f", t.inOffset);
}

task findHeading(){
	//because robotc does not support parameters being passed to functions the gyroSys variable MUST be named "gyr"
	gyr.iterations = 0;

	gyr.startTime = nSysTime;

	float actualGyro = SensorValue[gyr.gyroscope] - gyr.inOffset;
	while(true){
			//if( abs(actualGyro) > 1){
				gyr.rotationsHeading =  ((gyr.rotationsHeading + (actualGyro * ((gyr.readFreq - gyr.dTOffset)/1000.0))));
				gyr.currentHeading = ((int)(gyr.rotationsHeading % 360) + 360) % 360;
		//	}
			gyr.iterations++;
			wait1Msec(gyr.readFreq);
	}
}
#endif
