#include <cstdio>

int min(int a, int b) {
	if (a < b)
		return a;
	else
		return b;
}

int n, m, total;

void search(int rem, int num, int lmt) {	// remain, number, limit
	if (rem == 0 && num == 0)
		++total;

	if (rem == 0 || num == 0)
		return;

	int mini = rem / num;
	int maxi = min(rem - num + 1, lmt);

	for (int i = maxi; i >= mini; --i)
		search(rem - i, num - 1, i);
}

int main() {
	scanf("%d%d", &n, &m);

	search(n, m, n);

	printf("%d\n", total);
}