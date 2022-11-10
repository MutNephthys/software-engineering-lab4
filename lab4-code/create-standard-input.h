#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
void readConfigFile();
string create();
char generateChar();
int generateInt(int a, int b);
void out();
class input
{
public:
	string type;
	int left;
	int right;
	input(string type, int left, int right) {
		this->type = type;
		this->left = left;
		this->right = right;
	}

};
