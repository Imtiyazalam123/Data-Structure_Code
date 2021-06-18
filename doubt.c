#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct stack*createstack(int);
void push(struct stack*,int);
void pop(struct stack*);
void peek(struct stack*);
void view(struct stack*);
struct stack
{
	int capacity;
	int top;
	int *ptr;
};
int main()
{
	struct stack *s=NULL;
	int choice,a,b;
	while(1)
	{
		printf("enter the choice\n");
		printf("1.createstack\n");
		printf("2.push\n");
		printf("3.pop\n");
		printf("4.peek\n");
		printf("5.view\n");
		printf("6.exits\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:

				printf("enter the array size\n");
				scanf("%d",&a);
				s=createstack(a);
				break;
			case 2:
				printf("enter the item\n");
				scanf("%d",&b);
				push(s,a);
				break;
			case 3:
					pop(s);
					break;
			case 4:
			    	peek(s);
			    	break;
			case 5:
			       view(s);
				   break;
			case 6:
				exit(1);
			default:
			        printf("illegal choice\n");
				}
			}

}
struct stack* createstack(int cap)
{
	struct stack *s;
	s=(struct stack*)malloc(sizeof(struct stack));
	s->capacity=cap;
	s->top=-1;
	s->ptr=(int*)malloc(sizeof(int)*cap);
	return(s);
}
void push(struct stack *s,int data)
{
	if(s->capacity-1==s->top)
	{
		printf("overflow\n");
	}
	else
	{
		s->top+=1;
		s->ptr[s->top]=data;
	}
}
	void pop(struct stack *s)
	{
		if(s->top==-1)
		printf("\nunderflow\n");
	else
	     s->top-=1;
	}
	void peek(struct stack *s)
	{
		if(s->top==-1)
		printf("stack is empty\n");
    else
        printf("%d",s->ptr[s->top]);
	}
	void view(struct stack *s)
	{
	    int i;
		if(s->top==-1)
		printf("stack is empty\n");
		else
		{
		  for(i=s->top;i>=0;i--)
		  printf("%d\n",s->ptr[i]);
	}

	}
