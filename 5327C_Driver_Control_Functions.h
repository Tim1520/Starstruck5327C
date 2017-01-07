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

//---BASE---//:Powers motors to true speed values for acurate control.
bool hanging = false;
void drive(int leftSpeed , int rightSpeed , int go)
{
	if(!go && !hanging)
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
}

//---LAUNCHER---//:Powers arm at 127 speed multipied by input.
void armState(float state)
{
	motor[LArm1] = (state * -127);
	motor[LArm2] = (state * -127);
	motor[RArm1] = (state * -127);
	motor[RArm2] = (state * -127);
}

//---Arm---//:Power arm motors in direction desired by user.
void arm(bool drop , bool up , float hspeed)
{
	if(!hanging)
	{
	if(drop && up)
	{
		armState(hspeed);
	}
	else
	{
		armState(drop - up);
	}
}
}

//---ClAW---//:Open or Close both claw arms at the same time.
int buttonToggleState1 = 1;
int buttonPressed1 = 0;

void clawControl(bool toggle)
{
	if(toggle)
	{
		if(!buttonPressed1)
		{
			buttonToggleState1 = 1 - buttonToggleState1;
			buttonPressed1 = 1;
		}
	}
	else
	{
		buttonPressed1 = 0;
	}
	if(buttonToggleState1)
	{
		SensorValue[Claw1] = 0;
		SensorValue[Claw2] = 0;
	}
	else
	{
		SensorValue[Claw1] = 1;
		SensorValue[Claw2] = 1;
	}
}

task autoRelease()
{
	if(SensorValue[release] == 1)
	{
		buttonToggleState1 = 0;
	}
}

int buttonToggleState2 = 1;
int buttonPressed2 = 0;

void liftLock(bool toggle)
{
	if(toggle)
	{
		if(!buttonPressed2)
		{
			buttonToggleState2 = 1 - buttonToggleState2;
			buttonPressed2 = 1;
		}
	}
	else
	{
		buttonPressed2 = 0;
	}
	if(buttonToggleState2)
	{
		SensorValue[Lock] = 0;
	}
	else
	{
		SensorValue[Lock] = 1;
	}
}

//:Kill Switch for autonomous testing
task killSwitch()
{
	while(true)
	{
		if(vexRT[Btn7D] == 1)
		{
			stopAllTasks();
		}
	}
}
