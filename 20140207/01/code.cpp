#include<cstdio>
#include<cstring>
const int MAX_LEN=100;

char f_line[MAX_LEN + 1];
char s_line[MAX_LEN + 1];

int f_num[MAX_LEN];
int s_num[MAX_LEN];
int result_[MAX_LEN];

int s_num_leng, f_num_leng;

int Minus(int zero_position, int end_index) {
	for(; zero_position <= end_index; ++zero_position) {
		if(f_num[zero_position] != 0)
			break;
		if(zero_position == end_index) {
			return -1;
		}
	}
	if(end_index - zero_position + 1 < s_num_leng)
		return -1;
	else if(end_index - zero_position + 1 == s_num_leng) {
		for(int i = zero_position, j = 0; i <= end_index; ++i, ++j) {
			if(f_num[i] < s_num[j])
				return -1;
		}
	}
	for(int i = end_index, j = s_num_leng - 1; j >= 0; --i, --j) {
		f_num[i] -= s_num[j];
		if(f_num[i] < 0) {
			f_num[i] += 10;
			f_num[i-1] -= 1;
		}
	}
	return 1;
}

int DivideResult(int &zero_position, int ind) {

	int r = 0;
	int e = Minus(zero_position, ind);
	while(e > 0) {
		r += 1;
		e = Minus(zero_position, ind);
	}
	//for(int i = 0; i < f_num_leng - ind - 1; ++i)
	//	r *= 10;
	return r;
}

void Plus2Result(int i, int carry) {
	result_[carry] += i;
	for(int j = carry; j <= MAX_LEN; ++j) {
		if(result_[j] >= 10) {
			result_[j] -= 10;
			result_[j+1] += 1;
		} else break;
	}

}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	int n;
	scanf("%d", &n);

	memset(result_, 0, sizeof(result_));

	while(--n >= 0) {
		scanf("%s%s", f_line, s_line);
		int f_len = strlen(f_line), s_len = strlen(s_line);
		s_num_leng = s_len;
		f_num_leng = f_len;
		if(f_len < s_len) {
			printf("0\n");
			continue;
		}

		for(int i = 0; i < f_len; ++i) {
			f_num[i] = f_line[i] - '0';
		}

		for(int i = 0; i < s_len; ++i) {
			s_num[i] = s_line[i] - '0';
		}

		int zero_position = 0;
		//the next position of the last useless zero in the first number 
		
		for(int i = s_len-1; i < f_len; ++i) {
			if(i - zero_position < s_len - 1)
				i = s_len + zero_position - 1;
			if(i < f_len)
				Plus2Result(DivideResult(zero_position, i), f_len - i - 1);
		}
		int i = MAX_LEN - 1;
		for(; i > 0 && result_[i] == 0; -- i);
		for(; i >= 0 ; --i) {
			printf("%d", result_[i]);
		}
		printf("\n");


	}

}
