#include <iostream>
#pragma warning (disable : 4996)
using namespace std;

static long long dp[91];

int main() {
	int n;
	scanf(" %d", &n);
	
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 2; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];

	printf("%lld", dp[n]);
}