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
void turn(int distance, int speed, int direction, int wait)
{
	SensorValue[LEncoder] = 0;
	SensorValue[REncoder] = 0;
	while(direction * SensorValue[LEncoder] < distance && direction * SensorValue[REncoder] < distance)
	{
		base((direction * speed) , (-direction * speed));
	}
	base(0,0);
	wait1Msec(wait);
}

//---Swing---//:Turns using only one side of the base.
void swing(int distance, int speed, int direction, int wait)
{
	SensorValue[LEncoder] = 0;
	SensorValue[REncoder] = 0;
	if(direction > 0)
	{
		while(direction * SensorValue[REncoder] < distance)
		{
			base(direction * speed,-10);
		}
	}
	else
	{
		while(direction * SensorValue[LEncoder] < distance)
		{
			base(-10,-direction * speed);
		}
	}

	base(0,0);
	wait1Msec(wait);
}

//---Forwards/Backwards---//:Moves the base forward and backward using IME's.
void fwds(int distance, int speed, int wait)
{
	clearTimer(T2);
	SensorValue[LEncoder] = 0;
	while(abs(SensorValue[LEncoder]) < distance && time1[T2] < 3000)
	{
		base(speed,speed);
	}
	base(0,0);
	wait1Msec(wait);
}

void bwds(int distance, int speed, int wait)
{
	fwds(distance, -speed, wait);
}

//---Claw--//:Switches the claw from closed to open or open to closed.
void lclaw(int wait)
{
	SensorValue[Claw2] = !SensorValue[Claw2];
	wait1Msec(wait);
}
void rclaw(int wait)
{
	SensorValue[Claw1] = !SensorValue[Claw1];
	wait1Msec(wait);
}
void claw(int wait)
{
	lclaw(0);
	rclaw(0);
	wait1Msec(wait);
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
