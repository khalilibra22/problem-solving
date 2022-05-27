#include <iostream>
#include <vector>
#include <queue>
#include<stack>
#include<map>
#include <iterator>
#include <sstream>

using namespace std;

vector<int> findErrorsNums(vector<int> nums) {
	
	if (nums[0] != 1) return { 1, nums[0] };
	vector<int> result;
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i - 1] + 1 != nums[i]) {
			result = { nums[i] ,nums[i - 1] + 1 };
		}
	}

	return result;
}