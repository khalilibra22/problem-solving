#include <iostream>
#include <vector>
#include <queue>
#include<stack>
#include<map>
#include <iterator>
#include <sstream>

using namespace std;

int determineWinner(string player1, string player2) {
	vector<string> hand1;
	vector<string> hand2;
	string s = "";
	for (int i = 0; i < player1.length(); i++) {
		if(player1[i] != ' ') s += player1[i];
		else
		{
			hand1.push_back(s);
			s = "";
		}
	}
	hand1.push_back(s);
	s = "";

	for (int i = 0; i < player2.length(); i++) {
		if (player2[i] != ' ') s += player2[i];
		else
		{
			hand2.push_back(s);
			s = "";
		}
	}
	hand2.push_back(s);
	s = "";
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < hand1.size(); i++) {
		string str = hand1[i];
		sum1 += ((int)str[0] * (int)str[1]);
	}
	for (int i = 0; i < hand2.size(); i++) {
		string str = hand2[i];
		sum2 += ((int)str[0] * (int)str[1]);
	}
	cout << "S1 : " << sum1 << " S2: " << sum2 << endl;
	if (sum1 > sum2) return 1;
	else return 2;

}