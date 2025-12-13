#include <iostream>
#include <vector>

using namespace std;

void Searching(int n, int m, int field[][50], int N, int M) {
	// Return if out of bounds
	if (n < 0 || m < 0 || n>= N || m >= M) return;
	// Return if empty
	if (field[n][m] == 0) {
		return;
	}
	// Mark as visited and recurse (DFS)
	else {
		field[n][m] = 0;
		Searching(n - 1, m, field, N,M);
		Searching(n + 1, m, field, N,M);
		Searching(n, m - 1, field, N,M);
		Searching(n, m + 1, field, N,M);
	}
}

int main() {

	int TestCase;
	cin >> TestCase;

	vector<int> result;
	result.reserve(TestCase);

	for (int i = 0; i < TestCase; i++) {
		int N, M, K;
		int field[50][50] = { 0 };
		int count = 0;
		
		cin >> N >> M >> K;

		// plant cabbages
		for (int j = 0; j < K; j++) {
			int kx, ky;
			cin >> kx >> ky;
			field[ky][kx] = 1;
		}

		for (int a = 0; a < N; a++) {
			for (int b = 0; b < M; b++) {
				if (field[a][b] == 1) {
					count++;
					Searching(a, b, field,N,M);
				}
			}
		}
		result.push_back(count);
	}
	
	for (const auto& item : result) {
		cout << item << "\n";
	}
}

