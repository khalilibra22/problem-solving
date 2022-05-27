#include <iostream>
#include <vector>
#include <queue>
#include<stack>
#include<map>
#include <iterator>
#include <sstream>

using namespace std;

bool canEnterCave(vector<vector<int>> x) {

	queue<pair<int, int>> file;
	vector<pair<int, int>>visited;
	pair<int, int> start;
	for (int i = 0; i < x.size(); i++) {
		if (x[0][i] == 0) {
			start.first = 0;
			start.second = i;
			break;
		}
	}
	file.push(pair<int, int>(start.first, start.second));
	while (!file.empty()) {
		pair<int, int> p = file.front();
		file.pop();
		visited.push_back(p);
		if (p.second == (x[0].size() - 1)) return true;
		if ((p.first + 1 < x.size()) && (x[p.first + 1][p.second] == 0)) {
			if (find(visited.begin(), visited.end(), pair<int, int>(p.first + 1, p.second)) == visited.end())
				file.push(pair<int, int>(p.first + 1, p.second));
		}
		if ((p.first - 1 >= 0) && (x[p.first - 1][p.second] == 0)) {
			if (find(visited.begin(), visited.end(), pair<int, int>(p.first - 1, p.second)) == visited.end())
				file.push(pair<int, int>(p.first - 1, p.second));
		}
		if ((p.second + 1 < x[0].size()) && (x[p.first][p.second + 1] == 0)) {
			if (find(visited.begin(), visited.end(), pair<int, int>(p.first, p.second + 1)) == visited.end())
				file.push(pair<int, int>(p.first, p.second + 1));
		}
		if ((p.second - 1 >= 0) && (x[p.first][p.second - 1] == 0)) {
			if (find(visited.begin(), visited.end(), pair<int, int>(p.first, p.second - 1)) == visited.end())
				file.push(pair<int, int>(p.first, p.second - 1));
		}
	}
	return false;
}