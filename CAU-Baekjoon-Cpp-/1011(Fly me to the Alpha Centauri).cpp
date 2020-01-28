#include <iostream>

typedef long long ll;
#pragma warning (disable : 4996)
using namespace std;

int t;

int main() {
	scanf(" %d", &t);

	for (int z = 0; z < t; z++) {
		ll x, y;
		scanf(" %lld %lld", &x, &y);
		ll dis = y - x;
		ll i = 1;
		while (i * i < dis) i++;

		ll res = ((dis - (i * i)) / i);

		printf("%d\n", (i * 2 - 1 + res));
	}

}