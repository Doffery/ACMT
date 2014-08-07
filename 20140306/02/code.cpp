#include<cstdio>
#include<cstring>

#define MAX_CAN_NUM 200
#define MAX_JUR_NUM 20

int point_pro[MAX_CAN_NUM + 10];
int point_def[MAX_CAN_NUM + 10];

int f[20][600];
int path[20][600];

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, m;
    scanf("%d %d", &n, &m);
    for(int ni = 1; ni <= n; ++ni) {
	scanf("%d %d", &point_pro[ni], &point_def[ni]);
    }

    memset(f, -1, sizeof(f));
    memset(path, 0, sizeof(path));

    f[0][m * 10] = 0;
    for(int i = 0; i <= m; ++i) {
	for(int j = 0; j <= m * 20; ++j) {
	    if(f[i][j] >= 0) {
		for(int k = 1; k <= n; ++k) {
		    if(f[i][j] + point_pro[k] + point_def[k] > 
			    f[i + 1][j + point_pro[k] - point_def[k]]) {
			int t1 = i, t2 = j;
			while(t1 > 0 && path[t1][t2] != k) {
			    t2 -= point_pro[path[i][j]] - point_def[path[i][j]];
			    --t1;
			}
			if(t1 == 0) {
			    f[i + 1][j + point_pro[k] - point_def[k]] =
				f[i][j] + point_pro[k] + point_def[k];
			    path[i + 1][j + point_pro[k] - point_def[k]] = k;
			}
		    }

	    	}
	    }
	}
    }

    int i = m * 10, j = 0;
    while(f[m][i + j] < 0 && f[m][i - j] < 0)
	++j;
    int r;
    if(f[m][i + j] > f[m][i - j])
	r = i + j;
    else r = i - j;

    printf("%d prosecution and %d defence\n", (f[m][r] + r - 10 * m) / 2, (f[m][r] - r + 10 * m) / 2);

}
