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
public:
    ProgramsRunor()=default;
    ProgramsRunor(string OJPath,vector <string> ProgramPaths);
    ~ProgramsRunor(){cout<<"~ProgramsRunor"<<endl;};
    void Run(string inputs_path);
};
