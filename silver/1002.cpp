#include <iostream>
#include <vector>
#include <cmath>

int turret(int x1, int x2, int r1, int y1, int y2, int r2);

int main() {

	// Declare variables
	int TestCase = 0;
	int x1 = 0, x2 = 0, r1 = 0, y1 = 0, y2 = 0, r2 = 0;

	// Declare result vector
	std::vector<int> result;

	// input number of TestCase
	std::cin >> TestCase;

	// input each case and calculate result
	for (int i = 0; i < TestCase; i++) {
		std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		result.push_back(turret(x1, y1, r1, x2, y2, r2));
	}
	// output result
	for (auto num : result) {
		std::cout << num << std::endl;
	}

	return 0;
}

int turret(int x1, int y1, int r1, int x2, int y2, int r2) {

	// Calculate distance squared between two centers
	long long dx = x1 - x2;
	long long dy = y1 - y2;
	long long ds = dx * dx + dy * dy;

	// Calculate radius sums and differences squared
	long long rps = (long long)(r1 + r2) * (r1 + r2);
	long long rms = (long long)(r1 - r2) * (r1 - r2);

	// perfect same center 
	if (ds == 0 && r1 == r2) return -1;
	// too far apart to touch each other
	if (ds > rps) return 0;
	// one circle is contained within the other without touching
	if (ds < rms) return 0;
	// circles touch at exactly one point (externally or internally)
	if (ds == rps || ds == rms) return 1;

	return 2;
}
