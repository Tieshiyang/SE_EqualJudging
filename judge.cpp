#include "judge.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

Judger::Judger(vector<string>paths,string indir_name,string outdir_name){
    FileNum = paths.size();
    ProgramPaths = paths;
    input_dir_name =indir_name;
    output_dir_name = outdir_name;
    for(int i = 0;i<FileNum;i++){
        string outspath =replace_all(paths[i],indir_name,outdir_name);
        outspath = replace_all(outspath,".cpp","_out.txt");
        OutpusPaths.push_back(outspath);
    }
    dsu_files = DSU_FileOutput(paths.size(),paths);
}

DSU_FileOutput Judger::judge_and_output(string equal_path,string inequal_path,string abnormal_path){
    ofstream eql_path = ofstream(equal_path,ios::app);
    ofstream ineql_path = ofstream(inequal_path,ios::app);
    ofstream abnml_path = ofstream(abnormal_path,ios::app);
    if(!eql_path.is_open()){
        cout << equal_path<<" open fail" << endl;
        exit(-1);
    }
    if(!ineql_path.is_open()){
        cout << inequal_path<<" open fail" << endl;
        exit(-1);
    }
    for(int i =0;i<ProgramPaths.size();i++){
        //error
         ifstream error_file1;
         string error_file1_path = replace_all(OutpusPaths[i],"_out.txt","_error.txt");
         error_file1.open(error_file1_path);
          if(!error_file1.is_open()){
             cout << error_file1_path<<" open fail" << endl;
             exit(-1);
            }
        string error_line;
        if(error_file1>>error_line){
                abnml_path<<ProgramPaths[i]<<endl;
                continue;
        }

        for(int j =i+1; j<ProgramPaths.size();j++){
            //error
            ifstream error_file2;
            string error_file2_path = replace_all(OutpusPaths[j],"_out.txt","_error.txt");
            error_file2.open(error_file2_path);
            if(!error_file2.is_open()){
                cout << error_file2_path<<" open fail" << endl;
                exit(-1);
                }
            if(error_file2>>error_line){
                    //abnml_path<<ProgramPaths[j]<<endl;
                    //repeat!!!!
                    continue;
            }

            int r1 = dsu_files.Find(i);
            int r2 = dsu_files.Find(j);
            if(r1 == r2){
                //equal
                eql_path<<ProgramPaths[i]<<","<<ProgramPaths[j]<<endl;
            }
            else{
                ifstream file1,file2;
                file1.open(OutpusPaths[i]);
                file2.open(OutpusPaths[j]);
                if(!file1.is_open()){
                    cout << OutpusPaths[i]<<" open fail" << endl;
                    exit(-1);
                }
                if(!file2.is_open()){
                    cout << OutpusPaths[j]<<" open fail" << endl;
                    exit(-1);
                }
                
                string line1,line2;
                int out1,out2;
                int equal_flag = 1;
                while(true){
                    if (!getline(file1, line1, '\n')){
                        line1="";
                        out1 = 1;
                    };
                    if (!getline(file2, line2, '\n')){
                        line2="";
                        out2 = 1;
                    };
                    if(line1 != line2){
                        ineql_path<<ProgramPaths[i]<<","<<ProgramPaths[j]<<endl;      
                        equal_flag = 0;
                        break;
                    }
                    if (out1 && out2){
                        break;
                    }
                }
                if(equal_flag){
                    eql_path<<ProgramPaths[i]<<","<<ProgramPaths[j]<<endl;      
                    dsu_files.Union(i,j);         
                }
               
                file1.close();
                file2.close();    
            }
        }
    }

    eql_path.close();
    ineql_path.close();
    return dsu_files;
}   

