#include<cstdio>
#include<cstring>

#define MAX_L 200

char seq1[MAX_L + 10], seq2[MAX_L + 10];
int aMaxLength[MAX_L + 10][MAX_L + 10] = {0};

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while(scanf("%s %s", seq1, seq2) != EOF) {
		int len1 = strlen(seq1);
		int len2 = strlen(seq2);
		for(int i = 1; i <= len1; ++i)
			for(int j = 1; j <= len2; ++j) {
				if(seq1[i - 1] == seq2[j - 1])
					aMaxLength[i][j] = aMaxLength[i - 1][j - 1] + 1;
				else if(aMaxLength[i - 1][j] > aMaxLength[i][j - 1])
					aMaxLength[i][j] = aMaxLength[i - 1][j];
				else 
					aMaxLength[i][j] = aMaxLength[i][j - 1];
			}
		printf("%d\n", aMaxLength[len1][len2]);
	}
}
