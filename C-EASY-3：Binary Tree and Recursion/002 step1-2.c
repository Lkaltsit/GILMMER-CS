#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TREE_SIZE 100

typedef struct SeqTreeNode
{
    int data;
    bool used;
} SeqTreeNode;
typedef struct SeqBiTree 
{
    SeqTreeNode nodes[MAX_TREE_SIZE];
    int size;
} SeqBiTree;

void init_tree(SeqBiTree *tree);
void set_root(SeqBiTree *tree, int value);
void set_left_child(SeqBiTree *tree, int parent_node, int value);
void set_right_child(SeqBiTree *tree, int parent_node, int value);
void level_order(SeqBiTree *tree);

int main()
{
    SeqBiTree tree;
    init_tree(&tree);
    set_root(&tree,39);
    set_right_child(&tree,0,42);
    set_left_child(&tree,2,27);
    level_order(&tree);
    return 0;

}
void init_tree(SeqBiTree *tree)
{
    for(int i=0;i<MAX_TREE_SIZE;i++)
    {
        tree->nodes[i].data=0;
        tree->nodes[i].used=false;
    }
    tree->size=-1;
}
void set_root(SeqBiTree *tree, int value)
{
    tree->nodes[0].data=value;
    tree->nodes[0].used=true;
    tree->size=0;
}
void set_left_child(SeqBiTree *tree, int parent_node, int value)
{
    if(parent_node*2+1>=MAX_TREE_SIZE||tree->nodes[parent_node].used==false||tree->nodes[parent_node*2+1].used==true)
    {
        printf("Error");
    }
    else
    {
        tree->nodes[parent_node*2+1].used=true;
        tree->nodes[parent_node*2+1].data=value;
        tree->size=parent_node*2+1;
    }
}
void set_right_child(SeqBiTree *tree, int parent_node, int value)
{
    if(parent_node*2+2>=MAX_TREE_SIZE||tree->nodes[parent_node].used==false||tree->nodes[parent_node*2+2].used==true)
    {
        printf("Error");
    }
    else
    {
        tree->nodes[parent_node*2+2].used=true;
        tree->nodes[parent_node*2+2].data=value;
        tree->size=parent_node*2+2;
    }
    
}
void level_order(SeqBiTree *tree)
{
    int eachline=1;
    int changenumber=0;
    int level=0;
    for(int i=0;i<tree->size+1;i++)
    {
        if(tree->nodes[i].used==true)
        {
            printf("%d ",tree->nodes[i].data);
        }
        else
        {
            printf("-1 ");
        }
        if(i==changenumber)
        {
            printf("\n");
            eachline*=2;
            changenumber+=eachline;
        }
    }
    
}