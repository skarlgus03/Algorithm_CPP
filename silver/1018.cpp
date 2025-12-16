#include <iostream>
#include <vector>

using namespace std;


// Constant for the fixed window size (8x8)
const int WSize = 8;

vector<string> Chessboard;
// Pre-defined reference patterns for even/odd rows (White-start vs Black-start)
vector<string> Window = { "WBWBWBWB", "BWBWBWBW" };

// Calculates the Hammin distance between two strings
int CompareString(string s1,string s2, int size) {
	int diff = 0;

	for (int i = 0; i < size; i++) {
		if (s1[i] != s2[i]) diff++;
	}
	return diff;
}

// Scans the entire board using a Sliding Window approach
// Finds the minimum number of repaints required
void ScanBoard(vector<string> board, int N, int M) {

	int mincount = 20030226;
	for (int i = 0; i <= N - WSize; i++) {
		for (int j = 0; j <= M - WSize; j++) {
			// Check the current 8x8 window
			int count = 0;
			for (int a = 0; a < WSize; a++) {
				count += CompareString(board[i + a].substr(j, WSize), Window[a % 2], WSize);
			}
      // The cost for the opposite pattern (Black-start) is simply (Total Cells - Current count)
			int reverseCount = 64 - count;
			mincount = min(mincount, min(count, reverseCount));
		}
	}
	cout << mincount;
}

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		Chessboard.push_back(str);
	}

	ScanBoard(Chessboard, N, M);
}
