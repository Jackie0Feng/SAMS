/*������:   ѧ���ɼ�����
������:   JackieFeng
����:  04/11/2021
�汾��:2.0
��ע��
ĳ������಻����30��(���������ɼ������룩�μ�ĳ�ſεĿ���:��һά����ͺ���ָ����Ϊ�����������ʵ������ѧ���ɼ�����
(1)¼��ÿ��ѧ����ѧ�źͿ��Գɼ���
(2)����γ̵��ֺܷ�ƽ���֣�
(3)���ɼ��ɸߵ����ų����α�
(4)���ɼ��ɵ͵����ų����α�
(5)��ѧ����С�����ų��ɼ���
(6)��ѧ�Ų�ѯѧ���������俼�Գɼ���
(7)������(90- 100)������(80- 89)���е�(70-79)������(60- 69)��������0-59)5�����,ͳ��ÿ�����������Լ���ռ�İٷֱ�;
(8)���ÿ��ѧ����ѧ�š����Գɼ����γ��ֺܷ�ƽ���֡�*/
#include <stdio.h>
#include "SAMS.h"

int main()
{
    int order = -1;//�û�ָ��
    
    /*int n;
    long num[STU_NUM];
    float score[STU_NUM];*/
    //��ʼ����
    int n = 5;
    long num[STU_NUM] = { 10001,10002,10003,10004,10005 };
    float score[STU_NUM] = { 20.0,80.0,50.0,66.0,95.0 };
    Mean();//��ʾ�˵�
    //ʹ��ϵͳ
    while (1)
    {
        scanf_s("%d", &order);
        switch (order)
        {
        case 1://¼��ɼ�
            n = ReadScore(num, score, n);
            break;
        case 2://��ƽ���ֺ��ܷ�
            AverSumofScore(score, n);
            break;
        case 3://���ɼ���������
            SortbyScore(num, score, n, Descending);
            printf("Descendingly scorted by scores:\n");
            PrintScore(num, score, n);
            break;
        case 4://���ɼ���������
            SortbyScore(num, score, n, Ascending);
            printf("Ascendingly scorted by scores:\n");
            PrintScore(num, score, n);
            break;
        case 5://��ѧ����������
            AsSortbyNum(num, score, n);
            printf("Ascendingly scorted by num:\n");
            PrintScore(num, score, n);
            break;
        case 6://��ѧ�Ų�ѯѧ���������俼�Գɼ�
        {//�������case��ǩ��ʼ������������Ӵ�����{}
            int rank = -1;//ѧ������
            int x;//����ѯѧ��
            printf("Please enter the student ID queried\n");
            scanf_s("%d", &x);
            DeSortbyScore(num, score, n);//������
            rank = SearchbyNum(num, x, n);//��ʹ����Ҳ�����������λ��
            printf("The student's rank is %d and his grade is %f\n", rank+1, score[rank]);//����+1Ϊ����
            break;
        }
        case 7://������(90- 100)������(80- 89)���е�(70-79)������(60- 69)��������0-59)5�����,
                   //ͳ��ÿ�����������Լ���ռ�İٷֱ�;
            StatistAnalysis( score, n);
            break;
        case 8://���ÿ��ѧ����ѧ�š����Գɼ����γ��ֺܷ�ƽ����
            PrintScore(num, score, n);
            AverSumofScore(score, n);
            break;
        case 0://�˳�ϵͳ
            printf("Good Bye!\n");
            return 0;
            break;
        default:
            break;
        }
        printf("Please enter your choice : \n");
    }
    return 0;
}

int Mean(void)
{
    printf("1.Input record\n");
    printf("2.Caculate total and average score of course\n");
    printf("3.Sort in descending order by score\n");
    printf("4.Sort in ascending order by score\n");
    printf("5.Sort in ascending order by number\n");
    printf("6.Search by number\n");
    printf("7.Statistic analysis\n");
    printf("8.List record\n");
    printf("0.Exit\n");
    printf("Please enter your choice : \n");
    return 0;
}

int ReadScore(long num[], float score[],int n)
{
    printf("����¼��ѧ�źͳɼ�...\n");
    printf("ͬʱ��������-1����¼��\n");
    int i = n-1;
    do
    {
        i++;
        printf("����¼���%d��ѧ����ѧ�źͳɼ�\n", i + 1);
        scanf_s("%ld%*c%f", &num[i], &score[i]);
    } while (score[i] > 0 && i <= 30);
    printf("¼������ܹ�¼��%d��\n", i);
    return i;
}

int AverSumofScore(float score[], int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += score[i];
    }
    printf("�γ��ܷ�Ϊ%f,ƽ����Ϊ%f\n", sum, sum / n);
    return sum;
}

void DeSortbyScore(long num[], float score[], int n)//ѡ������
{
    long nTemp;
    float sTemp;
    int max=0;//���λ����ֵ����ʼΪ��һλ
    //ѡ�����򣬵�һ��ѭ���������飬ÿ�ι�һλ
    for (int i = 0; i < n-1; i++)
    {
        //�ڶ���ѭ������λ��ÿ�δ���������ѡ�����һλ
        for (int j = i; j < n; j++)
        {
            if (score[max] < score[j])
            {
                max = j;
            }
        }
        //�����ı䣬����
        if (i != max)
        {
            nTemp = num[i];
            num[i] = num[max];
            num[max] = nTemp;

            sTemp = score[i];
            score[i] = score[max];
            score[max] = sTemp;
        }
    }
}

void SortbyScore(long num[], float score[], int n, int(*compare)(int a, int b))
{
    long nTemp;
    float sTemp;
    int cmp = 0;//�Ƚ�λ����ֵ����ʼΪ��һλ
    //ѡ�����򣬵�һ��ѭ���������飬ÿ�ι�һλ
    for (int i = 0; i < n - 1; i++)
    {
        //�ڶ���ѭ������λ��ÿ�δ���������ѡ�����һλ
        for (int j = i; j < n; j++)
        {
            if ((*compare)(score[cmp], score[j]))
            {
                cmp = j;
            }
        }
        //�����ı䣬����
        if (i != cmp)
        {
            nTemp = num[i];
            num[i] = num[cmp];
            num[cmp] = nTemp;

            sTemp = score[i];
            score[i] = score[cmp];
            score[cmp] = sTemp;
        }
    }
}

int Ascending(int a, int b)
{
    return a<b;
}

int Descending(int a, int b)
{
    return a>b;
}

void AsSortbyNum(long num[], float score[], int n)
{
    long nTemp;
    float sTemp;
    int min = 0;//���λ����ֵ������Ϊ1
    //ѡ�����򣬵�һ��ѭ���������飬ÿ�ι�һλ
    for (int i = 0; i < n - 1; i++)
    {
        //�ڶ���ѭ������λ��ÿ�δ���������ѡ��ѧ����С��һλ
        for (int j = i; j < n; j++)
        {
            if (num[min] > num[j])
            {
                min = j;
            }
        }
        //�����ı䣬����
        if (i != min)
        {
            nTemp = num[i];
            num[i] = num[min];
            num[min] = nTemp;

            sTemp = score[i];
            score[i] = score[min];
            score[min] = sTemp;
        }
    }
}

int SearchbyNum(long num[], long x, int n)
{
    //˳�����
    for (int i = 0; i < n; i++)
    {
        if (x == num[i])
        {
            return i;
        }
    }
    return -1;
}

void StatistAnalysis(float score[], int n)
{
    int ranks[5] = {0};// ���ֵ��ε���������λ��ֵΪ0������λ����Ϊ0
    for (int i = 0; i < n; i++)//���������ɼ���ͳ������
    {
        if (score[i] < 60)
        {
            ranks[0]++;
        }
        else if (score[i] < 70 && score[i] >= 60) 
        {
            ranks[1]++;
        }
        else if (score[i] < 80 && score[i] >= 70)
        {
            ranks[2]++;
        }
        else if (score[i] < 90 && score[i] >= 80)
        {
            ranks[3]++;
        }
        else//90��100��
        {
            ranks[4]++;
        }
    }
    //���ͳ������
    printf("rank            amount            percent\n");
    printf("0-59            %d                  %.0f%%\n", ranks[0], ranks[0] / (float)n * 100);
    printf("60-69           %d                  %.0f%%\n", ranks[1], ranks[1] / (float)n * 100);
    printf("70-79           %d                  %.0f%%\n", ranks[2], ranks[2] / (float)n * 100);
    printf("80-89           %d                  %.0f%%\n", ranks[3], ranks[3] / (float)n * 100);
    printf("90-100          %d                  %.0f%%\n", ranks[4], ranks[4] / (float)n * 100);
}

void PrintScore(long num[], float score[], int n)
{
    printf("ѧ��      �ɼ�      \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d      %f      \n", num[i], score[i]);
    }
}