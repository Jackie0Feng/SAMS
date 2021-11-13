/*程序功能:   学生成绩管理
编码者:   JackieFeng
日期:  13/11/2021
版本号:5.0
备注：
某班有最多不超过30人(具体人数由键盘输入）参加期末考试，考试科目最多不超过6门（具体门数由键盘输入）。
定义结构体类型，用结构体数组作函数参数编程实现如下菜单驱动的学生成绩管理系统：
(1)录入每个学生的学号，姓名和各科考试成绩；
(2)计算每门课程的总分和平均分；
(3)计算每个学生的总分和平均分
(4)按每个学生的总分由高到低排出名次表；
(5)按每个学生的总分由低到高排出名次表；
(6)按学号由小到大排出成绩表；
(7)按姓名的字典顺序排出成绩表；
(8)按学号查询学生排名及其各科考试成绩；
(9)按姓名查询学生排名及其各科考试成绩；
(10)按优秀(90- 100)、良好(80- 89)、中等(70-79)、及格(60- 69)、不及格（0-59)5个类别,对每门课程分别统计每个类别的人数以及所占的百分比;
(11)输出每个学生的学号、姓名，各科考试成绩，总分，平均分，以及每门课程的总分和平均分。*/
#include <stdio.h>
#include "SAMS.h"
#include <string.h>
#include <stdlib.h>
//#pragma warning(disable : 4996)

int main()
{
    int order = -1;//用户指令
    
    /*int n;
    long num[STU_NUM];
    float score[STU_NUM];*/
    //初始数据
    int n = 5;//学生人数
    int m = 3;//课程数

    long num[STU_NUM] = { 10001,10002,10003,10004,10005 };
    char name[][MAX_LEN] = { "tom","jack","bill","amy","jackie" };
    float score[STU_NUM] = { 20.0,80.0,50.0,66.0,95.0 };
    float score2[STU_NUM][COURSE_NUM] = { {20.0,80.0,50.0},//2表示二维
                                                                        {66.0,95.0,77.0},
                                                                        {63.0,77.0,81.0},
                                                                        {86.0,43.0,72.0},
                                                                        {96.0,95.0,89.0} };
    /*这次改变了一个字段，将一维的课程升级为了二维数组，
    又新增了一个功能统计每个学生所有课程的平均分和总分，
    所以需要新增两个一维数组sum[],aver[]存储一下此信息.*/
    float sum[STU_NUM] = { 0 };
    float aver[STU_NUM] = { 0 };
    //AverSumofEveryStudent(score2, sum, aver, n, m);

    //初始化结构体数组数据
    STU students[STU_NUM];
    for (int i = 0; i < n; i++)
    {
        students[i].num = num[i];
        strcpy_s(students[i].name, MAX_LEN, name[i]);
        for (int j = 0; j < m; j++)
        {
            students[i].score[j] = score2[i][j];
        }
    }
    AverSumofEveryStudent(students, n, m);

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
            n = ReadScore(students, n, m);
            AverSumofEveryStudent(students, n, m);//每次录入结束后都得重新计算
            break;
        case 2://计算每门课程的总分和平均分；
            AverSumofEveryCourse(students, n, m);
            break;
        case 3://计算每个学生的总分和平均分
            AverSumofEveryStudent(students, n, m);
            printf("已经重新计算总分和平均分\n");
            break;
        case 4://按每个学生的总分由高到低排出名次表；
            SortbyScore(students, n, m, Descending);
            printf("Descendingly scorted by scores:\n");
            PrintScore(students, n, m);
            break;
        case 5://按每个学生的总分由低到高排出名次表；
            SortbyScore(students, n, m, Ascending);
            printf("Ascendingly scorted by scores:\n");
            PrintScore(students, n, m);
            break;
        case 6://按学号升序排名
            SortbyNum(students, n, m, Ascending);
            printf("Ascendingly scorted by num:\n");
            PrintScore(students, n, m);
            break;
        case 7://按姓名的字典顺序排出成绩表；
            SortbyName(students, n, m);
            printf("Dictionarily scorted by name:\n");
            PrintScore(students, n, m);
            break;
        case 8://按学号查询学生排名及其各科考试成绩；
            SearchbyNum(students, n, m);
            break;
        case 9://按姓名查询学生排名及其各科考试成绩；
            SearchbyName(students, n, m);
            break;
        case 10://按优秀(90- 100)、良好(80- 89)、中等(70-79)、及格(60- 69)、不及格（0-59)5个类别,
                   //统计每个类别的人数以及所占的百分比;
            StatistAnalysis(students, n, m);
            break;
        case 11://输出每个学生的学号、姓名，各科考试成绩，总分，平均分，以及每门课程的总分和平均分。
            PrintScore(students, n, m);
            AverSumofEveryCourse(students, n, m);
            break;
        case 0://退出系统
            printf("Good Bye!\n");
            exit(0);//建议main函数用exit(0)表示正常结束
        default:
            Mean();
            break;
        }
    }
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

int ReadScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], int n, int m)
{
    printf("正在录入学生信息...\n");
    printf("学号录入-1时结束录入\n");
    int i = n - 1;
    do
    {
        i++;
        printf("正在录入第%d个学生的学号,姓名\n", i + 1);
        //scanf("%ld%s%f", &num[i], name[i], &score[i]);//数值类型与字符串类型交叉输入可用空格隔开
        scanf_s("%ld", &num[i]);
        if (num[i] == -1)//若用户输入完毕则退出输入
            break;
        scanf_s("%s", name[i], 10);//scanf_s函数在输入字符串时必须指定字符串长度
        getchar();//读走回车符
        printf("请连续按顺序输入第%d个学生%d课成绩\n", i + 1, m);
        for (int j = 0; j < m; j++)
        {
            scanf_s("%f", &score[i][j]);
        }
    } while (i <= 30);
    printf("录入完成总共录入%d人\n", i);
    return i;
}

int ReadScore(STU students[], int n, int m)
{
    printf("正在录入学生信息...\n");
    printf("学号录入-1时结束录入\n");
    int i = n - 1;
    do
    {
        i++;
        printf("正在录入第%d个学生的学号,姓名\n", i + 1);
        //scanf("%ld%s%f", &num[i], name[i], &score[i]);//数值类型与字符串类型交叉输入可用空格隔开
        scanf_s("%ld", &students[i].num);
        if (students[i].num == -1)//若用户输入完毕则退出输入
            break;
        scanf_s("%s", students[i].name, 10);//scanf_s函数在输入字符串时必须指定字符串长度
        getchar();//读走回车符
        printf("请连续按顺序输入第%d个学生%d课成绩\n", i + 1, m);
        for (int j = 0; j < m; j++)
        {
            scanf_s("%f", &students[i].score[j]);
        }
    } while (i <= 30);
    printf("录入完成总共录入%d人\n", i);
    return i;
}

void AverSumofEveryCourse(float score[][COURSE_NUM], int n, int m)
{
    float sum[COURSE_NUM] = { 0 };
    float aver[COURSE_NUM] = { 0 };
    //i行j列，算课程总分，按列算总和
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            sum[j] += score[i][j];
        }
        aver[j] = sum[j] / n;
        printf("科目%d的总分为%.2f,平均分为%.2f\n", j + 1, sum[j], aver[j]);
    } 
}

void AverSumofEveryCourse(STU students[], int n, int m)
{
    float sum[COURSE_NUM] = { 0 };
    float aver[COURSE_NUM] = { 0 };
    //i行j列，算课程总分，按列算总和
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            sum[j] += students[i].score[j];
        }
        aver[j] = sum[j] / n;
        printf("科目%d的总分为%.2f,平均分为%.2f\n", j + 1, sum[j], aver[j]);
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

void AverSumofEveryStudent(STU students[], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        students[i].sum = 0;//每次计算总和都得先初始化sum为0
        for (int j = 0; j < m; j++)
        {
            students[i].sum += students[i].score[j];
        }
        students[i].aver = students[i].sum / m;
    }
}

void SortbyScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m, int(*compare)(int a, int b))
{
    //选择排序，第一层循环整个数组，每次归一位
    for (int i = 0; i < n - 1; i++)
    {
        int cmp = i;//比较位索引值，初始为乱序区第一位
        //第二层循环乱序位，每次从乱序列中选择最大一位
        for (int j = i; j < n; j++)
        {
            if (compare(sum[cmp], sum[j]))//比总分
            {
                cmp = j;
            }
        }
        //发生改变，交换
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

void SortbyScore(STU students[], int n, int m, int(*compare)(int a, int b))
{
    //选择排序，第一层循环整个数组，每次归一位
    for (int i = 0; i < n - 1; i++)
    {
        int cmp = i;//比较位索引值，初始为乱序区第一位
        //第二层循环乱序位，每次从乱序列中选择最大一位
        for (int j = i; j < n; j++)
        {
            if (compare(students[cmp].sum, students[j].sum))//比总分
            {
                cmp = j;
            }
        }
        //发生改变，交换
        if (i != cmp)
        {
            LongSwap(&students[i].num, &students[cmp].num);
            CharSwap(students[i].name, students[cmp].name);
            FloatSwap(&students[i].sum, &students[cmp].sum);
            FloatSwap(&students[i].aver, &students[cmp].aver);
            for (int j = 0; j < m; j++)
            {
                FloatSwap(&students[i].score[j], &students[cmp].score[j]);
            }
        }
    }
}

void SortbyNum(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m, int(*compare)(int a, int b))
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
            FloatSwap(&sum[i], &sum[cmp]);
            FloatSwap(&aver[i], &aver[cmp]);
            for (int j = 0; j < m; j++)
            {
                FloatSwap(&score[i][j], &score[cmp][j]);
            }
        }
    }
}

void SortbyNum(STU students[], int n, int m, int(*compare)(int a, int b))
{
    //选择排序，第一层循环整个数组，每次归一位
    for (int i = 0; i < n - 1; i++)
    {
        int cmp = i;//最大位索引值，初试为乱序区第一位
        //第二层循环乱序位，每次从乱序列中选择学号最小的一位
        for (int j = i + 1; j < n; j++)
        {
            if ((*compare)(students[cmp].num, students[j].num))
            {
                cmp = j;
            }
        }
        //发生改变，交换
        if (i != cmp)
        {
            LongSwap(&students[i].num, &students[cmp].num);
            CharSwap(students[i].name, students[cmp].name);
            FloatSwap(&students[i].sum, &students[cmp].sum);
            FloatSwap(&students[i].aver, &students[cmp].aver);
            for (int j = 0; j < m; j++)
            {
                FloatSwap(&students[i].score[j], &students[cmp].score[j]);
            }
        }
    }
}

void SortbyName(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m)
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
            FloatSwap(&sum[i], &sum[cmp]);
            FloatSwap(&aver[i], &aver[cmp]);
            for (int j = 0; j < m; j++)
            {
                FloatSwap(&score[i][j], &score[cmp][j]);
            }
        }
    }
}

void SortbyName(STU students[], int n, int m)
{
    //选择排序，第一层循环整个数组，每次归一位
    for (int i = 0; i < n - 1; i++)
    {
        int cmp = i;//最大位索引值，初试为乱序区第一位
        //第二层循环乱序位，每次从乱序列中选择字典顺序靠前的一位
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(students[cmp].name, students[j].name) > 0)//对比位比乱序位大，不行要换，保持对比位最小（升序）
            {
                cmp = j;
            }
        }
        //发生改变，交换
        if (i != cmp)
        {
            LongSwap(&students[i].num, &students[cmp].num);
            CharSwap(students[i].name, students[cmp].name);
            FloatSwap(&students[i].sum, &students[cmp].sum);
            FloatSwap(&students[i].aver, &students[cmp].aver);
            for (int j = 0; j < m; j++)
            {
                FloatSwap(&students[i].score[j], &students[cmp].score[j]);
            }
        }
    }
}

int SearchbyNum(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m)
{
    int rank = -1;//学生排名
    int x;//被查询学号
    while (true)
    {
        printf("Please enter the student ID queried\n");
        scanf_s("%d", &x);
        SortbyScore(num, name, score, sum, aver, n, m, Descending);//先排序
        //顺序查找
        for (int i = 0; i < n; i++)
        {
            if (x == num[i])
            {
                printf("name:%-10s rank:%-10d", name[i], i + 1);//索引+1为排名
                for (int j = 0; j < m; j++)
                {
                    printf("科目%d:%-10.1f", j + 1, score[i][j]);
                }
                printf("\n");
                return i;
            }
        }
        printf("Can't find,please checkout again.\n");
    }
}

int SearchbyNum(STU students[], int n, int m)
{
    int rank = -1;//学生排名
    int x;//被查询学号
    while (true)
    {
        printf("Please enter the student ID queried\n");
        scanf_s("%d", &x);
        SortbyScore(students, n, m, Descending);//先排序
        //顺序查找
        for (int i = 0; i < n; i++)
        {
            if (x == students[i].num)
            {
                printf("name:%-10s rank:%-10d", students[i].name, i + 1);//索引+1为排名
                for (int j = 0; j < m; j++)
                {
                    printf("科目%d:%-10.1f", j + 1, students[i].score[j]);
                }
                printf("\n");
                return i;
            }
        }
        printf("Can't find,please checkout again.\n");
    }
}

int SearchbyName(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m)
{
    int rank = -1;//学生排名
    char x[MAX_LEN];//被查询姓名
    while (true)
    {
        printf("Please enter the student name queried\n");
        gets_s(x, MAX_LEN);
        SortbyScore(num, name, score, sum, aver, n, m, Descending);//先排序
        //顺序查找
        for (int i = 0; i < n; i++)
        {
            if (strcmp(x, name[i]) == 0)
            {
                printf("name:%-10s rank:%-10d", name[i], i + 1);//索引+1为排名
                for (int j = 0; j < m; j++)
                {
                    printf("科目%d:%-10.1f", j + 1, score[i][j]);
                }
                printf("\n");
                return i;
            }
        }
        printf("Can't find,please checkout again.\n");
    }
}

int SearchbyName(STU students[], int n, int m)
{
    int rank = -1;//学生排名
    char x[MAX_LEN];//被查询姓名
    while (true)
    {
        printf("Please enter the student name queried\n");
        gets_s(x, MAX_LEN);
        SortbyScore(students, n, m, Descending);//先排序
        //顺序查找
        for (int i = 0; i < n; i++)
        {
            if (strcmp(x, students[i].name) == 0)
            {
                printf("name:%-10s rank:%-10d", students[i].name, i + 1);//索引+1为排名
                for (int j = 0; j < m; j++)
                {
                    printf("科目%d:%-10.1f", j + 1, students[i].score[j]);
                }
                printf("\n");
                return i;
            }
        }
        printf("Can't find,please checkout again.\n");
    }
}

void StatistAnalysis(float score[][COURSE_NUM], int n, int m)
{
    for (int j = 0; j < m; j++)//统计每门课
    {
        printf("科目%d情况如下：\n", j+1);

        int ranks[5] = { 0 };// 各种档次的人数，首位赋值为0，后续位补充为0
        for (int i = 0; i < n; i++)//遍历整个成绩，统计数据
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
            else//90到100档
            {
                ranks[4]++;
            }
        }
        //输出统计数据
		printf("%-10s%-10s%-10s\n", "rank ", "amount", "percent");
		printf("%-10s%-10d%.0f%%\n", "0-59 ", ranks[0], ranks[0] / (float)n * 100);
		printf("%-10s%-10d%.0f%%\n", "60-69", ranks[1], ranks[1] / (float)n * 100);
		printf("%-10s%-10d%.0f%%\n", "70-79", ranks[2], ranks[2] / (float)n * 100);
		printf("%-10s%-10d%.0f%%\n", "80-89", ranks[3], ranks[3] / (float)n * 100);
		printf("%-10s%-10d%.0f%%\n", "90-100", ranks[4], ranks[4] / (float)n * 100);
    }
}

void StatistAnalysis(STU students[], int n, int m)
{
    for (int j = 0; j < m; j++)//统计每门课
    {
        printf("科目%d情况如下：\n", j + 1);

        int ranks[5] = { 0 };// 各种档次的人数，首位赋值为0，后续位补充为0
        for (int i = 0; i < n; i++)//遍历整个成绩，统计数据
        {
            if (students[i].score[j] < 60)
            {
                ranks[0]++;
            }
            else if (students[i].score[j] < 70 && students[i].score[j] >= 60)
            {
                ranks[1]++;
            }
            else if (students[i].score[j] < 80 && students[i].score[j] >= 70)
            {
                ranks[2]++;
            }
            else if (students[i].score[j] < 90 && students[i].score[j] >= 80)
            {
                ranks[3]++;
            }
            else//90到100档
            {
                ranks[4]++;
            }
        }
        //输出统计数据
        printf("%-10s%-10s%-10s\n", "rank ", "amount", "percent");
        printf("%-10s%-10d%.0f%%\n", "0-59 ", ranks[0], ranks[0] / (float)n * 100);
        printf("%-10s%-10d%.0f%%\n", "60-69", ranks[1], ranks[1] / (float)n * 100);
        printf("%-10s%-10d%.0f%%\n", "70-79", ranks[2], ranks[2] / (float)n * 100);
        printf("%-10s%-10d%.0f%%\n", "80-89", ranks[3], ranks[3] / (float)n * 100);
        printf("%-10s%-10d%.0f%%\n", "90-100", ranks[4], ranks[4] / (float)n * 100);
    }
}

void PrintScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m)
{
    printf("%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n", "学号", "姓名", "科目一", "科目二", "科目三", "总分", "平均分");
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

void PrintScore(STU students[], int n, int m)
{
    printf("%-10s%-10s", "学号", "姓名");
    for (int j = 0; j < m; j++)
    {
        printf("%-4s%-6d", "科目", j + 1);//汉字一个字算两个width
    }
    printf("%-10s%-10s\n", "总分", "平均分");

    for (int i = 0; i < n; i++)
    {
        printf("%-10d%-10s", students[i].num, students[i].name);
        for (int j = 0; j < m; j++)
        {
            printf("%-10.1f", students[i].score[j]);
        }
        printf("%-10.1f%-10.1f", students[i].sum, students[i].aver);
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