/*程序功能:   学生成绩管理
编码者:   JackieFeng
日期:  04/11/2021
版本号:2.0
备注：
某班有最多不超过30人(具体人数由键盘输入）参加某门课的考试:用一维数组和函数指针作为函数参数编程实现如下学生成绩管理：
(1)录入每个学生的学号和考试成绩；
(2)计算课程的总分和平均分；
(3)按成绩由高到低排出名次表；
(4)按成绩由低到高排出名次表；
(5)按学号由小到大排出成绩表；
(6)按学号查询学生排名及其考试成绩；
(7)按优秀(90- 100)、良好(80- 89)、中等(70-79)、及格(60- 69)、不及格（0-59)5个类别,统计每个类别的人数以及所占的百分比;
(8)输出每个学生的学号、考试成绩，课程总分和平均分。*/
#include <stdio.h>
#include "SAMS.h"

int main()
{
    int order = -1;//用户指令
    
    /*int n;
    long num[STU_NUM];
    float score[STU_NUM];*/
    //初始数据
    int n = 5;
    long num[STU_NUM] = { 10001,10002,10003,10004,10005 };
    float score[STU_NUM] = { 20.0,80.0,50.0,66.0,95.0 };
    Mean();//显示菜单
    //使用系统
    while (1)
    {
        scanf_s("%d", &order);
        switch (order)
        {
        case 1://录入成绩
            n = ReadScore(num, score, n);
            break;
        case 2://求平均分和总分
            AverSumofScore(score, n);
            break;
        case 3://按成绩降序排名
            SortbyScore(num, score, n, Descending);
            printf("Descendingly scorted by scores:\n");
            PrintScore(num, score, n);
            break;
        case 4://按成绩升序排名
            SortbyScore(num, score, n, Ascending);
            printf("Ascendingly scorted by scores:\n");
            PrintScore(num, score, n);
            break;
        case 5://按学号升序排名
            AsSortbyNum(num, score, n);
            printf("Ascendingly scorted by num:\n");
            PrintScore(num, score, n);
            break;
        case 6://按学号查询学生排名及其考试成绩
        {//如果想在case标签初始化变量，必须加大括号{}
            int rank = -1;//学生排名
            int x;//被查询学号
            printf("Please enter the student ID queried\n");
            scanf_s("%d", &x);
            DeSortbyScore(num, score, n);//先排序
            rank = SearchbyNum(num, x, n);//即使排名也是所在数组的位置
            printf("The student's rank is %d and his grade is %f\n", rank+1, score[rank]);//索引+1为排名
            break;
        }
        case 7://按优秀(90- 100)、良好(80- 89)、中等(70-79)、及格(60- 69)、不及格（0-59)5个类别,
                   //统计每个类别的人数以及所占的百分比;
            StatistAnalysis( score, n);
            break;
        case 8://输出每个学生的学号、考试成绩，课程总分和平均分
            PrintScore(num, score, n);
            AverSumofScore(score, n);
            break;
        case 0://退出系统
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
    int max=0;//最大位索引值，初始为第一位
    //选择排序，第一层循环整个数组，每次归一位
    for (int i = 0; i < n-1; i++)
    {
        //第二层循环乱序位，每次从乱序列中选择最大一位
        for (int j = i; j < n; j++)
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
    int cmp = 0;//比较位索引值，初始为第一位
    //选择排序，第一层循环整个数组，每次归一位
    for (int i = 0; i < n - 1; i++)
    {
        //第二层循环乱序位，每次从乱序列中选择最大一位
        for (int j = i; j < n; j++)
        {
            if ((*compare)(score[cmp], score[j]))
            {
                cmp = j;
            }
        }
        //发生改变，交换
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
    int min = 0;//最大位索引值，初试为1
    //选择排序，第一层循环整个数组，每次归一位
    for (int i = 0; i < n - 1; i++)
    {
        //第二层循环乱序位，每次从乱序列中选择学号最小的一位
        for (int j = i; j < n; j++)
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

int SearchbyNum(long num[], long x, int n)
{
    //顺序查找
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
        printf("%d      %f      \n", num[i], score[i]);
    }
}