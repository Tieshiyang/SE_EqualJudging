#include <iostream>
#include <fstream>
#include <unistd.h>
#include "creat_inputs.h"
#include "run_programs.h"
#include "judge.h"
#include "InputModule.h"
#include "OutputModule.h"


int main(){
//----------------------prepare files--------------------
    string indir_name = "input";
    string outdir_name = "outputs";
   system("mkdir output");
    ofstream eql_path = ofstream("output/equal.csv");
    ofstream ineql_path = ofstream("output/inequal.csv");
     ofstream abnml_path = ofstream("output/abnormal.csv");
     if(!eql_path.is_open()){
        cout << "output/equal.csv"<<" open fail" << endl;
        exit(-1);
    }
    if(!ineql_path.is_open()){
        cout << "output/inequal.csv"<<" open fail" << endl;
        exit(-1);
    }
     if(!abnml_path.is_open()){
        cout << "output/abnormal.csv"<<" open fail" << endl;
        exit(-1);
    }
    eql_path <<"file1,file2"<<endl;
    ineql_path <<"file1,file2"<<endl;
    abnml_path<<"file"<<endl;
 //----------------------prepare files--------------------


 //----------------------------------input------------------------------------
    InputModule file_in = InputModule("input");
//----------------------------------input------------------------------------


//****************************************for every "dir" ****************************************
    for(int i = 0;i<file_in.get_oj_num();i++){
        //---------------creat inputs------------------
        //file_in.file_names[i] is my FileInput Class
        string oj_path = file_in.get_oj_name(i);    //input/dir
        string stdin_path = oj_path+"/stdin_format.txt";    
        InputsCreator inputs_creator = InputsCreator(stdin_path, 30);
        inputs_creator.generate_inputs("inputs.txt");
        //---------------creat inputs------------------


         //--------------------------------------------------run--------------------------------------------------
         // print outputs in-> outputs/dir/1.txt   outputs/dir/2.txt ......
         ProgramsRunor runor = ProgramsRunor(oj_path,file_in.get_file_names(i),indir_name,outdir_name);
         runor.Run("inputs.txt");
         //--------------------------------------------------run--------------------------------------------------

        //---------------------------judge and get final output---------------------------
        Judger judger = Judger(file_in.get_file_names(i),indir_name,outdir_name);
        judger.judge_and_output("output/equal.csv","output/inequal.csv","output/abnormal.csv");
        //---------------------------judge and get final output---------------------------
    }
//***************************************for every "dir" ****************************************
         


   
   

    //judge ->  union
}