#include "creat_inputs.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "tool.h"
using namespace std;


InputsCreator::InputsCreator(string input_direction, int group_num){
	inputs_group_num = group_num;
	ifstream infile;
	infile.open(input_direction, ios::in);
	if (!infile.is_open()){
		cout << "Open infile Fail" << endl;
		return;
	}
	string parameter = "";
	int num = 0;
	while (infile >> parameter){
		parameters.push_back(parameter);
		parameter = "";
		num++;
	}
	inputs_num = num;
	
	output_dirction = replace_all(input_direction, "input", "outputs");
	output_dirction = replace_all(output_dirction, "stdin_format.txt", "");
	infile.close();
}
void InputsCreator::generate_inputs(string inputs_path){
	ofstream outfile(inputs_path);
	if (!outfile.is_open()){
		cout << "Open outfile Fail" << endl;
		return;
	}
	//set time as the seed
	srand((unsigned)time(0));
	char chars[26+26];
	int i, j, k, n;
	for (i=0; i<26; chars[i]='A'+i, i++);
	for (j=0; j<26; chars[i]='a'+j, i++, j++);
	for (int k = 0; k < inputs_group_num; k++){
		for (int i = 0; i < inputs_num; i++){
			if (parameters[i].find("int") != -1){
				//input(a,b)
				int int_min = stoi(parameters[i].substr(parameters[i].find("(") + 1, parameters[i].find(",") - parameters[i].find("(") - 1));
				int int_max = stoi(parameters[i].substr(parameters[i].find(",") + 1, parameters[i].find(")") - parameters[i].find(",") - 1));
				outfile << (rand() % (int_max - int_min + 1)) + int_min << " ";
			}
			else if (parameters[i].find("char") != -1){
				//char
				outfile << chars[rand() % 52] << " ";

			}
			else{
				//string(a,b)
				int len_min = stoi(parameters[i].substr(parameters[i].find("(") + 1, parameters[i].find(",") - parameters[i].find("(") - 1));
				int len_max = stoi(parameters[i].substr(parameters[i].find(",") + 1, parameters[i].find(")") - parameters[i].find(",") - 1));
				int len = (rand() % (len_max - len_min + 1)) + len_min;
				for (int i = 0; i < len; i++){
					outfile << chars[rand() % 52];
				}
				outfile << " ";
			}

		}
		outfile << '\n';
	}
	outfile.close();
}
