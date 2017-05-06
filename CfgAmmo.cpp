class CfgAmmo
{
	class M_R73_AA;

	class Granit : M_R73_AA
	{
		model="\ulyanovsk\Granit.p3d";
		proxyshape="\ulyanovsk\Granit.p3d";
		hit = 500;
		indirectHit = 70;
		indirectHitRange = 21;
		maneuvrability = 99;
		sideAirFriction = 1;
		simulationStep = 0.002;
		trackOversteer = 30;
		trackLead = 0.6;
		airLock = true;
		irLock = true;
		cost = 50000;
		maxSpeed = 2500;	// max speed on level road, km/h
		initTime = 0;
		thrustTime = 55;
		thrust = 285;
		fuseDistance = 300;
		maxControlRange = 10000;	// max range for manual control, 0 = no control (passive weapon)
		timeToLive = 65;
		whistleDist = 42;
		visibleFireTime = 5000;	// how long is it visible
		CraterEffects = "MissileCrater";
		explosionEffects = "ExplosionEffects";
	};
	class BulletBase;	// External class reference
	class ak630_Bullet: BulletBase
	{
		airLock = true;
		irLock = true;
		hit=137;
		indirectHit=10;
		explosive=1;
		tracerColor[] ={0,0,0,0};
		tracerColorR[] = {0,0,0,0};
	};
	class ak630_BulletTracer: ak630_Bullet
	{
		tracerColor[] ={0,1,0,.5};
		tracerColorR[] = {0,1,0,.5};
	};
};