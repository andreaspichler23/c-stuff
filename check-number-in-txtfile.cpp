#include <stdio.h>
#include <unistd.h>   
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdio>
#include <unistd.h>
#include <string>

using namespace std;

// g++ -o press-readout check-number-in-txtfile.cpp
// ./press-readout 


bool ReadSocketState(int socket_number){
 
  ifstream info_file;
  info_file.open("info.ini");
  string dummie;
  int line_number = socket_number * 3;
  bool socket_state;

  for(int i = 0; i < line_number; i++){

    getline(info_file, dummie);
    
  }

  size_t pos = dummie.find("-");   
  string bool_str = dummie.substr(pos); 

  int val_true = bool_str.compare("-TRUE");
  int val_false = bool_str.compare("-FALSE");

  if(val_true == 0) { socket_state = true; }
  else if(val_false == 0){ socket_state = false; }
  else{ cout << " THERE WAS AN ERROR " << endl;}

  //cout << bool_str << " " << socket_state  << " " << val_true << " " << val_false << endl;

  info_file.close();

  return socket_state;

}

int main(){
 
 
 ReadSocketState(1);
 
/*
  double pressure;


  ifstream press_file;
  press_file.open("test.dat");
  press_file >> pressure;
  

  ifstream sdd_file;

  if( access( "SDD_ON.txt", F_OK ) != -1 ) {

       cout << "file exists" << endl;

       if(pressure < 250) { cout << "everything OK. Do nothing!" << endl; }
       else{ remove("SDD_ON.txt");  cout << "removed file" << endl;}    
  
    } else {

       cout << "file does not exist" << endl;

       //if(pressure < 250){ ofstream outfile; }
      
  }

  
  

  
  outfile.open("SDD_ON.txt");


   cout << pressure << endl;
   sleep(1);


  press_file.close();
  //outfile.close();

*/
 
return 0;
}





