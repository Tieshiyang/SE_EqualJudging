#include "run_programs.h"
#include <vector>
#include <iostream>
#include "tool.h"
using namespace std;
ProgramsRunor::ProgramsRunor(string OJPath,vector <string> ProgramPaths,string indir_name,string outdir_name){
    oj_path= OJPath;
    input_dir_name = indir_name;
    outputs_dir_name = outdir_name;
    output_path = replace_all(OJPath,indir_name,outdir_name);
    system(("mkdir "+outdir_name).c_str());
    system(("mkdir "+output_path).c_str());
    for(int i = 0;i < ProgramPaths.size();i++){
        //CPPName  = a.cpp
        string CPPName = ProgramPaths[i].substr(OJPath.size() + 1);
        //ProgramName  =  a
        string ProgramName = CPPName.substr(0,CPPName.size()-4);
        ProgramNames.push_back(ProgramName);
        //ELFPath = input/dir/a.out
        string ELFPath = OJPath + "/" + ProgramName +".out";
        ELFPaths.push_back(ELFPath);
        system(("g++ -O2 "+ProgramPaths[i] +" -w 2>" + output_path + "/" +ProgramName + "_error.txt" + " -o " + ELFPath ).c_str());
    }
}

void ProgramsRunor::Run(string inputs_path){
    system(("rm "+output_path + "/*_out.txt").c_str());
    for(int i = 0;i<ELFPaths.size();i++){
        string command = "cat "+ inputs_path + " | while read line ; do echo $line|./"+ELFPaths[i] +" 1>>"+output_path + "/" +ProgramNames[i] + "_out.txt ; echo  \"\n***LINE***\"" + " >>" +output_path + "/" +ProgramNames[i] + "_out.txt; done";
        system(command.c_str());
    }
}
    
