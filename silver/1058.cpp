#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int buddy[50][50] = {0};

int main() {
	
	int N;
	cin >> N;

  // Adjacency Matrix 
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < N; j++) {
			if (temp[j] == 'Y') {
				buddy[i][j] = 1;
			}
		}
	}

	int count = 0;
	for (int i = 0; i < N; i++) {
		set<int> friends;
		for (int j = 0; j < N; j++) {
			if (buddy[i][j] == 1) {
				friends.insert(j);
				for (int a = 0; a < N; a++) {
					if (buddy[j][a] == 1 && a != i) friends.insert(a);
				}
			}
		}
		count = max(count, (int)friends.size());
	}

	cout << count;
}
