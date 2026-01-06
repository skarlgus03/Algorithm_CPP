#include <iostream>

using namespace std;

int main() {

	long long X, Y;
	cin >> X >> Y;

	long long Z = (Y * 100) / X;

	if (Z >= 99) {
		cout << "-1" << endl;
		return 0;
	}

	long long low = 0, high = 1000000000;
	long long result = -1;

	while (low <= high) {
		long long mid = (low + high) / 2;
		long long nextZ = ((Y + mid) * 100) / (X + mid);

		if (nextZ > Z) {
			result = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	cout << result;
	return 0;
}
