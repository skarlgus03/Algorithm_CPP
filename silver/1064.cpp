#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;


int main() {

	int Ax, Ay, Bx, By, Cx, Cy;
	cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy;

  // if two line has same gradient
	if ((By-Ay)*(Cx-Bx) == (Cy-By)*(Bx-Ax)) {
		cout << "-1.0";
		return 0;
	}

	double AB = sqrt((Bx - Ax) * (Bx - Ax) + (By - Ay) * (By - Ay));
	double AC = sqrt((Cx - Ax) * (Cx - Ax) + (Cy - Ay) * (Cy - Ay));
	double BC = sqrt((Cx - Bx) * (Cx - Bx) + (Cy - By) * (Cy - By));

	double case1 = 2 * (AC + BC);
	double case2 = 2 * (AB + AC);
	double case3 = 2 * (AB + BC);

	double maxlength = max({ case1, case2, case3 });
	double minlength = min({ case1, case2, case3 });

	cout << fixed << setprecision(10) << maxlength - minlength << endl;

	return 0;
}
