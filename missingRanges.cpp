#include <iostream>
#include <vector>
#include <queue>
#include<stack>
#include<map>
#include <iterator>
#include <sstream>

using namespace std;

vector<int> missingRanges(vector<int> arr, int low, int high) {

	vector<int> result;
	for (int i = low; i < high+1; i++) {
		if (find(arr.begin(), arr.end(), i) == arr.end())
			result.push_back(i);
	}

	return result;
}