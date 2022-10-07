#include <iostream>
#include <vector>
#include <queue>
#include<stack>
#include<map>
#include <iterator>
#include <sstream>


pair<int, int> getMostFrequentNumber(vector<int> numbers)
{
	sort(numbers.begin(),numbers.end()); //----------- O(n log(n)) 
	int frequence = 1;
	int number = numbers[0];
	int counter = 1;
	for (int i = 1; i < numbers.size(); i++) {
		if (numbers[i - 1] != numbers[i]) {
			if (counter > frequence) {
				frequence = counter;
				number = numbers[i - 1];
			}
			counter = 0;
		}
		counter++;
	}//------------------------------------------------- O(n) 
	if (counter > frequence) {
		frequence = counter;
		number = numbers[numbers.size()-1];
	}
	return {number,frequence};//----------------------- O(n log(n)) 
}
