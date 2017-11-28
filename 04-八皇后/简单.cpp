#include <cstdio>

int ans[10];

void print_answer() {
	for (int i = 1; i <= 8; ++i)
		printf("%d ", ans[i]);

	printf("\n");

	/*
	for (int i = 1; i <= 8; ++i) {
		for (int j = 1; j <= 8; ++j)
			putchar(ans[i] == j ? 'O' : '.');
		puts("");
	}
	puts("");
	*/
}

bool judge(int now, int pos) {
	for (int i = 1; i < now; ++i) {
		if (ans[i] == pos)
			return false;
		if (ans[i] + i == pos + now)
			return false;
		if (ans[i] - i == pos - now)
			return false;
	}

	return true;
}

void search(int now) {
	if (now > 8) {
		print_answer();
		return;
	}

	for (int i = 1; i <= 8; ++i)
		if (judge(now, i)) {
			ans[now] = i;
			search(now + 1);
			ans[now] = 0;
		}
}

int main() {
	search(1);
}