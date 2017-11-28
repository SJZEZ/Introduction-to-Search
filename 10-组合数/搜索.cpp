#include <cstdio>

int n, m, ans[20];

void print_answer() {
	for (int i = 1; i <= m; ++i)
		printf("%d ", ans[i]);
	
	printf("\n");
}

void search(int now, int limit) {
	if (now > m) {
		print_answer();
		return;
	}
	
	for (int i = limit; i <= n - m + now; ++i) {
		ans[now] = i;
		search(now + 1, i + 1);
		ans[now] = 0;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	
	search(1, 1);
}
