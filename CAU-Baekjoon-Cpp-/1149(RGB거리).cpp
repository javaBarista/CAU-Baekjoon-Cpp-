#include <iostream>

#pragma warning (disable : 4996)
using namespace std;

int dp[1001][3];
static int rgb[1001][3];

int min(int a, int b) { return a < b ? a : b; }

int main() {
	int n;
	scanf(" %d", &n);
	
	for (int i = 0; i < 3; i++) dp[0][i] = rgb[0][i] = 0;
	for (int i = 1; i <= n; i++) scanf(" %d %d %d", &rgb[i][0], &rgb[i][1], &rgb[i][2]);
	
	for (int i = 0; i < n; i++) {
		dp[i + 1][0] = min(dp[i][1], dp[i][2]) + rgb[i + 1][0];
		dp[i + 1][1] = min(dp[i][0], dp[i][2]) + rgb[i + 1][1];
		dp[i + 1][2] = min(dp[i][0], dp[i][1]) + rgb[i + 1][2];
	}
	printf("%d", min(dp[n][0], min(dp[n][1], dp[n][2])));
}