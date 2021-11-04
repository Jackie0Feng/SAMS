/*������:   ѧ���ɼ�����
������:   JackieFeng
����:  30/10/2021
�汾��:1.0
��ע��
ĳ������಻����30��(���������ɼ������룩��ʵ������ѧ���ɼ�����:��һά�������������������ʵ������ѧ���ɼ�����
(1)¼��ÿ��ѧ����ѧ�źͿ��Գɼ���
(2)����γ̵��ֺܷ�ƽ���֣�
(3)���ɼ��ɸߵ����ų����α�
(4)��ѧ����С�����ų��ɼ���
(5)��ѧ�Ų�ѯѧ���������俼�Գɼ���
(6)������(90- 100)������(80- 89)���е�(70-79)������(60- 69)��������0-59)5�����,ͳ��ÿ�����������Լ���ռ�İٷֱ�;
(7)���ÿ��ѧ����ѧ�š����Գɼ����γ��ֺܷ�ƽ���֡�*/
#pragma once
#define STU_NUM 30
/*
��������:   ReadScore
��������:   ¼��ÿ��ѧ����ѧ�źͳɼ�,������������
����:
    num[]:ѧ��
    score[]:����
����:������
��ע��*/
int ReadScore(long num[], float score[], int n);
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
void DeSortbyScore(long num[], float score[], int n);

/*
��������:   SortbyScore
��������:   ���ճɼ��������α�,ʹ�ú���ָ����������
����:
    num[]:ѧ��
    score[]:����
    n:������
    *compare���ȽϺ���ָ��
����:
��ע��*/
void SortbyScore(long num[], float score[], int n, int (*compare)(int a, int b));
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
/*
��������:   AsSortbyNum
��������:   ����ѧ����������
����:
    num[]:ѧ��
    score[]:����
    n:������
����:
��ע�������ã���ʹ�ú���ָ�������SortbyNum����*/
void AsSortbyNum(long num[], float score[], int n);
/*
��������:   SortbyNum
��������:   ����ѧ����������
����:
    num[]:ѧ��
    score[]:����
    n:������
    *compare���ȽϺ���ָ��
����:
��ע*/
void SortbyNum(long num[], float score[], int n, int(*compare)(int a, int b));
/*
��������:   SearchbyNum
��������:   ��ѧ�Ų�ѯѧ���������俼�Գɼ�
����:
    num[]:ѧ��
    x:��ѯѧ��
    n:������
����:�����ţ�-1Ϊû�ҵ�
��ע��*/
int SearchbyNum(long num[], long x, int n);
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
��ע��*/
void PrintScore(long num[], float score[],int n);
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
��������:   Mean
��������:   ��ʾ�˵�ҳ�棬��ʾ�û����ʹ��
����:
����:
��ע��*/
int Mean(void);

