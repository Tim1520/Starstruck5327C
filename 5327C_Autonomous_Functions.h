//********************************************************************************************************//
//********************************************AUTON_FUNCTIONS*********************************************//
//********************************************************************************************************//
//---Base---//:Controls the speed of the base motors.
void base(int rSpeed, int lSpeed)
{
	motor[RFBase] = rSpeed;
	motor[RBBase] = rSpeed;
	motor[LFBase] = lSpeed;
	motor[LBBase] = lSpeed;
}

//---Turn---//:Turns robot to a given angle at a given speed.
void turn(int distance, int speed, int direction, int brake, int wait)
{
	SensorValue[LEncoder] = 0;
	SensorValue[REncoder] = 0;
	while(direction * SensorValue[LEncoder] < distance && direction * SensorValue[REncoder] < distance)
	{
		base((direction * speed) , (-direction * speed));
	}
	if(brake != 0)
	{
		base(-direction * brake,direction * brake);
		wait1Msec(100);
	}
	base(0,0);
	wait1Msec(wait);
}

//---Swing---//:Turns using only one side of the base.
void swing(int distance, int speed, int direction, int brake, int wait)
{
	SensorValue[LEncoder] = 0;
	SensorValue[REncoder] = 0;
	if(direction > 0)
	{
		while(direction * SensorValue[REncoder] < distance)
		{
			base(direction * speed,-10);
		}
		if(brake != 0)
		{
			base(-brake,0);
			wait1Msec(200);
		}
	}
	else
	{
		while(direction * SensorValue[LEncoder] < distance)
		{
			base(-10,-direction * speed);
		}
		if(brake != 0)
		{
			base(0,-brake);
			wait1Msec(200);
		}
	}

	base(0,0);
	wait1Msec(wait);
}

void swingB(int distance, int speed, int direction, int brake, int wait)
{
	SensorValue[LEncoder] = 0;
	SensorValue[REncoder] = 0;
	if(direction > 0)
	{
		while(direction * SensorValue[LEncoder] < distance)
		{
			base(10,-direction * speed);
		}
		if(brake != 0)
		{
			base(0,brake);
			wait1Msec(200);
		}
	}
	else
	{
		while(direction * SensorValue[REncoder] <distance)
		{
			base(direction * speed,10);
		}
		if(brake != 0)
		{
			base(brake,0);
			wait1Msec(200);
		}
	}

	base(0,0);
	wait1Msec(wait);
}

//---Forwards/Backwards---//:Moves the base forward and backward using IME's.
void fwds(int distance, int speed, int brake, int wait)
{
	clearTimer(T2);
	SensorValue[REncoder] = 0;
	while(abs(SensorValue[REncoder]) < distance && time1[T2] < 3000)
	{
		base(speed,speed);
	}
	if(brake != 0)
	{
		base(-brake,-brake);
		wait1Msec(100);
	}
	base(0,0);
	wait1Msec(wait);
}

void bwds(int distance, int speed, int brake, int wait)
{
	fwds(distance, -speed, brake, wait);
}

void bwdsT(int time, int speed, int wait)
{
	base(-speed,-speed);
	wait1Msec(time);
	base(0,0);
	wait1Msec(wait);
}

void fwdsT(int time, int speed, int wait)
{
	bwdsT(time,-speed,wait);
}

void pArm(int height, float hspeed, int wait)
{
	if(SensorValue[armPot] < height)
	{
		while(SensorValue[armPot] < height)
		{
			armState(1);
		}
	}
	else
	{
		while(SensorValue[armPot] > height)
		{
			armState(-1);
		}
	}
	armState(hspeed);
	wait1Msec(wait);
}

void pArmH(int height, float hspeed, int wait)
{
	if(SensorValue[armPot] < height)
	{
		while(SensorValue[armPot] < height)
		{
			armState(0.09);
		}
	}
	else
	{
		while(SensorValue[armPot] > height)
		{
			armState(-0.09);
		}
	}
	armState(hspeed);
	wait1Msec(wait);
}

void pClaw(int value, int hspeed, int wait)
{
	if(SensorValue[clawPot] < value)
	{
		while(SensorValue[clawPot] < value)
		{
			motor[clw] = -127;
		}
	}
	else
	{
		while(SensorValue[clawPot] > value)
		{
			motor[clw] = 127;
		}
	}
	motor[clw] = hspeed;
	wait1Msec(wait);
}

void tClaw(int time, int speed, int hspeed, int wait)
{
	motor[clw] = -speed;
	wait1Msec(time);
	motor[clw] = -hspeed;
	wait1Msec(wait);
}
