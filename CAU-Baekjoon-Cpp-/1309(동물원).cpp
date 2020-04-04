#include <iostream>

#pragma warning (disable : 4996)
#define div 9901
using namespace std;

static int dp[100001] = {1, 3, 7};

int main() {
	int n;
	scanf(" %d", &n);
	
	for (int i = 3; i <= n; i++) dp[i] = ((dp[i - 1] << 1) + dp[i - 2]) % div;
	printf("%d", dp[n]);
}