#include<stdio.h>
#include<string.h>
//#include<color.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
typedef struct train          //��Ʊ�ľ�����Ϣ
{
	char num[10];             //�𳵺�
	char startcity[10];        //��ʼվ
	char reachcity[10];        //�յ�վ
	char takeofftime[10];     //��ʼʱ��
	char arrivetime[10];      //����ʱ��
	int surticket;            //ʣ���Ʊ��
	int price;                //Ʊ��
	struct train *next;       //������һ���𳵽��ĵ�ַ
}TRAIN;                      
typedef struct man            //��Ʊ�˵���Ϣ
{
	char ticketnum[10];       //�����Ļ𳵺�
	char name[10];            //��Ʊ������
	int booknum;              //����Ʊ��
	char id[20];              //��Ʊ�˵�Ʊ��
	struct man *next;         //������һ����Ʊ�˵Ľ���ַ
}MAN;                          //��Ʊ�˵ľ�����Ϣ
int z=0,k=0;            //����Ϣ����Ʊ�˵�ǰ�ĸ���
void regi()                                            //��½ϵͳ����Ҫ׼ȷ���˺ź�����
{
	char account[6]="abcdef",password[8]="04131094";
	char acc[6],pass[9];
	int i,j;
	printf("\n\n\n\n\n\t\t\t|-----------------------------------------|\n");
	for(i=0;i<3;i++)                          //�������λ�����е�¼
	{
		//system("color 3e");
		
		printf("\t\t\t\t\t��½�˺�:");
	    gets(acc);
	    printf("\n\t\t\t\t\t��½����:");
	  for(j=0;j<8;j++)                       // ��ʽ���������
	  {
	 	 pass[j]=getch();
		 printf("*");
	  }
	  pass[8]='\0';
	  getch();
	  printf("\n");
	  if(((strcmp(acc,"abcdef"))==0)&&((strcmp(pass,"04131094"))==0))
	  {
		  printf("\n\n\n\t\t\t\tϵͳ���ڵ�½,���Ժ�.........");
		  Sleep(2000);                                                   //��ͣ2000ms
		  system("cls");                                                      //����
		  printf("\n\n\n\n\n\n\n\n\n\n");
		  printf("ww        ww         ww   eeeeeeee   ll       ccccccc   oooooooo        mm         mm       eeeeeeee\n");
		  printf(" ww      ww ww      ww    ee    ee   ll       cc        oo    oo      mm  mm     mm  mm     ee    ee\n");
	      printf("  ww    ww   ww    ww     ee  eeee   ll       cc        oo    oo     mm    mm   mm    mm    ee  eeee\n");
		  printf("   ww  ww     ww  ww      ee         ll       cc        oo    oo    mm      mm mm      mm   ee\n");
		  printf("     ww         ww        eeeeeeee   lllllll  ccccccc   oooooooo   mm        mm         mm  eeeeeeee\n");
		  break;
	  }
	  else
		  printf("\n\n\t\t\t\t\t�˺������벻��!\n");
    }
	if(i==3)
	{
	   printf("û������!\n");
	   exit(0);
	}
	printf("\n\n\n\t\t\t\t���ڽ���ϵͳ,���Ժ�.........");
	Sleep(2000);                                       //��ͣ2000ms
	system("cls");                                       //����
}
MAN *opfile()                                     //�Ա��涩Ʊ����Ϣ���ļ����ж�ȡ
{
	FILE *fp;
	MAN *head,*p1;
	head=NULL;
	    printf("\n\n\n\n\t\t\t�ļ������еĶ�Ʊ������:\n\n\n");
	    printf("\t\t\t----------------------MAN  INFORMATION-------------------\n");
	    printf("\t\t\t| name     |         id         |ticketnumber|booknum   |\n");
	    printf("\t\t\t|----------|--------------------|------------|----------|\n");
	fp=fopen("E:\\man.dat","rb");
    if(fp==NULL)
	{
		fp=fopen("E:\\man.dat","wb+");
	    return NULL;

	}   
    p1=(MAN *)malloc(sizeof(MAN));                         //���ļ����ж�ȡʱ�����������
	while(fread(p1,sizeof(MAN),1,fp))                   //����������ж�
	{
		p1->next=head;
		head=p1;
		printf("\t\t\t|%-10s|%-20s|%-12s|%-10d|\n",p1->name,p1->id,p1->ticketnum,p1->booknum);
		p1=(MAN *)malloc(sizeof(MAN));
		k++;
	}
	free(p1);
	if(k==0)   
		printf("\t\t\t�ļ���������!\n");             //�ļ��д�ʱ����������
	fclose(fp);
	getch();
	return head;
}

TRAIN *openfile()                                     //�Ա����Ʊ��Ϣ���ļ����ж�ȡ
{
	FILE *fp;
	TRAIN *head,*p1;
	head=NULL;
	system("cls");
	    printf("\n\n\n\n\t\t\t�ļ������еĻ���Ϣ����:\n\n\n");
	    printf("\t\t-------------------------------BOOK TICKET---------------------------------\n");
	    printf("\t\t| number  |start city|reach city|takeofftime|receivetime|price|ticketnumber|\n");
	    printf("\t\t|---------|----------|----------|-----------|-----------|-----|------------|\n");
	fp=fopen("E:\\train.dat","rb");
    if(fp==NULL)
	{
		fp=fopen("E:\\train.dat","wb+");            //ֻ����ʽ�򲻿�ʱ�½�һ���ļ�
		return NULL;
		//printf("���ļ�����!\n");
		//exit(0);
	}   
	p1=(TRAIN *)malloc(sizeof(TRAIN));
	while(fread(p1,sizeof(TRAIN),1,fp))
	{
		p1->next=head;
		head=p1;
		printf("\t\t|%-9s|%-10s|%-10s|%-11s|%-11s|%-5d|%-12d|\n",p1->num,p1->startcity,p1->reachcity,p1->takeofftime,p1->arrivetime,p1->price,p1->surticket);
		p1=(TRAIN *)malloc(sizeof(TRAIN));
		z++;
	}
	free(p1);
	if(z==0)   printf("�ļ���������!\n");
	fclose(fp);
	return head;
}

void menu()                      //�˵�����������ѡ��������
{
	system("cls");
	printf("\n\n\n\n");
	printf("\t\t\t|-----------------------�˵�---------------------|\n\n");
    printf("\t\t\t                     0>�˳�ϵͳ                 \n\n");
	printf("\t\t\t                     1>¼����Ϣ                 \n\n");
	printf("\t\t\t                     2>������Ϣ                 \n\n");
	printf("\t\t\t                     3>�޸���Ϣ                 \n\n");
	printf("\t\t\t                     4>�����Ϣ                 \n\n");
	printf("\t\t\t                     5>ɾ����Ϣ                 \n\n");
	printf("\t\t\t                     6>��Ʊ��Ϣ                 \n\n");
	printf("\t\t\t                     7>��Ʊ��Ϣ                 \n\n");
	printf("\t\t\t                     8>��Ϣ����                 \n\n");
	printf("\t\t\t                     9>��Ϣ��ʾ                 \n\n");
	printf("\t\t\t                   10>��Ʊ����Ϣ��ʾ             \n\n");
    printf("\t\t\t|------------------------------------------------|\n");
	printf("                  ��ѡ��(0--10):");
}
void saveman(MAN head)               // ����Ʊ�˵���Ϣҳ���浽�ļ���
{
	FILE *fp;
	MAN *p;
	p=&head;
	fp=fopen("E:\\man.dat","ab+");
	if(fp==NULL)
	{
		printf("���ļ�����!\n");
		exit(0);
	}
	else
	{
		  fwrite(p,sizeof(MAN),1,fp);
	}
	fclose(fp);
}
void savetrain(TRAIN *head)        //������Ϣ���浽�ļ���
{
	FILE *fp;
	TRAIN *p;int j;
	p=head;
	fp=fopen("E:\\train.dat","wb");
	if(fp==NULL)
	{
		printf("���ļ�����!\n");
		exit(0);
	}
	else
	{
		for(j=0;j<z;j++)
		{
		  fwrite(p,sizeof(TRAIN),1,fp);
		  p=p->next;
		}
	}
	fclose(fp);
}

TRAIN *intrain(TRAIN *head)                     // ¼�����Ϣ
{
	TRAIN *p1; 
	int i=0;
	char num[10];
	p1=head;
	printf("���л𳵺�Ϊ��λ�������� 007��\n\n");
	while(1)
	{
		p1=(TRAIN *)malloc(sizeof(TRAIN));
		fflush(stdin);
		printf("������𳵺�(000������):");
		scanf("%s",num);
	    if((strcmp(num,"000"))==0)
		{
			free(p1);
			break;                             //�������Ļ𳵺�Ϊ00���˳��ñ�������
		}
		else
		{  
		    strcpy(p1->num,num);
			fflush(stdin);
		    printf("�������ʼ��վ:");
		    scanf("%s",p1->startcity);
			fflush(stdin);
		    printf("��������յ�վ:");
		    scanf("%s",p1->reachcity);
			fflush(stdin);
		    printf("���������ʼʱ��:");
		    scanf("%s",p1->takeofftime);
			fflush(stdin);
	    	printf("������𳵵�վʱ��:");
	    	scanf("%s",p1->arrivetime);
			fflush(stdin);
	    	printf("������ʣ��Ʊ��:");
	    	scanf("%d",&p1->surticket);
			fflush(stdin);
	    	printf("������Ʊ��:");
			scanf("%d",&p1->price);
			printf("\n");
            z++;
		    p1->next=head;
	     	head=p1;
		}
	}	
	savetrain(head);                              //��¼�����Ϣ���浽��Ӧ���ļ���
	return head;
}
void showtrain(TRAIN *head)      // ��ʾ��ǰ�����л���Ϣ
{
	TRAIN *p;int i=0;
	 p=head;
	    printf("\n\n\t\t\t��ǰ����%d������Ϣ\n\n",z);
	    printf("\n\n\n");
	    printf("\t\t-------------------------------BOOK TICKET---------------------------------\n");
	    printf("\t\t| number  |start city|reach city|takeofftime|receivetime|price|ticketnumber|\n");
	    printf("\t\t|---------|----------|----------|-----------|-----------|-----|------------|\n");
	while(p!=NULL)                          //���������������
	{
        printf("\t\t|%-9s|%-10s|%-10s|%-11s|%-11s|%-5d|%-12d|\n",p->num,p->startcity,p->reachcity,p->takeofftime,p->arrivetime,p->price,p->surticket);
	    i++;
		p=p->next;
	}
	
	if(i==0)
	{
		printf("û����Ϣ\n");
		return;
	}
    getch();
	return;
}
void seatrain(TRAIN *head)           //����ĳ���𳵵���Ϣ
{
	TRAIN *p1,*h;
    char snum[10],ad[10];
	int ch,i=0;
	p1=h=head;
	printf("1>���𳵺Ų�ѯ\n");
    printf("2>���յ�վ��ѯ\n");
	printf("��ѡ���ѯ��ʽ:");
	scanf("%d",&ch);
	if(ch==1)                       //���𳵺Ž��в�ѯ                        
	{
	   printf("����������Ҫ���ҵĻ𳵺�:");
	   scanf("%s",snum);
	   printf("\t\t-------------------------------BOOK TICKET---------------------------------\n");
	   printf("\t\t| number  |start city|reach city|takeofftime|receivetime|price|ticketnumber|\n");
	   printf("\t\t|---------|----------|----------|-----------|-----------|-----|------------|\n");
	   while(p1!=NULL)
	   {
		  if((strcmp(p1->num,snum))==0)
		  {
		    printf("\t\t|%-9s|%-10s|%-10s|%-11s|%-11s|%-5d|%-12d|\n",p1->num,p1->startcity,p1->reachcity,p1->takeofftime,p1->arrivetime,p1->price,p1->surticket);
			i++;                                          // ����û���Ϣ
		  }
		  p1=p1->next;
	   }
	   if(i==0)
		   printf("û�ҵ������Ϣ!\n");
	}
	else                                               //�����յ�վ���в�ѯ
	{
		printf("����������Ҫ���ҵĻ��յ�վ:");
		scanf("%s",ad);
		printf("\t\t-------------------------------BOOK TICKET---------------------------------\n");
	    printf("\t\t| number  |start city|reach city|takeofftime|receivetime|price|ticketnumber|\n");
	    printf("\t\t|---------|----------|----------|-----------|-----------|-----|------------|\n");
		while(p1!=NULL)
		{
		  if((strcmp(p1->reachcity,ad))==0)
		  {
		     printf("\t\t|%-9s|%-10s|%-10s|%-11s|%-11s|%-5d|%-12d|\n",p1->num,p1->startcity,p1->reachcity,p1->takeofftime,p1->arrivetime,p1->price,p1->surticket);
			 i++;                                      //������������е�����յ�վ�Ļ���Ϣ
		  }
		  p1=p1->next;
		}
		if(i==0)
		   printf("û�ҵ������Ϣ!\n");
	}
	getch();
}
TRAIN *modtrain(TRAIN *head)               //�޸�ĳ������Ϣ
{
	TRAIN *p;
	char mnum[10];
	int i=0;
	p=head;
	printf("����������Ҫ�޸ĵĻ𳵺�:");
	scanf("%s",mnum);
	while(p!=NULL)
	{
        if((strcmp(p->num,mnum))==0)
		{
		   printf("\t\t-------------------------------BOOK TICKET---------------------------------\n");     //��������û���Ϣ
	       printf("\t\t| number  |start city|reach city|takeofftime|receivetime|price|ticketnumber|\n");    
	       printf("\t\t|---------|----------|----------|-----------|-----------|-----|------------|\n");
		   printf("\t\t|%-9s|%-10s|%-10s|%-11s|%-11s|%-5d|%-12d|\n",p->num,p->startcity,p->reachcity,p->takeofftime,p->arrivetime,p->price,p->surticket);
		     i++;break;
		}
		p=p->next;
	}
	if(i==0)
	{
		printf("û�ҵ��ó��ŵĻ�!\n");
		getch();
		return NULL;
	}
	else                                      //Ȼ������޸�
	{
		strcpy(p->num,mnum);
		fflush(stdin);
		printf("�������ʼ��վ:");
		scanf("%s",p->startcity);
	    fflush(stdin);
		printf("��������յ�վ:");
		scanf("%s",p->reachcity);
		fflush(stdin);
	    printf("���������ʼʱ��:");
		scanf("%s",p->takeofftime);
		fflush(stdin);
	    printf("������𳵵�վʱ��:");
	    scanf("%s",p->arrivetime);
		fflush(stdin);
	    printf("������ʣ��Ʊ��:");
	    scanf("%d",&p->surticket);
		fflush(stdin);
	    printf("������Ʊ��:");
		scanf("%d",&p->price);
	}
	savetrain(head);                   //���޸ĺ����Ϣ����
	getch();
	return head;
}
TRAIN *addtrain(TRAIN *head)              //���һ������Ϣ
{
	TRAIN *p,*q;
    char anum[10];
	int flag=1;
	q=head;
	printf("\t\t\t������������ӵĻ���Ϣ:\n\n\n");
	printf("������𳵺�:");
	scanf("%s",anum);
	while(q!=NULL)
	{
		if((strcmp(q->num,anum))==0)                //�鿴�Ƿ��Ѿ����ڸû�
		{
			printf("�û��Ѿ����ڣ����ܽ������");
			flag=0;
		break;
		}
		q=q->next;
	}
	if(flag==1)                                         //��������ɽ������
	{
		p=(TRAIN *)malloc(sizeof(TRAIN));
		strcpy(p->num,anum);
		fflush(stdin);
		printf("�������ʼ��վ:");
		scanf("%s",p->startcity);
		fflush(stdin);
		printf("��������յ�վ:");
		scanf("%s",p->reachcity);
		fflush(stdin);
		printf("���������ʼʱ��:");
		scanf("%s",p->takeofftime);
		fflush(stdin);
	    printf("������𳵵�վʱ��:");
	    scanf("%s",p->arrivetime);
		fflush(stdin);
	    printf("������ʣ��Ʊ��:");
	    scanf("%d",&p->surticket);
		fflush(stdin);
	    printf("������Ʊ��:");
		scanf("%d",&p->price);
		printf("\n");
	    p->next=head;
		head=p;
		z++;
		printf("\n\n\n\t\t\t��ӳɹ�!\n");
	}
	savetrain(head);                //��Ӻ����Ϣ����
	getch();
	return head;
}
TRAIN *deltrain(TRAIN *head)                 //ɾ��ĳ������Ϣ
{
   TRAIN *p,*q;
   char dnum[10];
   int flag=0;
   printf("����������Ҫɾ���Ļ𳵺�:");
   scanf("%s",dnum);
   for(p=head;p!=NULL&&(strcmp(p->num,dnum)!=0);q=p,p=p->next);

   if(p==NULL)
	   printf("\t\t\tû�ҵ��û���Ϣ!\n");
   else             //�Ըû𳵽���ɾ��
   {
	   if(p==head)
	   {
		   head=head->next;
		   free(p);
	   }
	   else
	   {
		   q->next=p->next;
		   free(p);
	   }
	   z--;
	   printf("\t\t\tɾ���ɹ�!\n");
	   printf("\t\t\t���Ե��  9>��Ϣ��ʾ  ���л���Ϣ��ѯ");
   }
   savetrain(head);                 //����ɾ�������Ϣ
   getch();
   return head;
}
TRAIN *booktrain(TRAIN *head)        //�𳵶�Ʊ���ֶ�Ʊ��ʽ 
{
	MAN h;
	TRAIN *p;
	char tac[10];
	int ch,flag=0;
	p=head;
    printf("\t\t\t��ѡ��Ʊ�ķ�ʽ:\n");
    printf("\n1>���𳵺Ŷ�Ʊ\n");
	printf("\n2>���յ�վ��Ʊ\n");
	scanf("%d",&ch);
	if(ch==1)                          //   ���𳵺Ž��ж�Ʊ
	{
        
		printf("�����붩Ʊ�Ļ𳵺�:");
		scanf("%s",h.ticketnum);
		        printf("\t\t-------------------------------BOOK TICKET---------------------------------\n");
	            printf("\t\t| number  |start city|reach city|takeofftime|receivetime|price|ticketnumber|\n");
	            printf("\t\t|---------|----------|----------|-----------|-----------|-----|------------|\n");
		while(p!=NULL)
		{
			if((strcmp(p->num,h.ticketnum))==0)
			{
				printf("�ҵ���!\n");
				printf("\t\t|%-9s|%-10s|%-10s|%-11s|%-11s|%-5d|%-12d|\n",p->num,p->startcity,p->reachcity,p->takeofftime,p->arrivetime,p->price,p->surticket);
				if(p->surticket<1)
				{
					printf("\n��Ǹ,ûƱ��\n");
					return head;
				}
				flag=1;
				break;
			}
			p=p->next;
		}
		if(flag)
		{
			printf("��������������:");
			scanf("%s",h.name);
			printf("�������������֤��:");
			scanf("%s",h.id);
			printf("��������Ҫ������Ʊ:");
			scanf("%d",&h.booknum);
			p->surticket=(p->surticket)-(h.booknum);

		}
		else
		{
			printf("��ʱû�иû���Ϣ!\n");
		}
	}
	else                                 //�����յ�վ���ж�Ʊ
	{
		printf("�����붩Ʊ���յ�վ:");
		scanf("%s",tac);
		printf("\t\t-------------------------------BOOK TICKET---------------------------------\n");
	    printf("\t\t| number  |start city|reach city|takeofftime|receivetime|price|ticketnumber|\n");
	    printf("\t\t|---------|----------|----------|-----------|-----------|-----|------------|\n");
		
        while(p!=NULL)
		{
			if((strcmp(p->reachcity,tac))==0)
			{
				printf("\t\t|%-9s|%-10s|%-10s|%-11s|%-11s|%-5d|%-12d|\n",p->num,p->startcity,p->reachcity,p->takeofftime,p->arrivetime,p->price,p->surticket);
				flag=1;
			}
			p=p->next;                //�����е�����յ�վ�Ļ���Ϣ��ʾ����
		}          
	
		if(flag)
		{
			p=head;
			printf("�����붩Ʊ�Ļ𳵺�:");                //ѡ���㶩Ʊ�Ļ𳵺�
		    scanf("%s",h.ticketnum);
			while(p!=NULL)
			{
			   if((strcmp(p->num,h.ticketnum))==0)
			   {
				  printf("�ҵ���!\n");
				  printf("\t\t|%-9s|%-10s|%-10s|%-11s|%-11s|%-5d|%-12d|\n",p->num,p->startcity,p->reachcity,p->takeofftime,p->arrivetime,p->price,p->surticket);
				  if(p->surticket<1)
				{
					printf("\n��Ǹ,ûƱ��\n");              //����ǰ��ʣ��Ʊ��<1���޷���Ʊ
					return head;
				}
				  flag=1;
				  break;
			   }
			   p=p->next;
			}
			printf("��������������:");
			scanf("%s",h.name);
			printf("�������������֤��:");
			scanf("%s",h.id);
			printf("��������Ҫ������Ʊ:");
			scanf("%d",&h.booknum);
			p->surticket=(p->surticket)-(h.booknum);
		}
		else
		{
			printf("��ʱû�иû���Ϣ!\n");
		}
	}
    if(flag==1)
	{
		printf("\n\n\n\t\t\t��Ʊ�ɹ�!\n");
		k++;
	}
	savetrain(head);
	saveman(h);
	getch();
	return head;
}

TRAIN *rettrain(TRAIN *head)
{
	FILE *fp; 

	char rnum[10],na[10];
	MAN *he,*p,*q;
	TRAIN *m,*n;
	int t;
	he=opfile();
	fflush(stdin);
	printf("��������������:");
   gets(na);
   fflush(stdin);
   printf("����������Ʊ�Ļ𳵺�:");
   gets(rnum);
   for(p=he;p!=NULL&&(strcmp(p->name,na)!=0);q=p,p=p->next);
   t=p->booknum;
   if(p==NULL)
	   printf("\t\t\tû�ҵ��ö�Ʊ����Ϣ!\n");
   else             
   {
	   if(p==he)
	   {
		   he=he->next;
		   free(p);
	   }
	   else
	   {
		   q->next=p->next;
		   free(p);
	   }
	  k--;
   }
   
   for(m=head;m!=NULL&&(strcmp(m->num,rnum))!=0;n=m,m=m->next);
   if((strcmp(m->num,rnum))==0)
   {
	   printf("\t\t|%-9s|%-10s|%-10s|%-11s|%-11s|%-5d|%-12d|\n",m->num,m->startcity,m->reachcity,m->takeofftime,m->arrivetime,m->price,m->surticket);
       m->surticket+=t;
   } 
   fp=fopen("E:\\man.dat","wb");
   while(he!=NULL)
   {
	  
	  fwrite(he,sizeof(MAN),1,fp);
	  he=he->next;	 
   }
  fclose(fp);
  savetrain(head);
  getch();
  return head;
}
TRAIN *sorttrain(TRAIN *head)           //�Ի���Ϣ���𳵺Ŵ�С��������
{
	TRAIN *p,*q,*t,*m,*n,a;
	for(p=head;p;t=p,p=p->next);
	for(p=head;p;p=p->next)
	{
		for(q=p->next;q;q=q->next)
		{
			if(strcmp(p->num,q->num)>0)
			{
				m=p->next;
				n=q->next;
				a=*p;
				*p=*q;
				p->next=m;
				*q=a;
				q->next=n;
			}
		}
	}
	printf("\n\n\t\t\t�ѳɹ�����  ��ѡ�� 8>��Ϣ��ʾ ���в鿴!\n\n");
	savetrain(head);            //�ź���ı��浽�ļ���
	getch();
	return head;	
}
int main(void)
{
	int sel;
    TRAIN *head;
	regi();                          //��¼ϵͳ
	head=openfile();//���ļ��鿴�ļ������Ƿ�������
	getch();
	menu();
	scanf("%d",&sel);
	while(sel)
	{
	  switch(sel)
	  {
	    case 1:head=intrain(head);break;
        case 2:seatrain(head);break;
        case 3:head=modtrain(head);break;
        case 4:head=addtrain(head);break;
        case 5:head=deltrain(head);break;
        case 6:head=booktrain(head);break;
		case 7:head=rettrain(head);break;
        case 8:head=sorttrain(head);break;
		case 9:showtrain(head);break;
		case 10:opfile();break;
	   default:break;
	  }
	  menu();
	scanf("%d",&sel);
	}
}