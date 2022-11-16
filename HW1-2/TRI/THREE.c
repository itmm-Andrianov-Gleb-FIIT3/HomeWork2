#include<stdio.h>
#include<limits.h>
int main() {
	printf(".\n");
	printf(".........\n");
	printf(".................\n");
	printf(".........................\n");
	printf(".................................\n");

	printf("\n");
	printf("\n");

	printf(".................................\n");
	printf(".");
	printf("%33s", ".\n");
	printf(".");
	printf("%33s", ".\n");
	printf(".");
	printf("%33s", ".\n");
	printf(".");
	printf("%33s", ".\n");
	printf(".................................\n");

	printf("\n");
	printf("\n");

	printf("%34s", ".\n");
	printf("%34s", ".........\n");
	printf("%34s", ".................\n");
	printf("%34s", ".........................\n");
	printf("%34s", ".................................\n");

	printf("\n");
	printf("\n");

	printf("%s\n", ".................................");
	printf(".");
	printf("%8s", "|");
	printf("%8s", "|");
	printf("%8s", "|");
	printf("%8s\n", ".");

	printf(".");
	printf("%8s", "|");
	printf("%8s", "|");
	printf("%8s", "|");
	printf("%8s\n", ".");

	printf(".");
	printf("%8s", "|");
	printf("%8s", "|");
	printf("%8s", "|");
	printf("%8s\n", ".");

	printf(".");
	printf("%8s", "|");
	printf("%8s", "|");
	printf("%8s", "|");
	printf("%8s\n", ".");

	printf(".");
	printf("%8s", "|");
	printf("%8s", "|");
	printf("%8s", "|");
	printf("%8s\n", ".");

	printf("%s\n", ".................................");

	system("pause");
	return 0;
}