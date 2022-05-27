#include <iostream>
#include <vector>
#include <queue>
#include<stack>
#include<map>
#include <iterator>
#include <sstream>

using namespace std;

const vector<char> vowels = { 'a','e','i','o','u' };

vector<string> getVowelSubstrings(string str) {
	vector<string> result;
	bool isBeginVowel = false;
	for (int i = 0; i < str.length(); i++) {
		string tmp = "";
		isBeginVowel = false;
		for (int j = i; j < str.length(); j++) {
			if ((find(vowels.begin(), vowels.end(), str[j]) != vowels.end()) && !isBeginVowel) {
				string s = "";
				s += str[j];
				if(find(result.begin(), result.end(), s) == result.end())
					result.push_back(s);
				tmp += str[j];
				isBeginVowel = true;
			}
			else if ((find(vowels.begin(), vowels.end(), str[j]) != vowels.end()) && isBeginVowel) {
				string s = ""; 
				s+=str[j];
				if (find(result.begin(), result.end(), s) == result.end())
					result.push_back(s);
				tmp += str[j];
				if (find(result.begin(), result.end(), tmp) == result.end()) 
					result.push_back(tmp);
			}
			else if (isBeginVowel) tmp += str[j];
		}
	}
	sort(result.begin(), result.end());
	return result;
}

vector<string> getConsonantSubstrings(string str) {
	vector<string> result;
	bool isBeginConst = false;
	for (int i = 0; i < str.length(); i++) {
		string tmp = "";
		isBeginConst = false;
		for (int j = i; j < str.length(); j++) {
			if ((find(vowels.begin(), vowels.end(), str[j]) == vowels.end()) && !isBeginConst) {
				string s = "";
				s += str[j];
				if (find(result.begin(), result.end(), s) == result.end())
					result.push_back(s);
				tmp += str[j];
				isBeginConst = true;
			}
			else if ((find(vowels.begin(), vowels.end(), str[j]) == vowels.end()) && isBeginConst) {
				string s = "";
				s += str[j];
				if (find(result.begin(), result.end(), s) == result.end())
					result.push_back(s);
				tmp += str[j];
				if (find(result.begin(), result.end(), tmp) == result.end())
					result.push_back(tmp);
			}
			else if (isBeginConst) tmp += str[j];
		}
	}
	sort(result.begin(), result.end());
	return result;
}