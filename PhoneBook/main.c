#define _crt_secure_no_warnings
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<conio.h>
#define male true
#define female false
#define data_file_name "address.txt"

int printui() {
	int num = 0;
	system("cls");
	printf("[1] add\t  [2] search\t  [3] print all\t  [4] remove\t  [0]exit\n");

	scanf_s("%d", &num);

	return num;
}
void main() {

	////////////////////////////////////////////////////////////////////////////////////////////////////
	int commandnum = 0;
	//loadlist(data_file_name);

	while ((commandnum = printui()) != 0) {
		switch (commandnum) {
		case 1:
			//add();
			printf("add();\n");
			break;
		case 2:
			//search();
			printf("search();\n");
			break;
		case 3:
			//printall();
			printf("printall();\n");
			break;
		case 4:
			//remove();
			printf("remove();\n");
			break;
		}

	}

}
