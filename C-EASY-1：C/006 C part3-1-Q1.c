#include <stdio.h>
typedef struct allgrade
{
    int A;
    int B;
    int C;
}allgrade;
 
int outcheck(allgrade grade);
void scan(allgrade *grade);
void averagegrade(allgrade grade,int *result);
void variance(allgrade grade,int pgrade,int *result);
void overallgrade(int pgrade,int fgrade,int *result);
void swapandprint(int zh_x,int zh_y,int zh_z);
int main()
{
  allgrade x;
  int x_p;
  int x_f;
  int x_zh;
  allgrade y;
  int y_p;
  int y_f;
  int y_zh;
  allgrade z;
  int z_p;
  int z_f;
  int z_zh;
  do
  {
    printf("请输入小明的三项成绩（顺序为A B C,以一个空格为间隔）：");
    scan(&x);
    printf("请输入小强的三项成绩（顺序为A B C,以一个空格为间隔）：");
    scan(&y);
    printf("请输入小林的三项成绩（顺序为A B C,以一个空格为间隔）：");
    scan(&z);
  }
  while(!outcheck(x)||!outcheck(y)||!outcheck(z));
  averagegrade(x,&x_p);
  averagegrade(y,&y_p);
  averagegrade(z,&z_p);
  variance(x,x_p,&x_f);
  variance(y,y_p,&y_f);
  variance(z,z_p,&z_f);
  overallgrade(x_p,x_f,&x_zh);
  overallgrade(y_p,y_f,&y_zh);
  overallgrade(z_p,z_f,&z_zh);
  swapandprint(x_zh,y_zh,z_zh);
  return 0;
}
int outcheck(allgrade grade)
{   
    int ret=0;
    while(grade.A<=100&&grade.A>=0&&grade.B<=100&&grade.B>=0&&grade.C<=100&&grade.C>=0)
    {
        ret=1;
        break;
    }
    return ret;
}
void scan(allgrade *grade)
{
    scanf("%d %d %d", &grade->A, &grade->B, &grade->C);
}
void averagegrade(allgrade grade,int *result)
{
    *result=(grade.A+grade.B+grade.C)/3;
}
void variance(allgrade grade,int pgrade,int *result)
{
    *result=((pgrade-grade.A)*(pgrade-grade.A)+(pgrade-grade.B)*(pgrade-grade.B)+(pgrade-grade.C)*(pgrade-grade.C))/3;
}
void overallgrade(int pgrade,int fgrade,int *result)
{
    *result=3*pgrade-fgrade/3;
}
void swapandprint(int zh_x,int zh_y,int zh_z)
{
    int arr[3]={zh_x,zh_y,zh_z};
    int order[3]={0,1,2};
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2-i;j++)
        {
            if(arr[order[j]]>arr[order[j+1]])
            {
                int temp=order[j];
                order[j]=order[j+1];
                order[j+1]=temp;
            }
        }
    }
    const char *name[]={"小明","小强","小林"};
    printf("%s<%s<%s\n",name[order[0]],name[order[1]],name[order[2]]);
}
