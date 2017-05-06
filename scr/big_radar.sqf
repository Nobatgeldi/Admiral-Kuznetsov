
private["_vehicle"];

_vehicle = _this select 0;
sleep 0.1;

while {(isEngineOn _vehicle) and (alive _vehicle)} do
{
	_anim = _vehicle animationPhase "big_radar";
	_vehicle animate ["big_radar",_anim + 1];
	sleep 10;
};
