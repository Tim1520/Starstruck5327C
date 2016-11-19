//********************************************************************************************************//
//*******************************************AUTONOMOUS***************************************************//
//********************************************************************************************************//
void autonCloseRedAlt()
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

	//*/
	wait1Msec(1000);
}

void autonCloseRed()
{
	gyroSetup(900,127);

	//*Reverse to knock off fence.
	turn(200,80,LEFT,100);
	bwds(330,100,100);
	turn(190,90,RIGHT,100);
	bwds(270,100,300);

	fwds(200,100,50);
	swing(870,90,LEFT,50);
	pArm(1250,0.07,0);
	claw(0);
	fwds(800,80,100);
	claw(100);
	pArm(1400,0.07,0);


	turn(880,80,RIGHT,0);
	knockknock(1300,100);
	bwdsLaunch(250,100,0);

	turn(20,80,RIGHT,100);
	fwds(300,100,100);
	claw(400);
	pArm(2000,0.07,0);
	turn(20,80,LEFT,0);
	lift(1,0,0,0,20,4000,0);
	bwdsLaunch(300,100,0);

	//*/
	wait1Msec(1000);
}

void autonFarRed()
{
	gyroSetup(900,127);

	//*Reverse to knock off fence.
	turn(245,80,RIGHT,100);
	bwds(550,100,100);
	turn(170,90,LEFT,100);
	bwds(510,100,300);

	//*Turn and grab the cube.
	fwds(310,90,50);
	swing(810,90,RIGHT,50);
	lift(1,0,0,0,20,4000,20);
	fwds(1400,80,30);
	claw(0);
	lift(0,0,0,0,0,4000,20);

  //Turn, launch, and knock off fence.
	turn(870,90,LEFT,0);
	claw(0);
	//launchLiftBwds(1300,100,450,100,300);

	//*Grab 2 more stars and launch.
	turn(30,90,LEFT,20);
	fwds(910,90,300);
	claw(200);
	bwds(280,100,300);
	claw(500);
	//launch(1);
	//*/
	wait1Msec(1000);
}

void autonCloseBlue()
{
	gyroSetup(900,127);

	//*Reverse to knock off fence.
	turn(200,80,LEFT,100);
	bwds(550,100,100);
	turn(190,90,RIGHT,100);
	bwds(500,100,300);

	//*Turn and grab the cube.
	fwds(310,90,50);
	swing(850,90,LEFT,50);
	lift(1,0,0,0,20,4000,0);
	fwds(1300,80,30);
	claw(0);
	lift(0,0,0,0,0,4000,0);

	//*Turn, launch, and knock off fence.
	turn(870,90,RIGHT,0);
	claw(0);
	//launchLiftBwds(1300,100,470,100,300);

	//*Grab 2 more stars and launch.
	turn(30,90,RIGHT,20);
	fwds(910,90,300);
	claw(200);
	bwds(280,100,300);
	claw(500);
	//launch(1);

	//*/
	wait1Msec(1000);
}

void autonFarBlue()
{
	gyroSetup(900,127);

	//*Reverse to knock off fence.
	turn(200,80,LEFT,100);
	bwds(550,100,100);
	turn(190,90,RIGHT,100);
	bwds(500,100,300);

	//*Turn and grab the cube.
	fwds(310,90,50);
	swing(850,90,LEFT,50);
	lift(1,0,0,0,20,4000,0);
	fwds(1300,80,30);
	claw(0);
	lift(0,0,0,0,0,4000,0);

	//*Turn, launch, and knock off fence.
	turn(870,90,RIGHT,0);
	claw(0);
	//launchLiftBwds(1300,100,470,100,300);

	//*Grab 2 more stars and launch.
	turn(30,90,RIGHT,20);
	fwds(910,90,300);
	claw(200);
	bwds(280,100,300);
	claw(500);
	//launch(1);

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
