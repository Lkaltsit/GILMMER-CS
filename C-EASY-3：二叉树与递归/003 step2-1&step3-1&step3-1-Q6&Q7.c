#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;
typedef struct Stack {
    TreeNode **arr;
    int top;
    int capacity;
} Stack;
TreeNode* create_node(int value);
TreeNode* create_root(int value);
TreeNode* create_tree_left(TreeNode *tree,int value);
TreeNode* create_tree_right(TreeNode *tree,int value);
//void print_tree(TreeNode *tree);
void headrootfind(TreeNode *tree_root);
void mediumrootfind(TreeNode *tree_root);
void tailrootfind(TreeNode *tree_root);
int depth(TreeNode *root, int current_depth, int max_depth);
void preorderTraversal(TreeNode *root);
int main()
{
    TreeNode *root=create_root(1);
    TreeNode *n1=create_tree_left(root,2);
    TreeNode *n2=create_tree_right(root,3);
    TreeNode *n3=create_tree_left(n1,4);
    TreeNode *n4=create_tree_right(n1,5);
    TreeNode *n5=create_tree_left(n2,6);
    TreeNode *n6=create_tree_right(n2,7);
    TreeNode *n8=create_tree_right(n3,9);
    headrootfind(root);
    printf("\n");
    mediumrootfind(root);
    printf("\n");
    tailrootfind(root);
    printf("\n");
    /*while(root)
    {
        if(!root->printed)
        {
            print_tree(root);
        }
        else if(root->left&&!root->left->printed)
        {
            root=root->left;
        }
        else if(root->right&&!root->right->printed)
        {
            root=root->right;
        }
        else
        {
            root=root->parent;
            if(!root)
            {

            }
        }
    }*/
    printf("%d\n",depth(root,1,1));
    preorderTraversal(root);
    return 0;
}
TreeNode* create_node(int value)
{
    TreeNode *newNode=(TreeNode*)malloc(sizeof(TreeNode));
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
TreeNode* create_root(int value)
{
    TreeNode *root=create_node(value);
    return root;
}
TreeNode* create_tree_left(TreeNode *tree,int value)
{
    if(tree&&tree->left==NULL)
    {
        tree->left=create_node(value);
    }
    else
    {
        printf("Error");
    }
    return tree->left;
    

}
TreeNode* create_tree_right(TreeNode *tree,int value)
{
    if(tree&&tree->right==NULL)
    {
        tree->right=create_node(value);
    }
    else
    {
        printf("Error");
    }
    return tree->right;

}
/*void print_tree(TreeNode *tree)
{
    printf("%d ",tree->data);
    tree->used=true;
}*/
/*void headrootfind(TreeNode *tree_root)
{
    TreeNode *findp=tree_root;
    if(tree_root->left)
    {
        TreeNode *temp=tree_root->left;
        findp=temp;
        findp->used=true;
        headrootfind(findp);
    }
    else if(findp->used==true&&tree_root->right)
    {
        TreeNode *temp=tree_root->right;
        findp=temp;
        findp->used=true;
        headrootfind(findp);
    }
}*/ //ok啊 成功地写出了没有意义的递归 用不着啊。
void headrootfind(TreeNode *tree_root)//先序
{
    if(tree_root!=NULL)
    {
        printf("%d\t",tree_root->data);
        headrootfind(tree_root->left);
        headrootfind(tree_root->right);
    }
}
void mediumrootfind(TreeNode *tree_root)//中序
{
    if(tree_root!=NULL)
    {
        mediumrootfind(tree_root->left);
        printf("%d\t",tree_root->data);
        mediumrootfind(tree_root->right);
    }
}
void tailrootfind(TreeNode *tree_root)//后序
{
    if(tree_root!=NULL)
    {
        tailrootfind(tree_root->left);
        tailrootfind(tree_root->right);
        printf("%d\t",tree_root->data);
    }
}
//学到这的时候 发现好简洁 很美的递归 自己想的还是复杂了

Stack *createStack(int capacity) 
{
    Stack *stack = malloc(sizeof(Stack));//申请一个栈
    stack->arr = malloc(sizeof(TreeNode *) * capacity);//申请整个栈的容量 防止极端情况 类似链表的树
    stack->top = -1;//栈顶
    stack->capacity = capacity;//栈容量
    return stack;//返回创建后的栈
}
int isEmpty(Stack *stack) 
{
    return stack->top == -1;//判断是否为空 用以后续确认是不是走完了整个树
}
void push(Stack *stack, TreeNode *node) 
{
    if (stack->top == stack->capacity - 1) 
    {
        return;//避免栈溢出
    }
    stack->arr[++stack->top] = node;//节点入栈
}
TreeNode *pop(Stack *stack) 
{
    if (isEmpty(stack)) 
    {
        return NULL;//为空则不操作
    }
    return stack->arr[stack->top--];//这里双出口真的好吗。? 想听一下学长怎么看单一出口与多出口的
    //节点出栈
}
int depth(TreeNode *root, int current_depth, int max_depth)
{
    if(root!=NULL)
    {
        if(current_depth>max_depth)
        {
            max_depth=current_depth;
        }
        int left_max=depth(root->left,current_depth+1,max_depth);
        int right_max=depth(root->right,current_depth+1,max_depth);
        return (left_max>right_max)?left_max:right_max;
    }
    else
    {
        return max_depth;
    }
}
void preorderTraversal(TreeNode *root)// 补全这个函数
{
    Stack *traversal=createStack(100);
    TreeNode *proot=root;
    while(!isEmpty(traversal)||proot)
    {
        if(proot)
        {
            printf("%d\t",proot->data);
            push(traversal,proot);
            proot=proot->left;
        }
        else
        {
            proot=pop(traversal);
            proot=proot->right;
        }   
    }
} 
