#include <iostream>
#include <string>

using namespace std;

int main() {

	string L, R;

	cin >> L >> R;

	// 자리수 비교
	if (L.size() != R.size()) {
		cout << '0' << endl;
		return 0;
	}

	int count = 0;
	for (int i = 0; i < L.size(); i++) {
	
		// 두 수가 다르면 반복문 종료
		if (L[i] != R[i]) {
			break;
		}
		// 8의 개수 세기
		if (L[i] == '8') {
			count++;
		}

	}
	cout << count;

	return 0;
}
