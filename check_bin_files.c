#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;


int main(){

  FILE *datafile;
  datafile = fopen("/home/andreas/vip2/data/bin/SMI/20151006_1220", "r"); // 1132,1220

  short dummyword;
  int word_count = 0;
  int module_count = 0;
  int line_count = 0;


  while (!feof(datafile)){

    //cout << "test" << endl;
    fread(&dummyword, sizeof(dummyword), 1, datafile);

    //cout << dummyword << endl;

    if (dummyword == -1){
       
       module_count += 1;

       if (word_count != 38 && word_count != 18 && word_count != 51 ){cout << line_count << " " << word_count << endl;}

       if (module_count == 3){

          //cout << word_count << endl;
          line_count += 1;
          module_count = 0;
 
       }

       //else {cout << word_count << " ";}
       
       
       word_count = 0;
       
    }
    else {

      word_count += 1; 

    }

  }

  //cout << word_count << endl;
  cout << line_count << " " << word_count << endl;

  fclose(datafile);


return 0;

}
