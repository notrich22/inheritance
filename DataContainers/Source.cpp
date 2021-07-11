#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	const int n = 5;
	int arr[n] = { 3, 5, 8, 13, 21 };
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		cout << arr + 1 << "\t";
	}
}