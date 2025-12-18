#include <iostream>

using namespace std;


void Findx(int N, int L) {

// Loop
	for (; L <= 100; L++) {
		int temp = N - (L * (L - 1)) / 2;
    
    // in this case, break loop
		if (temp < 0) break;
		
		// when remain is zero
		if (temp % L == 0) {
			int x = temp / L;
			
			// output
			for (int i = 0; i < L; i++) {
				cout << x + i << " ";
			}
			return;
		}
	}
	// if can't find x, output -1
	cout << -1;
}

int main() {

	int N, L;
	cin >> N >> L;
	Findx(N, L);
	return 0;
}
