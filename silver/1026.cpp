#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> A;
vector<int> B;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int sum = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		A.push_back(a);
	}
	for (int i = 0; i < N; i++) {
		int b;
		cin >> b;
		B.push_back(b);
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());

	for (int i = 0; i < N; i++) {
		sum += A[i] * B[i];
	}

	cout << sum;
	return 0;
}
