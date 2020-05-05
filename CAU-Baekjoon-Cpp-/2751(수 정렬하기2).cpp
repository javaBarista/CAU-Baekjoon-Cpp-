#pragma warning (disable : 4996)
#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	int n, num;
	scanf(" %d", &n);

	while (n--) {
		scanf(" %d", &num);
		pq.push(num);
	}

	while (!pq.empty()) {
		printf("%d\n", pq.top());
		pq.pop();
	}
}