#include <iostream>
#include <vector>

using namespace std;

void checkarray(vector<int> array,int length) {

	vector<int> Parray(length);

	for (int i = 0; i < length; i++) {
		int minindex = -1;

    // Find the first valid element to initialize minindex
		for (int j = 0; j < length; j++) {
			if (array[j] != 1001) {
				minindex = j;         
				break;
			}
		}

		if (minindex == -1) break; // Safety Check

	  // Iterate through the array to find the actual minimum value among valid element
		for (int j = 0; j < length; j++) {
			if (array[j] != 1001 && array[j] < array[minindex]) { 
				minindex = j;
			}
		}
		// Mark the found minimum value as deleted (using 1001 as a flag)
		array[minindex] = 1001;
		// Store the current rank 'i' 
		Parray[minindex] = i;
	}
	for (const auto& item : Parray) cout << item << " ";
	return;
}


int main() {

	int N;
	cin >> N;
	vector<int> Aarray(N);
	for (int i = 0; i < N; i++) {
		cin >> Aarray[i];
	}

	checkarray(Aarray, N);
}
