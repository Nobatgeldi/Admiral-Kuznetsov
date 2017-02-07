_vehicle = _this select 0;
sleep 0.1;

while {(isengineon _vehicle) and (alive _vehicle)} do
{
	_anim = _vehicle animationphase "front_left_radar";	
	_vehicle animate ["front_left_radar",_anim + 1];
	_vehicle animate ["front_right_radar",_anim + 1];
	_vehicle animate ["back_left_radar",_anim + 1];
	_vehicle animate ["back_right_radar",_anim + 1];
	_vehicle animate ["top_radar_back",_anim + 1];
	_vehicle animate ["top_radar_front",_anim + 1];
	sleep 2;
};
