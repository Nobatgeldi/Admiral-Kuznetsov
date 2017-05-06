_plane = _this select 0;
_veh = _this select 1;
_player = _this select 2;
_d = direction _plane;
_dv = direction _veh;
_dv = _dv - _d;

_difx = (cos(_d))*((getPos _veh select 0) - (getPos _plane select 0)) - (sin(_d))*((getPos _veh select 1) - (getPos _plane select 1));
_dify = (cos(_d))*((getPos _veh select 1) - (getPos _plane select 1)) + (sin(_d))*((getPos _veh select 0) - (getPos _plane select 0));


if (ABS(_difx)>40) then
{
    hint (localize "STR_GALAXY_C5_OP");
	if (true) exitWith {};
}
else
{
	_player setFuel 0;
	_player action ["GetOut", vehicle _player];
	player disableAI "ANIM";  
	_veh disableAI "ANIM"; 
	_veh disableAI "MOVE"; 
	_veh setFuel 0;
	sleep 0.01;
	_difz = (getPos _plane select 2) - (getPos _veh select 2) + 25.0;
	_veh allowDamage false;
	
	//hint format ["X1: %1 Y1: %2 Z1: %3", _difx, _dify, _difz];
	_veh attachTo [_plane,[_difx,_dify,_difz]]; 
	_veh setFuel 0;
	sleep 0.01;
	_difz = (getPos _plane select 2) - (getPos _veh select 2) + 25.0;
	_veh allowDamage false;
	//hint format ["X2: %1 Y2: %2 Z2: %3", _difx, _dify, _difz];
	_veh attachTo [_plane,[_difx,_dify,_difz]]; 
	_veh setDir _dv;
	_veh setFuel 0;
	sleep 5;
	_veh enableSimulation false;
	if (true) exitWith {};
};