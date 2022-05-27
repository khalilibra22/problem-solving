#include <iostream>
#include <vector>
#include <queue>
#include<stack>
#include<map>
#include <iterator>
#include <sstream>

using namespace std;

bool isValidParentheses(string s) {

	if (s[0] == ')' || s[0] == '}' || s[0] == ']')
		return false;
	if (s[s.length() - 1] == '(' || s[s.length() - 1] == '{' || s[s.length() - 1] == '[')
		return false;
	stack<char> pile;


	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '{' || s[i] == '(' || s[i] == '[') pile.push(s[i]);
		else {
			if (pile.empty()) return false;
			if (s[i] == '}') {
				if (pile.top() == '{') {
					pile.pop();
				}
				else return false;
			}
			else if (s[i] == ')') {
				if (pile.top() == '(') {
					pile.pop();
				}
				else return false;
			}
			else if (s[i] == ']') {
				if (pile.top() == '[') {
					pile.pop();
				}
				else return false;
			}
		}
	}
	if (!pile.empty()) return false;
	return true;
}