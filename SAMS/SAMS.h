/*������:   ѧ���ɼ�����
������:   JackieFeng
����:  05/11/2021
�汾��:3.0
��ע��
ĳ������಻����30��(���������ɼ������룩�μ�ĳ�ſεĿ��ԣ��ö�ά�ַ������������������ʵ�����²˵�������ѧ���ɼ�����ϵͳ��
(1)¼��ÿ��ѧ����ѧ�ţ������Ϳ��Գɼ���
(2)����γ̵��ֺܷ�ƽ���֣�
(3)���ɼ��ɸߵ����ų����α�
(4)���ɼ��ɵ͵����ų����α�
(5)��ѧ����С�����ų��ɼ���
(6)���������ֵ�˳���ų��ɼ���
(7)��ѧ�Ų�ѯѧ���������俼�Գɼ���
(8)��������ѯѧ���������俼�Գɼ���
(9)������(90- 100)������(80- 89)���е�(70-79)������(60- 69)��������0-59)5�����,ͳ��ÿ�����������Լ���ռ�İٷֱ�;
(10)���ÿ��ѧ����ѧ�š����������Գɼ����Լ��γ��ֺܷ�ƽ���֡�*/
#pragma once
#define STU_NUM 30      //�������
#define MAX_LEN 10      //������󳤶�
/*
��������:   Mean
��������:   ��ʾ�˵�ҳ�棬��ʾ�û����ʹ��
����:
����:
��ע��*/
int Mean(void);
/*
��������:   ReadScore
��������:   ¼��ÿ��ѧ����ѧ�źͳɼ�,������������
����:
    num[]:ѧ��
    score[]:����
    n:������
����:������
��ע������*/
//int ReadScore(long num[], float score[], int n);
/*
��������:   ReadScore
��������:   ¼��ÿ��ѧ����ѧ�źͳɼ�,������������
����:
    num[]:ѧ��
    name[]:����
    score[]:����
    n��������
����:������
��ע��*/
int ReadScore(long num[], char name[][MAX_LEN], float score[], int n);
/*
��������:   AverSumofScore
��������:   �����ֺܷ�ƽ��ֵ�����
����:
    score[]:����
    n:�ܷ�
����:
��ע��*/
int AverSumofScore(float score[], int n);
/*
��������:   DeSortbyScore
��������:   ���ճɼ������������α�
����:
    num[]:ѧ��
    score[]:����
    n:������
����:
��ע�������ã���ʹ�ú���ָ�������SortbyScore����*/
//void DeSortbyScore(long num[], float score[], int n);
/*
��������:   SortbyScore
��������:   ���ճɼ��������α�,ʹ�ú���ָ����������
����:
    num[]:ѧ��
    score[]:����
    n:������
    *compare���ȽϺ���ָ��
����:
��ע���ϰ�������*/
//void SortbyScore(long num[], float score[], int n, int (*compare)(int a, int b));
/*
��������:   SortbyScore
��������:   ���ճɼ��������α�,ʹ�ú���ָ����������
����:
    num[]:ѧ��
    name[]:����
    score[]:����
    n:������
    *compare���ȽϺ���ָ��
����:
��ע��*/
void SortbyScore(long num[], char name[][MAX_LEN], float score[], int n, int (*compare)(int a, int b));
/*
��������:   AsSortbyNum
��������:   ����ѧ����������
����:
    num[]:ѧ��
    score[]:����
    n:������
����:
��ע�������ã���ʹ�ú���ָ�������SortbyNum����*/
//void AsSortbyNum(long num[], float score[], int n);
/*
��������:   SortbyNum
��������:   ����ѧ����������
����:
    num[]:ѧ��
    score[]:����
    n:������
    *compare���ȽϺ���ָ��
����:
��ע:�ϰ�������*/
//void SortbyNum(long num[], float score[], int n, int(*compare)(int a, int b));
/*
��������:   SortbyNum
��������:   ����ѧ����������
����:
    num[]:ѧ��
    name[]:����
    score[]:����
    n:������
    *compare���ȽϺ���ָ��
����:
��ע*/
void SortbyNum(long num[], char name[][MAX_LEN], float score[], int n, int(*compare)(int a, int b));
/*
��������:   SortbyName
��������:   ���������ֵ�˳������
����:
    num[]:ѧ��
    name[]:����
    score[]:����
    n:������
    *compare���ȽϺ���ָ��
����:
��ע*/
void SortbyName(long num[], char name[][MAX_LEN], float score[], int n);
/*
��������:   SearchbyNum
��������:   ��ѧ�Ų�ѯѧ���������俼�Գɼ�
����:
    num[]:ѧ��
    name[]:����
    score[]:����
    n:������
����:������
��ע��*/
int SearchbyNum(long num[], char name[][MAX_LEN], float score[], int n);
/*
��������:   SearchbyName
��������:   ��ѧ�Ų�ѯѧ���������俼�Գɼ�
����:
    num[]:ѧ��
    name[]:����
    score[]:����
    n:������
����:������
��ע��*/
int SearchbyName(long num[], char name[][MAX_LEN], float score[], int n);
/*
��������:   StatistAnalysis
��������:   ������(90 - 100)������(80 - 89)���е�(70 - 79)������(60 - 69)��������0 - 59)5�����, 
                 ͳ��ÿ�����������Լ���ռ�İٷֱ�;
����:
    num[]:ѧ��
    score[]:����
    n:������
����:
��ע��*/
void StatistAnalysis( float score[], int n);
/*
��������:   PrintScore
��������:   ��ӡÿλѧ���ĳɼ�
����:
    num[]:ѧ��
    score[]:����
    n:������
���أ�
��ע������*/
//void PrintScore(long num[], float score[],int n);
/*
��������:   PrintScore
��������:   ��ӡÿλѧ����ѧ�ţ������ͳɼ�
����:
    num[]:ѧ��
    name[]:����
    score[]:����
    n:������
���أ�
��ע��*/
void PrintScore(long num[], char name[][MAX_LEN], float score[], int n);
/*
��������:   FloatSwap
��������:   �������������ͱ���
����:
    a:float��ָ��
    b:float��ָ��
���أ�
��ע��*/
void FloatSwap(float* a, float* b);
/*
��������:   LongSwap
��������:   �������������ͱ���
����:
    a:long��ָ��
    b:long��ָ��
���أ�
��ע��*/
void LongSwap(long* a, long* b);
/*
��������:   LongSwap
��������:   �������������ͱ���
����:
    a:long��ָ��
    b:long��ָ��
���أ�
��ע��*/
void CharSwap(char a[], char b[]);
/*
��������:   Ascending
��������:   ����ȽϺ���
����:
    a:�Ƚ���
    b:�Ƚ���
����:a<b
��ע��*/
int Ascending(int a, int b);
/*
��������:   Descending
��������:   ����ȽϺ���
����:
    a:�Ƚ���
    b:�Ƚ���
����:a>b
��ע��*/
int Descending(int a, int b);