#define TEast 0
#define TWest 1
#define TGuerrila 2
#define TCivilian 3
#define TSideUnknown 4
#define TEnemy 5
#define TFriendly 6
#define TLogic 7

#define true 1
#define false 0

#define private 0
#define protected 1
#define public 2

class CfgPatches
{
	class ulyanovsk
	{
		units[] =
		{
			"ulyanovsk"
		};
		weapons[] = {};
		requiredVersion = 0.0.1;
		requiredAddons[] = {};
	};
};

class MissileCrater;
class CfgNonAIVehicles
{
	class ProxyFlag;	// External class reference

	class ProxyFlag_vmf : ProxyFlag
	{
		model = "\ulyanovsk\models\flag_vmf";
	};

	class ProxyWeapon;
	class ProxyGranit : ProxyWeapon
	{
		model ="\ulyanovsk\models\Granit";
		simulation ="maverickweapon";
	};
};

class CfgVehicles
{
	class All{};
	class AllVehicles:All{};

	class Air: AllVehicles {};
	class Plane: Air
	{
		class HitPoints;
		class AnimationSources;
		class NewTurret;
		class ViewPilot;
    };

	class Land : AllVehicles {};
	class Ship: AllVehicles{};
	class BigShip: Ship
	{
		class HitPoints;
		class AnimationSources;
		class NewTurret;
		class ViewPilot;
		class ViewOptics ;
		class Turrets
		{
			//class MainTurret;
		};
	};

	class LandVehicle : Land
	{
		class NewTurret ;
		class ViewOptics ;
	};
	class Tank : LandVehicle
	{
		class HitPoints ;
		class Turrets
			{
				class MainTurret ;
			};
		class ViewOptics : ViewOptics{};
	};
	class ulyanovsk: BigShip
	{
		vehicleClass="Ship";
		faction = "OPF_F";
		scope = 2;
		displayName = "Ulyanovsk";
		picture = "\ulyanovsk\icons\picture.paa";
		icon = "\ulyanovsk\icons\icon.paa";
		model = "\ulyanovsk\models\ulyanovsk.p3d";
		soundEngine[]={"\ulyanovsk\sound\Underway.wav",4,1.2};
		soundEnviron[]={"Objects\noise",db-60,1.0};			// Cessna
		side = 0;
		maxSpeed = 60;
		maneuvrability=30.0;
		wheelSteeringSensitivity = 12.5;
		driverAction="driver_mid01";
		gunnerAction="mbt2_slot2b_in";
		commanderAction="driver_mid01";
		cargoAction[]=
		{
		  "O_crew_F"
		};
		mapSize = 250;
		extCameraPosition[]={0,37,-230};		// 0,5,-30 is standard Air class
		canFloat = 1;
		fuelCapacity = 200000;
		cost = 2000000;
		simulation="ship";
		accuracy = 0.9;
		irScanRange = 5000;
	    irTarget = true ;
	    irScanGround = true;
		laserScanner = true;
		nightVision = true;
		getInRadius=20;
		transportSoldier = 50;
		//hideProxyInCombat=1;

		memoryPointsGetInCargo = "pos cargo";
		memoryPointsGetInCoDriver = "pos driver";
		memoryPointsGetInCommander = "pos driver";
		memoryPointsGetInDriver = "pos driver";
		memoryPointsGetInGunner = "pos gunner";

		getInAction = "GetInMedium";
		getOutAction = "GetOutMedium";
		cargoGetInAction[] = {"GetInMedium"};
		cargoGetOutAction[] = {"GetOutMedium"};
		castDriverShadow = true;
		castCargoShadow = true;
		gunnerHasFlares = false;

		hasDriver=1;
		hasGunner=1;
		hasCommander=1;
		crew="O_crew_F";
		commanderCanSee=31;
		driverIsCommander = true;
		gunnerCanSee="1+16+4+8";

		weapons[]=
		{

		};
		magazines[]=
		{

		};

		armor = 6000;
		//armorStructural=2.000000;

		class AnimationSources
		{
			class Big_Radar
			{
				source = "user";
				animPeriod = 10;
				initPhase = 0;
			};

			class Small_Radar
			{
				source = "user";
				animPeriod = 2;
				initPhase = 0;
			};

			class catapult1
			{
				source = "user";
				animPeriod = 2;
				initPhase = 0;
			};

			class catapult2
			{
				source = "user";
				animPeriod = 2;
				initPhase = 0;
			};

			class catapult3
			{
				source = "user";
				animPeriod = 2;
				initPhase = 0;
			};

			class catapult4
			{
				source = "user";
				animPeriod = 2;
				initPhase = 0;
			};
		};

		class Library
		{
			libTextDesc = "$STR_ulyanovsk_DESCR";
		};
		class ViewPilot: ViewPilot
		{
			initFov = 0.8; minFov = 0.3; maxFov = 1.2;
			initAngleX = 0; minAngleX = -20; maxAngleX = 60;
			initAngleY = 0; minAngleY = -170; maxAngleY = 170;
		};
		class EventHandlers
        {
            init = "[_this select 0] exec ""\ulyanovsk\scr\tips.sqs""";
			engine = "[_this select 0] execVM ""\ulyanovsk\scr\small_radar.sqf"";[_this select 0] execVM ""\ulyanovsk\scr\big_radar.sqf""";
            fired = "_this call BIS_Effects_EH_Fired;";
			killed = "_this call BIS_Effects_EH_Killed;";
        };

		class Reflectors
		{
			class Left {
				color[] = {0.8, 0.7, 0.6, 1.0};
				ambient[] = {0.07, 0.07, 0.07, 1.0};
				position = "L svetlo";
				direction = "konec L svetlo";
				hitpoint = "L svetlo";
				selection = "L svetlo";
				size = 4;
				brightness = 4.0;
			};

			class Right {
				color[] = {0.8, 0.7, 0.6, 1.0};
				ambient[] = {0.07, 0.07, 0.07, 1.0};
				position = "P svetlo";
				direction = "konec P svetlo";
				hitpoint = "P svetlo";
				selection = "P svetlo";
				size = 4;
				brightness = 4.0;
			};
		};

		class Turrets : Turrets
		{
			class MainTurret : NewTurret
			{
				body = "MainTurret";
      			gun = "MainGun";
				gunBeg= "";
				gunEnd= "";
				animationSourceBody= "MainTurret"
				animationSourceGun= "MainGun"
				outGunnerMayFire = true;
				commanding = -1;
				primary = true;
				primaryGunner= true;
				memoryPointsGetInGunner= "pos gunner";
				memoryPointsGetInGunnerDir= "pos gunner dir";
				weapons[]={/*"ak630_Gun"*/};
		        magazines[]={/*"ak630_Gun"*/};
				castGunnerShadow = 1;
				viewGunnerShadow = 1;
				gunnerName="$STR_ULYANOVSK_KOU";
				gunnerCompartments= "Compartment1";
				proxyIndex = 1;
				minElev=0;
				maxElev=+90;
				minTurn=-180;
				maxTurn=+180;
				gunnerAction = "rhs_t80a_gunner_out";
				gunnerInAction = "rhs_t80a_gunner_in";
				soundServo[]={"\a3\weapons_f\Data\Sound\gun_elevate2",db-60,1.0};
				gunnerOpticsModel = "\a3\weapons_f\optika_empty";
				gunnerForceOptics = true;
				selectionFireAnim = "zasleh";
				initTurn = 0;
				maxHorizontalRotSpeed = 0.8;
				maxVerticalRotSpeed = 0.8;
				class Turrets {};
			};
			class gunner2 : MainTurret
			{
				body = "Turret_2";
      	gun = "Gun_2";
				gunBeg= "";
				gunEnd= "";
				animationSourceBody= "Turret_2"
				animationSourceGun= "Gun_2"
				outGunnerMayFire = true;
				commanding = -1;
				primary = true;
				memoryPointsGetInGunner= "pos gunner";
				memoryPointsGetInGunnerDir= "pos gunner dir";
				weapons[]={/*"ak630_Gun"*/};
		    magazines[]={/*"ak630_Gun"*/};
				castGunnerShadow = 1;
				viewGunnerShadow = 1;
				gunnerName="$STR_ULYANOVSK_SG";
				gunnerCompartments= "Compartment1";
				proxyIndex = 2;
				minElev=0;
				maxElev=+90;
				minTurn=-180;
				maxTurn=+180;
				gunnerAction = "rhs_t80a_gunner_out";
				gunnerInAction = "rhs_t80a_gunner_in";
				soundServo[]={"\a3\Weapons_f\Data\Sound\gun_elevate2",db-60,1.0};
				gunnerOpticsModel = \ca\Weapons\optika_empty;
				gunnerForceOptics = true;
				selectionFireAnim = "zasleh";
				initTurn = 0;
				maxHorizontalRotSpeed = 0.8;
				maxVerticalRotSpeed = 0.8;
				class Turrets {};
			};
		};

		class Light
		{

			position="light";
			ambient[] = {0.3,0.15,0.0,1.0};
			size = 3.3;
			brightness = 0.3;
			color[] = {1.0,0.5,0.0,1.0};

		};
		class test_Light
		{

			name="light";
			ambient[] = {0.3,0.15,0.0,1.0};
			size = 3.3;
			brightness = 0.3;
			color[] = {1.0,0.5,0.0,1.0};

		};
		class MarkerLights
		{
			class YellowStill
			{
				name = "yellow";
				color[] = {0.5, 0.4, 0.0, 0.3};
				ambient[] = {0.5, 0.4, 0.0, 0.3};
				brightness = 0.25;
				blinking = false;
			};

			class WhiteStill
			{
				name = "bily pozicni";
				color[] = {1.0, 0.9, 0.8, 1};
				ambient[] = {0.4, 0.35, 0.3, 1};
				brightness = 0.25;
				blinking = false;
			};

			class RedStill
			{
				name = "cerveny pozicni";
				color[] = {0.8, 0.0, 0.0, 1};
				ambient[] = {0.5, 0.0, 0.0, 1};
				brightness = 0.25;
				blinking = false;
			};

			class GreenStill
			{
				name = "zeleny pozicni";
				color[] = {0.0, 0.8, 0.0, 1};
				ambient[] = {0.0, 0.5, 0.0, 1};
				brightness = 0.25;
				blinking = false;
			};
		};

		class UserActions
		{
        	class loadcargo
			{
				onlyforplayer = 0;
				showwindow = 0;
				displayName = "$STR_ULYANOVSK_LC";
				position="dor";
				radius = 350.0;
				condition = "(speed (vehicle player) < 5) and !(player in this) and ((vehicle player)!=(this)) AND ((vehicle player)!=(player))";
				statement = "[this, vehicle player, player] execVM ""\ulyanovsk\scr\attach.sqf""";
			};

			class unloadcargo
			{
				onlyforplayer = 0;
				showwindow = 0;
				displayName = "$STR_ULYANOVSK_UC";
				position="dor";
				radius = 350.0;
				//condition = "(vehicle player != vehicle this) and (vehicle player != player) AND Alive(this)";
				condition = "(speed (vehicle player) < 5) and !(player in this) and ((vehicle player)!=(this)) AND ((vehicle player)!=(player))";
				statement = "[this, vehicle player, player] execVM ""\ulyanovsk\scr\detach.sqf""";
			};

			class movegunner
			{
				onlyforplayer = 0;
				showwindow = 0;
				displayName = "$STR_ULYANOVSK_ING";
				position="dor";
				radius=40;
				condition = "!(player in this) AND ISNULL (gunner this)";
				statement = "player moveInGunner this";
			};

			class movedriver
			{
				onlyforplayer = 0;
				showwindow = 0;
				displayName = "$STR_ULYANOVSK_IND";
				position="dor";
				radius=40;
				condition = "!(player in this) AND ISNULL (driver this)";
				statement = "player moveInDriver this";
			};

			class catapult1
			{
				onlyforplayer = 0;
				showwindow = 0;
				displayName = "$STR_ULYANOVSK_C1";
				position="catapult1";
				radius=10;
				condition = "!(player in this) AND ((vehicle player)!=(this)) AND ((vehicle player)!=(player))";
				statement = "[vehicle player, player] execVM ""\ulyanovsk\scr\catapult1.sqf""";
			};

			class catapult2
			{
				onlyforplayer = 0;
				showwindow = 0;
				displayName = "$STR_ULYANOVSK_C2";
				position="catapult2";
				radius=10;
				condition = "!(player in this) AND ((vehicle player)!=(this)) AND ((vehicle player)!=(player))";
				statement = "[vehicle player, player] execVM ""\ulyanovsk\scr\catapult2.sqf""";
			};

			class catapult3
			{
				onlyforplayer = 0;
				showwindow = 0;
				displayName = "$STR_ULYANOVSK_C3";
				position="catapult3";
				radius=10;
				condition = "!(player in this) AND ((vehicle player)!=(this)) AND ((vehicle player)!=(player))";
				statement = "[vehicle player, player] execVM ""\ulyanovsk\scr\catapult3.sqf""";
			};

			class catapult4
			{
				onlyforplayer = 0;
				showwindow = 0;
				displayName = "$STR_ULYANOVSK_C4";
				position="catapult4";
				radius=10;
				condition = "!(player in this) AND ((vehicle player)!=(this)) AND ((vehicle player)!=(player))";
				statement = "[vehicle player, player] execVM ""\ulyanovsk\scr\catapult4.sqf""";
			};
 		};
	};
	class forward_roadway : Ship
	{
		scope=1;
		model="\ulyanovsk\models\forward_roadway.p3d";
		displayname="test";
		side=0;
		//simulation="ship";
		faction = "OPF_F";
		vehicleclass = "Ship";
		//crew = "O_crew_F";
		hideProxyInCombat=0;
		getInRadius=0;
		class Reflectors{};
		class MarkerLights{};
	};

	class ff_roadway : forward_roadway
	{
		model="\ulyanovsk\models\ff_roadway.p3d";
	};

	class midlle_rooad : forward_roadway
	{
		model="\ulyanovsk\models\midlle_rooad.p3d";
	};

	class back_roadway : forward_roadway
	{
		model="\ulyanovsk\models\back_roadway.p3d";
	};

	class bb_roadway : forward_roadway
	{
		model="\ulyanovsk\models\bb_roadway.p3d";
	};

	class catapult1 : Ship
	{
		scope=1;
		model="\ulyanovsk\models\catapult.p3d";
		displayname="";
		side=0;
		faction = "OPF_F";
		vehicleclass = "Ship";
		crew = "O_crew_F";
		hideProxyInCombat=1;
		getInRadius=0;
		class Reflectors{};
		class MarkerLights{};
		class UserActions
		{
			class catapult1
			{
				onlyforplayer = 0;
				showwindow = 0;
				displayName = "$STR_ULYANOVSK_C1";
				position="dor";
				radius=10;
				condition = "!(player in this) AND ((vehicle player)!=(this)) AND ((vehicle player)!=(player))";
				statement = "[vehicle player, player] execVM ""\ulyanovsk\scr\catapult1.sqf""";
			};
		};
	};

	class catapult2 : Ship
	{
		scope=1;
		model="\ulyanovsk\models\catapult.p3d";
		displayname="";
		side=0;
		faction = "OPF_F";
		vehicleclass = "Ship";
		crew = "O_crew_F";
		hideProxyInCombat=1;
		getInRadius=0;
		class Reflectors{};
		class MarkerLights{};
		class UserActions
		{
			class catapult2
			{
				onlyforplayer = 0;
				showwindow = 0;
				displayName = "$STR_ULYANOVSK_C2";
				position="dor";
				radius=10;
				condition = "!(player in this) AND ((vehicle player)!=(this)) AND ((vehicle player)!=(player))";
				statement = "[vehicle player, player] execVM ""\ulyanovsk\scr\catapult2.sqf""";
			};
		};
	};

	class catapult3 : Ship
	{
		scope=1;
		model="\ulyanovsk\models\catapult.p3d";
		displayname="";
		side=0;
		faction = "OPF_F";
		vehicleclass = "Ship";
		crew = "O_crew_F";
		hideProxyInCombat=1;
		getInRadius=0;
		class Reflectors{};
		class MarkerLights{};
		class UserActions
		{
			class catapult3
			{
				onlyforplayer = 0;
				showwindow = 0;
				displayName = "$STR_ULYANOVSK_C3";
				position="dor";
				radius=10;
				condition = "!(player in this) AND ((vehicle player)!=(this)) AND ((vehicle player)!=(player))";
				statement = "[vehicle player, player] execVM ""\ulyanovsk\scr\catapult3.sqf""";
			};
		};
	};

	class catapult4 : Ship
	{
		scope=1;
		model="\ulyanovsk\models\catapult.p3d";
		displayname="";
		side=0;
		faction = "OPF_F";
		vehicleclass = "Ship";
		crew = "O_crew_F";
		hideProxyInCombat=1;
		getInRadius=0;
		class Reflectors{};
		class MarkerLights{};

		class UserActions
		{
			class catapult4
			{
				onlyforplayer = 0;
				showwindow = 0;
				displayName = "$STR_ULYANOVSK_C4";
				position="dor";
				radius=10;
				condition = "!(player in this) AND ((vehicle player)!=(this)) AND ((vehicle player)!=(player))";
				statement = "[vehicle player, player] execVM ""\ulyanovsk\scr\catapult4.sqf""";
			};
		};
	};

	class Granit_turret1: Tank
	{
		scope =1;
		faction="OPF_F";
		displayName="$STR_ULYANOVSK_T1";
		vehicleclass="Ship";
		getInRadius = 5;
		picture = "";
		outGunnerMayFire=true;
		gunnerAction="pilot";
		icon="";
		hideProxyInCombat=1;
		destrType=0;
		hasDriver=0;
		hasGunner=1;
		hasCommander=0;
		castGunnerShadow=0;
		ejectDeadGunner=0;
		irScanRangeMin=0;
		irScanRangeMax=1200;
		irTarget=0;
		maxSpeed=500;
		fuelCapacity=0;
		transportSoldier=0;
		model="\ulyanovsk\models\rocket_turret";
		cost=150000;
		weapons[]={};
		magazines[]={};
		side=0;
		crew="O_crew_F";
		armor=100;
		armorStructural=20.000000;
		soundEnviron[]={,1,1};
		soundEngine[]={,1,1};
		soundCrash[]={,1,1};
		soundGear[]={,1,1};
		transportAmmo=0;
		autocenter =0;
		accuracy=0.30;
		threat[] = {0,0,1};
		sensitivity=2;
		class Reflectors{};
		class Turrets : Turrets
		{
			class MainTurret : MainTurret
			{
				minElev=-20;
				maxElev=+90;
				minTurn=-180;
				maxTurn=+180;
				gunnerAction = T72_GunnerOut;
				gunnerInAction = T72_Gunner;
				soundServo[]={\ca\Weapons\Data\Sound\gun_elevate2,db-60,1.0};
				weapons[]=
				{
					/*"Granit_rail"*/
				};
				magazines[]=
				{
					/*"Granit_rail"*/
				};
				gunnerOpticsModel = \a3\weapons_f\optika_empty;

				class Turrets {};
			};
		};
	};

	class Granit_turret2: Granit_turret1
	{
		displayName="$STR_ULYANOVSK_T2";
	};

	class Granit_turret3: Granit_turret1
	{
		displayName="$STR_ULYANOVSK_T3";
	};

	class Granit_turret4: Granit_turret1
	{
		displayName="$STR_ULYANOVSK_T4";
	};

	class Granit_turret5: Granit_turret1
	{
		displayName="$STR_ULYANOVSK_T5";
	};

	class Granit_turret6: Granit_turret1
	{
		displayName="$STR_ULYANOVSK_T6";
	};

	class Granit_turret7: Granit_turret1
	{
		displayName="$STR_ULYANOVSK_T7";
	};

	class Granit_turret8: Granit_turret1
	{
		displayName="$STR_ULYANOVSK_T8";
	};
};
