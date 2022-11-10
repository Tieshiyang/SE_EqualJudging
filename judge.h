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
public:
    Judger()=default;
    Judger(vector<string>paths);
    ~Judger(){cout<<"~Judger"<<endl;};
    // send to cequre
    DSU_FileOutput judge_and_output(string equal_path,string inequal_path,string abnormal_path);

};
