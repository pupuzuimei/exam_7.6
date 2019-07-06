#include <iostream>
#include<fstream>
#include <algorithm>
#include<string>
#define statistics 6//改变学生人数
using namespace std;
struct student{
    string number;//学号
    string name;//姓名
    string sex;//性别
    string phone;
    int age;//年龄
    double score[7];//成绩
    double ave;//平均分
}a[statistics];
struct people{
    string referee;//裁判
    string people;
    string number1;//学号
    string name1;//姓名
    string sex1;//性别
    string phone1;
    double score[7];
};
bool cmp(student s1,student s2)
{
    return s1.ave>s2.ave;
}
int main() {
    student t[statistics];
    people k[statistics];
    int i,j;
    ofstream inf("/Users/s20181106278/Desktop/myinf.txt");
    ifstream onf("/Users/s20181106278/Desktop/onf.txt");
    ifstream enf("/Users/s20181106278/Desktop/enf.txt");
    ifstream unf("/Users/s20181106278/Desktop/unf.txt");
    if(onf.is_open())
    {
        for(i=0;i<statistics;++i)//向文件中输入学生信息
        {
            onf>>a[i].number>>a[i].name>>a[i].sex>>a[i].age>>a[i].phone;
        }
        onf.close();
    }
    if(unf.is_open())
    {
        for(i=0;i<statistics;++i)//向文件中输入裁判信息
        {
            unf>>k[i].number1>>k[i].name1>>k[i].sex1>>k[i].phone1;
        }
        onf.close();
    }
    if(enf.is_open())
    {
        for(j=0;j<7;j++)
        {
            enf>>k[j].referee;
        }
        for(j=0;j<statistics;++j)//输入裁判打的分数n
        {
            for(i=0;i<7;++i)
            {
                enf>>a[j].score[i];
            }
            enf>>a[j].number;
        }
        enf.close();
    }
    for(i=0;i<statistics;i++)//冒泡排序
        sort(a[i].score,a[i].score+7);
    for(j=0;j<statistics;++j)//求平均分
    {
        for(i=1;i<6;++i)
        {
            a[j].ave+=a[j].score[i];
        }
        a[j].ave/=5;
    }
    sort(a,a+statistics,cmp);//将平均分从大到小排序
    if(inf.is_open())
    {
        for(int i=0;i<statistics;i++)
        {
            inf<<a[i].number<<" "<<a[i].name<<" "<<a[i].sex<<" "<<a[i].age<<" "<<a[i].phone<<" "<<a[i].ave<<endl;
            for(j=0;j<7;j++)
            {
                inf<<a[i].score[j]<<" ";
            }
            inf<<endl;
        }
        inf.close();
    }
    return 0;
}
