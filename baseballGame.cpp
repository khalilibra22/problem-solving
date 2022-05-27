#include <iostream>
#include <vector>
#include <queue>
#include<stack>
#include<map>
#include <iterator>
#include <sstream>

using namespace std;

int baseballGame(vector<string> ops) {
	int sum = 0;
	vector<int> v;
	for (int i = 0; i < ops.size(); i++) {
		if (ops[i] != "C" && ops[i] != "D" && ops[i] != "+") {
			int num;
			stringstream ss;
			ss << ops[i];
			ss >> num;
			v.push_back(num);
		}
		else {
			if (ops[i] == "C") v.pop_back();
			else if (ops[i] == "D") {
				int n = v[v.size() - 1];
				v.push_back(n * 2);
			}
			else if (ops[i] == "+") {
				int a = v[v.size() - 1];
				int b = v[v.size() - 2];
				v.push_back(a + b);
			}
		}
	}
	for (int i = 0; i < v.size(); i++) sum += v[i];
	return sum;
}