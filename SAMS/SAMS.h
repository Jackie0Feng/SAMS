/*程序功能:   学生成绩管理
编码者:   JackieFeng
日期:  08/11/2021
版本号:4.0
备注：
某班有最多不超过30人(具体人数由键盘输入）参加期末考试，考试科目最多不超过6门（具体门数由键盘输入）。用二维数组做函数参数编程实现如下菜单驱动的学生成绩管理系统：
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
#pragma once
#define STU_NUM 30      //最多人数
#define MAX_LEN 10      //名字最大长度
#define COURSE_NUM 6//课程数上限
/*
函数名称:   Mean
功能描述:   显示菜单页面，提示用户如何使用
参数:
返回:
备注：*/
int Mean(void);
/*
函数名称:   ReadScore
功能描述:   录入每个学生的学号和成绩,并返回总人数
参数:
    num[]:学号
    score[]:分数
    n:总人数
返回:总人数
备注：弃用*/
//int ReadScore(long num[], float score[], int n);
/*
函数名称:   ReadScore
功能描述:   录入每个学生的学号和成绩,并返回总人数
参数:
    num[]:学号
    name[]:姓名
    score[]:分数
    n：总人数
返回:总人数
备注：弃用*/
int ReadScore(long num[], char name[][MAX_LEN], float score[], int n);
/*
函数名称:   ReadScore
功能描述:   录入每个学生的学号和成绩,并返回总人数
参数:
    num[]:学号
    name[]:姓名
    score[][COURSE_NUM]:每门课分数
    n:实际总人数
    m:实际课程数
返回:变化后总人数
备注：*/
int ReadScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], int n, int m);
/*
函数名称:   AverSumofScore
功能描述:   计算总分和平均值并输出
参数:
    score[]:分数
    n:总人数
返回:
备注：弃用*/
int AverSumofScore(float score[], int n);
/*
函数名称:   AverSumofEveryCourse
功能描述:   计算每门课程的总分和平均分
参数:
    score[][COURSE_NUM]:分数
    n:总人数
    m:课程总数
返回:
备注：*/
void AverSumofEveryCourse(float score[][COURSE_NUM], int n, int m);
/*
函数名称:   AverSumofEveryCourse
功能描述:   计算每个学生的总分和平均分
参数:
    score[][COURSE_NUM]:分数
    sum[]:学生的总分
    aver[]:学生的平均分
    n:总人数
    m:课程总数
返回:
备注：*/
void AverSumofEveryStudent(float score[][COURSE_NUM], float sum[], float aver[], int n, int m);
/*
函数名称:   DeSortbyScore
功能描述:   按照成绩降序排列名次表
参数:
    num[]:学号
    score[]:分数
    n:总人数
返回:
备注：已弃用，被使用函数指针参数的SortbyScore替用*/
//void DeSortbyScore(long num[], float score[], int n);
/*
函数名称:   SortbyScore
功能描述:   按照成绩排列名次表,使用函数指针表达升降序
参数:
    num[]:学号
    score[]:分数
    n:总人数
    *compare：比较函数指针
返回:
备注：老版已弃用*/
//void SortbyScore(long num[], float score[], int n, int (*compare)(int a, int b));
/*
函数名称:   SortbyScore
功能描述:   按照成绩排列名次表,使用函数指针表达升降序
参数:
    num[]:学号
    name[]:姓名
    score[]:分数
    n:总人数
    *compare：比较函数指针
返回:
备注：弃用*/
//void SortbyScore(long num[], char name[][MAX_LEN], float score[], int n, int (*compare)(int a, int b));
/*
函数名称:   SortbyScore
功能描述:   按照学生总分排列名次表,使用函数指针表达升降序
参数:
    num[]:学号
    name[]:姓名
    score[]:分数
    sum[]:学生的总分
    aver[]:学生的平均分
    n:总人数
    m:课程总数
    *compare：比较函数指针
返回:
备注：*/
void SortbyScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m, int (*compare)(int a, int b));
/*
函数名称:   AsSortbyNum
功能描述:   按照学号升序排列
参数:
    num[]:学号
    score[]:分数
    n:总人数
返回:
备注：已弃用，被使用函数指针参数的SortbyNum替用*/
//void AsSortbyNum(long num[], float score[], int n);
/*
函数名称:   SortbyNum
功能描述:   按照学号升序排列
参数:
    num[]:学号
    score[]:分数
    n:总人数
    *compare：比较函数指针
返回:
备注:老版已弃用*/
//void SortbyNum(long num[], float score[], int n, int(*compare)(int a, int b));
/*
函数名称:   SortbyNum
功能描述:   按照学号升序排列
参数:
    num[]:学号
    name[]:姓名
    score[]:分数
    n:总人数
    *compare：比较函数指针
返回:
备注弃用*/
//void SortbyNum(long num[], char name[][MAX_LEN], float score[], int n, int(*compare)(int a, int b));
/*
函数名称:   SortbyNum
功能描述:   按照学号升序排列
参数:
    num[]:学号
    name[]:姓名
    score[]:分数
    sum[]:学生的总分
    aver[]:学生的平均分
    n:总人数
    m:课程总数
    *compare：比较函数指针
返回:
备注:*/
void SortbyNum(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m, int (*compare)(int a, int b));
/*
函数名称:   SortbyName
功能描述:   按照姓名字典顺序排列
参数:
    num[]:学号
    name[]:姓名
    score[]:分数
    n:总人数
返回:
备注弃用*/
//void SortbyName(long num[], char name[][MAX_LEN], float score[], int n);
/*
函数名称:   SortbyName
功能描述:   按照姓名字典顺序排列
参数:
    num[]:学号
    name[]:姓名
    score[]:分数
    sum[]:学生的总分
    aver[]:学生的平均分
    n:总人数
    m:课程总数
返回:
备注*/
void SortbyName(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m);
/*
函数名称:   SearchbyNum
功能描述:   按学号查询学生排名及其考试成绩
参数:
    num[]:学号
    name[]:姓名
    score[]:分数
    n:总人数
返回:索引号
备注：弃用*/
//int SearchbyNum(long num[], char name[][MAX_LEN], float score[], int n);
/*
函数名称:   SearchbyNum
功能描述:   按学号查询学生排名及其各科考试成绩；
参数:
    num[]:学号
    name[]:姓名
    score[]:分数
    sum[]:学生的总分
    aver[]:学生的平均分
    n:总人数
    m:课程总数
返回:索引号
备注：*/
int SearchbyNum(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m);
/*
函数名称:   SearchbyName
功能描述:   按学号查询学生排名及其考试成绩
参数:
    num[]:学号
    name[]:姓名
    score[]:分数
    n:总人数
返回:索引号
备注：弃用*/
//int SearchbyName(long num[], char name[][MAX_LEN], float score[], int n);
/*
函数名称:   SearchbyName
功能描述:   按姓名查询学生排名及其各科考试成绩；
参数:
    num[]:学号
    name[]:姓名
    score[]:分数
    sum[]:学生的总分
    aver[]:学生的平均分
    n:总人数
    m:课程总数
返回:索引号
备注：*/
int SearchbyName(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m);
/*
函数名称:   StatistAnalysis
功能描述:   按优秀(90 - 100)、良好(80 - 89)、中等(70 - 79)、及格(60 - 69)、不及格（0 - 59)5个类别, 
                 统计每个类别的人数以及所占的百分比;
参数:
    num[]:学号
    score[]:分数
    n:总人数
返回:
备注：*/
//void StatistAnalysis( float score[], int n);
/*
函数名称:   StatistAnalysis
功能描述:   按优秀(90- 100)、良好(80- 89)、中等(70-79)、及格(60- 69)、不及格（0-59)5个类别,
                 对每门课程分别统计每个类别的人数以及所占的百分比;
参数:
    num[]:学号
    score[][COURSE_NUM]:分数
    n:总人数
    m:总课程数
返回:
备注：*/
void StatistAnalysis(float score[][COURSE_NUM], int n, int m);
/*
函数名称:   PrintScore
功能描述:   打印每位学生的成绩
参数:
    num[]:学号
    score[]:分数
    n:总人数
返回：
备注：弃用*/
//void PrintScore(long num[], float score[],int n);
/*
函数名称:   PrintScore
功能描述:   打印每位学生的学号，姓名和成绩
参数:
    num[]:学号
    name[]:姓名
    score[]:分数
    n:总人数
返回：
备注：弃用*/
//void PrintScore(long num[], char name[][MAX_LEN], float score[], int n);
/*
函数名称:   PrintScore
功能描述:   打印每位学生的学号，姓名和成绩
参数:
    num[]:学号
    name[][MAX_LEN]:姓名
    score[][COURSE_NUM]:每门课
    sum[]:学生的总分
    aver[]:学生的平均分
    n:总人数
    m:课程总数
返回：
备注：*/
void PrintScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m);
/*
函数名称:   FloatSwap
功能描述:   交换两个浮点型变量
参数:
    a:float型指针
    b:float型指针
返回：
备注：*/
void FloatSwap(float* a, float* b);
/*
函数名称:   LongSwap
功能描述:   交换两个长整型变量
参数:
    a:long型指针
    b:long型指针
返回：
备注：*/
void LongSwap(long* a, long* b);
/*
函数名称:   LongSwap
功能描述:   交换两个长整型变量
参数:
    a:long型指针
    b:long型指针
返回：
备注：*/
void CharSwap(char a[], char b[]);
/*
函数名称:   Ascending
功能描述:   升序比较函数
参数:
    a:比较数
    b:比较数
返回:a<b
备注：*/
int Ascending(int a, int b);
/*
函数名称:   Descending
功能描述:   降序比较函数
参数:
    a:比较数
    b:比较数
返回:a>b
备注：*/
int Descending(int a, int b);