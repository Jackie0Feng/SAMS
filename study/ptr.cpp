/*������:   �����˽����ָ���ʹ��
������:   JackieFeng
����:  06/11/2021
�汾��:
��ע����ϵͳ���ܣ�ѧϰ�ô���*/
#include <stdio.h>
int add(int a, int b)
{
	return a + b;
}

int main()
{
	//���������������������ݣ����Ի�ȡ��������������ַ
	printf("�����ı���\n");
	int variable = 3;
	printf("��ʶ��		��ַ			��ַ��ָ������\n");
	printf("%s	%p		%d\n", "variable", &variable, *&variable);
	printf("���ı���...\n");
	variable = 2;
	printf("%s	%p		%d\n", "variable", &variable, *&variable);

	//ָ�뱾���ǵ�ַ������ͨ����ַ����޸�����
	printf("ָ��ı���\n");
	int* ptr = &variable;
	printf("��ʶ��		��ַ			��ַ��ָ������\n");
	printf("%s	%p		%d\n", "ptr", ptr, *ptr);
	printf("����ָ��...\n");
	int variable2 = 3;
	ptr = &variable2;
	printf("%s	%p		%d\n", "ptr", ptr, *ptr);
	printf("����ָ����ָ������\n");
	*ptr = 4;
	printf("%s	%p		%d\n", "ptr", ptr, *ptr);

	//���������Ǵ�������ַ����ַ��ָ��������Ǵ�������ʹ��*���ѰַҲû��
	printf("�����ı���\n");
	printf("��ʶ��		��ַ			��ַ��ָ������\n");
	printf("%s	%p		%d\n", "add", add, *add);
	printf("%s	%p		%d\n", "*add", *add, **add);
	
	return 0;
}