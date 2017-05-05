// compile with: g++ get_mean_run_temp.cpp -o get_mean_run_temp
// builds string from date (integer) and calculates average temperatures


#include  <stdlib.h>
#include  <stdio.h>
#include  <iostream>
#include <sstream> 
#include <string>  

using namespace std;

int main (){

 stringstream file_name;

 char  fline[512];

 int counter= 0;
 
 int date = 20150624;
 int  d, yr, hr, min, s;
 double current, voltage;
 double vac_pres, argon_pres;
 double heater, ls331;
 char mon[3];
 double ticks;
 double tmp[11];

 string log = ".log";
 string file_name_string;
 string slow_path = "/home/andreas/vip2/data/slow_control/";

 file_name << slow_path << date << log;
 file_name_string = file_name.str();

// cout << 1 << endl;

 char* slow_file_char = (char*) file_name_string.c_str();

 cout << file_name_string<< endl;

 FILE *fslow;
 fslow = fopen( slow_file_char, "r" );
// cout << 2 << endl;
 fgets( fline, 512, fslow ); // read the header
 while( fgets( fline, 512, fslow ) != NULL ){
      
     counter +=1;       
     sscanf( fline, "%2d-%3s-%2d %2d:%2d:%2d %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf \n",

     &d, mon, &yr, &hr, &min, &s, &ticks, tmp, tmp+1, tmp+2, tmp+3, tmp+4, tmp+5, tmp+6, tmp+7, tmp+8, tmp+9, tmp+10, &vac_pres, &current, &argon_pres, &voltage, &heater, &ls331);
     //cout << counter<< " "  << d<< " "  << mon<< " "  << yr<< " "  << hr << " " << min << " " << s << " " << ticks << " " << tmp[0]<< endl; 
 cout << tmp[4] << " " << tmp[7] << endl;
 }
 

 fclose( fslow );
 
 return 0;
}









