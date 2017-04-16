//********************************************************************************************************//
//*******************************************AUTONOMOUS***************************************************//
//********************************************************************************************************//
void takeTheL()
{
	armState(1);
	wait1Msec(100);
	armState(-1);
	wait1Msec(50);
	armState(0);
	pClaw(1600,-10,0);
	startTask(lift);
	wait1Msec(100);
	fwds(3000,100,0,0);
	fwds(1700,50,10,500);

	startTask(sClose);
	bwds(860,100,10,200);
	turn(1200,90,RIGHT,10,0);
	pArm(390,-0.18,100);
	fwds(1200,100,5,100);
	tClaw(700,127,15,100);
	pArm(700,0.08,100);
	turn(800,90,RIGHT,10,0);
	bwdsT(200,100,0);
	startTask(launch);
	bwdsT(200,100,2400);

	pClaw(1700,-5,0);
	fwds(3000,70,10,100);
	tClaw(800,127,15,100);
	pArm(700,0.1,0);
	bwdsT(300,100,0);
	startTask(lastLaunch);
	bwdsT(200,100,2400);

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
	startTask(hoard);
	bwds(5200,20,0,500);

	wait1Msec(3000);
}
