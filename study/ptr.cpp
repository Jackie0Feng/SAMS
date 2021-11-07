/*程序功能:   深入了解各种指针的使用
编码者:   JackieFeng
日期:  06/11/2021
版本号:
备注：非系统功能，学习用代码*/
#include <stdio.h>
int add(int a, int b)
{
	return a + b;
}

int main()
{
	//变量本质是数据区的内容，可以获取到它的数据区地址
	printf("变量的本质\n");
	int variable = 3;
	printf("标识符		地址			地址所指向内容\n");
	printf("%s	%p		%d\n", "variable", &variable, *&variable);
	printf("更改变量...\n");
	variable = 2;
	printf("%s	%p		%d\n", "variable", &variable, *&variable);

	//指针本质是地址，可以通过地址间接修改内容
	printf("指针的本质\n");
	int* ptr = &variable;
	printf("标识符		地址			地址所指向内容\n");
	printf("%s	%p		%d\n", "ptr", ptr, *ptr);
	printf("更改指针...\n");
	int variable2 = 3;
	ptr = &variable2;
	printf("%s	%p		%d\n", "ptr", ptr, *ptr);
	printf("更改指针所指的内容\n");
	*ptr = 4;
	printf("%s	%p		%d\n", "ptr", ptr, *ptr);

	//函数本质是代码区地址，地址所指向的内容是代码区，使用*间接寻址也没用
	printf("函数的本质\n");
	printf("标识符		地址			地址所指向内容\n");
	printf("%s	%p		%d\n", "add", add, *add);
	printf("%s	%p		%d\n", "*add", *add, **add);
	
	return 0;
}