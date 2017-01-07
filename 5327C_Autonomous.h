//********************************************************************************************************//
//*******************************************AUTONOMOUS***************************************************//
//********************************************************************************************************//
void autonLeftAlt()
{//test
	gyroSetupAlt(900,127);

	//*Reverse to knock off fence.
	turn(230,80,LEFT,100);
	bwds(300,100,100);
	turn(230,90,RIGHT,100);
	bwds(140,100,300);

	fwds(130,100,200);
	lift(1,0,0,0,20,4000,0);
	turn(96,80,RIGHT,200);
	claw(100);
	pArm(1250,0.07,100);
	fwds(280,100,200);
	lift(0,0,0,0,0,4000,0);
	claw(300);
	pArm(1400,0.07,100);

	bwds(200,100,200);
	turn(96,80,LEFT,200);
	bwds(200,100,0);
	launch(100);

	//*/
	wait1Msec(1000);
}

void autonLeft()
{
	gyroSetup(900,127);

	//*Reverse to knock off fence.
	turn(210,80,LEFT,100);
	bwds(345,100,100);
	turn(150,90,RIGHT,100);
	bwds(140,100,300);

	fwds(130,100,50);
	swing(840,90,LEFT,50);
	fwds(860,80,100);
	claw(100);
	pArm(1700,0.07,0);

	turn(780,80,RIGHT,0);
	base(50,-50);
	wait1Msec(200);
	base(0,0);
	knockknock(1100,100);
	bwdsLaunch(250,100,0);

	turn(20,80,RIGHT,100);
	fwds(350,100,200);
	claw(400);
	pArm(1400,0.07,0);
	lift(1,0,0,0,20,4000,0);
	bwds(100,100,0);
	bwdsLaunch(400,100,0);

	//*/
	wait1Msec(1000);
}

void autonRightAlt()
{
	gyroSetupAlt(900,127);

	//*Reverse to knock off fence.
	turn(190,80,RIGHT,100);
	bwds(250,100,100);
	turn(210,90,LEFT,100);
	bwds(140,100,300);

	fwds(130,100,200);
	lift(1,0,0,0,20,4000,0);
	turn(70,80,LEFT,200);
	claw(100);
	pArm(1250,0.07,100);
	fwds(280,100,200);
	lift(0,0,0,0,0,4000,0);
	claw(300);
	pArm(1400,0.07,100);

	bwds(200,100,200);
	turn(96,80,RIGHT,200);
	bwds(200,100,0);
	launch(100);

	//*/
	wait1Msec(1000);
}

void autonRight()
{
	gyroSetup(900,127);

	//*Reverse to knock off fence.
	turn(210,80,RIGHT,100);
	bwds(345,100,100);
	turn(130,90,LEFT,100);
	bwds(140,100,300);

	fwds(130,100,50);
	swing(840,90,RIGHT,50);
	fwds(1100,80,100);
	claw(100);
	pArm(1700,0.07,0);

	turn(750,80,LEFT,0);
	base(-50,50);
	wait1Msec(200);
	base(0,0);
	knockknock(1100,100);
	bwdsLaunch(250,100,0);

	turn(27,80,LEFT,100);
	fwds(320,100,200);
	claw(400);
	pArm(1400,0.07,0);
	lift(1,0,0,0,20,4000,0);
	bwds(100,100,0);
	bwdsLaunch(400,100,0);

	//*/
	wait1Msec(1000);
}

void skills()
{
	gyroSetup(900,127);

	//*Reverse to knock off fence.
	turn(200,80,LEFT,100);
	bwds(330,100,100);
	turn(190,90,RIGHT,100);
	bwds(270,100,300);

	fwds(130,100,200);
	lift(1,0,0,0,20,4000,0);
	turn(96,80,RIGHT,200);
	claw(100);
	pArm(1250,0.07,100);
	fwds(280,100,200);
	lift(0,0,0,0,0,4000,0);
	claw(300);
	pArm(1400,0.07,100);

	bwds(200,100,200);
	turn(96,80,LEFT,200);
	bwds(200,100,0);
	launch(100);

	fwds(200,100,50);
	swing(880,90,LEFT,50);
	fwds(800,80,30);
	claw(0);
	pArm(1250,0.07,100);
	turn(890,80,RIGHT,0);
	knockknock(1300,100);
	bwds(250,100,100);
	launch(0);

}
