//*********************************************************bwds***********************************************//
//********************************************SUPER_FUNCTIONS*********************************************//
//********************************************************************************************************//

//---Setup---//:Sets up the gyro and position for the robot to expand
void setup()
{
	//fwds(800,127,100);
	armState(1);
	wait1Msec(300);
	armState(-1);
	wait1Msec(200);
	armState(0);
	bwds(1200,100,300);
	claw(600);
}
task launch()
{
	while(!SensorValue[release])
	{
		armState(1);
	}
	claw(400);
	armState(-1);
	wait1Msec(1400);
	armState(0);
}
task knock()
{
	while(!SensorValue[release])
	{
		armState(1);
	}
	armState(-1);
	wait1Msec(1400);
	armState(0);
}
