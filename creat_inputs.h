#ifndef CREAT_INPUTS_H
#define CREAT_INPUTS_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;
class InputsCreator{
public:
	InputsCreator()=default;
	InputsCreator(string input_direction, int group_num = 30);
	~InputsCreator() {cout<<"~InputsCreator"<<endl;};
	void generate_inputs(string inputs_path);

private:
	int inputs_num;
	int inputs_group_num;
	string output_dirction;
	vector <string> parameters;
};
#endif
