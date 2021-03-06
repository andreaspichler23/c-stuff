#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
//#include <chrono>
//#include <thread>
#include <unistd.h>    


//g++ -Wall  ExeCalibMacro.C  -o ExeCalibMacro
// ./ExeCalibMacro

using namespace std;

int main(){
    
    string fileName;
    //string rootFilePath = "/home/andreas/vip2/data/root/LNGS/test/";
    string rootFileName;
    string finalString;
    string smallQuote = "'";
    string bigQuote = "\"";
    string firstPart = "root -q -b 'CalibMacro.C(";
    string Comma = ",";
    string sddString;
    string adcString;
    string lastPart = ",\"TiMnCu\",\"lngs\")'";
    
    stringstream adcSS, sddSS;
    ifstream fileList;
    int adcChannelList[6] = {0,2,3,5,6,7};
    int adcChannel;
    int startFileNumber = 172;
    int endFileNumber = 618;
    int fileNumber;
    
    
    fileList.open("/home/andreas/vip2/filelist/1-618Files-LNGS.txt");
    
  for( int j = 1; j <= endFileNumber; j++ ){
    
    fileList >> fileName;
    rootFileName = fileName + ".root";
    fileNumber = atoi(rootFileName.c_str());
    cout << fileNumber << endl;
    
    if ( fileNumber < startFileNumber ){ continue; }
    //cout << fileNumber << endl;
    
    
    for( int sdd = 1; sdd < 7; sdd++ ){
        
        adcChannel = adcChannelList[sdd-1];
        adcSS << adcChannel;
        adcString = adcSS.str();
        
        sddSS << sdd;
        sddString = sddSS.str();
        
        finalString = firstPart + sddString + Comma + adcString + Comma + bigQuote + rootFileName + bigQuote + lastPart;
        system(finalString.c_str());
       
        
        adcSS.str("");
        sddSS.str("");
        
    }
    
   

  }
    
    fileList.close();
    return 0;
    
}