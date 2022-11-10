#ifndef RUN_PROGRAMS_H
#define RUN_PROGRAMS_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;
class ProgramsRunor
{
private:

    string oj_path;
    vector <string> ELFPaths;
    vector <string> ProgramNames;
    string output_path;
    string outputs_dir_name;
    string input_dir_name;
public:
    ProgramsRunor()=default;
    ProgramsRunor(string OJPath,vector <string> ProgramPaths,string indir_name,string outdir_name);
    ~ProgramsRunor(){cout<<"~ProgramsRunor"<<endl;};
    void Run(string inputs_path);
};

#endif
