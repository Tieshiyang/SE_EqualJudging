#include "OutputModule.h"
#include <iostream>
#include <fstream>
using namespace std;

DSU_FileOutput::DSU_FileOutput(int len,vector<string> paths ){
    dsu.resize(len,-1);
    FilePaths=paths;
  
}
int DSU_FileOutput::Find(int x){
    while(dsu[x]>=0){
        x = dsu[x];
    }
    return x;
}

void DSU_FileOutput::Union(int a, int b){
    int r1 = Find(a);
    int r2 = Find(b);
    int temp;
    if(r1 != r2){
        temp = dsu[r1] + dsu[r2];
        if (dsu[r2] < dsu[r1]) {
            dsu[r1] = r2;
            dsu[r2] = temp;
        }
        else {
            dsu[r2] = r1;
            dsu[r1] = temp;
        }
    }
}

void DSU_FileOutput::generate_input(string equal_path,string ineaual_path){
 
}