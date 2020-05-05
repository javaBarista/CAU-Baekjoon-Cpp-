#include <iostream>
#include <queue>
#pragma warning (disable : 4996)
using namespace std;

priority_queue<int, vector<int>, greater<int>> apq;
priority_queue<int> bpq;

int main() {
	int n, a, b;
	scanf(" %d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %d", &a);
		apq.push(a);
	}
	while(n--) {
		scanf(" %d", &b);
		bpq.push(b);
	}

	int sum = 0;
	while (!apq.empty()) {
		sum += (apq.top() * bpq.top());
		apq.pop();
		bpq.pop();
	}
	printf("%d", sum);
}