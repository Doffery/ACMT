#include<cstdio>

int main() {
	int a = 123;

	printf("I can live %05d years.\n", a);
	printf("I can live %-5d years.\n", a);

	double b = 123.456;

	printf("This is a double %010.4f\n", b);
	printf("This is a double %10.3e\n", b);
	printf("This is a double %010g", b);
}
