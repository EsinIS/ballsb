#include <iostream>
#include <cstdlib>
using namespace std;
unsigned long long int F(int n) {
	unsigned long long int ans = 1;
	for (int i = 1; i < n + 1; i++) {
		ans *= i;
	}
	return ans;
}
unsigned long long int Cnk(int k, int n) {
	return (F(n)) / (F(n - k) * F(k));
}
unsigned long long int G(int n) {
	unsigned long long int ans = 1;
	if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		return 1;
	}
	else if (n == 3) {
		return 4;
	}
	else {
		for (int i = 1; i < n - 1; i++) {
			ans += Cnk(i, n) * (F(n - i) - G(n - i));
		}
	}
	return ans;
}
int main() {
	int n;
	cin >> n;
	cout << G(n);
}