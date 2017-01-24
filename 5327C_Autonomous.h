//********************************************************************************************************//
//*******************************************AUTONOMOUS***************************************************//
//********************************************************************************************************//
void auton8000L()
{
	setup();

	fwds(7200,100,300);
	claw(200);
	pArm(960,0.12,0);
	bwds(2200,100,0);
	swingB(130,80,RIGHT,0,0);
	bwds(500,100,0);
	swingB(130,80,RIGHT,0,0);
	bwds(1500,100,0);
	swingB(4200,80,RIGHT,0,0);
	bwds(3300,100,100);
	//*/
	wait1Msec(1000);
}

void autonDVL()
{
	setup();

	bwds(2000,100,100);
	turn(1200,80,RIGHT,10,100);
	startTask(knock);
	bwds(3600,100,4000);
	swing(3900,80,LEFT,10,100);
	fwds(3000,100,300);
	//*/
	wait1Msec(1000);
}
void skills()
{
	setup();

	fwds(7000,100,300);
	claw(200);
	pArm(920,0.12,0);
	turn(400,70,RIGHT,10,100);
	bwds(7100,100,100);
	turn(2500,80,RIGHT,10,100);
	startTask(launch);
	bwds(4200,100,2000);

	swing(3200,80,LEFT,10,100);
	fwds(3000,100,300);
	claw(200);
	pArm(960,0.12,100);
	bwds(3000,100,100);
	turn(1900,80,RIGHT,10,100);
	startTask(launch);
	bwds(2200,100,2400);
	stopTask(launch);

	for(int i = 0; i < 3; i++)
	{
	pArm(1600,0.12,0);
	fwds(5000,100,0);
	fwds(3000,70,600);
	claw(200);
	bwds(6000,100,0);
	startTask(launch);
	bwds(2000,100,2400);
	stopTask(launch);
	}

	pArm(1600,0.12,0);
	fwds(5000,100,0);
	fwds(3000,70,300);
	bwds(3200,100,300);
	turn(2400,80,LEFT,10,200);
	fwds(11000,127,0);
	fwds(3000,70,300);
	bwds(3000,100,100);
	turn(2400,80,RIGHT,10,200);
	bwds(2000,70,200);
	pArm(690,0,100);
	fwdsT(1100,100,200);
	claw(400);
	bwds(3000,100,0);
	startTask(launch);
	bwds(2600,100,2400);
	//*/
	wait1Msec(4000);
}
void auton8000R()
{
	setup();

	fwds(7000,100,300);
	claw(200);
	pArm(920,0.12,0);
	turn(750,70,LEFT,10,100);
	bwds(5800,100,100);
	turn(1960,80,LEFT,10,100);
	startTask(launch);
	bwds(4200,100,2000);

	swing(3200,80,RIGHT,10,100);
	fwds(3000,100,300);
	claw(200);
	pArm(960,0.12,100);
	bwds(3000,100,100);
	turn(2000,80,LEFT,10,100);
	startTask(launch);
	bwds(2200,100,2400);
	//*/
	wait1Msec(4000);
}
