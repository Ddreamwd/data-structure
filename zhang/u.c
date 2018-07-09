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
int Initstack(linkstack *s)    //�����ջ
{
	s->top=(listack)malloc(sizeof(stacknode));
	if(!s->top)
		return -1;
	s->top->netx=NULL;
	s->count=0;
	return 0;
}

int clearstack(linkstack *s)    //�ÿ�ջ
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
int stackempty(linkstack *s)    //�ж��Ƿ�Ϊ��ջ
{
	return s->count;
}
int gettop(linkstack *s,int *e)  //��ջ��Ϊ�գ��𷵻�ջ��Ԫ�أ�������ok�����򷵻�ERROR
{
	if(stackempty(&s)>0)
	{
		*e=s->top->data;
		return 1;
	}
	else 
		return -1;
}
int push(linkstack *s,int g)    //����Ԫ��gΪ�µ�ջ��Ԫ��
{
	listack q=NULL;
	q=(listack)malloc(sizeof(stacknode));
	q->data=g;
	q->next=s->top;
	s->top=q;
	s->count++;
	return 0;
}
int pop(linkstack *s,int *e)   //ɾ��ջ��Ԫ�أ�����e������ֵ��������OK�����򷵻�ERROR
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
int destroystack(linkstack *s)    //����ջ
{
	int e=0;
	while(s->top->next!=NULL)
		pop(&s,&e);
	free(s);   
	s=NULL;   //����ͷ���/?Ϊʲô����Ҫ*
	return 0;
}
int printfstack(linkstack *s)   //���ջ
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
		printf("��ջ��ʼ���ɹ�");
	else
		return -1;
	do{
		printf("\n1.�����ջ��ֵ\n2.��ջ");
		printf("\n3.��ջ\n4.�ÿ�ջ\n5.�ж���ջ�Ƿ�Ϊ��\n6.��ȡջ��Ԫ��\n7.����ջ");
		printf("\n0.�˳�\n��ѡ������Ҫ�Ĳ�����\n");
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
			printf("����������Ҫ��ջ��Ԫ��:");
			scanf("%d",&g);
			push(&s,g);
			printf("\n");
			printfstack(&s);
			break;
		case 3:
			pop(&s,&e);
			printf("��ջԪ��e=%d\n",e);
			break;
		case 4:
			clearstack(&s);
			break;
		case 5:
			n=stackempty(&s);
			if(n>0)
				printf("ջ��Ϊ��\n");
			else
				printf("ջΪ��\n");
			break;
		case 6:
			if(gettop(&s,&e)==0)
				printf("ջ��Ԫ��e=%d\n",e);
			else
				printf("ջΪ��");
			break;
		case 7:
			destroystack(&s);
			break;
		}
	}while(i!=0);
}