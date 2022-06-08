#include <stdio.h>
#include <stdlib.h>
struct tree
{
    int data;
    struct tree *left, *right;
};
struct stack
{
    struct tree *tptr;
    struct stack *next;
};
struct tree *create(int data)
{
    struct tree *node = (struct tree *)malloc(sizeof(struct tree));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int isempty(struct stack *s)
{
    return (s == NULL ? 1 : 0);
}
void push(struct stack **topref, struct tree *ptr)
{
    struct stack *newnode = (struct stack *)malloc(sizeof(struct stack));
    if (newnode == NULL)
    {
        printf("overflow\n");
        exit(0);
    }
    else
    {
        newnode->tptr = ptr;
        newnode->next = *topref;
        *topref = newnode;
    }
}
struct tree *pop(struct stack **topref)
{
    struct tree *res;
    struct stack *s;
    if (isempty(*topref))
    {
        printf("underflow\n");
        exit(0);
    }
    else
    {
        s = *topref;
        res = s->tptr;
        *topref = s->next;

        free(s);
    }
    return res;
}
void inorder(struct tree *root)
{
    struct tree *current = root;
    struct stack *s = NULL;
    int ans = 1;
    while (ans != 0)
    {
        if (current != NULL)
        {
            push(&s, current);
            current = current->left;
        }
        else
        {
            if (!isempty(s))
            {
                current = pop(&s);
                printf("%d\t", current->data);
                current = current->right;
            }
            else
                ans = 0;
        }
    }
}
int main()
{

    struct tree *root = NULL;
    root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(5);
    printf("binary tree inoredr without recursion\n");
    inorder(root);
}
