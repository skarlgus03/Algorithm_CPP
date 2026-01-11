#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int N, M;

int Am[50][50] = { 0 };
int Bm[50][50] = { 0 };

void changeMatrix(int row, int col) {
	for (int i = row; i < row + 3; i++) {
		for (int j = col; j < col + 3; j++) {
			Am[i][j] ^= 1;
		}
	}
}

bool isSame() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Am[i][j] != Bm[i][j]) return false;
		}
	}
	return true;
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < M; j++) {
			Am[i][j] = row[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < M; j++) {
			Bm[i][j] = row[j] - '0';
		}
	}

	int count = 0;
	for (int i = 0; i <= N - 3; i++) {
		for (int j = 0; j <= M - 3; j++) {
			if (Am[i][j] != Bm[i][j]) {
				changeMatrix(i, j);
				count++;
			}
		}
	}

	if (isSame()) {
		cout << count << endl;
	}
	else {
		cout << -1 << endl;
	}

	return 0;
}
