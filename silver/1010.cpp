#include <iostream>
#include <vector>

using namespace std;

long long C[31][31];

int main() {


	// Use Pascal's triangle for precomputation.
	for (int i = 0; i <= 30; i++) {
		C[i][0] = C[i][i] = 1;
		for (int r = 1; r < i; r++) {
			C[i][r] = C[i-1][r - 1] + C[i-1][r];
		}
	}

	int TestCase;
	cin >> TestCase;
	vector<int> result;

	for (int i = 0; i < TestCase; i++) {
		int N, M;
		cin >> N >> M;
		result.push_back(C[M][N]);
	}

	for (const auto& item : result) {
		cout << item << "\n";
	}
}
