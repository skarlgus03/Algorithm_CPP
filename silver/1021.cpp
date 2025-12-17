#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;


deque<int> dq;
vector<int> position;

// Rotate Deque
void rotateLeft() {
	dq.push_back(dq.front());
	dq.pop_front();
}
void rotateRight() {
	dq.push_front(dq.back());
	dq.pop_back();
}

int main() {

	int rollcount = 0;
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}

	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		position.push_back(a);
	}
	
	for (auto item : position) {
		// calculate 
		auto it = find(dq.begin(), dq.end(), item);
		int index = distance(dq.begin(), it);

		// if the target is closer to the back, calculate distance from the end and rotate right
		if (index > (dq.size() / 2)) {
			index = dq.size() - index;
			for (int j = 0; j < index; j++) {
				rotateRight();
				rollcount++;
			}
		}
		// Otherwise, rotate left
		else {
			for (int j = 0; j < index; j++) {
				rotateLeft();
				rollcount++;
			}
		}
		// 뽑기
		dq.pop_front();
	}

	cout << rollcount;

	return 0;
}
