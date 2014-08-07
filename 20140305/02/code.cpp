#include<cstdio>

int pieces[50];

double min_average_variance = MAXDOUBLE;

double AverageVariance(int num, int left) {
	return 1234;
}

void Divide(int x, int y, int num) {

	if(num == 0) {
		double a = AverageVariance(num, x * y);
		if(a < min_average_variance)
			min_average_variance = a;
	}

	if(x == y) {
		if(x == 1) {
			return;
		} else {`
			for(int i = 1; i < x; ++i) {	
				pieces[num] = i * x;
				Divide(x - i, y, num - 1);
			}
		}
	}
	else {
		for(int i = 1; i < x; ++i) {
			
			pieces[num] = i * x;
			Divide(x - i, y, num - 1);
		}
		for(int i = 1; i < y; ++i) {

			pieces[num] = i * y;
			Divide(x, y - i, num - 1);
		}
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	while(--n >= 0) {
		int m;
		scanf("%d", &m);

		Divide(8, 8, m);
	}
}
