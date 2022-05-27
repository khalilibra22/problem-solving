#include <iostream>
#include <vector>
#include <queue>
#include<stack>
#include<map>
#include <iterator>
#include <sstream>

using namespace std;

char findExtraChar(string s1, string s2) {
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	for (int i = 0; i < s1.length(); i++) if (s1[i] != s2[i])  return s2[i];
	return s2[s2.length() - 1];
}