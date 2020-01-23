#include <iostream>

#pragma warning (disable : 4996)
using namespace std;

static int zero[41];
static int one[41];

void fibo() {
	zero[0] = 1;
	zero[1] = 0;
	one[0] = 0;
	one[1] = 1;

	for (int i = 2; i <= 40; i++) {
		zero[i] = zero[i - 1] + zero[i - 2];
		one[i] = one[i - 1] + one[i - 2];
	}
}

int main() {
	int t;
	scanf(" %d", &t);

	fibo();

	while (t--) {
		int n;
		scanf(" %d", &n);
		printf("%d %d\n", zero[n], one[n]);
	}
}