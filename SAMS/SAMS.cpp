/*程序功能:   学生成绩管理
编码者:   JackieFeng
日期:  05/11/2021
版本号:3.0
备注：
某班有最多不超过30人(具体人数由键盘输入）参加某门课的考试，用二维字符数组作函数参数编程实现如下菜单驱动的学生成绩管理系统：
(1)录入每个学生的学号，姓名和考试成绩；
(2)计算课程的总分和平均分；
(3)按成绩由高到低排出名次表；
(4)按成绩由低到高排出名次表；
(5)按学号由小到大排出成绩表；
(6)按姓名的字典顺序排出成绩表；
(7)按学号查询学生排名及其考试成绩；
(8)按姓名查询学生排名及其考试成绩；
(9)按优秀(90- 100)、良好(80- 89)、中等(70-79)、及格(60- 69)、不及格（0-59)5个类别,统计每个类别的人数以及所占的百分比;
(10)输出每个学生的学号、姓名，考试成绩，以及课程总分和平均分。*/
#include <stdio.h>
#include "SAMS.h"
#include<string.h>
//#pragma warning(disable : 4996)

int main()
{
    int order = -1;//用户指令
    
    /*int n;
    long num[STU_NUM];
    float score[STU_NUM];*/
    //初始数据
    int n = 5;
    long num[STU_NUM] = { 10001,10002,10003,10004,10005 };
    char name[][MAX_LEN] = { "tom","jack","bill","amy","jackie" };
    float score[STU_NUM] = { 20.0,80.0,50.0,66.0,95.0 };
    Mean();//显示菜单
    //使用系统
    while (1)
    {
        printf("Please enter your choice : \n");
        scanf_s("%d", &order);
        getchar();//读走缓存里的回车符
        switch (order)
        {
        case 1://录入成绩
            //n = ReadScore(num, score, n);
            n = ReadScore(num, name, score, n);
            break;
        case 2://求平均分和总分
            AverSumofScore(score, n);
            break;
        case 3://按成绩降序排名
            SortbyScore(num, name, score, n, Descending);
            printf("Descendingly scorted by scores:\n");
            PrintScore(num, name, score, n);
            break;
        case 4://按成绩升序排名
            SortbyScore(num, name, score, n, Ascending);
            printf("Ascendingly scorted by scores:\n");
            PrintScore(num, name, score, n);
            break;
        case 5://按学号升序排名
            //AsSortbyNum(num, score, n);
            SortbyNum(num, name, score, n, Ascending);
            printf("Ascendingly scorted by num:\n");
            PrintScore(num, name, score, n);
            break;
        case 6://按姓名的字典顺序排出成绩表；
            SortbyName(num, name, score, n);
            printf("Dictionarily scorted by name:\n");
            PrintScore(num, name, score, n);
            break;
        case 7://按学号查询学生排名及其考试成绩
            SearchbyNum(num, name, score, n);
            break;
        case 8://按姓名查询学生排名及其考试成绩
            SearchbyName(num, name, score, n);
            break;
        case 9://按优秀(90- 100)、良好(80- 89)、中等(70-79)、及格(60- 69)、不及格（0-59)5个类别,
                   //统计每个类别的人数以及所占的百分比;
            StatistAnalysis( score, n);
            break;
        case 10://输出每个学生的学号、考试成绩，课程总分和平均分
            PrintScore(num, name, score, n);
            AverSumofScore(score, n);
            break;
        case 0://退出系统
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
    printf("正在录入学号和成绩...\n");
    printf("同时输入两个-1结束录入\n");
    int i = n-1;
    do
    {
        i++;
        printf("正在录入第%d个学生的学号和成绩\n", i + 1);
        scanf_s("%ld%*c%f", &num[i], &score[i]);
    } while (score[i] > 0 && i <= 30);
    printf("录入完成总共录入%d人\n", i);
    return i;
}

int ReadScore(long num[], char name[][MAX_LEN], float score[], int n)
{
    printf("正在录入学生信息...\n");
    printf("成绩录入-1时结束录入\n");
    int i = n-1;
    do
    {
        i++;
        printf("正在录入第%d个学生的学号,姓名和带小数点的成绩\n", i + 1);
        //scanf("%ld%s%f", &num[i], name[i], &score[i]);//数值类型与字符串类型交叉输入可用空格隔开
        scanf_s("%ld%s%f", &num[i], name[i],10, &score[i]);//scanf_s函数在输入字符串时必须指定字符串长度
    } while (score[i] > 0 && i <= 30);
    printf("录入完成总共录入%d人\n", i);
    return i;
}

int AverSumofScore(float score[], int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += score[i];
    }
    printf("课程总分为%f,平均分为%f\n", sum, sum / n);
    return sum;
}

void DeSortbyScore(long num[], float score[], int n)//选择排序
{
    long nTemp;
    float sTemp;
    //选择排序，第一层循环整个数组，每次归一位
    for (int i = 0; i < n-1; i++)
    {
        int max = i;//最大位索引值，初始为乱序区第一位
        //第二层循环乱序位，每次从乱序列中选择最大一位
        for (int j = i+1; j < n; j++)
        {
            if (score[max] < score[j])
            {
                max = j;
            }
        }
        //发生改变，交换
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
    //选择排序，第一层循环整个数组，每次归一位
    for (int i = 0; i < n - 1; i++)
    {
        int cmp = i;//比较位索引值，初始为乱序区第一位
        //第二层循环乱序位，每次从乱序列中选择最大一位
        for (int j = i; j < n; j++)
        {
            if (compare(score[cmp], score[j]))//函数名就是地址，所以直接使用指针也是正常工作
            {
                cmp = j;
            }
        }
        //发生改变，交换
        if (i != cmp)
        {
            LongSwap(&num[i], &num[cmp]);

            FloatSwap(&score[i], &score[cmp]);
        }
    }
}

void SortbyScore(long num[], char name[][MAX_LEN], float score[], int n, int(*compare)(int a, int b))
{
    //选择排序，第一层循环整个数组，每次归一位
    for (int i = 0; i < n - 1; i++)
    {
        int cmp = i;//比较位索引值，初始为乱序区第一位
        //第二层循环乱序位，每次从乱序列中选择最大一位
        for (int j = i; j < n; j++)
        {
            if (compare(score[cmp], score[j]))//函数名就是地址，所以直接使用指针也是正常工作
            {
                cmp = j;
            }
        }
        //发生改变，交换
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
    //选择排序，第一层循环整个数组，每次归一位
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;//最大位索引值，初试为乱序区第一位
        //第二层循环乱序位，每次从乱序列中选择学号最小的一位
        for (int j = i+1; j < n; j++)
        {
            if (num[min] > num[j])
            {
                min = j;
            }
        }
        //发生改变，交换
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
    //选择排序，第一层循环整个数组，每次归一位
    for (int i = 0; i < n - 1; i++)
    {
        int cmp = i;//最大位索引值，初试为乱序区第一位
        //第二层循环乱序位，每次从乱序列中选择学号最小的一位
        for (int j = i + 1; j < n; j++)
        {
            if ((*compare)(num[cmp], num[j]))
            {
                cmp = j;
            }
        }
        //发生改变，交换
        if (i != cmp)
        {
            LongSwap(&num[i], &num[cmp]);

            FloatSwap(&score[i], &score[cmp]);
        }
    }
}

void SortbyNum(long num[], char name[][MAX_LEN], float score[], int n, int(*compare)(int a, int b))
{
    //选择排序，第一层循环整个数组，每次归一位
    for (int i = 0; i < n - 1; i++)
    {
        int cmp = i;//最大位索引值，初试为乱序区第一位
        //第二层循环乱序位，每次从乱序列中选择学号最小的一位
        for (int j = i + 1; j < n; j++)
        {
            if ((*compare)(num[cmp], num[j]))
            {
                cmp = j;
            }
        }
        //发生改变，交换
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
    //选择排序，第一层循环整个数组，每次归一位
    for (int i = 0; i < n - 1; i++)
    {
        int cmp = i;//最大位索引值，初试为乱序区第一位
        //第二层循环乱序位，每次从乱序列中选择字典顺序靠前的一位
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(name[cmp],name[j])>0)//对比位比乱序位大，不行要换，保持对比位最小（升序）
            {
                cmp = j;
            }
        }
        //发生改变，交换
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
    int rank = -1;//学生排名
    int x;//被查询学号
    while (true)
    {
        printf("Please enter the student ID queried\n");
        scanf_s("%d", &x);
        SortbyScore(num, name, score, n, Descending);//先排序
        //顺序查找
        for (int i = 0; i < n; i++)
        {
            if (x == num[i])
            {
                printf("name:%-10s rank:%-10d grade:%-10f\n", name[i], i + 1, score[i]);//索引+1为排名
                return i;
            }
        }
        printf("Can't find,please checkout again.\n");
    }
}

int SearchbyName(long num[], char name[][MAX_LEN], float score[], int n)
{
    int rank = -1;//学生排名
    char x[MAX_LEN];//被查询姓名
    while (true)
    {
        printf("Please enter the student name queried\n");
        gets_s(x, MAX_LEN);
        SortbyScore(num, name, score, n, Descending);//先排序
        //顺序查找
        for (int i = 0; i < n; i++)
        {
            if (strcmp(x, name[i]) == 0)
            {
                printf("name:%-10s rank:%-10d grade:%-10f\n", name[i], i + 1, score[i]);//索引+1为排名
                return i;
            }
        }
        printf("Can't find,please checkout again.\n");
    }
}

void StatistAnalysis(float score[], int n)
{
    int ranks[5] = {0};// 各种档次的人数，首位赋值为0，后续位补充为0
    for (int i = 0; i < n; i++)//遍历整个成绩，统计数据
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
        else//90到100档
        {
            ranks[4]++;
        }
    }
    //输出统计数据
    printf("rank            amount            percent\n");
    printf("0-59            %d                  %.0f%%\n", ranks[0], ranks[0] / (float)n * 100);
    printf("60-69           %d                  %.0f%%\n", ranks[1], ranks[1] / (float)n * 100);
    printf("70-79           %d                  %.0f%%\n", ranks[2], ranks[2] / (float)n * 100);
    printf("80-89           %d                  %.0f%%\n", ranks[3], ranks[3] / (float)n * 100);
    printf("90-100          %d                  %.0f%%\n", ranks[4], ranks[4] / (float)n * 100);
}

void PrintScore(long num[], float score[], int n)
{
    printf("学号      成绩      \n");
    for (int i = 0; i < n; i++)
    {
        printf("%-10d%-10f\n", num[i], score[i]);
    }
}

void PrintScore(long num[], char name[][MAX_LEN], float score[], int n)
{
    printf("%-10s%-10s%-10s\n","学号","姓名","成绩");
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