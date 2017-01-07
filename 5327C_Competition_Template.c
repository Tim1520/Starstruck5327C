#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    liftPot,        sensorPotentiometer)
#pragma config(Sensor, in2,    gyro,           sensorGyro)
#pragma config(Sensor, in3,    armPot,         sensorPotentiometer)
#pragma config(Sensor, in4,    xAccel,         sensorAccelerometer)
#pragma config(Sensor, dgtl2,  Claw2,          sensorDigitalOut)
#pragma config(Sensor, dgtl3,  Transmission,   sensorDigitalOut)
#pragma config(Sensor, dgtl4,  limit,          sensorTouch)
#pragma config(Sensor, dgtl12, Claw1,          sensorDigitalOut)
#pragma config(Sensor, I2C_1,  baseIME,        sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port2,           RArm,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           RLift,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           LFBase,        tmotorVex393TurboSpeed_MC29, openLoop)
#pragma config(Motor,  port5,           RFBase,        tmotorVex393TurboSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           LBBase,        tmotorVex393TurboSpeed_MC29, openLoop, encoderPort, I2C_1)
#pragma config(Motor,  port7,           RBBase,        tmotorVex393TurboSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           LLift,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           LArm,          tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//VRC Specific pragmas below
#pragma platform(VEX)
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)
#include "Vex_Competition_Includes.c"
//VRC Specific pragmas above

#include "5327C_Driver_Control_Functions.h"
#include "5327C_Autonomous_Functions.h"
#include "5327C_Super_Functions.h"
#include "5327C_Autonomous.h"

//--------------------------------------------------------------------------------------------------------//
//-----------------------------------------------PRE_AUTON------------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
void pre_auton(){}

//--------------------------------------------------------------------------------------------------------//
//-----------------------------------------------AUTONOMOUS-----------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
task autonomous
{
	//autonLeftAlt();
	autonLeft();
	//autonRightAlt();
	//autonRight();
	//skills();
}

//--------------------------------------------------------------------------------------------------------//
//----------------------------------------------USERCONTROL-----------------------------------------------//
//--------------------------------------------------------------------------------------------------------//
task usercontrol()
{
	while(true)
	{
		drive(vexRT[Ch3] , vexRT[Ch2] , vexRT[Btn8U]);
		clawControl(vexRT[Btn5U] || vexRT[Btn5UXmtr2]);
		lift((vexRT[Btn7L] || vexRT[Btn7LXmtr2]) - (vexRT[Btn7U] || vexRT[Btn7UXmtr2]), vexRT[Ch3Xmtr2], vexRT[Btn7DXmtr2], vexRT[Btn8DXmtr2], 127, 2300, 20);
		baseToLift(vexRT[Btn8U] || vexRT[Btn8UXmtr2]);
		hang(vexRT[Btn8R] || vexRT[Btn8RXmtr2], 127);
		arm(vexRT[Btn6U] || vexRT[Btn6UXmtr2], vexRT[Btn6D] || vexRT[Btn6DXmtr2], 0.07);
		if(vexRT[Btn8D] == 1)
		{
			startTask(killSwitch);
			autonLeft();
		}
	}
}
//...THE_END...//
