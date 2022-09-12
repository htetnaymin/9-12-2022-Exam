#include <stdio.h>
#include <stdlib.h>

void emptyStack();
void push();
void pop();
void search();
int *getcurrentlist();
struct Node
{
    int data;
    struct Node* next;
};
struct stack
{
    struct Node* list;
    int top;
};typedef struct stack st;
int main()
{
    st *s=(st*) malloc(sizeof(st));
    s->list=(struct Node*)malloc(sizeof (struct Node));
    emptyStack(s);
    push(s,10);
//    printf("%d",getdata(s));
    push(s,20);
    push(s,30);
    pop(s);
    pop(s);
    push(s,40);
    push(s,50);
    search(s,40);
    pop(s);
    pop(s);
    pop(s);
//    push(s,40);
//    push(s,50);
//    push(s,60);
    return 0;
}
void emptyStack(st *s)
{
    s->top=-1;
}
void push(st *s,int data)
{
    struct Node* temp=(struct Node*)malloc(sizeof (struct Node));
    temp=s->list;
    s->top++;
    if(s->top==0)
    {
        s->list=(struct Node*)malloc(sizeof (struct Node));
        s->list->data=data;
        s->list->next=NULL;
    }
    else
    {
//        temp=getcurrentlist(s);
        for (int i = 1; i < s->top; ++i)
        {
            temp = temp->next;
        }
        if(temp->next!=NULL)
        {
//            printf("Error in push!");
            temp->next->data=data;
        }
        struct Node* newNode=(struct Node*) malloc(sizeof (struct Node));
        newNode->data=data;
        newNode->next=NULL;
        temp->next=newNode;
    }
}
void pop(st *s)
{
    struct Node* temp=(struct Node*)malloc(sizeof (struct Node));
    temp=getcurrentlist(s);
    if(s->top==-1)
    {
        printf("Stack is empty!");
    }
    else
    {
        printf("Pop item : %d\n",temp->data);
        s->top--;
    }
}
void search(st *s,int data)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp=s->list;
    for (int i = 0; i < s->top; ++i)
    {
        if(temp->data==data)
        {
            printf("Your data %d found in index %d\n",data,i);
            return;
        }
        temp = temp->next;
    }
    printf("Cant find your data : %d\n",data);
}
int *getcurrentlist(st *s)
{
    struct Node* temp=(struct Node*)malloc(sizeof (struct Node));
    temp=s->list;
    for (int i = 0; i < s->top; ++i)
    {
        temp = temp->next;
    }
    return temp;
}
