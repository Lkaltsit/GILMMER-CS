#include <stdio.h>
typedef struct Perlnfo_1
{
    char name[1];
    char sex;
    int age;
    double height;
}perlnfo_1;
typedef struct Perlnfo_2
{
    char sex;
    char name[1];
    int age;
    double height;
}perlnfo_2;
typedef struct Perlnfo_3
{
    char sex;
    int age;
    char name[1];
    double height;
}perlnfo_3;
typedef struct Perlnfo_4
{
    char sex;
    int age;
    double height;
    char name[1];
}perlnfo_4;
int main()
{
    printf("%d字节",sizeof(perlnfo_1));
    printf("%d字节",sizeof(perlnfo_2));
    printf("%d字节",sizeof(perlnfo_3));
    printf("%d字节",sizeof(perlnfo_4));
    return 0;
}