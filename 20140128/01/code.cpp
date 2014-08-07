#include<cstdio>
#include<cstring>
#include<cstdlib>

//using namespace std;

char map[] = "22233344455566677778889999";
void conver_save_temp(char* t, char* s) {
	int len = strlen(t);
	int j = 0;
	for(int i = 0; i != len; ++i) {
		if(t[i] != '-') {
			if(t[i] <= '9')
				s[j] = t[i];
			else s[j] = map[t[i] - 'A'];
			j++;
		}
	}
	s[j] = '\0';
}

int compare(const void* c1, const void* c2) {
	return (strcmp((char *)c1, (char *)c2));
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int tele_num = 0;
	scanf("%d", &tele_num);
	char temp[50];
	char telenum[100000][9];

	for(int i = 0; i != tele_num; ++i) {
		scanf("%s", temp);
		conver_save_temp(temp, telenum[i]);
	}
	
	bool nomulti_tele = true;
	qsort(telenum, tele_num, 9, compare);
	int i = 0, j = 1;
	while(i < tele_num) {
		printf("%s\t", telenum[i]);
		while(strcmp(telenum[i], telenum[j]) == 0) {
			j++;
		}
		printf("%d\n", j-i);
		i = j;
	}
}
