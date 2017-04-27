

private ["_plane","_flanim","_Typeof3d","_TimerPeriod","_LifeTime","_Position1","_Position2","_Position3","_Position4","_Position5","_Position6","_Position7","_Position8","_Position9","_MoveVelocity","_RotationVelocity","_Weight","_Volume","_Rubbing","_Size","_Color","_AnimationPhase","_RandomDirectionPeriod","_RandomDirectionIntensity","_OnTimer","_BeforeDestroy","_Obj"];
_plane = _this select 0;
_flanim = 0;

[_plane] execVM "\ulyanovsk\scr\catapults_init.sqf";

//_Drop3d = "\lun903\WaterEffects";
_Typeof3d = "Billboard";
_TimerPeriod = 4;
_LifeTime = 4;
_Position1 = (_plane selectionPosition "pravy prach");
_Position2 = (_plane selectionPosition "levy prach");
_Position3 = (_plane selectionPosition "predny prach");
_Position4 = (_plane selectionPosition "prostredny prach");
_Position5 = (_plane selectionPosition "last prach");
_Position6 = (_plane selectionPosition "predny prach 2");
_Position7 = (_plane selectionPosition "prostredny prach 2");
_Position8 = (_plane selectionPosition "last prach 2");
_Position9 = (_plane selectionPosition "forward prach");
_MoveVelocity = [(velocity _plane select 0)/2,(velocity _plane select 1)/2,(velocity _plane select 2)/2];
_RotationVelocity = 1;
_Weight = 1.4;
_Volume = 1;
_Rubbing = 0;
_Size = [3,5,15,10];
_Color = [[1,1,1,0.6],[0.8,0.8,1,0]];
_AnimationPhase = [0];
_RandomDirectionPeriod = 0;
_RandomDirectionIntensity = 0;
_OnTimer = "";
_BeforeDestroy = "";
_Obj = _plane;

if (((surfaceIsWater [((getPos _plane select 0)+10*(sin(direction _plane))),((getPos _plane select 1)+10*(cos(direction _plane)))]) or (surfaceIsWater(getPos _plane)) or (surfaceIsWater [((getPos _plane select 0)-10*(sin(direction _plane))),((getPos _plane select 1)-10*(cos(direction _plane)))])) and ((getPos _plane select 2) < 0)) then
{
    _plane setPos [(getPos _plane select 0), (getPos _plane select 1), 0.5];
}

#mainroop
?!(alive _plane):goto "exit"
?(_plane animationPhase "Rland" == 1) : _plane animate ["Rland",0];_plane animate ["Fland",0];_plane animate ["planebody",0];

if ((surfaceIsWater [((getPos _plane select 0)+10*(sin(direction _plane))),((getPos _plane select 1)+10*(cos(direction _plane)))]) or (surfaceIsWater(getPos _plane)) or (surfaceIsWater [((getPos _plane select 0)-10*(sin(direction _plane))),((getPos _plane select 1)-10*(cos(direction _plane)))])) then {goto "water";_plane animate ["Rland",1];_plane animate ["Fland",1];_plane animate ["planebody",1]}
sleep 0.01;

goto "mainroop"


#water
if !((surfaceIsWater [((getPos _plane select 0)+10*(sin(direction _plane))),((getPos _plane select 1)+10*(cos(direction _plane)))]) or (surfaceIsWater(getPos _plane)) or (surfaceIsWater [((getPos _plane select 0)-10*(sin(direction _plane))),((getPos _plane select 1)-10*(cos(direction _plane)))])) then {goto "mainroop"}
~0.01
?!(alive _plane):goto "exit"
?((getPos _plane select 2) > 5): goto "water"

goto "floatset"


#floatend
deletevehicle _float
goto "mainroop"

#land

#floatset
?!(alive _plane):goto "planekilled"
?(((velocity _plane select 2) < -10) and ((getpos _plane select 2) < 5)): goto "mainroop"

if !((surfaceisWater [((getpos _plane select 0)+10*(sin(direction _plane))),((getpos _plane select 1)+10*(cos(direction _plane)))]) or (surfaceisWater(getpos _plane)) or (surfaceisWater [((getpos _plane select 0)-10*(sin(direction _plane))),((getpos _plane select 1)-10*(cos(direction _plane)))])) then {goto "floatend"}

?((getpos _plane select 2) > 5): goto "floatend"
~0.01

_rnd = (random 10)/10-0.5
_rnd2 = (random 10)/10

_MoveVelocity = [10*_rnd,-10*_rnd2,0 + (speed _plane)/60]
_Position = [4*_rnd,8,-2-(getpos _plane select 2)]
_Size = [1,5+(speed _plane)/10,2]

?(((getpos _plane select 2) < 10) and (speed _plane > 7)): drop [_Drop3d, "",_Typeof3d,_TimerPeriod,_LifeTime,_Position1,_MoveVelocity,_RotationVelocity,_Weight,_Volume,_Rubbing,_Size,_Color,_AnimationPhase,_RandomDirectionPeriod,_RandomDirectionIntensity,_OnTimer,_BeforeDestroy,_Obj];
?(((getpos _plane select 2) < 10) and (speed _plane > 7)): drop [_Drop3d, "",_Typeof3d,_TimerPeriod,_LifeTime,_Position2,_MoveVelocity,_RotationVelocity,_Weight,_Volume,_Rubbing,_Size,_Color,_AnimationPhase,_RandomDirectionPeriod,_RandomDirectionIntensity,_OnTimer,_BeforeDestroy,_Obj];
?(((getpos _plane select 2) < 10) and (speed _plane > 7)): drop [_Drop3d, "",_Typeof3d,_TimerPeriod,_LifeTime,_Position3,_MoveVelocity,_RotationVelocity,_Weight,_Volume,_Rubbing,_Size,_Color,_AnimationPhase,_RandomDirectionPeriod,_RandomDirectionIntensity,_OnTimer,_BeforeDestroy,_Obj];
?(((getpos _plane select 2) < 10) and (speed _plane > 7)): drop [_Drop3d, "",_Typeof3d,_TimerPeriod,_LifeTime,_Position4,_MoveVelocity,_RotationVelocity,_Weight,_Volume,_Rubbing,_Size,_Color,_AnimationPhase,_RandomDirectionPeriod,_RandomDirectionIntensity,_OnTimer,_BeforeDestroy,_Obj];
?(((getpos _plane select 2) < 10) and (speed _plane > 7)): drop [_Drop3d, "",_Typeof3d,_TimerPeriod,_LifeTime,_Position5,_MoveVelocity,_RotationVelocity,_Weight,_Volume,_Rubbing,_Size,_Color,_AnimationPhase,_RandomDirectionPeriod,_RandomDirectionIntensity,_OnTimer,_BeforeDestroy,_Obj];
?(((getpos _plane select 2) < 10) and (speed _plane > 7)): drop [_Drop3d, "",_Typeof3d,_TimerPeriod,_LifeTime,_Position6,_MoveVelocity,_RotationVelocity,_Weight,_Volume,_Rubbing,_Size,_Color,_AnimationPhase,_RandomDirectionPeriod,_RandomDirectionIntensity,_OnTimer,_BeforeDestroy,_Obj];
?(((getpos _plane select 2) < 10) and (speed _plane > 7)): drop [_Drop3d, "",_Typeof3d,_TimerPeriod,_LifeTime,_Position7,_MoveVelocity,_RotationVelocity,_Weight,_Volume,_Rubbing,_Size,_Color,_AnimationPhase,_RandomDirectionPeriod,_RandomDirectionIntensity,_OnTimer,_BeforeDestroy,_Obj];
?(((getpos _plane select 2) < 10) and (speed _plane > 7)): drop [_Drop3d, "",_Typeof3d,_TimerPeriod,_LifeTime,_Position8,_MoveVelocity,_RotationVelocity,_Weight,_Volume,_Rubbing,_Size,_Color,_AnimationPhase,_RandomDirectionPeriod,_RandomDirectionIntensity,_OnTimer,_BeforeDestroy,_Obj];
?(((getpos _plane select 2) < 10) and (speed _plane > 7)): drop [_Drop3d, "",_Typeof3d,_TimerPeriod,_LifeTime,_Position9,_MoveVelocity,_RotationVelocity,_Weight,_Volume,_Rubbing,_Size,_Color,_AnimationPhase,_RandomDirectionPeriod,_RandomDirectionIntensity,_OnTimer,_BeforeDestroy,_Obj];

goto "floatset"

#planekilled
deletevehicle _float
#exit
exit