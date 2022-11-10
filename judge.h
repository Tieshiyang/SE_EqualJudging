#ifndef JUDGE_H
#define JUDGE_H

#include "tool.h"
#include "OutputModule.h"
using namespace std;
class Judger
{
private:
    int FileNum;
    vector <string> ProgramPaths;
    vector <string> OutpusPaths;
    DSU_FileOutput dsu_files;
    string input_dir_name;
    string output_dir_name;
public:
    Judger()=default;
    Judger(vector<string>paths,string indir_name,string outdir_name);
    ~Judger(){cout<<"~Judger"<<endl;};
    // send to cequre
    DSU_FileOutput judge_and_output(string equal_path,string inequal_path,string abnormal_path);

};

#endif
