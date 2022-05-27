#include <iostream>
#include <vector>
#include <queue>
#include<stack>
#include<map>
#include <iterator>
#include <sstream>

using namespace std;

string actualMemorySize(string ms) {
	const vector<char>nums = {'0','1','2','3','4','5','6','7','8','9'};
	string memoSize = "";
	string unite = "";
	const float loss = 0.07;
	for (int i = 0; i < ms.length(); i++) {
		if (find(nums.begin(), nums.end(), ms[i]) != nums.end()) {
			memoSize += ms[i];
		}
		else unite += ms[i];
	}
	float n;
	stringstream ss;
	ss << memoSize;
	ss >> n;
	n = n - (n * loss);
	if (unite == "MB") n = (int)n;
	if (n < 1) {
		n *= 1000;
		unite = "MB";
	}
	
	stringstream ss1;
	ss1 << n;
	ss1 >> memoSize;
	return (memoSize + unite);
}
