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
    int n = 5;//ѧ������
    int m = 3;//�γ���
    long num[STU_NUM] = { 10001,10002,10003,10004,10005 };
    char name[][MAX_LEN] = { "tom","jack","bill","amy","jackie" };
    float score[STU_NUM] = { 20.0,80.0,50.0,66.0,95.0 };
    float score2[STU_NUM][COURSE_NUM] = { {20.0,80.0,50.0},//2��ʾ��ά
                                                                        {66.0,95.0,77.0},
                                                                        {63.0,77.0,81.0},
                                                                        {86.0,43.0,72.0},
                                                                        {96.0,95.0,89.0} };
    /*��θı���һ���ֶΣ���һά�Ŀγ�����Ϊ�˶�ά���飬
    ��������һ������ͳ��ÿ��ѧ�����пγ̵�ƽ���ֺ��ܷ֣�
    ������Ҫ��������һά����sum[],aver[]�洢һ�´���Ϣ.*/
    float sum[STU_NUM] = { 0 };
    float aver[STU_NUM] = { 0 };
    AverSumofEveryStudent(score2, sum, aver, n, m);

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
            n = ReadScore(num, name, score2, n, m);
            AverSumofEveryStudent(score2, sum, aver, n, m);//ÿ��¼������󶼵����¼���
            break;
        case 2://����ÿ�ſγ̵��ֺܷ�ƽ���֣�
            AverSumofEveryCourse(score2, n, m);
            break;
        case 3://����ÿ��ѧ�����ֺܷ�ƽ����
            AverSumofEveryStudent(score2, sum, aver, n, m);
            printf("�Ѿ����¼����ֺܷ�ƽ����");
            break;
        case 4://��ÿ��ѧ�����ܷ��ɸߵ����ų����α�
            SortbyScore(num, name, score2, sum, aver, n, m, Descending);
            printf("Descendingly scorted by scores:\n");
            PrintScore(num, name, score2, sum, aver, n, m);
            break;
        case 5://��ÿ��ѧ�����ܷ��ɵ͵����ų����α�
            SortbyScore(num, name, score2, sum, aver, n, m, Ascending);
            printf("Ascendingly scorted by scores:\n");
            PrintScore(num, name, score2, sum, aver, n, m);
            break;
        case 6://��ѧ����������
            SortbyNum(num, name, score2, sum, aver, n, m, Ascending);
            printf("Ascendingly scorted by num:\n");
            PrintScore(num, name, score2, sum, aver, n, m);
            break;
        case 7://���������ֵ�˳���ų��ɼ���
            SortbyName(num, name, score2, sum, aver, n, m);
            printf("Dictionarily scorted by name:\n");
            PrintScore(num, name, score2, sum, aver, n, m);
            break;
        case 8://��ѧ�Ų�ѯѧ������������ƿ��Գɼ���
            SearchbyNum(num, name, score2, sum, aver, n, m);
            break;
        case 9://��������ѯѧ������������ƿ��Գɼ���
            SearchbyName(num, name, score2, sum, aver, n, m);
            break;
        case 10://������(90- 100)������(80- 89)���е�(70-79)������(60- 69)��������0-59)5�����,
                   //ͳ��ÿ�����������Լ���ռ�İٷֱ�;
            StatistAnalysis(score2, n, m);
            break;
        case 11://���ÿ��ѧ����ѧ�š����������ƿ��Գɼ����ܷ֣�ƽ���֣��Լ�ÿ�ſγ̵��ֺܷ�ƽ���֡�
            PrintScore(num, name, score2, sum, aver, n, m);
            AverSumofEveryCourse(score2, n, m);
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
    printf("2.Caculate total and average score of every course\n");
    printf("3.Caculate total and average score of every student\n");
    printf("4.Sort in descending order by total score of every student\n");
    printf("5.Sort in ascending order by total score of every student\n");
    printf("6.Sort in ascending order by number\n");
    printf("7.Sort in dictionary order by name\n");
    printf("8.Search by number\n");
    printf("9.Search by name\n");
    printf("10.Statistic analysis\n");
    printf("11.List record\n");
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

int ReadScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], int n, int m)
{
    printf("����¼��ѧ����Ϣ...\n");
    printf("ѧ��¼��-1ʱ����¼��\n");
    int i = n - 1;
    do
    {
        i++;
        printf("����¼���%d��ѧ����ѧ��,����\n", i + 1);
        //scanf("%ld%s%f", &num[i], name[i], &score[i]);//��ֵ�������ַ������ͽ���������ÿո����
        scanf_s("%ld", &num[i]);
        if (num[i] == -1)//���û�����������˳�����
            break;
        scanf_s("%s", name[i], 10);//scanf_s�����������ַ���ʱ����ָ���ַ�������
        getchar();//���߻س���
        printf("��������˳�������%d��ѧ��%d�γɼ�\n", i + 1, m);
        for (int j = 0; j < m; j++)
        {
            scanf_s("%f", &score[i][j]);
        }
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

void AverSumofEveryCourse(float score[][COURSE_NUM], int n, int m)
{
    float sum[COURSE_NUM] = { 0 };
    float aver[COURSE_NUM] = { 0 };
    //i��j�У���γ��ܷ֣��������ܺ�
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            sum[j] += score[i][j];
        }
        aver[j] = sum[j] / n;
        printf("��Ŀ%d���ܷ�Ϊ%.2f,ƽ����Ϊ%.2f\n", j + 1, sum[j], aver[j]);
    } 
}

void AverSumofEveryStudent(float score[][COURSE_NUM], float sum[], float aver[], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            sum[i] += score[i][j];
        }
        aver[i] = sum[i] / m;
    }
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

void SortbyScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m, int(*compare)(int a, int b))
{
    //ѡ�����򣬵�һ��ѭ���������飬ÿ�ι�һλ
    for (int i = 0; i < n - 1; i++)
    {
        int cmp = i;//�Ƚ�λ����ֵ����ʼΪ��������һλ
        //�ڶ���ѭ������λ��ÿ�δ���������ѡ�����һλ
        for (int j = i; j < n; j++)
        {
            if (compare(sum[cmp], sum[j]))//���ܷ�
            {
                cmp = j;
            }
        }
        //�����ı䣬����
        if (i != cmp)
        {
            LongSwap(&num[i], &num[cmp]);
            CharSwap(name[i], name[cmp]);
            FloatSwap(&sum[i], &sum[cmp]);
            FloatSwap(&aver[i], &aver[cmp]);
			for (int j = 0; j < m; j++)
			{
				FloatSwap(&score[i][j], &score[cmp][j]);
			}
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

void SortbyNum(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m, int(*compare)(int a, int b))
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
            FloatSwap(&sum[i], &sum[cmp]);
            FloatSwap(&aver[i], &aver[cmp]);
            for (int j = 0; j < m; j++)
            {
                FloatSwap(&score[i][j], &score[cmp][j]);
            }
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

void SortbyName(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m)
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
            FloatSwap(&sum[i], &sum[cmp]);
            FloatSwap(&aver[i], &aver[cmp]);
            for (int j = 0; j < m; j++)
            {
                FloatSwap(&score[i][j], &score[cmp][j]);
            }
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

int SearchbyNum(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m)
{
    int rank = -1;//ѧ������
    int x;//����ѯѧ��
    while (true)
    {
        printf("Please enter the student ID queried\n");
        scanf_s("%d", &x);
        SortbyScore(num, name, score, sum, aver, n, m, Descending);//������
        //˳�����
        for (int i = 0; i < n; i++)
        {
            if (x == num[i])
            {
                printf("name:%-10s rank:%-10d", name[i], i + 1);//����+1Ϊ����
                for (int j = 0; j < m; j++)
                {
                    printf("��Ŀ%d:%-10.1f", j + 1, score[i][j]);
                }
                printf("\n");
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

int SearchbyName(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m)
{
    int rank = -1;//ѧ������
    char x[MAX_LEN];//����ѯ����
    while (true)
    {
        printf("Please enter the student name queried\n");
        gets_s(x, MAX_LEN);
        SortbyScore(num, name, score, sum, aver, n, m, Descending);//������
        //˳�����
        for (int i = 0; i < n; i++)
        {
            if (strcmp(x, name[i]) == 0)
            {
                printf("name:%-10s rank:%-10d", name[i], i + 1);//����+1Ϊ����
                for (int j = 0; j < m; j++)
                {
                    printf("��Ŀ%d:%-10.1f", j + 1, score[i][j]);
                }
                printf("\n");
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

void StatistAnalysis(float score[][COURSE_NUM], int n, int m)
{
    for (int j = 0; j < m; j++)//ͳ��ÿ�ſ�
    {
        printf("��Ŀ%d������£�\n", j+1);

        int ranks[5] = { 0 };// ���ֵ��ε���������λ��ֵΪ0������λ����Ϊ0
        for (int i = 0; i < n; i++)//���������ɼ���ͳ������
        {
            if (score[i][j] < 60)
            {
                ranks[0]++;
            }
            else if (score[i][j] < 70 && score[i][j] >= 60)
            {
                ranks[1]++;
            }
            else if (score[i][j] < 80 && score[i][j] >= 70)
            {
                ranks[2]++;
            }
            else if (score[i][j] < 90 && score[i][j] >= 80)
            {
                ranks[3]++;
            }
            else//90��100��
            {
                ranks[4]++;
            }
        }
        //���ͳ������
		printf("%-10s%-10s%-10s\n", "rank ", "amount", "percent");
		printf("%-10s%-10d%.0f%%\n", "0-59 ", ranks[0], ranks[0] / (float)n * 100);
		printf("%-10s%-10d%.0f%%\n", "60-69", ranks[1], ranks[1] / (float)n * 100);
		printf("%-10s%-10d%.0f%%\n", "70-79", ranks[2], ranks[2] / (float)n * 100);
		printf("%-10s%-10d%.0f%%\n", "80-89", ranks[3], ranks[3] / (float)n * 100);
		printf("%-10s%-10d%.0f%%\n", "90-100", ranks[4], ranks[4] / (float)n * 100);
    }
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

void PrintScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m)
{
    printf("%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n", "ѧ��", "����", "��Ŀһ", "��Ŀ��", "��Ŀ��", "�ܷ�", "ƽ����");
    for (int i = 0; i < n; i++)
    {
        printf("%-10d%-10s", num[i], name[i]);
        for (int j = 0; j < m; j++)
        {
            printf("%-10.1f", score[i][j]);
        }
        printf("%-10.1f%-10.1f", sum[i], aver[i]);
        printf("\n");
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