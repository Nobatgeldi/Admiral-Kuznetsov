class CfgWeapons
{
	class LauncherCore;	// External class reference

	class MissileLauncher : LauncherCore {};

	class 9M311Laucher;
	class AT5Launcher;

	class Granit_rail : 9M311Laucher
	{
		magazines[] = {"Granit_rail"};
		displayName = "$STR_ULYANOVSK_PKRK";
		nameSound = "aalauncher";
		reloadTime = 0.2;
		magazineReloadTime = 30;
		minRange = 20;
		minRangeProbab = 0.1;
		midRange = 3000;
		midRangeProbab = 0.7;
		maxRange = 6000;
		maxRangeProbab = 0.2;
		aiRateOfFire = 4;	// delay between shots at given distance
		aiRateOfFireDistance = 5000;
		//autoFire = true;
	};
	class CannonCore;	// External class reference
	class AZP85;	// External class reference
	class ak630_Gun: CannonCore
	{
		scope = public;
		displayName="$STR_ULYANOVSK_AK630";
		ammo=ak630_Bullet;
		flashSize=0.001;
		initSpeed=2000;
		maxLeadSpeed=1800;
		modes[] ={normal,tracer};
		magazines[] = {ak630_Gun};
		class normal
		{
			begin1[] = {"ulyanovsk\mg51.wav", 1.77828, 1, 1000};
			begin2[] = {"ulyanovsk\mg51.wav", 1.77828, 1, 1000};
			soundBegin[] = {"begin1", 0.5, "begin2", 0.5};
			recoilprone = "Empty";
			multiplier=1;
			burst=1;
			autofire=true;
			dispersion=0.02;
			ammo = ak630_Bullet;
			reloadTime=0.1;
			displayName="AK630";
			ffCount=300;
			sound[]={"weapons\m2-50-loop",db20,1};
			soundContinuous=false;
			showtoplayer = true;
			soundBurst = 0;
			recoil = Empty;
			aiRateOfFire=0.05;
			aiRateOfFireDistance=2000;
			useAction=false;
			useActionTitle="";
			minRange=1;minRangeProbab=0.10;
			midRange=1400;midRangeProbab=0.58;
			maxRange=3000;maxRangeProbab=0.04;
			maxLeadSpeed = 2000;
			artilleryDispersion = 0;
			artilleryCharge = 0;
			textureType="";
			soundBeginWater[]={}; // all three sounds have roughly the same probablity
			soundClosure[]={};
 			weaponSoundEffect  = "DefaultRifle";
		};
		class tracer
		{
			begin1[] = {"ulyanovsk\mg51.wav", 1.77828, 1, 1000};
			begin2[] = {"ulyanovsk\mg51.wav", 1.77828, 1, 1000};
			soundBurst = 0;
			soundBegin[] = {"begin1", 0.5, "begin2", 0.5};
			recoilprone = "Empty";
			multiplier =1;
			burst=1;
			autofire=true;
			showtoplayer = true;
			dispersion=0.02;
			ammo = ak630_BulletTracer;
			reloadTime=0.1;
			displayName="AK630 tracer";
			ffCount=300;
			sound[]={"weapons\m2-50-loop",db20,1};
			soundContinuous=false;
			recoil = Empty;
			aiRateOfFire=0.05;
			aiRateOfFireDistance=2000;
			useAction=false;
			useActionTitle="";
			minRange=1;minRangeProbab=0.10;
			midRange=1400;midRangeProbab=0.58;
			maxRange=3000;maxRangeProbab=0.04;
			maxLeadSpeed = 2000;
			artilleryDispersion = 0;
			artilleryCharge = 0;
			textureType="";
			soundBeginWater[]={}; // all three sounds have roughly the same probablity
			soundClosure[]={};
 			weaponSoundEffect  = "DefaultRifle";
		};
	};
};