//*********************************************************bwds***********************************************//
//********************************************SUPER_FUNCTIONS*********************************************//
//********************************************************************************************************//

//---Setup---//:Sets up the gyro and position for the robot to expand
void setup()
{
	fwds(800,127,100);
	armState(1);
	wait1Msec(200);
	armState(-1);
	wait1Msec(200);
	armState(0);
	bwds(2000,100,300);
	claw(600);
}
task launch()
{
	startTask(autoRelease);
	while(!SensorValue[release])
	{
		armState(1);
	}
	wait1Msec(400);
	while(SensorValue[armPot] > 690)
	{
		armState(-1);
	}
	armState(0);
}
