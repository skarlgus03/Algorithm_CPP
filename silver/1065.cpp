#include <iostream>
#include <string>

using namespace std;

int main() {

	int N;
	cin >> N;

	
	if (N < 100) {
		cout << N;
	}
	else {
		int count = 99;

		for (int i = 100; i <= N; i++) {

			if (i == 1000) break;

			string str = to_string(i);

			int item = str[0] - '0';
			int item2 = str[1] - '0';
			int item3 = str[2] - '0';
			
			if ((item2 - item) == (item3 - item2)) {
				count++;
			}
		}

		cout << count;
	}

	return 0;
}
