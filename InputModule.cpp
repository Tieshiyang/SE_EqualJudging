#include <iostream>
#include "InputModule.h"
#include "tool.h"
using namespace std;

InputModule::InputModule(string input_path){
    GetFileNames(input_path,oj_names);
    oj_num = oj_names.size();
    file_names.resize(oj_num);
    for(int i = 0;i < oj_num; i++){
        system(("rm "+oj_names[i]+"/*.out").c_str());
        //get all .cpp files into file_nams
        GetFileNames(oj_names[i],file_names[i]);
    }
}

int InputModule::get_oj_num(){
    return oj_num;
}
vector<string> InputModule::get_file_names(int idx){
    return file_names[idx];
}
string InputModule::get_oj_name(int idx){
    return oj_names[idx];
}