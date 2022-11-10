#include <dirent.h>
#include "tool.h"
#include <iostream>
#include <string.h>
using namespace std;
void GetFileNames(string path,vector<string>& filenames)
{
    DIR *pDir;
    struct dirent* ptr;
    if(!(pDir = opendir(path.c_str()))){
        cout<<"Folder doesn't Exist!"<<endl;
        return;
    }
    while((ptr = readdir(pDir))!=0) {
        if (strcmp(ptr->d_name, ".") != 0 && strcmp(ptr->d_name, "..") != 0  && (((string)ptr->d_name).find(".") == -1  || ((string)ptr->d_name).find(".cpp") != -1)){
            filenames.push_back(path + "/" + ptr->d_name);
    }
    }
    closedir(pDir);
}

string replace_all(string str, const string strold, const string strvalue)
{
	while (true) {
		string::size_type pos(0);
		if ((pos = str.find(strold)) != string::npos) //"string::npos"means find failed
			str.replace(pos, strold.length(), strvalue);
		else break;
	}
	//std::cout << str<<std::endl;
	return str;
}

