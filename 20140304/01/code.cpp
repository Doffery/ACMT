#include<cstdio>

int an[20];

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	while(--n >= 0) {
		int a, b;
		scanf("%d %d", &a, &b);
		int t = 1, tr = 1;
		for(int x = 0; x <= 20; ++x) {
			tr *= a;
			if(b >= t && b < tr) {
				printf("%d\n", x);
			//	return 1;
				break;
			}
			else t = tr;

		}
	}
}

