#include <iostream>
#include <vector>
#include <queue>
#include<stack>
#include<map>
#include <iterator>
#include <sstream>

using namespace std;

string reverseLetters(string str) {
	string result = "";
	int l = 0; int r = str.length() - 1;
	while (l < r)
	{
		if (!(str[l] >= 'a' && str[l] <= 'z')) l++;
		else if (!(str[r] >= 'a' && str[r] <= 'z')) r--;
		else {
			swap(str[l], str[r]);
			l++;
			r--;
		}
	}
	result = str;
	return result;
}