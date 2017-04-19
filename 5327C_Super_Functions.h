//********************************************************************************************************//
//********************************************SUPER_FUNCTIONS*********************************************//
//********************************************************************************************************//

task sClose()
{
	pClaw(2600,5,0);
}

task launch()
{
	while(SensorValue[armPot] < 2480)
	{
		armState(1);
		if(SensorValue[armPot] > 1800 && SensorValue[clawPot] > 2900)
		{
			motor[clw] = 127;
		}
		else if(SensorValue[clawPot] > 2900)
		{
			motor[clw] = 0;
		}
	}
	startTask(sClose);
	motor[clw] = 0;
	armState(0);
	wait1Msec(600);
	armState(-1);
	wait1Msec(2300);
	armState(-0.2);
}

task lastLaunch()
{
	while(SensorValue[armPot] < 2480)
	{
		armState(1);
		if(SensorValue[armPot] > 1800 && SensorValue[clawPot] > 2900)
		{
			motor[clw] = 127;
		}
		else if(SensorValue[clawPot] > 2900)
		{
			motor[clw] = 0;
		}
	}
	motor[clw] = 0;
	armState(0);
}

task hLift()
{
	pArmH(800,-0.06,0);
}
task hClaw()
{
	wait1Msec(400);
	pClaw(3500,0,0);
}
task open()
{
	motor[winch] = 127;
	wait1Msec(250);
	motor[winch] = -127;
	wait1Msec(250);
	motor[winch] = 0;
}

task lift()
{
	pArmH(1700,-0.18,0);
}
