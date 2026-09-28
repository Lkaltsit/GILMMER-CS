```c
#include <stdio.h>

void getamount(int n,int cl,int ld,int rd,int *amount,int Nowallow,int cnt);

int main()
{   
    int cl=0;
    int ld=0;
    int rd=0;
    int amount=0;
    int cnt=0;
    int n; 
    printf("请输入N=");
    scanf("%d",&n);
    int full=(1<<n)-1;
    int Nowallow=full;
    
    getamount(n,cl,ld,rd,&amount,Nowallow,cnt);
    printf("总共有%d种方案",amount);
}

void getamount(int n,int cl,int ld,int rd,int *amount,int Nowallow,int cnt)
{  
    int full=(1<<n)-1;
    if(cnt==n)
    {
        (*amount)++;
        return;
        
    }
    if(Nowallow==0)
    {
        return;
    }
    while(Nowallow)
    {
        int Nowchoose=Nowallow&-Nowallow;
        Nowallow-=Nowchoose;
        int NEWcl=cl|Nowchoose;
        int NEWld=(ld|Nowchoose)<<1;
        int NEWrd=(rd|Nowchoose)>>1;
        int NEWNowallow=full&(~(NEWcl|NEWld|NEWrd));
        getamount(n,NEWcl,NEWld,NEWrd,amount,NEWNowallow,cnt+1);      
    }       
 
   

}
```