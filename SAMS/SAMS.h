/*������:   ѧ���ɼ�����
������:   JackieFeng
����:  08/11/2021
�汾��:4.0
��ע��
ĳ������಻����30��(���������ɼ������룩�μ���ĩ���ԣ����Կ�Ŀ��಻����6�ţ����������ɼ������룩���ö�ά�����������������ʵ�����²˵�������ѧ���ɼ�����ϵͳ��
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
��ע������*/
int ReadScore(long num[], char name[][MAX_LEN], float score[], int n);
/*
��������:   ReadScore
��������:   ¼��ÿ��ѧ����ѧ�źͳɼ�,������������
����:
    num[]:ѧ��
    name[]:����
    score[][COURSE_NUM]:ÿ�ſη���
    n:ʵ��������
    m:ʵ�ʿγ���
����:�仯��������
��ע��*/
int ReadScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], int n, int m);
/*
��������:   AverSumofScore
��������:   �����ֺܷ�ƽ��ֵ�����
����:
    score[]:����
    n:������
����:
��ע������*/
int AverSumofScore(float score[], int n);
/*
��������:   AverSumofEveryCourse
��������:   ����ÿ�ſγ̵��ֺܷ�ƽ����
����:
    score[][COURSE_NUM]:����
    n:������
    m:�γ�����
����:
��ע��*/
void AverSumofEveryCourse(float score[][COURSE_NUM], int n, int m);
/*
��������:   AverSumofEveryCourse
��������:   ����ÿ��ѧ�����ֺܷ�ƽ����
����:
    score[][COURSE_NUM]:����
    sum[]:ѧ�����ܷ�
    aver[]:ѧ����ƽ����
    n:������
    m:�γ�����
����:
��ע��*/
void AverSumofEveryStudent(float score[][COURSE_NUM], float sum[], float aver[], int n, int m);
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
��ע������*/
//void SortbyScore(long num[], char name[][MAX_LEN], float score[], int n, int (*compare)(int a, int b));
/*
��������:   SortbyScore
��������:   ����ѧ���ܷ��������α�,ʹ�ú���ָ����������
����:
    num[]:ѧ��
    name[]:����
    score[]:����
    sum[]:ѧ�����ܷ�
    aver[]:ѧ����ƽ����
    n:������
    m:�γ�����
    *compare���ȽϺ���ָ��
����:
��ע��*/
void SortbyScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m, int (*compare)(int a, int b));
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
��ע����*/
//void SortbyNum(long num[], char name[][MAX_LEN], float score[], int n, int(*compare)(int a, int b));
/*
��������:   SortbyNum
��������:   ����ѧ����������
����:
    num[]:ѧ��
    name[]:����
    score[]:����
    sum[]:ѧ�����ܷ�
    aver[]:ѧ����ƽ����
    n:������
    m:�γ�����
    *compare���ȽϺ���ָ��
����:
��ע:*/
void SortbyNum(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m, int (*compare)(int a, int b));
/*
��������:   SortbyName
��������:   ���������ֵ�˳������
����:
    num[]:ѧ��
    name[]:����
    score[]:����
    n:������
����:
��ע����*/
//void SortbyName(long num[], char name[][MAX_LEN], float score[], int n);
/*
��������:   SortbyName
��������:   ���������ֵ�˳������
����:
    num[]:ѧ��
    name[]:����
    score[]:����
    sum[]:ѧ�����ܷ�
    aver[]:ѧ����ƽ����
    n:������
    m:�γ�����
����:
��ע*/
void SortbyName(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m);
/*
��������:   SearchbyNum
��������:   ��ѧ�Ų�ѯѧ���������俼�Գɼ�
����:
    num[]:ѧ��
    name[]:����
    score[]:����
    n:������
����:������
��ע������*/
//int SearchbyNum(long num[], char name[][MAX_LEN], float score[], int n);
/*
��������:   SearchbyNum
��������:   ��ѧ�Ų�ѯѧ������������ƿ��Գɼ���
����:
    num[]:ѧ��
    name[]:����
    score[]:����
    sum[]:ѧ�����ܷ�
    aver[]:ѧ����ƽ����
    n:������
    m:�γ�����
����:������
��ע��*/
int SearchbyNum(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m);
/*
��������:   SearchbyName
��������:   ��ѧ�Ų�ѯѧ���������俼�Գɼ�
����:
    num[]:ѧ��
    name[]:����
    score[]:����
    n:������
����:������
��ע������*/
//int SearchbyName(long num[], char name[][MAX_LEN], float score[], int n);
/*
��������:   SearchbyName
��������:   ��������ѯѧ������������ƿ��Գɼ���
����:
    num[]:ѧ��
    name[]:����
    score[]:����
    sum[]:ѧ�����ܷ�
    aver[]:ѧ����ƽ����
    n:������
    m:�γ�����
����:������
��ע��*/
int SearchbyName(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m);
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
//void StatistAnalysis( float score[], int n);
/*
��������:   StatistAnalysis
��������:   ������(90- 100)������(80- 89)���е�(70-79)������(60- 69)��������0-59)5�����,
                 ��ÿ�ſγ̷ֱ�ͳ��ÿ�����������Լ���ռ�İٷֱ�;
����:
    num[]:ѧ��
    score[][COURSE_NUM]:����
    n:������
    m:�ܿγ���
����:
��ע��*/
void StatistAnalysis(float score[][COURSE_NUM], int n, int m);
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
��ע������*/
//void PrintScore(long num[], char name[][MAX_LEN], float score[], int n);
/*
��������:   PrintScore
��������:   ��ӡÿλѧ����ѧ�ţ������ͳɼ�
����:
    num[]:ѧ��
    name[][MAX_LEN]:����
    score[][COURSE_NUM]:ÿ�ſ�
    sum[]:ѧ�����ܷ�
    aver[]:ѧ����ƽ����
    n:������
    m:�γ�����
���أ�
��ע��*/
void PrintScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m);
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