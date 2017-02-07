_vehicle = _this select 0;
sleep 0.1;

while {(isengineon _vehicle) and (alive _vehicle)} do
{
	_anim = _vehicle animationphase "big_radar";	
	_vehicle animate ["big_radar",_anim + 1];
	sleep 10;
};
