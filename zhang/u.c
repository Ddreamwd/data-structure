#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 typedef struct stacknode
{
	int data;
	struct stacknode *next;
}stacknode,*listack;
typedef struct 
{
	listack top;
	int count;
}linkstack;
int Initstack(linkstack *s)    //构造空栈
{
	s->top=(listack)malloc(sizeof(stacknode));
	if(!s->top)
		return -1;
	s->top->netx=NULL;
	s->count=0;
	return 0;
}

int clearstack(linkstack *s)    //置空栈
{
	listack p=NULL, q=NULL ;
	p=s->top;
	while(p!=NULL)
	{
		q=p;
		p=p->next;
		free(q);
		s->count--;
	}
	if(s->count==0)
		return 1;
	else
		return -1;
}
int stackempty(linkstack *s)    //判断是否为空栈
{
	return s->count;
}
int gettop(linkstack *s,int *e)  //若栈不为空，责返回栈顶元素，并返回ok，否则返回ERROR
{
	if(stackempty(&s)>0)
	{
		*e=s->top->data;
		return 1;
	}
	else 
		return -1;
}
int push(linkstack *s,int g)    //插入元素g为新的栈顶元素
{
	listack q=NULL;
	q=(listack)malloc(sizeof(stacknode));
	q->data=g;
	q->next=s->top;
	s->top=q;
	s->count++;
	return 0;
}
int pop(linkstack *s,int *e)   //删除栈顶元素，并用e返回其值，并返回OK，否则返回ERROR
{
	listack l=NULL;
	if(stackempty(&s)<=0)
		return -1;
	l=s->top;
	s->top=s->top->next;
	*e=l->data;
	free(l);
	s->count--;
	return 0;
}
int destroystack(linkstack *s)    //销毁栈
{
	int e=0;
	while(s->top->next!=NULL)
		pop(&s,&e);
	free(s);   
	s=NULL;   //撤销头结点/?为什么不需要*
	return 0;
}
int printfstack(linkstack *s)   //输出栈
{
	listack p=NULL;
	p=s->top;
	while(p->next!=NULL)
	{	printf("%d",p->data);
		p=p->next;
	}
	printf("\n");
	return 0;
}
int main()
{
	linkstack *s=NULL;
	char *p=NULL;
	int g=0,i=0,n,j=0,e=0;
	if (Initstack(&s)==0)
		printf("链栈初始化成功");
	else
		return -1;
	do{
		printf("\n1.随机给栈赋值\n2.近栈");
		printf("\n3.出栈\n4.置空栈\n5.判断链栈是否为空\n6.获取栈顶元素\n7.销毁栈");
		printf("\n0.退出\n请选着你需要的操作！\n");
		scanf("%d",&i);
		switch(i)
		{
		case 1:
			srand(time(0));
			for(j=0;j<10;j++)
			{
				push(&s,rand()%100+1);
			}
			printf("\n");
			printfstack(&s);
			break;
		case 2:
			printf("请输入你需要近栈的元素:");
			scanf("%d",&g);
			push(&s,g);
			printf("\n");
			printfstack(&s);
			break;
		case 3:
			pop(&s,&e);
			printf("出栈元素e=%d\n",e);
			break;
		case 4:
			clearstack(&s);
			break;
		case 5:
			n=stackempty(&s);
			if(n>0)
				printf("栈不为空\n");
			else
				printf("栈为空\n");
			break;
		case 6:
			if(gettop(&s,&e)==0)
				printf("栈顶元素e=%d\n",e);
			else
				printf("栈为空");
			break;
		case 7:
			destroystack(&s);
			break;
		}
	}while(i!=0);
}