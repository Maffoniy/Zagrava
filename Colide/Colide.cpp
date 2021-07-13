#include <iostream>
using namespace std;
struct p {
	int x1;
	int x2;
	int y1;
	int y2;
}p1, p2;
bool Colide(p p1, p p2) {
	if (p1.x2 == p2.x1 || p1.x1 == p2.x2 || p1.y2 == p2.y1 || p1.y1 == p2.y2) {
		return false;
	}
	else if ((p1.x1 <= p2.x1 && p2.x1 <= p1.x2 || p1.x1 <= p2.x2 && p2.x2 <= p1.x2) && (p1.y1 <= p2.y1 && p2.y1 <= p1.y2 || p1.y1 <= p2.y2 && p2.y2 <= p1.y2))
		return true;
	else return false;
}
void main() {
	cout << "P1 rectangle" << endl;
	int x1, x2, y1, y2;
	cout << "enter x1" << endl;
	cin >> x1;
	cout << "enter y1" << endl;
	cin >> y1;
	cout << "enter x2" << endl;
	cin >> x2;
	cout << "enter y2" << endl;
	cin >> y2;
	if (x1 == x2 || y1 == y2) {
		cout << "it`s not a rectangle" << endl;
	}
	if (x1 > x2) {
		p1.x1 = x2;
		p1.x2 = x1;
	}
	else if (x1 < x2) {
		p1.x1 = x1;
		p1.x2 = x2;
	}
	if (y1 > y2) {
		p1.y1 = y2;
		p1.y2 = y1;
	}
	else if (y1 < y2) {
		p1.y1 = y1;
		p1.y2 = y2;
	}
	cout << "P2 rectangle" << endl;
	cout << "enter x1" << endl;
	cin >> x1;
	cout << "enter y1" << endl;
	cin >> y1;
	cout << "enter x2" << endl;
	cin >> x2;
	cout << "enter y2" << endl;
	cin >> y2;
	if (x1 == x2 || y1 == y2) {
		cout << "it`s not a rectangle" << endl;
	}
	if (x1 > x2) {
		p2.x1 = x2;
		p2.x2 = x1;
	}
	else if (x1 < x2) {
		p2.x1 = x1;
		p2.x2 = x2;
	}
	if (y1 > y2) {
		p2.y1 = y2;
		p2.y2 = y1;
	}
	else if (y1 < y2) {
		p2.y1 = y1;
		p2.y2 = y2;
	}
	if (Colide(p1, p2))
		cout << "Yes";
	else
		cout << "No";
	cout << "xy " << p1.x1 << " " << p1.y1 << endl;
	cout << "xy " << p1.x2 << " " << p1.y2 << endl;
	cout << "xy " << p2.x1 << " " << p2.y1 << endl;
	cout << "xy " << p2.x2 << " " << p2.y2 << endl;
	main();
}