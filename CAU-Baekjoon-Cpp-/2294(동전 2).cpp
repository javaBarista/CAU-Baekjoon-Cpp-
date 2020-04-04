#include <iostream>

#pragma warning (disable : 4996)
using namespace std;

int coin[101];
int dp[10001];

int min(int a, int b) { return a < b ? a : b; }

int main() {
	int n, k;
	scanf(" %d %d", &n, &k);
	for (int i = 1; i <= n; i++) scanf(" %d", &coin[i]);
	for (int i = 1; i <= k; i++) dp[i] = 100001;

	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) dp[j] = min(dp[j], dp[j - coin[i]] + 1);
	}

	printf("%d", dp[k] == 100001 ? -1 : dp[k]);
}