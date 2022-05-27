#include <iostream>
#include <vector>
#include <queue>
#include<stack>
#include<map>
#include <iterator>
#include <sstream>

using namespace std;

string toBinaryCode(int n) {
	if (n == 0) return "0";
	string result;
	int q = n;
	int r = 0;
	do {
		q = n / 2;
		r = n % 2;
		n = q;
		string sr;
		stringstream ss;
		ss << r;
		ss >> sr;
		result = sr + result;
	} while (n != 1);
	return ("1"+result);
}

string replaceNums(string str) {
	const vector<char>nums = {'0','1','2','3','4','5','6','7','8','9'};
	string s = "";
	string num = "";
	for (int i = 0; i < str.length(); i++) {
		if (find(nums.begin(), nums.end(), str[i]) != nums.end()) {
			num += str[i];
			if ((i + 1) < str.length() && (find(nums.begin(), nums.end(), str[i + 1]) == nums.end())) {
				int n;
				stringstream ss;
				ss << num;
				ss >> n;
				string binNum = toBinaryCode(n);
				s += binNum;
				num = "";
			}
		}
		else s += str[i];
	}
	if (num != "") {
		int n;
		stringstream ss;
		ss << num;
		ss >> n;
		string binNum = toBinaryCode(n);
		s += binNum;
	}
	return s;
 }
