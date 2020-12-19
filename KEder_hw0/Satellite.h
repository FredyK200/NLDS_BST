	#pragma once
#include "KEder_hw0.h"
#include <iostream>
#include <fstream>
using namespace std;

class Satellite
{
protected:
	string name;
	string country;
	string users;
	string operator_name;
	string purpose;
	string purpose_detail;
	string orbit_type;
	string apogee;
	string perigee;
	string period;
	string launch_date;
	string lifetime;
	string launch_site;
	string launch_vehicle;
	string norad;
public:
	Satellite(string n, string c, string u, string on, string p, string pd, string ot, string a, string pr, string period, string ld, string l, string ls, string lv, string norad);
	Satellite() {
		name = "defult";
		country	= "defult";
		users = "defult";
		operator_name = "defult";
		purpose = "defult";
		purpose_detail = "defult";
		orbit_type = "defult";
		apogee = "defult";
		perigee = "defult";
		period = "defult";
		launch_date = "defult";
		lifetime = "defult";
		launch_site = "defult";
		launch_vehicle = "defult";
		norad = "defult";
	}

	string getName() { return name; };
	string getCountry() { return country; };
	string getUsers() { return users; };
	string getOperatorName() { return operator_name; };
	string getPurpose() { return purpose; };
	string getPurposeDetail() { return purpose_detail; };
	string getOrbitType() { return orbit_type; };
	string getApogee() { return apogee; };
	string getPerigee() { return perigee; };
	string getPeriod() { return period; };
	string getLaunchDate() { return launch_date; };
	string getLifetime() { return lifetime; };
	string getLaunchSite() { return launch_site; };
	string getLaunchVehicle() { return launch_vehicle; };
	string getNorad() { return norad; };

	void setName(string n) { name = n; };
	void setCountry(string c) { country = c; };
	void setUsers(string u) { users = u; };
	void setOperatorName(string on) { operator_name = on; };
	void setPurpose(string p) { purpose = p; };
	void setPurposeDetail(string pd) { purpose_detail = pd; };
	void setOrbitType(string ot) { orbit_type = ot; };
	void setApogee(string a) { apogee = a; };
	void setPerigee(string pr) { perigee = pr; };
	void setPeriod(string perid) { period = perid; };
	void setLaunchDate(string ld) { launch_date = ld; };
	void setLifetime(string l) { lifetime = l; };
	void setLaunchSite(string ls) { launch_site = ls; };
	void setLaunchVehicle(string lv) { launch_vehicle = lv; };
	void setNorad(string no) { norad = no; };

	string getSatalliteInfo()
	{
		return 	name + "\n" 
				+ country + "\n" 
				+ users + "\n" 
				+ operator_name + "\n" 
				+ purpose + "\n" 
				+ purpose_detail + "\n" 
				+ orbit_type + "\n"
				+ apogee + "\n"
				+ perigee + "\n"
				+ period + "\n" 
				+ launch_date + "\n" 
				+ lifetime + "\n" 
				+ launch_site + "\n" 
				+ launch_vehicle +"\n" 
				+ norad + "\n";
	}

	string prettyPrint()
	{
		return 	"Sattelite Name: "+ name + "\n"
				+ "Country: " + country + "\n"
				+ "Users: "	+ users + "\n"
				+ "Operator: " + operator_name + "\n"
				+ "Purpose: " + purpose + "\n"
				+ "Purpose Detail: " + purpose_detail + "\n"
				+ "Orbit Type: " + orbit_type + "\n"
				+ "Apogee: " +apogee + "\n"
				+ "Perigee: " + perigee + "\n"
				+ "Period" + period + "\n"
				+ "Launch Date: " + launch_date + "\n"
				+ "Lifetime: " + lifetime + "\n"
				+ "Launch Site: " + launch_site + "\n"
				+ "Launch Vehicle: " + launch_vehicle + "\n"
				+ "NORAD: " + norad + "\n";
	}
};
