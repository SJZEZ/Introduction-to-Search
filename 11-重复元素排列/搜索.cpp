#include <cstdio>

int n, cnt[15], ans[25];

void print_answer() {
	for (int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
		
	printf("\n");
}

void search(int now) {
	if (now > n) {
		print_answer();
		return;
	}
	
	for (int i = 1; i <= 10; ++i)
		if (cnt[i] >= 1) {
			ans[now] = i, --cnt[i];
			search(now + 1);
			ans[now] = 0, ++cnt[i];
		}
}

int main() {
	scanf("%d", &n);
	
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		cnt[x] = cnt[x] + 1;
	}
	
	search(1);
}
