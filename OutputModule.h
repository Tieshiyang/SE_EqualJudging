#ifndef OUTPUTMODULE_H
#define OUTPUTMODULE_H
#include <iostream>
#include "tool.h"
using namespace std;

class DSU_FileOutput
{
private:
    vector <int> dsu;
    vector <string> FilePaths;
public:
    DSU_FileOutput()=default;
    DSU_FileOutput(int len,vector<string> paths);
    ~DSU_FileOutput(){cout<<FilePaths[0]<<"~DSU_FileOutput"<<endl;};
    int Find(int x);
    void Union(int a,int b); 
    void generate_input(string equal_path,string ineaual_path);   
};






#endif