#ifndef GYRO_H
#define GYRO_H
typedef struct{
	//pointer to sensor
	tSensors gyroscope;

	//the value to subtract from sensor readings such that when the sensor is stationary it returns 0;
	float inOffset;

	//current relative heading of sensor between 0 and 359
	float currentHeading;
	//current relative heading of sensor between -3.40282e38 and +3.40282e38
	float rotationsHeading;

	//frequency in milliseconds to read a value from the sensor
	long readFreq;
	//number of completed iterations through the "findHeading" task
	long iterations;
	//start time of the "findHeading" task, this value is used to find the
	//most accurate value for dT when determining currentHeading
	long startTime;
	//value to subtract from the readFreq to most accuratley determine the dT
	//this value is determined using the equation dToffset = ((nSysTime - startTime) / iterations) - readFreq
	float dTOffset;

	//heading which the sensor "wants" to point towards (useful for AI algorithms)
	float targetHeading;
}gyroSys;
#endif
