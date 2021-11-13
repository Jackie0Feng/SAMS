/*������:   ѧ���ɼ�����
������:   JackieFeng
����:  13/11/2021
�汾��:5.0
��ע��
ĳ������಻����30��(���������ɼ������룩�μ���ĩ���ԣ����Կ�Ŀ��಻����6�ţ����������ɼ������룩��
����ṹ�����ͣ��ýṹ�������������������ʵ�����²˵�������ѧ���ɼ�����ϵͳ��
(1)¼��ÿ��ѧ����ѧ�ţ������͸��ƿ��Գɼ���
(2)����ÿ�ſγ̵��ֺܷ�ƽ���֣�
(3)����ÿ��ѧ�����ֺܷ�ƽ����
(4)��ÿ��ѧ�����ܷ��ɸߵ����ų����α�
(5)��ÿ��ѧ�����ܷ��ɵ͵����ų����α�
(6)��ѧ����С�����ų��ɼ���
(7)���������ֵ�˳���ų��ɼ���
(8)��ѧ�Ų�ѯѧ������������ƿ��Գɼ���
(9)��������ѯѧ������������ƿ��Գɼ���
(10)������(90- 100)������(80- 89)���е�(70-79)������(60- 69)��������0-59)5�����,��ÿ�ſγ̷ֱ�ͳ��ÿ�����������Լ���ռ�İٷֱ�;
(11)���ÿ��ѧ����ѧ�š����������ƿ��Գɼ����ܷ֣�ƽ���֣��Լ�ÿ�ſγ̵��ֺܷ�ƽ���֡�*/
#pragma once
#define STU_NUM 30      //�������
#define MAX_LEN 10      //������󳤶�
#define COURSE_NUM 6//�γ�������

//ѧ���ṹ��
//long num;
//char name[MAX_LEN];
//float score[COURSE_NUM];
//float sum;
//float aver;
typedef struct student
{
    long num;
    char name[MAX_LEN];
    float score[COURSE_NUM];
    float sum;
    float aver;
}STU;

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
    STU students:ѧ���ṹ������
    n:ʵ��������
    m:ʵ�ʿγ���
����:�仯��������
��ע��*/
int ReadScore(STU students[], int n, int m);
/*
��������:   AverSumofEveryCourse
��������:   ����ÿ�ſγ̵��ֺܷ�ƽ����
����:
    STU students:ѧ���ṹ������
    n:������
    m:�γ�����
����:
��ע��*/
void AverSumofEveryCourse(STU students[], int n, int m);
/*
��������:   AverSumofEveryCourse
��������:   ����ÿ��ѧ�����ֺܷ�ƽ����
����:
    STU students:ѧ���ṹ������
    n:������
    m:�γ�����
����:
��ע��*/
void AverSumofEveryStudent(STU students[], int n, int m);
/*
��������:   SortbyScore
��������:   ����ѧ���ܷ��������α�,ʹ�ú���ָ����������
����:
    STU students:ѧ���ṹ������
    n:������
    m:�γ�����
    *compare���ȽϺ���ָ��
����:
��ע��*/
void SortbyScore(STU students[], int n, int m, int (*compare)(int a, int b));
/*
��������:   SortbyNum
��������:   ����ѧ����������
����:
    STU students:ѧ���ṹ������
    n:������
    m:�γ�����
    *compare���ȽϺ���ָ��
����:
��ע:*/
void SortbyNum(STU students[], int n, int m, int (*compare)(int a, int b));
/*
��������:   SortbyName
��������:   ���������ֵ�˳������
����:
    STU students:ѧ���ṹ������
    n:������
    m:�γ�����
����:
��ע*/
void SortbyName(STU students[], int n, int m);
/*
��������:   SearchbyNum
��������:   ��ѧ�Ų�ѯѧ������������ƿ��Գɼ���
����:
    STU students:ѧ���ṹ������
    n:������
    m:�γ�����
����:������
��ע��*/
int SearchbyNum(STU students[], int n, int m);
/*
��������:   SearchbyName
��������:   ��������ѯѧ������������ƿ��Գɼ���
����:
    STU students:ѧ���ṹ������
    n:������
    m:�γ�����
����:������
��ע��*/
int SearchbyName(STU students[], int n, int m);
/*
��������:   StatistAnalysis
��������:   ������(90- 100)������(80- 89)���е�(70-79)������(60- 69)��������0-59)5�����,
                 ��ÿ�ſγ̷ֱ�ͳ��ÿ�����������Լ���ռ�İٷֱ�;
����:
    STU students:ѧ���ṹ������
    n:������
    m:�ܿγ���
����:
��ע��*/
void StatistAnalysis(STU students[], int n, int m);
/*
��������:   PrintScore
��������:   ��ӡÿλѧ����ѧ�ţ������ͳɼ�
����:
    STU students:ѧ���ṹ������
    n:������
    m:�γ�����
���أ�
��ע��*/
void PrintScore(STU students[], int n, int m);
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