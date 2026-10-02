```c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void poor_binary_sub(char s1[],char s2[],char result[]);
int binary_add(char s1[],char s2[],char result[],int number);
int get10number(char s[],int len);
int compare_binary(char e1[4], char e2[4]);


int main()
{
    char fpnumber_1[10];
    char fpnumber_2[10];

    //char fpnsign_1[1];
    //char fpnsign_2[1];

    char exponent_1[4];
    char exponent_2[4];

    char significand_1[5];
    char significand_2[5];

    char ex_result[4];

    significand_1[0]='1';
    significand_2[0]='1';
    significand_1[4]='\0';
    significand_2[4]='\0';

    int shift_number=0;

    char *Newsignificand_1,*Newsignificand_2;

    char max_exponent[4];
    char Newexponent[4];

    char Newfpnumber[10];

    scanf("%9s",fpnumber_1);
    scanf("%9s",fpnumber_2);

    for(int i=0;i<4;i++)
    {
        /*fpnsign_1[0]=fpnumber_1[0];
        fpnsign_2[0]=fpnumber_2[0];*/
        exponent_1[i]=fpnumber_1[1+i];
        exponent_2[i]=fpnumber_2[1+i];
        
    }
    for(int i=0;i<3;i++)
    {
        significand_1[i+1]=fpnumber_1[5+i];
        significand_2[i+1]=fpnumber_2[5+i];
    }
    
    if(compare_binary(exponent_1,exponent_2)>0)
    {
        poor_binary_sub(exponent_1,exponent_2,ex_result);
        memcpy(max_exponent,exponent_1,4);
        shift_number=get10number(ex_result,4);
        Newsignificand_1=(char*)malloc((shift_number+4)*sizeof(char));
        Newsignificand_2=(char*)malloc((shift_number+4)*sizeof(char));
        memset(Newsignificand_1,'0',shift_number+4);
        memset(Newsignificand_2,'0',shift_number+4);
        for(int i=0;i<4;i++)
        {
            Newsignificand_2[i+shift_number]=significand_2[i];
            Newsignificand_1[i]=significand_1[i];
        }
    }
    else if(compare_binary(exponent_1,exponent_2)<0)
    {
        poor_binary_sub(exponent_2,exponent_1,ex_result);
        memcpy(max_exponent,exponent_2,4);
        shift_number=get10number(ex_result,4);
        Newsignificand_1=(char*)malloc((shift_number+4)*sizeof(char));
        Newsignificand_2=(char*)malloc((shift_number+4)*sizeof(char));
        memset(Newsignificand_1,'0',shift_number+4);
        memset(Newsignificand_2,'0',shift_number+4);
        for(int i=0;i<4;i++)
        {
            Newsignificand_1[i+shift_number]=significand_1[i];
            Newsignificand_2[i]=significand_2[i];
        }
    }
    else
    {
        memcpy(max_exponent,exponent_1,4);
        shift_number=0;
        Newsignificand_1=(char*)malloc((shift_number+4)*sizeof(char));
        Newsignificand_2=(char*)malloc((shift_number+4)*sizeof(char));
        memset(Newsignificand_1,'0',shift_number+4);
        memset(Newsignificand_2,'0',shift_number+4);
        for(int i=0;i<4;i++)
        {
            Newsignificand_1[i]=significand_1[i];
            Newsignificand_2[i]=significand_2[i];
        }
    }

    int total=shift_number+4;
    char *Need_normalized_number=(char*)malloc((total+1)*sizeof(char));
    char *Newnormalized_number=(char*)malloc((total+1)*sizeof(char));
    memset(Need_normalized_number,'0',total+1);
    memset(Newnormalized_number,'0',total+1);
    int carry=binary_add(Newsignificand_1,Newsignificand_2,Need_normalized_number+1,shift_number+4);
    Need_normalized_number[0]=carry+'0';

    /*printf("shift_number=%d total=%d\n",shift_number,total);
    
    for(int i=0;i<total+1;i++)
    {
        printf("[%d]=%d('%c')\n",i,Need_normalized_number[i],Need_normalized_number[i]);
    }
    for(int i=0;i<total+1;i++)
    {
        printf("%c",Need_normalized_number[i]);
    }*/

    if(carry)
    {
        
        memcpy(Newnormalized_number,Need_normalized_number,total+1);
        char one[4]={'0','0','0','1'};
        binary_add(max_exponent,one,Newexponent,4);
    }
    else
    {
        memcpy(Newnormalized_number,Need_normalized_number,total+1);
        memcpy(Newexponent,max_exponent,4);
    }


    Newfpnumber[0]='0';
    for(int i=0;i<4;i++)
    {
        Newfpnumber[1+i]=Newexponent[i];
    }
    for(int i=0;i<3;i++)
    {
        Newfpnumber[5+i]=Newnormalized_number[1+i];    
    }
    Newfpnumber[8]='\0';

    /*printf("Newsignificand_1:");
    for(int i=0;i<total;i++)
    {
        printf("%c",Newsignificand_1[i]);
    }
    printf("\n");
    printf("Newsignificand_2:");
    for(int i=0;i<total;i++)
    {
        printf("%c",Newsignificand_2[i]);
    }
    printf("\n");
    printf("Need_normalized_number:");
    for(int i=0;i<total+1;i++)
    {
        printf("%c",Need_normalized_number[i]);
    }
    printf("\n");
    printf("Newnormalized_number:");

    for(int i=0;i<total+1;i++)
    {
        printf("%c",Newnormalized_number[i]);
    }
    printf("\n");
    printf("Newexponent:");
    for(int i=0;i<4;i++)
    {
        printf("%c",Newexponent[i]);
    }
    printf("\n");
    */
    printf("%s",Newfpnumber);
}

void poor_binary_sub(char s1[],char s2[],char result[])
{
    int borrow=0;
    for(int i=3;i>=0;i--)
    {
        int diff=(s1[i]-'0')-(s2[i]-'0')-borrow;
        if(diff<0)
        {
            result[i]=diff+2+'0';
            borrow=1;
        }
        else
        {
            result[i]=diff+'0';
            borrow=0;
        }
    }
}

int binary_add(char s1[],char s2[],char result[],int number)
{
    int carry=0;
    for(int i=number-1;i>=0;i--)
    {
        int diff=(s1[i]-'0')+(s2[i]-'0')+carry;
        if(diff>1)
        {
            result[i]=diff-2+'0';
            carry=1;
        }
        else
        {
            result[i]=diff+'0';
            carry=0;
        }
    }
    return carry;
}

int get10number(char s[],int len)
{
    int ret=0;
    for(int i=0;i<len;i++)
    {
        ret=ret*2+(s[i]-'0');
    }
    return ret;
}

int compare_binary(char e1[4], char e2[4]) 
{
    for (int i = 0; i < 4; i++) {
        if (e1[i] > e2[i]) return 1;
        if (e1[i] < e2[i]) return -1;
    }
    return 0;
}
```