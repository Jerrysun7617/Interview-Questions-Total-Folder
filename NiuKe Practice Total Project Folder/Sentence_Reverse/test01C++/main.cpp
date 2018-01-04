// VStest01.cpp : 定义控制台应用程序的入口点。
//
#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int main()
{
	string str, word;
	vector <string> split_str;
	int numi = 0;
	stack <string> s;
	while (numi++ < 20) {
		getline(cin, str);
		stringstream ss(str);
		while (ss >> word)
			s.push(word);

		while (!s.empty()) {
			word = s.top();
			 s.pop();
             cout<<word;
            if(s.size()>= 1)
                cout<<" ";
		}
		//cout << endl;
		ss.clear();
	}

	return 0;
}
