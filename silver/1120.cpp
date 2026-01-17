#include <iostream>
#include <string>

using namespace std;

int main() {

	string A, B;

	cin >> A >> B; 
	
	int count = 0;

	if (A.size() == B.size()) {
		for (int i = 0; i < A.size(); i++) {
			if (A[i] != B[i]) {
				count++;
			}
		}
		cout << count << endl;

		return 0;
	}

	int mincount = 51;
	for (int i = 0; i <= B.size() - A.size(); i++) {
		count = 0;
		for (int j = 0; j < A.size(); j++) {
			if (A[j] != B[i+j]) {
				count++;
			}
		}
		mincount = min(mincount, count);
	}

	cout << mincount << endl;
	return 0;
}
