#include <iostream>
#include <vector>
#include <queue>
#include<stack>
#include<map>
#include <iterator>
#include <sstream>

using namespace std;

int maximumSeating(vector<int> arr) {
	int cp = 0;
	if (arr.size() == 1) {
		if (arr[0] == 0) return 1;
		else return 0;
	}
	if (arr.size() == 2) {
		if (arr[0] == 1 || arr[1] == 1) return 0;
		else return 1;
	}
	if (arr[0] == 0) {
		if (arr[1] == 0 && arr[2] == 0) {
			cp++;
			arr[0] = 1;
		}
	}
	if (arr[arr.size()-1] == 0) {
		if (arr[arr.size() - 2] == 0 && arr[arr.size() - 3] == 0) {
			cp++;
			arr[arr.size() - 1] = 1;
		}
	}
	for (int i = 3; i < arr.size()-2; i++) {
		if (arr[i] == 0) {
			if ((i + 1 < arr.size() && arr[i + 1] == 0) && (i + 2 < arr.size() && arr[i + 2] == 0)) {
				if ((i - 1 >= 0 && arr[i - 1] == 0) && (i - 2 >= 0 && arr[i - 2] == 0)) {
					cp++;
					arr[i] = 1;
				}
			}
			
		}
	}
	return cp;
}