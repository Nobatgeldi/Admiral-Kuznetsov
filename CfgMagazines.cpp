class CfgMagazines
{
	class Default;	// External class reference

	class CA_Magazine : Default {};

	class VehicleMagazine : CA_Magazine {};
	class 8Rnd_9M311;
	class 5Rnd_AT5_BRDM2;

	class Granit_rail : 8Rnd_9M311
	{
		displayName = "$STR_ULYANOVSK_PKRK";
		ammo = "Granit";
		count = 256;
		initSpeed = 300;
		maxLeadSpeed = 1000;	// max estimated speed km/h
	};
	class 2000Rnd_23mm_AZP85;	// External class reference
	class ak630_Gun: VehicleMagazine
	{
		scope = public;
		displayName="$STR_ULYANOVSK_AK630";
		ammo="ak630_Bullet";
		count=10000;
		flashSize=0.001;
		initSpeed=2000;
		maxLeadSpeed=1800;
		modes[] ={normal,tracer};
		class normal
		{
			multiplier=1;
			burst=1;
			soundBurst = 0;
			autofire=true;
			dispersion=0.02;
			ammo = ak630_Bullet;
			reloadTime=0.1;
			displayName="AK630";
			ffCount=3000;
			sound[]={"\ulyanovsk\Ak_630.wav",db+1,1};
			soundContinuous=false;
			recoil = Empty;
			aiRateOfFire=0.05;
			aiRateOfFireDistance=2000;
			useAction=false;
			useActionTitle="";
		};
		class tracer
		{
			multiplier =1;
			burst=1;
			soundBurst = 0;
			autofire=true;
			dispersion=0.02;
			ammo = ak630_BulletTracer;
			reloadTime=0.1;
			displayName="AK630 tracer";
			ffCount=3000;
			sound[]={"\ulyanovsk\Ak_630expl.wav",db+1,1};
			soundContinuous=false;
			recoil = Empty;
			aiRateOfFire=0.05;
			aiRateOfFireDistance=2000;
			useAction=false;
			useActionTitle="";
		};
	};
};