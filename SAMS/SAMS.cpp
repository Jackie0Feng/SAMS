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
#include <stdio.h>
#include "SAMS.h"
#include<string.h>
//#pragma warning(disable : 4996)

int main()
{
    int order = -1;//�û�ָ��
    
    /*int n;
    long num[STU_NUM];
    float score[STU_NUM];*/
    //��ʼ����
    int n = 5;
    long num[STU_NUM] = { 10001,10002,10003,10004,10005 };
    char name[][MAX_LEN] = { "tom","jack","bill","amy","jackie" };
    float score[STU_NUM] = { 20.0,80.0,50.0,66.0,95.0 };
    Mean();//��ʾ�˵�
    //ʹ��ϵͳ
    while (1)
    {
        printf("Please enter your choice : \n");
        scanf_s("%d", &order);
        getchar();//���߻�����Ļس���
        switch (order)
        {
        case 1://¼��ɼ�
            //n = ReadScore(num, score, n);
            n = ReadScore(num, name, score, n);
            break;
        case 2://��ƽ���ֺ��ܷ�
            AverSumofScore(score, n);
            break;
        case 3://���ɼ���������
            SortbyScore(num, name, score, n, Descending);
            printf("Descendingly scorted by scores:\n");
            PrintScore(num, name, score, n);
            break;
        case 4://���ɼ���������
            SortbyScore(num, name, score, n, Ascending);
            printf("Ascendingly scorted by scores:\n");
            PrintScore(num, name, score, n);
            break;
        case 5://��ѧ����������
            //AsSortbyNum(num, score, n);
            SortbyNum(num, name, score, n, Ascending);
            printf("Ascendingly scorted by num:\n");
            PrintScore(num, name, score, n);
            break;
        case 6://���������ֵ�˳���ų��ɼ���
            SortbyName(num, name, score, n);
            printf("Dictionarily scorted by name:\n");
            PrintScore(num, name, score, n);
            break;
        case 7://��ѧ�Ų�ѯѧ���������俼�Գɼ�
            SearchbyNum(num, name, score, n);
            break;
        case 8://��������ѯѧ���������俼�Գɼ�
            SearchbyName(num, name, score, n);
            break;
        case 9://������(90- 100)������(80- 89)���е�(70-79)������(60- 69)��������0-59)5�����,
                   //ͳ��ÿ�����������Լ���ռ�İٷֱ�;
            StatistAnalysis( score, n);
            break;
        case 10://���ÿ��ѧ����ѧ�š����Գɼ����γ��ֺܷ�ƽ����
            PrintScore(num, name, score, n);
            AverSumofScore(score, n);
            break;
        case 0://�˳�ϵͳ
            printf("Good Bye!\n");
            return 0;
            break;
        default:
            Mean();
            break;
        }
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
    printf("6.Sort in dictionary order by name\n");
    printf("7.Search by number\n");
    printf("8.Search by name\n");
    printf("9.Statistic analysis\n");
    printf("10.List record\n");
    printf("0.Exit\n");
    printf("666.Show mean\n");
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

int ReadScore(long num[], char name[][MAX_LEN], float score[], int n)
{
    printf("����¼��ѧ����Ϣ...\n");
    printf("�ɼ�¼��-1ʱ����¼��\n");
    int i = n-1;
    do
    {
        i++;
        printf("����¼���%d��ѧ����ѧ��,�����ʹ�С����ĳɼ�\n", i + 1);
        //scanf("%ld%s%f", &num[i], name[i], &score[i]);//��ֵ�������ַ������ͽ���������ÿո����
        scanf_s("%ld%s%f", &num[i], name[i],10, &score[i]);//scanf_s�����������ַ���ʱ����ָ���ַ�������
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
    //ѡ�����򣬵�һ��ѭ���������飬ÿ�ι�һλ
    for (int i = 0; i < n-1; i++)
    {
        int max = i;//���λ����ֵ����ʼΪ��������һλ
        //�ڶ���ѭ������λ��ÿ�δ���������ѡ�����һλ
        for (int j = i+1; j < n; j++)
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
    //ѡ�����򣬵�һ��ѭ���������飬ÿ�ι�һλ
    for (int i = 0; i < n - 1; i++)
    {
        int cmp = i;//�Ƚ�λ����ֵ����ʼΪ��������һλ
        //�ڶ���ѭ������λ��ÿ�δ���������ѡ�����һλ
        for (int j = i; j < n; j++)
        {
            if (compare(score[cmp], score[j]))//���������ǵ�ַ������ֱ��ʹ��ָ��Ҳ����������
            {
                cmp = j;
            }
        }
        //�����ı䣬����
        if (i != cmp)
        {
            LongSwap(&num[i], &num[cmp]);

            FloatSwap(&score[i], &score[cmp]);
        }
    }
}

void SortbyScore(long num[], char name[][MAX_LEN], float score[], int n, int(*compare)(int a, int b))
{
    //ѡ�����򣬵�һ��ѭ���������飬ÿ�ι�һλ
    for (int i = 0; i < n - 1; i++)
    {
        int cmp = i;//�Ƚ�λ����ֵ����ʼΪ��������һλ
        //�ڶ���ѭ������λ��ÿ�δ���������ѡ�����һλ
        for (int j = i; j < n; j++)
        {
            if (compare(score[cmp], score[j]))//���������ǵ�ַ������ֱ��ʹ��ָ��Ҳ����������
            {
                cmp = j;
            }
        }
        //�����ı䣬����
        if (i != cmp)
        {
            LongSwap(&num[i], &num[cmp]);
            CharSwap(name[i], name[cmp]);
            FloatSwap(&score[i], &score[cmp]);
        }
    }
}

void AsSortbyNum(long num[], float score[], int n)
{
    long nTemp;
    float sTemp;
    //ѡ�����򣬵�һ��ѭ���������飬ÿ�ι�һλ
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;//���λ����ֵ������Ϊ��������һλ
        //�ڶ���ѭ������λ��ÿ�δ���������ѡ��ѧ����С��һλ
        for (int j = i+1; j < n; j++)
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

void SortbyNum(long num[], float score[], int n, int(*compare)(int a, int b))
{
    long nTemp;
    float sTemp;
    //ѡ�����򣬵�һ��ѭ���������飬ÿ�ι�һλ
    for (int i = 0; i < n - 1; i++)
    {
        int cmp = i;//���λ����ֵ������Ϊ��������һλ
        //�ڶ���ѭ������λ��ÿ�δ���������ѡ��ѧ����С��һλ
        for (int j = i + 1; j < n; j++)
        {
            if ((*compare)(num[cmp], num[j]))
            {
                cmp = j;
            }
        }
        //�����ı䣬����
        if (i != cmp)
        {
            LongSwap(&num[i], &num[cmp]);

            FloatSwap(&score[i], &score[cmp]);
        }
    }
}

void SortbyNum(long num[], char name[][MAX_LEN], float score[], int n, int(*compare)(int a, int b))
{
    //ѡ�����򣬵�һ��ѭ���������飬ÿ�ι�һλ
    for (int i = 0; i < n - 1; i++)
    {
        int cmp = i;//���λ����ֵ������Ϊ��������һλ
        //�ڶ���ѭ������λ��ÿ�δ���������ѡ��ѧ����С��һλ
        for (int j = i + 1; j < n; j++)
        {
            if ((*compare)(num[cmp], num[j]))
            {
                cmp = j;
            }
        }
        //�����ı䣬����
        if (i != cmp)
        {
            LongSwap(&num[i], &num[cmp]);
            CharSwap(name[i], name[cmp]);
            FloatSwap(&score[i], &score[cmp]);
        }
    }
}

void SortbyName(long num[], char name[][MAX_LEN], float score[], int n)
{
    //ѡ�����򣬵�һ��ѭ���������飬ÿ�ι�һλ
    for (int i = 0; i < n - 1; i++)
    {
        int cmp = i;//���λ����ֵ������Ϊ��������һλ
        //�ڶ���ѭ������λ��ÿ�δ���������ѡ���ֵ�˳��ǰ��һλ
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(name[cmp],name[j])>0)//�Ա�λ������λ�󣬲���Ҫ�������ֶԱ�λ��С������
            {
                cmp = j;
            }
        }
        //�����ı䣬����
        if (i != cmp)
        {
            LongSwap(&num[i], &num[cmp]);
            CharSwap(name[i], name[cmp]);
            FloatSwap(&score[i], &score[cmp]);
        }
    }
}

int SearchbyNum(long num[], char name[][MAX_LEN], float score[], int n)
{
    int rank = -1;//ѧ������
    int x;//����ѯѧ��
    while (true)
    {
        printf("Please enter the student ID queried\n");
        scanf_s("%d", &x);
        SortbyScore(num, name, score, n, Descending);//������
        //˳�����
        for (int i = 0; i < n; i++)
        {
            if (x == num[i])
            {
                printf("name:%-10s rank:%-10d grade:%-10f\n", name[i], i + 1, score[i]);//����+1Ϊ����
                return i;
            }
        }
        printf("Can't find,please checkout again.\n");
    }
}

int SearchbyName(long num[], char name[][MAX_LEN], float score[], int n)
{
    int rank = -1;//ѧ������
    char x[MAX_LEN];//����ѯ����
    while (true)
    {
        printf("Please enter the student name queried\n");
        gets_s(x, MAX_LEN);
        SortbyScore(num, name, score, n, Descending);//������
        //˳�����
        for (int i = 0; i < n; i++)
        {
            if (strcmp(x, name[i]) == 0)
            {
                printf("name:%-10s rank:%-10d grade:%-10f\n", name[i], i + 1, score[i]);//����+1Ϊ����
                return i;
            }
        }
        printf("Can't find,please checkout again.\n");
    }
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
        printf("%-10d%-10f\n", num[i], score[i]);
    }
}

void PrintScore(long num[], char name[][MAX_LEN], float score[], int n)
{
    printf("%-10s%-10s%-10s\n","ѧ��","����","�ɼ�");
    for (int i = 0; i < n; i++)
    {
        printf("%-10d%-10s%-10f\n", num[i], name[i], score[i]);
    }
}

void FloatSwap(float* a, float* b)
{
    float tmp = *a;
    *a = *b;
    *b = tmp;
}

void LongSwap(long* a, long* b)
{
    long tmp = *a;
    *a = *b;
    *b = tmp;
}

void CharSwap(char a[], char b[])
{
    char tmp[MAX_LEN];
    strcpy_s(tmp, MAX_LEN, a);
    strcpy_s(a, MAX_LEN, b);
    strcpy_s(b, MAX_LEN, tmp);
}

int Ascending(int a, int b)
{
    return a > b;
}

int Descending(int a, int b)
{
    return a < b;
}