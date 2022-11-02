#include<stdio.h>
#include<limits.h>
int main() {
	printf("%s\n", ".");
	printf("%s\n", ".........");
	printf("%s\n", ".................");
	printf("%s\n", ".........................");
	printf("%s\n", ".................................");
	printf("%s\n", "");
	printf("%s\n", "");
	printf("%s\n", ".................................");
	for (int g; g < 4; g++){
		printf("%s", ".");
		printf("%32s\n", ".");
	}
	printf("%s\n", ".................................");
	printf("%s\n", "");
	printf("%s\n", "");
	printf("%33s\n", ".");
	printf("%33s\n", ".........");
	printf("%33s\n", ".................");
	printf("%33s\n", ".........................");
	printf("%33s\n", ".................................");
	printf("%s\n", "");
	printf("%s\n", "");
	printf("%s\n", ".................................");
	for (int i; i < 5;i++) {
		printf("%s", ".");
		printf("%8s", "|");
		printf("%8s", "|");
		printf("%8s", "|");
		printf("%8s\n", ".");
	}
	printf("%s\n", ".................................");
	system("pause");
	return 0;
}