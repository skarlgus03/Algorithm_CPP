#include <iostream>
#include <cmath>
#include <vector>


using namespace std;


// 2D Vector
struct FVector2D {
	float X;
	float Y;
	FVector2D() : X(0), Y(0) {}
	FVector2D(float x, float y) : X(x), Y(y) {}

	FVector2D operator-(const FVector2D& V) const {
		return FVector2D(X - V.X, Y - V.Y);
	}

	float dot(const FVector2D& V) const {
		return X * V.X + Y * V.Y;
	}

	float lengthSq() const {
		return X * X + Y * Y;
	}
};

// Circle
struct Circle {
	int cx;
	int cy;
	int r;
	Circle(int x, int y, int rr) : cx(x), cy(y), r(rr) {}
};


// Number of Intersection Points between Line Segment and Circle
int NumberofPoint(int x1, int y1, int x2, int y2, int cx, int  cy, int r) {
	FVector2D V1(x2 - x1, y2 - y1);
	FVector2D V2(x1 - cx, y1 - cy);

	float a = V1.dot(V1);
	float b = 2 * (V1.dot(V2));
	float c = V2.dot(V2) - r * r;

	// Discriminant
	float d = b * b - 4 * a * c;
	if (d < 0) return 0; // imaginary roots

	float t1 = (-b - sqrt(d)) / (2 * a);
	float t2 = (-b + sqrt(d)) / (2 * a);

	bool hit1 = (t1 >= 0.f && t1 <= 1.f);
	bool hit2 = (t2 >= 0.f && t2 <= 1.f);

	if (hit1 && hit2) return 2;
	if (hit1 || hit2) return 1;
	return 0;
}


int main() {
	
	int Tc;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	int n;
	
	vector<int> Answers;

	cin >> Tc;
	for (int i = 0; i < Tc; i++) {
		
		vector<Circle> circles;
		int counting = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;

		// input circles
		for (int j = 0; j < n; j++) {
			int cx,cy,r;
			cin >> cx >> cy >> r;
			Circle temp = { cx,cy,r };
			circles.push_back(temp);
		}
		
		// Calculate number of intersection points
		for (const auto& item : circles) {
			int result;
			result = NumberofPoint(x1, y1, x2, y2, item.cx, item.cy, item.r);
			if (result == 1) counting++;
		}
		Answers.push_back(counting);
	}
	// output results
	for (auto item : Answers) {
		cout << item << "\n";
	}
}
