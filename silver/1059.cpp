#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int L;
	cin >> L;

	vector<int> numbers;
	for (int i = 0; i < L; i++) {
		int a;
		cin >> a;
		numbers.push_back(a);
	}
	sort(numbers.begin(), numbers.end());


	int n;
	cin >> n;
	int min = 0, max = 0;

	for (int i = 0; i < L; i++) {
		if (numbers[i] == n) {
			cout << "0";
			return 0;
		}
		if (numbers[i] > n) {
			max = numbers[i];
			if (i != 0) {
				min = numbers[i - 1];
			}
			break;
		}
	}

	int temp = n - min - 1;
	int temp2 = max - n;
	cout << temp * temp2 + (temp2 - 1);
}
