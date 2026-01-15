#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {

	int X;
	cin >> X;

	vector<int> sticks{ 64 };
	while (X < accumulate(sticks.begin(), sticks.end(), 0)) {

		sort(sticks.begin(), sticks.end());

		int shortest_half = sticks[0] / 2;
		sticks[0] = shortest_half;

		if (X > accumulate(sticks.begin(), sticks.end(), 0)) {
			sticks.push_back(shortest_half);
		}
	}
	
	cout << sticks.size();

	return 0;
}
