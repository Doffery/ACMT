#include<cstdio>
#include<cstring>
#include<cstdlib>

char words[1000][20];

void a(int rang_s, int rang_e, int pre_same_char) {
	int n_char_index = pre_same_char + 1;

	if(rang_s == rang_e) {
		words[rang_s][n_char_index] = '\0';
		printf("%s\n", words[rang_s]);
		return;
	}

	int n_rang_s = rang_s;
	for(int ind = rang_s; ind < rang_e; ++ind) {
		if(words[ind][n_char_index] != words[ind+1][n_char_index]) {
			a(n_rang_s, ind, n_char_index);
			n_rang_s = ind + 1;
		}
	}
	a(n_rang_s, rang_e, n_char_index);
	

}

int compare(const void* c1, const void* c2) {
	return (strcmp((char*)c1, (char*)c2));
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int n = 0;
	while(scanf("%s", words[n]) != EOF) {
		++n;
	}

	qsort(words, n, 20, compare);
	a(0, n-1, -1);

	return 0;



}
