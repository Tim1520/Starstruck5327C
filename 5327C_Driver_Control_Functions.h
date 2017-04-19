//********************************************************************************************************//
//****************************************DRIVER_CONTROL_FUNCTIONS****************************************//
//********************************************************************************************************//

//---BASE---//:True speed for drive function.
const unsigned int TrueSpeed[128] =
{
	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	0, 21, 21, 21, 22, 22, 22, 23, 24, 24,
	25, 25, 25, 25, 26, 27, 27, 28, 28, 28,
	28, 29, 30, 30, 30, 31, 31, 32, 32, 32,
	33, 33, 34, 34, 35, 35, 35, 36, 36, 37,
	37, 37, 37, 38, 38, 39, 39, 39, 40, 40,
	41, 41, 42, 42, 43, 44, 44, 45, 45, 46,
	46, 47, 47, 48, 48, 49, 50, 50, 51, 52,
	52, 53, 54, 55, 56, 57, 57, 58, 59, 60,
	61, 62, 63, 64, 65, 66, 67, 67, 68, 70,
	71, 72, 72, 73, 74, 76, 77, 78, 79, 79,
	80, 81, 83, 84, 84, 86, 86, 87, 87, 88,
	88, 89, 89, 90, 90,127,127,127
};

#define LEFT 1
#define RIGHT -1

bool down = false;
bool hold = false;
bool stp = false;
bool stp2 = false;
bool limit = false;

//---BASE---//:Powers motors to true speed values for acurate control.
void drive(int leftSpeed , int rightSpeed , int go, int test)
{
	if(!go && !test)
	{
		if(leftSpeed > 0)
		{
			motor[LFBase] = TrueSpeed[leftSpeed];
			motor[LBBase] = TrueSpeed[leftSpeed];
		}
		else if(leftSpeed < 0)
		{
			motor[LFBase] = -TrueSpeed[-leftSpeed];
			motor[LBBase] = -TrueSpeed[-leftSpeed];
		}
		if(rightSpeed > 0)
		{
			motor[RFBase] = TrueSpeed[rightSpeed];
			motor[RBBase] = TrueSpeed[rightSpeed];
		}
		else if(rightSpeed < 0)
		{
			motor[RFBase] = -TrueSpeed[-rightSpeed];
			motor[RBBase] = -TrueSpeed[-rightSpeed];
		}
	}
	else if(test)
	{
		motor[LFBase] = 127;
		motor[LBBase] = 127;
		motor[RFBase] = 127;
		motor[RBBase] = 127;
	}
	else
	{
		motor[LFBase] = -127;
		motor[LBBase] = -127;
		motor[RFBase] = -127;
		motor[RBBase] = -127;
	}
}

//---LAUNCHER---//:Powers arm at 127 speed multipied by input.
void armState(float state)
{
	motor[LArm1] = (state * 127);
	motor[LArm2] = (state * 127);
	motor[RArm1] = (state * 127);
	motor[RArm2] = (state * 127);
}

//---Arm---//:Power arm motors in direction desired by user.
void arm(bool up , bool drop , bool slow , float joystick, float hspeed , float sspeed)
{
	if(!stp)
	{
		if(drop && up)
		{
			armState(hspeed);
			hold = true;
		}
		else if(slow)
		{
			armState(sspeed);
			hold = false;
		}
		else if(up)
		{
			armState(up);
			down = false;
			hold = false;
		}
		else if(drop)
		{
			armState(-down);
			down = true;
			hold = false;
		}
		else if(abs(joystick) > 20)
		{
			armState(joystick/127);
			hold = false;
		}
		else
		{
			hold = false;
			if(SensorValue[armPot] < 400 && down)
				armState(-0.2);
			else
				armState(0);
		}
	}
}

//---ClAW---//:Open or Close both claw arms at the same time.
void clawControl(bool open, bool close)
{
	if(SensorValue[clawPot] > 3545)
	{
		limit = true;
	}
	else
	{
		limit = false;
	}
	if(!stp2)
	{
		if(open)
		{
			motor[clw] = 127;
			clearTimer(T2);
		}
		else if(close && !limit)
		{
			motor[clw] = -127;
			clearTimer(T3);
		}
		else if(SensorValue[armPot] > 1400 && SensorValue[clawPot] > 2900 && !hold)
		{
			motor[clw] = 127;
			clearTimer(T2);
		}
		else if(time1[T2] > 500 && !limit)
		{
			motor[clw] = -20;
		}
		else if(time1[T2] > 20)
		{
			if(time1[T3] < 100)
			{
				motor[clw] = 10;
			}
			else
			{
				clearTimer(T2);
				motor[clw] = 5;
			}
		}
		else
		{
			motor[clw] = 5;
			clearTimer(T2);
		}
	}
}
int count = 0;
//Winch
void lastShot(int hit, int back)
{
	if(!stp2)
	{
		motor[winch] = 127 * (hit - back);
		count = 0;
	}
}

task ls()
{
	count = 1;
	hold = false;
	stp2 = true;
	motor[clw] = -40;
	while(SensorValue[armPot] < 2480)
	{
		if(SensorValue[winchPot] < 2830)
		{
			stp2 = true;
			motor[winch] = 127;
		}
		else
		{
			motor[winch] = 0;
		}
		if(SensorValue[armPot] > 1400 && SensorValue[clawPot] > 2900)
		{
			motor[clw] = 127;
		}
		if(SensorValue[armPot] > 410)
		{
			stp = true;
			armState(1);
		}
	}
	armState(0);
	stp2 = false;
	stp = false;
	while(true)
	{
		if(vexRT[Btn8U])
		{
			hold = false;
			stp2 = true;
			motor[clw] = -40;
			motor[winch] = 127;
		}
		else
		{
			motor[winch] = 0;
		}
		if(SensorValue[armPot] > 1400 && SensorValue[clawPot] > 2900)
		{
			motor[clw] = 127;
			stp2 = false;
		}
	}
}
/*
task ls2()
{
count = 2;
hold = false;
clearTimer(T1);
while(SensorValue[armPot] < 2480)
{
if(time1[T1] < 1000)
{
stp2 = true;
motor[winch] = 127;
}
else
{
motor[winch] = 0;
}
if(SensorValue[armPot] > 1800 && SensorValue[clawPot] > 2900)
{
motor[clw] = 127;
}
if(SensorValue[armPot] > 410)
{
stp = true;
armState(1);
}
}
armState(0);
stp = false;
stp2 = false;
}
*/
//:Kill Switch for autonomous testing
task killSwitch()
{
	while(true)
	{
		if(vexRT[Btn7R] == 1)
		{
			stopAllTasks();
		}
	}
}
