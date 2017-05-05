#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdio>
#include <unistd.h>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;

// g++ -o press-readout check-number-in-txtfile.cpp
// ./press-readout


bool ReadSocketState(int socket_number) // on windows: 0 = false; 1 = true
{

	ifstream info_file;
	info_file.open("F:/Dokumente und Einstellungen/vip2/Desktop/info.ini");
	//info_file.open("info.ini");
	string dummie;
	int line_number = 2 + socket_number * 3;
	bool socket_state;

	for(int i = 0; i < line_number; i++) {

		getline(info_file, dummie);

	}

	size_t pos = dummie.find("=");
	string bool_str = dummie.substr(pos+1);

	int val_true = bool_str.compare("TRUE");// compare returns -1/1 if false and 0 if true; but bool is true = 1
	int val_false = bool_str.compare("FALSE");
	
	//cout << "val true = " << val_true << "val_false = " << val_false << endl;

	if(val_true == 0) {
		socket_state = true;
	} else if(val_false == 0) {
		socket_state = false;
	} else {
		cout << " THERE WAS AN ERROR" << endl;
	}

	cout << dummie << " " << bool_str << " " << socket_state  << " " << val_true << " " << val_false << endl;

	info_file.close();

	return socket_state;

}

void GetInfoFile(){
	
	system("pm.exe.lnk -info");
}

void TurnOffSocket1(){
	
	system("pm.exe.lnk -off -Socket1 -socket1");
}

double GetPressure(){
	
	ifstream press_file;
	press_file.open("F:/Dokumente und Einstellungen/vip2/Desktop/pressure.log");
	
	string dummie;
	getline(press_file, dummie);
	getline(press_file, dummie);
	
	size_t pos = dummie.find("sure:");
	string press_str = dummie.substr(pos+6);
	
	double pressure;
	stringstream conv(press_str);
	conv >> pressure;
	//cout << pressure << endl;
	press_file.close();
	
	return pressure;
	
}

string GetLastLine(ifstream& in)
{
    string line;
    while (in >> ws && getline(in, line)); //while (in >> ws && getline(in, line)); skip empty lines
     

    return line;
}

void GetSlowData(ifstream& in, int &month, int &day, int &year, int &hour, int &min, int &sec, string &AmOrPm, double &ticks, double &room, double &ar_target, double &pcb_a, double &pcb_b, double &sdd1, double &argon_up, double &argon_down, double &sdd2, double &copper_int, double &copper_ext1, double &cooling_pad, double &vacuum_pres, double &current, double &argon_pres, double &voltage, double &heater_percent, double &ar_gas){
	
	string str;
	str = GetLastLine(in);
	
	stringstream ss(str);
	char dum;
	
	//cout << str << endl;
	
	ss >> month >> dum >> day >> dum >> year >> ws >> hour >> dum >> min >> dum >> sec;
	ss >> AmOrPm >> ws >> ticks >> ws >> room >> ws >> ar_target >> ws >> pcb_a >> ws >> pcb_b;
	ss >> sdd1 >> ws >> argon_up >> ws >> argon_down >> ws >> sdd2 >> ws >> copper_int >> ws;
	ss >> copper_ext1 >> cooling_pad >> ws >> vacuum_pres >> ws >> current >> argon_pres >> ws;
	ss >> voltage >> ws >> heater_percent >> ar_gas;

}

int main()
{
    bool socket_state;
    int month, day, year, hour, min, sec;
    string amorpm;
    double ticks;
    double room, ar_target, pcb_a, pcb_b, sdd1, argon_up, argon_down, sdd2, copper_int, copper_ext1, cooling_pad, vacuum_pres, current, argon_pres, voltage, heater_percent, ar_gas;
    double vac_pres;
    int counter = 0;
    
    GetInfoFile();
    sleep(1);
    ReadSocketState(3);
/*
    while(1){
    	
    	counter += 1;
    	vac_pres = GetPressure();
    	//GetInfoFile();
    	
    	cout << 1 << endl;
    	
    	ifstream slow_file;
    	slow_file.open("F:/Dokumente und Einstellungen/vip2/Desktop/Gembird/SlowLog20160131.log");
    	GetSlowData(slow_file, month, day, year, hour, min, sec, amorpm, ticks, room, ar_target, pcb_a, pcb_b, sdd1, argon_up, argon_down, sdd2, copper_int, copper_ext1, cooling_pad, vacuum_pres, current, argon_pres, voltage, heater_percent, ar_gas);
    	
    	cout << 2 << endl;
    	
    	socket_state = ReadSocketState(1);
    	cout << 3 << endl;
    	if(socket_state == 1){
		
		   if(vac_pres > 1){TurnOffSocket1();}
		 
		}
    	
    	slow_file.close();
    	cout << "counter = " << counter << endl;
    	sleep(1);// in seconds
	}
	
	//cout << "Socket is " << socket_state << endl;


	
	cout << "ar_gas = " << ar_gas << endl;*/
	
	
}


