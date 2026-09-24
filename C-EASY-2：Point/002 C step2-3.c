#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int value;
    struct Node *next;
}Node;
typedef struct List
{
    Node *head;
    Node *tail;
}List;
void headadd(List *list,int number);
void tailadd(List *list,int number);
void print(List list);
void search(List list,int findnumber);
void change(List list,int changespace,int tochangenumber);
int delete_1(List *list,int deletespace);
void reverse(List *list);
int main()
{
    List list_1,list_2;
    list_1.head=list_2.head=NULL;
    list_1.tail=list_2.tail=NULL;
    int number;
	printf("请输入若干数字 停止输入则输入-1\n");
    do
    {
        scanf("%d",&number);
        if(number!=-1) 
        {
        	headadd(&list_1,number);
            tailadd(&list_2,number);
		}
        
    }while(number!=-1);
    print(list_1);
    print(list_2);
    search(list_1,1);
    search(list_2,1);
    change(list_1,2,4);
    change(list_2,2,4);
    print(list_1);
	print(list_2);
	reverse(&list_1);
	reverse(&list_2);
	print(list_1);
	print(list_2);
    delete_1(&list_1,5);
    delete_1(&list_2,5);
    print(list_1);
	print(list_2); 
    return 0;
}
void headadd(List *list,int number)
{
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->value=number;
    newNode->next=list->head;
    list->head=newNode;
    
}
void tailadd(List *list,int number)
{
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->value=number;
    newNode->next=NULL;
    if(list->head==NULL)
    {
        list->head=newNode;
        list->tail=newNode;
    }
    else
    {
        list->tail->next=newNode;
        list->tail=newNode;
    }
}
void print(List list)
{
    for(Node *p=list.head;p;p=p->next)
    {
        printf("%d ",p->value);
    }
}
void search(List list,int findnumber)
{
    Node *p=list.head;
    int cnt=1;
    while(p&&p->value!=findnumber)
    {
        cnt++;
        p=p->next;
    }
    if(p==NULL)
    {
        printf("false\n");
    }
    else
    {
        printf("找到了 是第%d个节点\n",cnt);
    }
}
void change(List list,int changespace,int tochangenumber)
{
    Node *p=list.head;
    int cnt=1;
    while(p&&cnt!=changespace)
    {
        cnt++;
        p=p->next;
    }
    p->value=tochangenumber;
}
int delete_1(List *list,int deletespace)
{
	int ret=0;
    int cnt_1=0;
    int cnt_2=1;
    for(Node *p=list->head;p;p=p->next)
    {
        cnt_1++;
    }
    if(cnt_1>=deletespace)
    {
        Node *head=list->head;
		Node *tail=list->head;
		tail=tail->next;
        while(cnt_2<=cnt_1)
        {
		    
        	if(deletespace==1)
        	{
            	Node *temp=list->head;
				list->head=list->head->next;//缓存原本的头->头移动->删除 
                free(temp);
        		break;
			}
			 cnt_2++;
            if(cnt_2==deletespace)
            {
            	Node *temp=tail->next;
            	head->next=temp;//可以合并 
                free(tail);
                //head=temp; //能够用在多次删除时 本次位定位删除 无用 
                tail=NULL;
                break; //临时变量缓存后节点地址->前节点指向临时变量->free 
            }
            else
            {
                head=head->next;
                tail=tail->next;//快慢指针 
            }
			
        }
        ret=1;
    }
    else
    {
    	ret=0;
	}
	return ret;
}
void reverse(List *list)
{
    Node *head=list->head;
	Node *tail=list->head->next;
    Node *temp=list->head;
    while(head)
    {
        
        if(head==temp)
        {
            head->next=NULL;
			head=tail;
        }
        else
        {
			head->next=temp;
			temp=head;
			head=tail;
        }
		
        if(tail)
        {
            tail=tail->next;
        }
    }
    list->head=temp;
    temp=NULL;
    head=NULL;
    tail=NULL;
}
void free()
{
    
}