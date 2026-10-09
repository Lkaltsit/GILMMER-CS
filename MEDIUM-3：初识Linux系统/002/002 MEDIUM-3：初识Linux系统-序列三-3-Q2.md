```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

ino_t get_inode(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) == -1) {
        perror("stat failed");
        exit(EXIT_FAILURE);
    }
    return statbuf.st_ino;
}
typedef struct Node
{
    char *name;
    struct Node *next;
}Node;
typedef struct List
{
    Node *head;
    Node *tail;
}List;

void headadd(List *list,const char *name)
{
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->name=strdup(name);
    newNode->next=list->head;
    list->head=newNode;
    
}

void mypwd(const char *path)
{
    Dir *dir=opendir(path);
    if(dir==NULL)
    {
        perror("opendir");
        return;
    }
    List list;
    list.head=NULL;
    list.tail=NULL;
    int temp1=get_inode(path);
    closedir(dir);
   
    while(get_inode(".")!=get_inode(".."))
    {
        chdir("..");
        Dir *dir_parent=opendir(".");
        if(dir_parent==NULL)
        {
            perror("opendir");
            return;
        }
        struct dirent *entry;
        while((entry=readdir(dir_parent))!=NULL)
        {
            const char *name=entry->d_name;
            int temp2=get_inode(name);
            if(temp1==temp2)
            {
                headadd(&list,name);
                break;
            }
            temp1=get_inode(".");
        }
        closedir(dir_parent);
    }
    
    printf("/");
    for(Node *p=list.head;p;p=p->next)
    {
        printf("%s/",p->name);
    }
}
```