/*Convert binary to hexadecimal
 * */


#include<cstdio>
#include<cstring>
#include<algorithm>

int b2ten(char* x) {
	int len = strlen(x);
	int r = 0;
	for(int i =  0; i != len; ++i) {
		r *= 2;
		r += x[i] - '0';
	}
	return r;
}

void ten2hex(int t, char*x) {
	int yu = 0;
	int n = 0;
	while(t != 0) {
		yu = t % 16;
		if(yu < 10)
			x[n++] = '0' + yu;
		else x[n++] = 'A' + (yu - 10);
		t /= 16;
	}
	x[n] = '\0';
	std::reverse(x, x+n);
	
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int line_num = 0;
	scanf("%d", &line_num);
	int num;
	char in_binary[100];
	char out_hexadecimal[100];
	while(line_num-- != 0) {
		//in_binary = new char[100];
		//out_hexadecimal = new char[50];
		scanf("%s", in_binary);
		num = b2ten(in_binary);
		printf("%d\t", num);
		ten2hex(num, out_hexadecimal);
		printf("%s\n", out_hexadecimal);
		//delete []out_hexadecimal;
		//delete []in_binary;
	}
	return 0;
}
