#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, M;

	cin >> N >> M;

	int minpackage = 1111;
	int mineach = 1111;

	for (int i = 0; i < M; i++) {
		int p, e;
		cin >> p >> e;
		minpackage = min(minpackage, p);
		mineach = min(mineach, e);
	}

	// Only buy packages
	int case1 = ((N + 5) / 6) * minpackage;
	
	// Only buy each
	int case2 = N * mineach;
	
	// buy package and each
	int case3 = (N / 6) * minpackage + (N % 6) * mineach;


	// min amoung three cases
	int result = min({ case1, case2, case3 });
	cout << result;
}


