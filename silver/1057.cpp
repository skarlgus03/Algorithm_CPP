#include <iostream>

using namespace std;


int main() {
	int N, Kim, Im;
	cin >> N >> Kim >> Im;

	// XOR
	int diff = (Kim - 1) ^ (Im - 1);

	int round = 0;
	while (diff > 0) {
		diff >>= 1;
		round++;
	}
	// find LCA

	cout << round;
}
