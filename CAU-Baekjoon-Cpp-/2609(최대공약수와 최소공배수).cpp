#include <iostream>

#pragma warning (disable : 4996)
using namespace std;


int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }

int lcm(int a, int b, int g) {
	printf("%d\n", g);
	return (a / g) * b;
}

int main() {
	int a, b;
	scanf(" %d %d", &a, &b);
	printf("%d", lcm(a, b, gcd(a, b)));
}