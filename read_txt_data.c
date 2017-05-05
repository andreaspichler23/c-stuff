

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;




int main(){

  // for txt file: arr[94] is scintillator, arr[55] is sdd -> tdc channel 0 for sdd and 13 for scintillator
  // for bin file: bin_arr[96] is scintillator, bin_arr[57] is sdd -> - " -

  ifstream txt_file;
  ofstream outfile;
  txt_file.open("20150717_1040");
  outfile.open("sdd_out.txt");

  FILE *bin_file;
  bin_file = fopen("20150720_1523", "r");

 // int size=107;
  int size = 109; // changes from txt->bin, 109 is binary, i think because in text there is no header
  int bins=1000;
  double scaling_factor = 0.25;

  int arr[size];
  short bin_arr[size];
  int sdd1[bins];
  int sdd2[bins],sdd3[bins],sdd4[bins],sdd5[bins],sdd6[bins];
  int bin1,bin2,bin3,bin4,bin5,bin6;
 


for (int i = 0; i < bins; i ++){

     sdd1[i]=0;
     sdd2[i]=0;
     sdd3[i]=0;
     sdd4[i]=0;
     sdd5[i]=0;
     sdd6[i]=0;

} 

// reading a text file------------------------
/*

while(!txt_file.eof()){ 

  for (int i = 0; i < size; i++){

       arr[i]=0;

  }  

  for (int i = 0; i < size; i++){

       txt_file>>arr[i];

  }

  //if( arr[94] > 0) {cout << arr[36] << " " << arr[38] << " " << arr[39] << " " << arr[41] << " " << arr[42] << " " << arr[43] << endl;}
  //if( arr[55] > 0) {cout << arr[36] << " " << arr[38] << " " << arr[39] << " " << arr[41] << " " << arr[42] << " " << arr[43] << endl;}
  //if( arr[94] > 0) {outfile << arr[36] << " " << arr[38] << " " << arr[39] << " " << arr[41] << " " << arr[42] << " " << arr[43] << endl;}

   if( arr[94] > 0){ 

     bin1 = round(arr[36]*scaling_factor);
     sdd1[bin1]+=1;
     bin2 = round(arr[38]*scaling_factor);
     sdd2[bin2]+=1;
     bin3 = round(arr[39]*scaling_factor);
     sdd3[bin3]+=1;
     bin4 = round(arr[41]*scaling_factor);
     sdd4[bin4]+=1;
     bin5 = round(arr[42]*scaling_factor);
     sdd5[bin5]+=1;
     bin6 = round(arr[43]*scaling_factor);
     sdd6[bin6]+=1;

   }

  outfile << arr[94] << " " << arr[55] << endl;

}
*/

//----------------------------

// reading a binary file


//while (!feof(bin_file)){---------------------change back here
for (int j = 0; j < 5000; j++){

  for (int i = 0; i < size; i++){

       bin_arr[i]=0;

  }  

  for (int i = 0; i < size; i ++){

    fread(bin_arr+i,2,1,bin_file);
  
  }

 // if( bin_arr[96] > 0) {cout << bin_arr[38] << " " << bin_arr[40] << " " << bin_arr[41] << " " << bin_arr[43] << " " << bin_arr[44] << " " << bin_arr[45] << endl;}

   if( bin_arr[96] > 0){ 

     bin1 = round(bin_arr[38]*scaling_factor);
     sdd1[bin1]+=1;
     bin2 = round(bin_arr[40]*scaling_factor);
     sdd2[bin2]+=1;
     bin3 = round(bin_arr[41]*scaling_factor);
     sdd3[bin3]+=1;
     bin4 = round(bin_arr[43]*scaling_factor);
     sdd4[bin4]+=1;
     bin5 = round(bin_arr[44]*scaling_factor);
     sdd5[bin5]+=1;
     bin6 = round(bin_arr[45]*scaling_factor);
     sdd6[bin6]+=1;

   }

   

 // outfile << bin_arr[96] << " " << bin_arr[57] << endl;

}




for (int i = 0; i < bins; i ++){

     outfile<<sdd1[i]<< " "<<sdd2[i]<< " "<<sdd3[i]<< " "<<sdd4[i]<< " "<<sdd5[i]<< " "<<sdd6[i]<< " "<<endl;

}

  

  txt_file.close();
  outfile.close();
  fclose(bin_file);

 

return 0;
}





