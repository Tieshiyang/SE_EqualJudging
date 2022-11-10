#ifndef INPUTMODULE_H
#define INPUTMODULE_H

#include <string>
#include <vector>
#include <string.h>
#include <vector>
using namespace std;

class InputModule
{
private:
   int oj_num;
   vector <vector<string>> file_names;
    vector <string> oj_names;
public:
    InputModule()=default;
    InputModule(string input_path);
    ~InputModule(){};
    int get_oj_num();
    vector<string> get_file_names(int idx);
    string get_oj_name(int idx);
};

#endif