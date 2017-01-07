//********************************************************************************************************//
//********************************************SUPER_FUNCTIONS*********************************************//
//********************************************************************************************************//

//---Setup---//:Sets up the gyro and position for the robot to expand
void gyroSetup(int height, int speed)
{
	SensorType[in2] = sensorNone;
	SensorType[in2] = sensorGyro;
	knockknock(height,speed);
	clearTimer(T2);
	nMotorEncoder[LBBase] = 0;
	bwds(100,100,50);
	claw(0);
	armState(1);
	wait1Msec(200);
	armState(-1);
	wait1Msec(100);
	armState(0);
	wait1Msec(600);
	claw(50);
	bwds(40,100,0);
	pArm(1400,0.07,100);
}

void gyroSetupSkills(int height, int speed)
{
	SensorType[in2] = sensorNone;
	SensorType[in2] = sensorGyro;
	knockknock(height,speed);
	bwds(650,100,400);
	lclaw(true);
	rclaw(true);
	wait1Msec(1000);
}
