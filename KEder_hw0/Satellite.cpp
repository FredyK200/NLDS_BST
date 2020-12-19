#include "Satellite.h"
Satellite::Satellite(string n, string c, string u, string on, string p, string pd, string ot, string a, string pr, string perid, string ld, string l, string ls, string lv, string no)
{
	name			= n;
	country			= c;
	users			= u;
	operator_name	= on;
	purpose			= p;
	purpose_detail	= pd;
	orbit_type		= ot;
	apogee			= a;
	perigee			= pr;
	period			= perid;
	launch_date		= ld;
	lifetime		= l;
	launch_site		= ls;
	launch_vehicle	= lv;
	norad			= no;
}
