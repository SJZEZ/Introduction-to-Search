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

bool used_a[20];
bool used_b[20];
bool used_c[20];

bool judge(int now, int pos) {
	return 
		used_a[pos] == false
	&&	used_b[now + pos] == false
	&&	used_c[now - pos + 8] == false;
}

void set(int x, int y) {
	used_a[y] = true;
	used_b[x + y] = true;
	used_c[x - y + 8] = true;
}

void reset(int x, int y) {
	used_a[y] = false;
	used_b[x + y] = false;
	used_c[x - y + 8] = false;
}

void search(int now) {
	if (now > 8) {
		print_answer();
		return;
	}

	for (int i = 1; i <= 8; ++i)
		if (judge(now, i)) {
			ans[now] = i, set(now, i);
			search(now + 1);
			ans[now] = 0, reset(now, i);
		}
}

int main() {
	search(1);
}