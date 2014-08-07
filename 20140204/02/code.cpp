#include<cstdio>

int num[1024];
int buf[1024];
int n, k;

void a(int rang_s, int rang_e) {
	if(rang_s == rang_e && k != 0) {
		k--;
		printf("%d", num[buf[0]]);
		for(int i = 1; i < n; ++i) {
			printf(" %d", num[buf[i]]);
		}
		printf("\n");
	}
	else {
		for(int c  = rang_s; c < rang_e; ++c) {
			int t = buf[rang_s];
			buf[rang_s] = buf[c];
			buf[c] = t;
			a(rang_s+1, rang_e);
			t = buf[rang_s];
			buf[rang_s] = buf[c];
			buf[c] = t;

		}
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int m;
	scanf("%d", &m);

	while(--m >= 0) {
		scanf("%d%d", &n, &k);
		for(int i = 0; i < n; ++i) {
			buf[i] = i;
			scanf("%d", &num[i]);
		}
		a(0, n-1);	
	}
	
	return 0;
}
