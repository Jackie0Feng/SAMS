//type �ļ���
//��ʾ�ļ��ڵ�����
#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void type(char* argv[])
{
	char ch;
	FILE* fp;
	if ((fp = fopen(argv[2], "r")) == 0)
	{
		puts("�ļ���ʧ��");
		exit(0);
	}
	else
	{
		int len = 0;
		while ((ch = fgetc(fp)) != EOF)
		{
			len++;
			//printf("%d\t%c\n", ch, ch);
			putchar(ch);
		}
		puts("");
		printf("%d", len);
		fclose(fp);
	}
}
int main(int argc, char *argv[])
{
	if (strcmp(argv[1], "type")==0)
	{
		type(argv);
	}
	return 0;
}
