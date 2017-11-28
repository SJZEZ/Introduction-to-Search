#include <cstdio>

int n, ans[15];

void print_answer() {
	for (int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);

	printf("\n");
}

bool used[15];

void search(int now) {
	if (now == n + 1) {
		print_answer();
		return;
	}

	for (int i = 1; i <= n; ++i)
		if (used[i] == false) {
			ans[now] = i, used[i] = true;
			search(now + 1);
			ans[now] = 0, used[i] = false;
		}
}

int main() {
	scanf("%d", &n);

	search(1);
}