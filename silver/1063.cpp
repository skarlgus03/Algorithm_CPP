#include <iostream>
#include <string>

using namespace std;

struct position {
	int x;
	int y;
	position(string str) {
		x = str[0] - 'A';
		y = str[1] - '1';
	};
	position() {
		x = 0;
		y = 0;
	}
};

void movement(position& obj, string input, position& moveresult) {
	position temp(obj);

	if (input == "R") temp.x++;
	else if (input == "L") temp.x--;
	else if (input == "B") temp.y--;
	else if (input == "T") temp.y++;
	else if (input == "RT") {
		temp.x++;
		temp.y++;
	}
	else if (input == "LT") {
		temp.x--;
		temp.y++;
	}
	else if (input == "RB") {
		temp.x++;
		temp.y--;
	}
	else if (input == "LB") {
		temp.x--;
		temp.y--;
	}
	else return;

	if (temp.x == 8 || temp.x == -1 || temp.y == 8 || temp.y == -1) {
		return;
	}
	else {
		moveresult.x = temp.x - obj.x;
		moveresult.y = temp.y - obj.y;

		obj.x = temp.x;
		obj.y = temp.y;

		return;
	}
}

void movement(position& obj, position& move) {

	obj.x += move.x;
	obj.y += move.y;
	return;
}

int main() {
	string A1, A2;
	int N;
	cin >> A1 >> A2 >> N;

	position king(A1);
	position stone(A2);

	for (int i = 0; i < N; i++) {
		string command;
		position moveResult;
		cin >> command;

		movement(king, command, moveResult);
		if (king.x == stone.x && king.y == stone.y) {
			movement(stone,moveResult);

			if (stone.x == 8 || stone.x == -1 || stone.y == 8 || stone.y == -1) {
				moveResult.x *= -1;
				moveResult.y *= -1;
				movement(king, moveResult);
				movement(stone, moveResult);
			}
		}
	}

	cout << (char)(king.x + 'A') << king.y + 1 << "\n";
	cout << (char)(stone.x + 'A') << stone.y + 1 << "\n";
}
