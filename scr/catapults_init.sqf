
private ["_vehicle","_midll","_fwrw1_position","_midll_position","_fwrw2_position","_bkrw1_position","_bkrw2_position","_fwrw1","_fwrw2","_bkrw1","_bkrw2","_vmfFlag","_trt1","_trt2","_trt3","_trt4","_trt5","_trt6","_trt7","_trt8"];

_vehicle = _this select 0;

//_pilot = driver _vehicle;
//_pilot_grp = group _pilot;

_fwrw1_position = _vehicle selectionPosition "froadway";
_fwrw2_position = _vehicle selectionPosition "froadway2";
_bkrw1_position = _vehicle selectionPosition "broadway";
_bkrw2_position = _vehicle selectionPosition "broadway2";
_midll_position = _vehicle selectionPosition "mroadway";

_fwrw1 = "forward_roadway" createVehicle _fwrw1_position;
_fwrw2 = "ff_roadway" createVehicle _fwrw2_position;
_bkrw1 = "back_roadway" createVehicle _bkrw1_position;
_bkrw2 = "bb_roadway" createVehicle _bkrw2_position;
_midll = "midlle_rooad" createVehicle _midll_position;

  _fwrw1 attachTo [_vehicle,[0.0,0.0,0.0],"froadway"];
  _fwrw2 attachTo [_vehicle,[0.0,0.0,0.0],"froadway2"];
  _bkrw1 attachTo [_vehicle,[0.0,0.0,0.0],"broadway"];
  _bkrw2 attachTo [_vehicle,[0.0,0.0,0.0],"broadway2"];
  _midll attachTo [_vehicle,[0.0,0.0,0.0],"mroadway"];

  /*
  cpult1 = "catapult1" createvehicle(_plane selectionposition "catapult1");
  cpult2 = "catapult2" createvehicle(_plane selectionposition "catapult2");
  cpult3 = "catapult3" createvehicle(_plane selectionposition "catapult3");
  cpult4 = "catapult4" createvehicle(_plane selectionposition "catapult4");
  */
  /*
  cpult1 attachTo [_plane,[0.0,0.0,0.0],"catapult1"];
  cpult2 attachTo [_plane,[0.0,0.0,0.0],"catapult2"];
  cpult3 attachTo [_plane,[0.0,0.0,0.0],"catapult3"];
  cpult4 attachTo [_plane,[0.0,0.0,0.0],"catapult4"];
  */

  _trt1 = "granit_turret1" createVehicle(_vehicle selectionPosition "turret1");
  _trt2 = "granit_turret2" createVehicle(_vehicle selectionPosition "turret2");
  _trt3 = "granit_turret3" createVehicle(_vehicle selectionPosition "turret3");
  _trt4 = "granit_turret4" createVehicle(_vehicle selectionPosition "turret4");
  _trt5 = "granit_turret5" createVehicle(_vehicle selectionPosition "turret5");
  _trt6 = "granit_turret6" createVehicle(_vehicle selectionPosition "turret6");
  _trt7 = "granit_turret7" createVehicle(_vehicle selectionPosition "turret7");
  _trt8 = "granit_turret8" createVehicle(_vehicle selectionPosition "turret8");

  _trt1 attachTo [_vehicle,[0.0,0.0,0.0],"turret1"];
  _trt2 attachTo [_vehicle,[0.0,0.0,0.0],"turret2"];
  _trt3 attachTo [_vehicle,[0.0,0.0,0.0],"turret3"];
  _trt4 attachTo [_vehicle,[0.0,0.0,0.0],"turret4"];
  _trt5 attachTo [_vehicle,[0.0,0.0,0.0],"turret5"];
  _trt6 attachTo [_vehicle,[0.0,0.0,0.0],"turret6"];
  _trt7 attachTo [_vehicle,[0.0,0.0,0.0],"turret7"];
  _trt8 attachTo [_vehicle,[0.0,0.0,0.0],"turret8"];
/*
  "RU_Soldier" createunit [getpos _plane, _pilot_grp,"", 0.7, "PRIVATE"];
  "RU_Soldier" createunit [getpos _plane, _pilot_grp,"", 0.7, "PRIVATE"];
  "RU_Soldier" createunit [getpos _plane, _pilot_grp,"", 0.7, "PRIVATE"];
  "RU_Soldier" createunit [getpos _plane, _pilot_grp,"", 0.7, "PRIVATE"];
  "RU_Soldier" createunit [getpos _plane, _pilot_grp,"", 0.7, "PRIVATE"];
  "RU_Soldier" createunit [getpos _plane, _pilot_grp,"", 0.7, "PRIVATE"];
  "RU_Soldier" createunit [getpos _plane, _pilot_grp,"", 0.7, "PRIVATE"];
  "RU_Soldier" createunit [getpos _plane, _pilot_grp,"", 0.7, "PRIVATE"];

  _tunits = units _pilot_grp;

  gunner1 = _tunits select (count(_tunits) -8);
  gunner2 = _tunits select (count(_tunits) -7);
  gunner3 = _tunits select (count(_tunits) -6);
  gunner4 = _tunits select (count(_tunits) -5);
  gunner5 = _tunits select (count(_tunits) -4);
  gunner6 = _tunits select (count(_tunits) -3);
  gunner7 = _tunits select (count(_tunits) -2);
  gunner8 = _tunits select (count(_tunits) -1);

  gunner1 moveingunner trt1;
  gunner2 moveingunner trt2;
  gunner3 moveingunner trt3;
  gunner4 moveingunner trt4;
  gunner5 moveingunner trt5;
  gunner6 moveingunner trt6;
  gunner7 moveingunner trt7;
  gunner8 moveingunner trt8;

  trt1 setcombatmode "RED";
  trt1 setbehaviour "COMBAT" ;
  trt2 setcombatmode "RED";
  trt2 setbehaviour "COMBAT" ;
  trt3 setcombatmode "RED";
  trt3 setbehaviour "COMBAT" ;
  trt4 setcombatmode "RED";
  trt4 setbehaviour "COMBAT" ;
  trt5 setcombatmode "RED";
  trt5 setbehaviour "COMBAT" ;
  trt6 setcombatmode "RED";
  trt6 setbehaviour "COMBAT" ;
  trt7 setcombatmode "RED";
  trt7 setbehaviour "COMBAT" ;
  trt8 setcombatmode "RED";
  trt8 setbehaviour "COMBAT" ;
*/

_vmfFlag = "FlagCarrier" createVehicle(_vehicle selectionPosition "catapult1");
_vmfFlag setFlagTexture "\ulyanovsk\icons\vmf.paa";
_vmfFlag setFlagOwner (gunner _vehicle);
