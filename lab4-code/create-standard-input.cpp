#include"create-standard-input.h"
extern vector<input>inputs;
void readConfigFile()
{
	ifstream infile;
	infile.open("input/dir/stdin_format.txt", ios::in);
	if (!infile.is_open())
	{
		cout << "*** open file failed ***" << endl;
		return;
	}
	else
	{
		string tmp;
		while (getline(infile, tmp))
		{
			tmp += " ";
			int pos = 0;
			string token;
			while ((pos = tmp.find(" ")) != string::npos)
			{
				token = tmp.substr(0, pos);
				if (token[0] == 'i')//int(a,b): a<=value(int)<=b    int r = (rand() % (b - a + 1)) + a;
				{
					int a = 0;
					int b = 0;
					int la = token.find("(") + 1;
					int ra = token.find(",");
					a = stoi(token.substr(la, ra - la));
					//cout << a << endl;
					int lb = token.find(",") + 1;
					int rb = token.find(")");
					b = stoi(token.substr(lb, rb - lb));
					//cout << b << endl;
					input ii("int", a, b);
					inputs.push_back(ii);
				}
				else if (token[0] == 'c') //char: 随机大小写字母 
				{
					input cc("char", 0, 0);
					inputs.push_back(cc);
				}
				else if (token[0] == 's')//sring(a, b) : 由char组成，a <= length(string) <= b
				{
					int a = 0;
					int b = 0;
					int la = token.find("(") + 1;
					int ra = token.find(",");
					a = stoi(token.substr(la, ra - la));
					//cout << a << endl;
					int lb = token.find(",") + 1;
					int rb = token.find(")");
					b = stoi(token.substr(lb, rb - lb));
					//cout << b << endl;
					input ss("string", a, b);
					inputs.push_back(ss);
				}
				tmp.erase(0, pos + 1);
			}
		}
	}
	return;
}

char generateChar() 
{
	string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	return chars[rand() % chars.length()];
}
int generateInt(int a,int b)
{
	return (rand() % (b - a + 1)) + a;
}

string create()
{
	string out = "";
	
	for (int i = 0; i < inputs.size(); i++)
	{
		string tmp;
		if (inputs[i].type == "int")
		{
			int a = inputs[i].left;
			int b = inputs[i].right;
			int tt = generateInt(a, b);
			tmp = to_string(tt);
		}
		else if (inputs[i].type == "char")
		{
			tmp = generateChar();
		}
		else if (inputs[i].type == "string")
		{
			int a = inputs[i].left;
			int b = inputs[i].right;
			int length = generateInt(a, b);
			string tt = "";
			for (int i = 0; i < length; i++)
			{
				tt += generateChar();
			}
			tmp = tt;
		}
		if (i == 0)
		{
			out += tmp;
		}
		else
		{
			out += (" " + tmp);
		}
	}
	//cout << out << endl;
	return out;
}

void out()
{
	const int num = 10;
	for (size_t i = 0; i < num; i++)
	{
		string str = create();
		ofstream outfile;
		string filename = "OJinput/input" + to_string(i) + ".txt";
		outfile.open(filename, ios::out);
		outfile << str;
		outfile.close();
	}
	return;
}