#include<stdio.h>
#include<malloc.h>
#include<string.h>
int top1=-1,top2=-1;
int stack1[20],stack2[20];

void push1(int x)
{
stack1[++top1]=x;
}

void push2(int x)
{
stack2[++top2]=x;
}

int pop1()
{
return (stack1[top1--]);
}

int pop2()
{
return (stack2[top2--]);
}

void push_at_start(int x)
{
push1(x);
return;
}

void pop_at_start()
{
if(top1==-1)
{
        printf("\nunderflow\n");
        return;
}
printf("\n%d\n",pop1());
return;
}

void push_at_end(int x)
{
while(top1!=-1)
{
push2(pop1());
}
push1(x);
while(top2!=-1)
{
push1(pop2());
}
return;
}

void pop_at_end()
{
if(top1==-1)
{
        printf("\nunderflow\n");
        return;
}

while(top1!=0)
{
push2(pop1());
}
printf("\n%d\n",pop1());
while(top2!=-1)
{
push1(pop2());
}
return;
}

int main()
{
int x,c;
while(1)
{
printf("1.enter at front\n2.enter at back\n3.remove from front\n4.remove from back\n5.exit\n\n");
scanf("%d",&c);
switch(c)
{
case 1: printf("enter element: ");
        scanf("%d",&x);
        push_at_start(x);
        break;
case 2:  printf("enter element: ");
        scanf("%d",&x);
        push_at_end(x);
        break;
case 3: pop_at_start();
        break;
case 4: pop_at_end();
        break;
case 5: goto end;
}
}
end:;
}
             
