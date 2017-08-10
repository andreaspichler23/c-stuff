#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
//#include <chrono>
//#include <thread>
#include <unistd.h> 

//g++ -Wall  00_mergeMacro.C  -o 00_mergeMacro
// ./00_mergeMacro
using namespace std;

int main(){
    
    
    ifstream fileList;
    string fileName, rootFileName, finalString;
    string firstPart = "hadd /home/andreas/vip2/data/root/LNGS/1-618files-final/withCurrent.root";
    string withString = "with";
    int maxFileNumber = 618;
    
    
    fileList.open("/home/andreas/vip2/filelist/1-618Files-LNGS.txt");
    finalString = firstPart;
    
    
    for( int fileNumber = 1; fileNumber <= maxFileNumber ; fileNumber++){
        
        fileList >> fileName;
        rootFileName = fileName + ".root";
        
        if( rootFileName.find(withString) != string::npos ){ 
        
            finalString = finalString + " " + rootFileName;
            
        }
        
        
    }
    
    //cout << finalString << endl;
    
    system(finalString.c_str());
    //system("-f hadd final.root 3noCurrent.root");
    
    fileList.close();
    
    return 0;
    
    
}