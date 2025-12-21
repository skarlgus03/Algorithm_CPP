#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main() {
	int N, M;

	cin >> N >> M;


	int MaxSize = min(N, M) - 1;
	int Bsize = 1;

// string vector for Square
	vector<string> Square(N);
	
	for (int i = 0; i < N; i++) {
		cin >> Square[i];
	}

// iterate k from the maximum side length downwards to find the largest square
	for (int k = MaxSize; k >= 1; k--) {
		for (int i = 0; i + k< N; i++) {
			for (int j = 0; j + k < M; j++) {
				if (Square[i][j] == Square[i][j + k]
					&& Square[i][j] == Square[i + k][j]
					&& Square[i][j] == Square[i + k][j + k]) {
					int size = (k + 1) * (k + 1);
					
					// The first square found is guaranteed to be the largest
					cout << size << endl;
					return 0;
				}
			}
		}
	}
  // if cannot find square, ouput '1'
	cout << Bsize;
	return 0;
}


