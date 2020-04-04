#include <iostream>

#pragma warning (disable : 4996)
using namespace std;

int minCost = 987654321;

void dp(int cnt, int num) {
	if (minCost < cnt || num < 1) return;

	if (num == 1 && minCost > cnt) {
		minCost = cnt;
		return;
	}

	if(num % 3 == 0) dp(cnt + 1, num / 3);
	if (num % 2 == 0) dp(cnt + 1, num / 2);
	dp(cnt + 1, num - 1);
}

int main() {
	int n;
	scanf(" %d", &n);

	dp(0, n);
	printf("%d", minCost);
}