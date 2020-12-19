#include "KEder_hw0.h"
#include "Satellite.h"
#include "Tree.h"
#include <iostream>
#include <fstream>
using namespace std;
/*=========================================================
	Project 1: BST Example
	Class: Non-Linear Data Structures
	Description: 
		Create 2 Binary Search Trees and pass data between them
		Data can be read by file or by user input
	Written By: Kane Eder / Sep 2020
===========================================================*/

void initialRead(string file_name);
void findInTree(string usr_input);
void deorbit(string usr_input);
void listSattelites();
void printHeader();
void saveTrees();
void readTrees();
void launch();

int deorbit_satellite_num = 0;
Satellite deorbit_sats[1000];
Tree<Satellite> deorbit_tree;
int orbit_satellite_num = 0;
Satellite orbit_sats[1000];
Tree<Satellite> orbit_tree;

int main()
{
	initialRead("Dataset1.txt");
	string usr_input;
	while (usr_input[0] != 'q' && usr_input[0] != 'Q')
	{
		printHeader();
		getline(cin, usr_input);
		switch (usr_input[0])
		{
		case 'l': case 'L':
			launch();
			break;

		case 'f': case 'F':
			findInTree(usr_input);
			break;

		case 'd': case 'D':
			deorbit(usr_input);
			break;

		case 'a': case 'A':
			listSattelites();
			break;

		case 's': case 'S':
			saveTrees();
			break;

		case 'r': case 'R':
			readTrees();
			break;

		case 'q': case 'Q':
			break;

		default:
			cout << "Unknown Command" << endl;
			break;
		}
		cout << endl;
	}
}

void initialRead(string file_name)
{
	string in_string;
	ifstream in_file;
	in_file.open(file_name);
	if (in_file.is_open())
	{
		while (in_file.good())
		{
			getline(in_file, in_string);
			if (in_file.bad() || in_file.eof())
			{
				in_file.close();
				break;
			}
			orbit_sats[orbit_satellite_num].setName(in_string);
			getline(in_file, in_string);
			orbit_sats[orbit_satellite_num].setCountry(in_string);
			getline(in_file, in_string);
			orbit_sats[orbit_satellite_num].setUsers(in_string);
			getline(in_file, in_string);
			orbit_sats[orbit_satellite_num].setOperatorName(in_string);
			getline(in_file, in_string);
			orbit_sats[orbit_satellite_num].setPurpose(in_string);
			getline(in_file, in_string);
			orbit_sats[orbit_satellite_num].setPurposeDetail(in_string);
			getline(in_file, in_string);
			orbit_sats[orbit_satellite_num].setOrbitType(in_string);
			getline(in_file, in_string);
			orbit_sats[orbit_satellite_num].setApogee(in_string);
			getline(in_file, in_string);
			orbit_sats[orbit_satellite_num].setPerigee(in_string);
			getline(in_file, in_string);
			orbit_sats[orbit_satellite_num].setPeriod(in_string);
			getline(in_file, in_string);
			orbit_sats[orbit_satellite_num].setLaunchDate(in_string);
			getline(in_file, in_string);
			orbit_sats[orbit_satellite_num].setLifetime(in_string);
			getline(in_file, in_string);
			orbit_sats[orbit_satellite_num].setLaunchSite(in_string);
			getline(in_file, in_string);
			orbit_sats[orbit_satellite_num].setLaunchVehicle(in_string);
			getline(in_file, in_string);
			orbit_sats[orbit_satellite_num].setNorad(in_string);
			orbit_satellite_num++;
		}
		for (int i = 0; i < orbit_satellite_num; i++)
		{
			orbit_tree.insert(orbit_sats[i]);
		}
	}
}
void findInTree(string usr_input)
{
	usr_input.erase(0, 2);
	auto result = orbit_tree.find(usr_input);
	if (result != nullptr)
	{
		cout << result->datum.prettyPrint() << endl;
	}
	else
	{
		result = deorbit_tree.find(usr_input);
		if (result != nullptr)
		{
			cout << result->datum.prettyPrint()
				 << "**This Satellite has been deorbited**" << "\n\n" ;
		}
		else
		{
			cout << "Satellite not found" << endl;
		}
	}
}
void deorbit(string usr_input)
{
	usr_input.erase(0, 2);
	auto result = orbit_tree.del(usr_input);
	if (result != nullptr)
	{
		deorbit_tree.insert(result->datum);
		deorbit_satellite_num++; orbit_satellite_num--;
	}
	else
	{
		cout << "Satellite not found" << endl;
	}
}
void listSattelites()
{
	cout << "ORBITING" << endl
		 << "========" << endl;
	orbit_tree.traverse();
	cout << "\n\n";
	cout << "DEORBITED" << endl
		 << "=========" <<endl;
	deorbit_tree.traverse();
	cout << endl;
}
void printHeader()
{
	cout << "==================================================================================" << endl;
	cout << "Orbing: ";
	for (int i = 0; i < orbit_satellite_num; i++) {	cout << '*'; }
	cout << endl;
	cout << "Deorbited: ";
	for (int i = 0; i < deorbit_satellite_num; i++) { cout << '*'; }
	cout << endl;
	cout << "(l)aunch - (f)ind - (d)eorbit - (a)ll - (s)ave - (r)ead - (q)uit" << endl;
	cout << "==================================================================================" << endl;
	cout << "> ";
}
void saveTrees()
{
	ofstream deorbitFile("DeorbitedSat.txt");
	ofstream orbitFile("OrbitingSat.txt");
	deorbit_tree.save(deorbitFile);
	orbit_tree.save(orbitFile);
	deorbitFile.close();
	orbitFile.close();
}
void readTrees()
{
	string in_string;
	orbit_satellite_num = 0;
	deorbit_satellite_num = 0;
	ifstream orbit_file("OrbitingSat.txt");
	if (!orbit_file)
	{
		cout << "Error opening OrbitingSat.txt" << endl;
		system("pause");
		return;
	}
	ifstream deorbit_file("DeorbitedSat.txt");
	if (!deorbit_file)
	{
		cout << "Error opening DeorbitedSat.txt" << endl;
		system("pause");
		return;
	}
	orbit_tree.clear();
	deorbit_tree.clear();
	if (orbit_file.is_open())
	{
		while (orbit_file.good())
		{
			getline(orbit_file, in_string);
			if (orbit_file.bad() || orbit_file.eof())
			{
				orbit_file.close();
				break;
			}
			orbit_sats[orbit_satellite_num].setName(in_string);
			getline(orbit_file, in_string);
			orbit_sats[orbit_satellite_num].setCountry(in_string);
			getline(orbit_file, in_string);
			orbit_sats[orbit_satellite_num].setUsers(in_string);
			getline(orbit_file, in_string);
			orbit_sats[orbit_satellite_num].setOperatorName(in_string);
			getline(orbit_file, in_string);
			orbit_sats[orbit_satellite_num].setPurpose(in_string);
			getline(orbit_file, in_string);
			orbit_sats[orbit_satellite_num].setPurposeDetail(in_string);
			getline(orbit_file, in_string);
			orbit_sats[orbit_satellite_num].setOrbitType(in_string);
			getline(orbit_file, in_string);
			orbit_sats[orbit_satellite_num].setApogee(in_string);
			getline(orbit_file, in_string);
			orbit_sats[orbit_satellite_num].setPerigee(in_string);
			getline(orbit_file, in_string);
			orbit_sats[orbit_satellite_num].setPeriod(in_string);
			getline(orbit_file, in_string);
			orbit_sats[orbit_satellite_num].setLaunchDate(in_string);
			getline(orbit_file, in_string);
			orbit_sats[orbit_satellite_num].setLifetime(in_string);
			getline(orbit_file, in_string);
			orbit_sats[orbit_satellite_num].setLaunchSite(in_string);
			getline(orbit_file, in_string);
			orbit_sats[orbit_satellite_num].setLaunchVehicle(in_string);
			getline(orbit_file, in_string);
			orbit_sats[orbit_satellite_num].setNorad(in_string);
			orbit_satellite_num++;
		}
	}
	if (deorbit_file.is_open())
	{
		while (deorbit_file.good())
		{
			getline(deorbit_file, in_string);
			if (deorbit_file.bad() || deorbit_file.eof())
			{
				deorbit_file.close();
				break;
			}
			deorbit_sats[deorbit_satellite_num].setName(in_string);
			getline(deorbit_file, in_string);
			deorbit_sats[deorbit_satellite_num].setCountry(in_string);
			getline(deorbit_file, in_string);
			deorbit_sats[deorbit_satellite_num].setUsers(in_string);
			getline(deorbit_file, in_string);
			deorbit_sats[deorbit_satellite_num].setOperatorName(in_string);
			getline(deorbit_file, in_string);
			deorbit_sats[deorbit_satellite_num].setPurpose(in_string);
			getline(deorbit_file, in_string);
			deorbit_sats[deorbit_satellite_num].setPurposeDetail(in_string);
			getline(deorbit_file, in_string);
			deorbit_sats[deorbit_satellite_num].setOrbitType(in_string);
			getline(deorbit_file, in_string);
			deorbit_sats[deorbit_satellite_num].setApogee(in_string);
			getline(deorbit_file, in_string);
			deorbit_sats[deorbit_satellite_num].setPerigee(in_string);
			getline(deorbit_file, in_string);
			deorbit_sats[deorbit_satellite_num].setPeriod(in_string);
			getline(deorbit_file, in_string);
			deorbit_sats[deorbit_satellite_num].setLaunchDate(in_string);
			getline(deorbit_file, in_string);
			deorbit_sats[deorbit_satellite_num].setLifetime(in_string);
			getline(deorbit_file, in_string);
			deorbit_sats[deorbit_satellite_num].setLaunchSite(in_string);
			getline(deorbit_file, in_string);
			deorbit_sats[deorbit_satellite_num].setLaunchVehicle(in_string);
			getline(deorbit_file, in_string);
			deorbit_sats[deorbit_satellite_num].setNorad(in_string);
			deorbit_satellite_num++;
		}
	}

	for (int i = 0; i < orbit_satellite_num; i++)
	{
		orbit_tree.insert(orbit_sats[i]);
	}

	for (int i = 0; i < deorbit_satellite_num; i++)
	{
		deorbit_tree.insert(deorbit_sats[i]);
	}
}
void launch()
{
	string usr_input;
	cout << "Satellite Name: ";
	getline(cin, usr_input);
	orbit_sats[orbit_satellite_num].setName(usr_input);
	cout << "Satellite Country: ";
	getline(cin, usr_input);
	orbit_sats[orbit_satellite_num].setCountry(usr_input);
	cout << "Satellite Users: ";
	getline(cin, usr_input);
	orbit_sats[orbit_satellite_num].setUsers(usr_input);
	cout << "Satellite Operator: ";
	getline(cin, usr_input);
	orbit_sats[orbit_satellite_num].setOperatorName(usr_input);
	cout << "Satellite Purpose: ";
	getline(cin, usr_input);
	orbit_sats[orbit_satellite_num].setPurpose(usr_input);
	cout << "Satellite Purpose Detail: ";
	getline(cin, usr_input);
	orbit_sats[orbit_satellite_num].setPurposeDetail(usr_input);
	cout << "Satellite Orbit Type: ";
	getline(cin, usr_input);
	orbit_sats[orbit_satellite_num].setOrbitType(usr_input);
	cout << "Satellite Apogee: ";
	getline(cin, usr_input);
	orbit_sats[orbit_satellite_num].setApogee(usr_input);
	cout << "Satellite Perigee: ";
	getline(cin, usr_input);
	orbit_sats[orbit_satellite_num].setPerigee(usr_input);
	cout << "Satellite Period: ";
	getline(cin, usr_input);
	orbit_sats[orbit_satellite_num].setPeriod(usr_input);
	cout << "Satellite Launch Date: ";
	getline(cin, usr_input);
	orbit_sats[orbit_satellite_num].setLaunchDate(usr_input);
	cout << "Satellite Lifetime: ";
	getline(cin, usr_input);
	orbit_sats[orbit_satellite_num].setLifetime(usr_input);
	cout << "Satellite Launch Site: ";
	getline(cin, usr_input);
	orbit_sats[orbit_satellite_num].setLaunchSite(usr_input);
	cout << "Satellite Launch Vehicle: ";
	getline(cin, usr_input);
	orbit_sats[orbit_satellite_num].setLaunchVehicle(usr_input);
	cout << "Satellite NORAD: ";
	getline(cin, usr_input);
	orbit_sats[orbit_satellite_num].setNorad(usr_input);
	orbit_tree.insert(orbit_sats[orbit_satellite_num]);
	orbit_satellite_num++;
}