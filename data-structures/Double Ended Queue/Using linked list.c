//double ended queue using linked list

#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct node{
int data;
struct node *next;};
struct node *header=NULL;
struct node *end=NULL;
void push_at_start(struct node *ptr,int data)
{
        struct node *ptr2;
        ptr2=(struct node*)malloc(sizeof(struct node));
        ptr2->next=header;
        ptr2->data=data;
        if(header==NULL)
                end=ptr2;
        header=ptr2;
}

void push_at_end(struct node *ptr,int data)
{
        struct node *ptr2;
        ptr2=(struct node*)malloc(sizeof(struct node));
        if(end==NULL)
        {
                end=ptr2;
                header=ptr2;
                ptr2->data=data;
                return;
        }
        end->next=ptr2;
        ptr2->data=data;
        end=ptr2;
}

int pop_at_start(struct node *ptr)
{
        if(header==NULL)
	 {
                printf("\nunderflow");
                return 0;
        }
        header=ptr->next;
        return(ptr->data);
}

int pop_at_end(struct node *ptr)
{
        struct node *temp;
        int x;
        temp=ptr;
        if(end==NULL)
        {
                printf("\nunderflow");
                return 0;
        }

        if(temp==end)
        {
                x=temp->data;
                end=NULL;
                header=NULL;
                return(x);
        }
        while(temp->next!=end)
        {
        temp=temp->next;
        }
        x=end->data;
        free(end);
        end=temp;
        return(x);
}

int main()
{
        int c,x;
        while(1)
 {
                printf("!.enter at front\n2.enter at end\n3.remove from front\n4.remove from back\n5.exit\n\n");
                scanf("%d",&c);
                switch(c)
                {
                        case 1: printf("\nenter element: ");
                                scanf("%d",&x);
                                push_at_start(header,x);
                                break;
                        case 2: printf("\nenter element: ");
                                scanf("%d",&x);
                                push_at_end(header,x);
                                break;
                        case 3: printf("\n%d\n",pop_at_start(header));
                                break;
                        case 4: printf("\n%d\n",pop_at_end(header));
                                break;
                        case 5: goto end;
                }
        }
        end:;
}

