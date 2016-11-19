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
void turn(int angle, int speed, int direction, int wait)
{
	int gError = SensorValue[gyro];
	while(direction * (SensorValue[gyro] - gError) < angle)
	{
		base((direction * speed) , (-direction * speed));
	}
	base(0,0);
	wait1Msec(wait);
}

//---Swing---//:Turns using only one side of the base.
void swing(int angle, int speed, int direction, int wait)
{
	int gError = SensorValue[gyro];
	if(direction > 0)
	{
		while(direction * (SensorValue[gyro] - gError) < angle)
		{
			base(direction * speed,-10);
		}
	}
	else
	{
		while(direction * (SensorValue[gyro] - gError)< angle)
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
	nMotorEncoder[LBBase] = 0;
	while(abs(nMotorEncoder[LBBase]) < distance && time1[T2] < 3000)
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

//---Lift---//:Raises the lift to desired height.
void knockknock(int height , int speed)
{
	int direction = 1;
	if(SensorValue[liftPot] > height)
	{
		direction = -1;
	}
	while(((height - SensorValue[liftPot]) * direction) > 0)
	{
		lift(direction,0,0,0,speed,4000,20);
	}
	lift(0,0,0,0,0,4000,20);
}

//---Move---//:Moves the base using the accelerometer.
int integral(int integrand)
{
	return integrand + (integrand * time1[T1]);
}

void movea(int direction , int distance , int speed)
{
	clearTimer(T1);
	int velocity = 0;
	int displacement = 0;
	while(abs(displacement) < distance)
	{
		velocity = integral(SensorValue[xAccel]);
		displacement = integral(velocity);
		base((direction * speed) , (direction * speed));
	}
	base(0,0);
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
int launchHeight = 3500;
int launchFinal = 3600;
int launchRest = 1250;
void launch(int wait)
{
	while(SensorValue[armPot] < launchHeight)
	{
		armState(1);
	}
	claw(0);
	while(SensorValue[armPot] < launchFinal)
	{
		armState(1);
	}
	arm(0,0,0);
	wait1Msec(300);
	while(SensorValue[armPot] > launchRest)
	{
		armState(-1);
	}
	armState(0);
	wait1Msec(wait);
}
