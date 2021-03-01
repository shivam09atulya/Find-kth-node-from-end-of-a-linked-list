#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head=NULL;

void insert(int data)
{
    struct node *t,*last;
 
    if(head==NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = data;
        head->next = NULL;
        last=head;
    }
    else{
        t=(struct node*)malloc(sizeof(struct node));
        t->data=data;
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void display()
{
    struct node *count=head;
    while(count)
    {
        printf("   %d  ",count->data);
        count=count->next;
    }
}

void kthnode(int k)
{
    struct node *pcount=head;int count;
    while(pcount)
    {
        count++;
        pcount=pcount->next;
    }
    int m=count-k;
    if(m<0 || m==count)
    {
        printf("\nk exceeds the size of link list ");
        return;
    }
    else if(m==count)
    {

        printf("\nfewer elements in the linked list");
        return;
    }
    pcount=head;
    while(m--)
    {
       pcount= pcount->next;
    }
    printf("\n%d\n",pcount->data);
}
void main()
{
    insert(5);
    insert(6);
    insert(4);
    insert(2);
    insert(9);
    insert(7);
    display();
    int k;
    printf("\nEnter the value of k = ");
    scanf("%d",&k);
    kthnode(k);
}