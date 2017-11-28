#include <cstdio>

int n, ans[15];

void print_answer() {
	for (int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);

	printf("\n");
}

void search(int now, int used) {
	if (now == n + 1)
		print_answer();
	else {
		for (int i = 1; i <= n; ++i)
			if (!((used >> i) & 1)) {
				ans[now] = i;
				search(now, used | (1 << i));
				ans[now] = 0;
			}
	}
}

int main() {
	scanf("%d", &n);

	search(1, 0);
}