#include <cstdio>

int n, ans[20], used;

void print_answer() {
	printf("%d ", used);

	for (int i = 1; i <= used; ++i)
		printf("%d ", ans[i]);

	printf("\n");
}

void search(int remain, int limit) {
	if (remain == 0) {
		print_answer();
		return;
	}

	for (int i = limit; i > 0; --i)
		if (i <= remain) {
			ans[++used] = i;
			search(remain - i, i);
			ans[used--] = 0;
		}
}

int main() {
	scanf("%d", &n);

	search(n, n - 1);
}