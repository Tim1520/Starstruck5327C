//********************************************************************************************************//
//********************************************SUPER_FUNCTIONS*********************************************//
//********************************************************************************************************//
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
	motor[clw] = 0;
	armState(0);
	wait1Msec(600);
	armState(-1);
	wait1Msec(2100);
	armState(-0.12);
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

task hoard()
{
	pArm(1500,0,0);
	pClaw(3500,0,0);
	pArmH(2500,0,0);
}

task lift()
{
	pArmH(1850,-0.12,0);
}
task sClose()
{
	pClaw(2100,-10,0);
}
