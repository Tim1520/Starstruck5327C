//********************************************************************************************************//
//*******************************************AUTONOMOUS***************************************************//
//********************************************************************************************************//
void takeTheL()
{
	startTask(open);
	armState(1);
	wait1Msec(100);
	armState(-1);
	wait1Msec(50);
	armState(0);
	pClaw(1600,5,0);
	startTask(lift);
	wait1Msec(100);
	fwds(3000,100,0,0);
	fwds(2300,50,10,500);

	startTask(sClose);
	bwds(1200,100,10,200);
	turn(1270,90,RIGHT,10,0);
	pArm(360,-0.2,100);
	fwds(1500,100,5,100);
	tClaw(700,127,15,100);
	pArm(700,-0.08,100);
	turn(800,90,RIGHT,10,0);
	bwdsT(200,100,0);
	startTask(launch);
	bwdsT(200,100,2400);

	fwds(2700,70,10,100);
	tClaw(800,127,30,100);
	pArm(700,0.1,0);
	bwdsT(300,100,0);
	startTask(lastLaunch);
	bwdsT(200,100,2400);

	wait1Msec(3000);
}

void fastL()
{
	startTask(open);
	armState(1);
	wait1Msec(100);
	armState(-1);
	wait1Msec(150);
	armState(-0.2);
	fwds(3000,127,10,0);
	tClaw(1200,127,15,0);
	pArm(700,-0.08,100);
	turn(1200,127,RIGHT,10,100);
	startTask(lastLaunch);
	bwdsT(500,127,0);

	wait1Msec(3000);
}

void hoardL()
{
	armState(1);
	wait1Msec(100);
	armState(-1);
	wait1Msec(50);
	armState(0);
	pClaw(1000,0,0);
	startTask(hLift);
	startTask(hClaw);
	bwds(5200,50,0,200);

	tClaw(1200,-127,0,100);
	fwds(2400,50,10,100);
	startTask(sClose);

	turn(750,90,LEFT,10,0);
	pArm(340,-0.22,200);
	fwds(1200,100,5,100);
	tClaw(1000,127,15,100);
	pArm(870,-0.08,100);
	turn(1000,90,LEFT,10,0);

	wait1Msec(3000);
}

void takeTheR()
{
	startTask(open);
	armState(1);
	wait1Msec(100);
	armState(-1);
	wait1Msec(50);
	armState(0);
	pClaw(1600,5,0);
	startTask(lift);
	wait1Msec(100);
	fwds(3000,100,0,0);
	fwds(2300,50,10,500);

	startTask(sClose);
	bwds(1200,100,10,200);
	turn(1270,90,LEFT,10,0);
	pArm(360,-0.2,100);
	fwds(1500,100,5,100);
	tClaw(700,127,15,100);
	pArm(700,-0.08,100);
	turn(1000,90,LEFT,10,0);
	bwdsT(200,100,0);
	startTask(launch);
	bwdsT(200,100,2400);

	fwds(2700,70,10,100);
	tClaw(800,127,30,100);
	pArm(700,0.1,0);
	bwdsT(300,100,0);
	startTask(lastLaunch);
	bwdsT(200,100,2400);

	wait1Msec(3000);
}
