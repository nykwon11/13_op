#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "keyword.h"


int is_whitespace(char c)
{
	if(c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == '(')
	{
		return 1;
	}
	return 0;
}


int fget_word(FILE *fp, char *word)
{
	int cnt;
	char c;
	
	while((c = fgetc(fp)) !=EOF)
	{
		if(is_whitespace(c) == 0)
		break;
	}
	
	if(c == EOF)
	{
		return 0;
	}
	
	cnt = 0;
	word[cnt++] = c;
	word[cnt] = '\0';		//to read one letter
	
	while((word[cnt] = fgetc(fp)) !=EOF)
	{
		if(is_whitespace(word[cnt]) == 1)
		{
			word[cnt] = '\0';
			break;
		}
		cnt++;
	}
	return cnt;
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
	
	FILE *fp;
	char filepath[100];
	char word[100];
	
	//file open
	printf("input the file path:");
	scanf("%s", filepath);
	fp = fopen(/*file path*/filepath, "r");
	
	if(fp == NULL)
	{
		printf("wrong file path %s\n", filepath);
		return -1;
	}
	
	
	//word reading
	while(fget_word(fp, word) !=0)
	{
		count_word(word);
	}
	
	//output
	print_word();

	fclose(fp);
	
	return 0;
}
