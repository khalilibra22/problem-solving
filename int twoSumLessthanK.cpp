#include <iostream>
#include <vector>
#include <queue>
#include<stack>
#include<map>
#include <iterator>
#include <sstream>

using namespace std;

int twoSumLessthanK(vector<int> a, int k) {
	int maxSum = -1;
	for (int i = 0; i < a.size()-1; i++) {
		for (int j = i + 1; j < a.size(); j++) {
			int s = a[i] + a[j];
			if (s < k && s > maxSum) maxSum = s;
		}
	}
	return maxSum;
}