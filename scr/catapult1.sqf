_carrier = nearestObject [player, "ulyanovsk"];
_plane = (vehicle player);
_player = player;
sleep(0.1); 

_Boost = 0.030;
_Intensity = 0.12;
_maxspeed = 300;
_MaxIntensity = 0.15;
_looptime = 0.1;
_runtime = 200;

_cangle = getDir _carrier;
_vangle = getDir _plane;
_angle = abs(_vangle - _cangle);
if (_angle > 10) then 
{
	hint (localize "STR_ULYANOVSK_LF");
	if (true) exitWith {};
}
else
{
	_carrier animate ["catapult1",1];

	sleep(2);	
	while {(alive _plane) and ((speed _plane)< 300)} do 
	{
		if (isEngineOn _plane) then
		{
			if (_Intensity < _MaxIntensity) then 
			{
				_Intensity = _Intensity + 0.1*(15*_looptime);
			}
			if ((speed _plane) < _maxspeed) then 
			{
				_plane setVelocity [(velocity _plane select 0)+((vectorDir _plane) select 0)*((_Boost*_Intensity/2)*(15*_looptime)),(velocity _plane select 1)+((vectorDir _plane) select 1)*((_Boost*_Intensity/2)*(15*_looptime)),(velocity _plane select 2)+((vectorDir _plane) select 2)*((_Boost*_Intensity/2)*(10*_looptime))];
			};
		} 
		else 
		{
			if (_Intensity > 0) then
			{
			    _Intensity = _Intensity - 0.2*(15*_looptime);
			}
		};
		_looptime = time;
		sleep 0.05; // mod by Crowe
		_runtime = _runtime - 1;
	};
	
	sleep(0.1);
	_carrier animate ["catapult1",0];
};