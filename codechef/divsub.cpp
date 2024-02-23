#include <iostream>
#include<cstdio>
#include <vector>
using namespace std;


#define maxn 1000000 + 5

int n, fl, tn, was[maxn], i, a[maxn], f[maxn], j, ti, sum;
int main() {
    scanf("%d", &tn);
	for(ti = 1; ti <= tn; ti++) {
		scanf("%d", &n);
		sum += n;
		fl = 0;
		for(i = 1; i <= n; i++) {
			scanf("%d", &a[i]); // if there is an answer from a single integer
			if (a[i] % n == 0 && !fl) {
				printf("1\n%d\n", i);
				fl = 1;
			}
		}
		if (!fl) { // otherwise
			for(i = 0; i < n; i++) was[i] = 0;
			was[0] = 1;
			for(i = 1; i <= n; i++) {
				f[i] = (f[i - 1] + a[i]) % n; // calculating f_i
				if (was[f[i]]) break; // if it occurs more than once, break
				was[f[i]] = 1;
			}
			for(j = 0; j <= i; j++) if (f[j] == f[i]) break; // finding the duplicate
			printf("%d\n", i - j); // outputting the answer
			for(++j; j <= i; j++) {
				printf("%d", j);
				if (j != i) printf(" ");
			}
			puts("");
		}
	}

	return 0;
}
