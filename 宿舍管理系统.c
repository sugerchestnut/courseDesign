#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
typedef struct
{
	char me1[20];
	char me2[20];
	char me3[20];
	char me4[20];
	char me5[20];
	char me6[20];
}MEB;
typedef struct
{
	char sex;
	int apr;
	int room;
	int area;
	int peo;
	int now;
	MEB mem;
}DORM;
DORM dor[200];
void menu()
{
	 system("cls");
	 printf("\n\n---------------------������Ϣ����ϵͳ---------------\n");
	 printf("0>�˳�--------------------------------------------------\n");
	 printf("1>����--------------------------------------------------\n");
	 printf("2>��ѯ--------------------------------------------------\n");
	 printf("3>ɾ��--------------------------------------------------\n");
	 printf("4>�޸�--------------------------------------------------\n");
	 printf("5>����--------------------------------------------------\n");
	 printf("6>����--------------------------------------------------\n");
     printf("-----------------choose(0--6):");
}
void show()
{
	int i=0,m=0;
	FILE *fp;
	if((fp=fopen("E:\\data.txt","rb"))==NULL)
	{
		printf("���ܴ򿪵��ļ�!\n");
		return;
	}
	while(!feof(fp))
	{
		if(fread(&dor[i],sizeof(DORM),1,fp)==1)
			m++;
	}
	fclose(fp);
	if(m==0)
	{
		printf("û�м�¼!\n");
		return;
	}
	printf("\n\n    ----------����ѧ����Ϣ��---------\n\n");
    printf("�Ա�--¥��--�����--���-----Ӧ������-----��������-----��Ա����--\n");
    printf("----------------------------------------------------\n");
	for(;i<m;i++)
	{
       printf("%-3c%-4d%-6d%-4d%-4d%-4d%-10s%-10s%-10s%-10s%-10s%-10s\n",dor[i].sex,dor[i].apr,dor[i].room,dor[i].area,
			  dor[i].peo,
			  dor[i].now,
			  dor[i].mem.me1,
			  dor[i].mem.me2,
			  dor[i].mem.me3,
			  dor[i].mem.me4,
			  dor[i].mem.me5,
			  dor[i].mem.me6);

	}
       printf("--------------------------------------------------\n");
	fclose(fp);
}
void input()
{
	int i=0,m=0;
    char ch;
	FILE *fp;
	if((fp=fopen("E:\\data.txt","a+"))==NULL)
	{
		printf("���ܴ򿪵��ļ�!\n");
		return;
	}
	while(!feof(fp))
	{
		if(fread(&dor[m],sizeof(DORM),1,fp)==1)
			m++;
	}
    fclose(fp);
	if(m==0)
		printf("û���ҵ�!\n");
	else
	{
			system("cls");
			show();
	}
	if((fp=fopen("E:\\data.txt","wb"))==NULL)
	{
		printf("���ܴ�!\n");
		return;
	}
	for(i=0;i<m;i++)
		fwrite(&dor[i],sizeof(DORM),1,fp);

	printf("�Ƿ�������Ϣ(y/n):");
	printf("hello\n");
	scanf("%c",&ch);

	while(ch=='y'||ch=='Y')
	{
		printf("\n\n\t\t------¼������ѧ����Ϣ(���200������)�������Ա�Ϊ'*'ʱ����\n");
		printf("\n             ��%d������",i+1);
		printf("\n             �Ա�:");
		fflush(stdin);
		scanf("%c",&dor[i].sex);

		if(dor[i].sex=='*')
			break;
		printf("\n             ¥��:");
		scanf("%d",&dor[i].apr);
		fflush(stdin);
		printf("\n             �����:");
		scanf("%d",&dor[i].room);
		fflush(stdin);
		printf("\n             ���:");
		scanf("%d",&dor[i].area);
		fflush(stdin);
		printf("\n             Ӧ������:");
		scanf("%d",&dor[i].peo);
		fflush(stdin);
		printf("\n             ��������:");
		scanf("%d",&dor[i].now);
		fflush(stdin);
		printf("\n             ��Ա����:");
		scanf("%s%s%s%s%s%s",dor[i].mem.me1,dor[i].mem.me2,dor[i].mem.me3,dor[i].mem.me4,dor[i].mem.me5,dor[i].mem.me6);
		if(fwrite(&dor[i],sizeof(DORM),1,fp)!=1)
		{
			printf("���ܱ���!\n");
			getch();
		}
		else
		{
			printf("%s�Ѿ�����",dor[i].room);
			m++;
		}
		printf("�Ƿ����?(y/n):");
		scanf("%c",&ch);
	}
	fclose(fp);
	printf("ok!\n");
}

void modify()
{
    int i=0,ch1,m=0,j;
	int modifynum;

	FILE *fp;
	if((fp=fopen("E:\\data.txt","r+"))==NULL)
	{
		printf("���ܴ򿪵��ļ�!\n");
		return;
	}
	while(!feof(fp))
	{
		if(fread(&dor[i],sizeof(DORM),1,fp)==1)
			m++;
	}
	if(m==0)
	{
		printf("û�м�¼!\n");
		fclose(fp);
		return;
	}
	printf("\n          ������Ҫ�޸ĵ������ź�:");
	scanf("%d",&modifynum);
	for(i=0;i<m;i++)
	{
		if(dor[i].room==modifynum)
		{
			printf("\n                     ���ҵ���������Ϣ\n");
			printf("�Ա�--¥��--�����--���--Ӧ������--��������--��Ա����--\n");
			printf("----------------------------------------------------\n");
			printf("%-3c%-4d%-6d%-4d%-4d%-4d%-10s%-10s%-10s%-10s%-10s%-10s\n",dor[i].sex,dor[i].apr,dor[i].room,dor[i].area,
					 dor[i].peo,
					 dor[i].now,
					 dor[i].mem.me1,
					 dor[i].mem.me2,
					 dor[i].mem.me3,
					 dor[i].mem.me4,
					 dor[i].mem.me5,
					 dor[i].mem.me6);
			break;
		}
	}
	if(i==m)
		printf("\n       ����Ʒ������!\n");
	else
	{
			printf("\n                  ��Ҫ�޸���һ�\n");
			printf("\n                      1.�Ա�\n");
			printf("\n                      2.¥��\n");
			printf("\n                      3.�����\n");
			printf("\n                      4.Ӧ������\n");
			printf("\n                      5.��������\n");
			printf("\n                      6.��Ա����\n");
			printf("\n                  ѡ��(1-6):");
			scanf("%d",&ch1);
			switch(ch1)
			{
			    case 1:printf("\n           �����޸ĺ���Ա�:");
						   scanf("%c",&dor[i].sex);
						     break;
			    case 2:printf("\n           �����޸ĺ��¥��:");
						   scanf("%d",&dor[i].apr);
						     break;
				case 3:printf("\n           �����޸ĺ�ķ����:");
						   scanf("%d",&dor[i].room);
						     break;
				case 4:printf("\n           �����޸ĺ��Ӧ������:");
						   scanf("%d",&dor[i].peo);
						     break;
				case 5:printf("\n           �����޸ĺ����������:");
						   scanf("%d",&dor[i].now);
						     break;
				case 6:printf("             �����޸ĺ�������Ա:");
						scanf("%s%s%s%s%s%s",dor[i].mem.me1,dor[i].mem.me2,dor[i].mem.me3,dor[i].mem.me4,dor[i].mem.me5,dor[i].mem.me6);
						     break;
			}

				printf("\n                 �޸ĳɹ����������Ϣ\n");
				printf("�Ա�--¥��--�����--���--Ӧ������--��������--��Ա����--\n");
				printf("----------------------------------------------------\n");
				printf("%-3c%-4d%-6d%-4d%-4d%-4d%-10s%-10s%-10s%-10s%-10s%-10s",dor[i].sex,dor[i].apr,dor[i].room,dor[i].area,
					 dor[i].peo,
					 dor[i].now,
					 dor[i].mem.me1,
					 dor[i].mem.me2,
					 dor[i].mem.me3,
					 dor[i].mem.me4,
					 dor[i].mem.me5,
					 dor[i].mem.me6);
	}
	if((fp=fopen("E:\\data.txt","wb"))==NULL)
	{
		printf("���ܴ򿪵��ļ�!\n");
		return;
	}
	for(j=0;j<m;j++)
		if(fwrite(&dor[j],sizeof(DORM),1,fp)!=1)
		{
			printf("���ܱ���\n");
			getch();
		}
		fclose(fp);
}
void search()
{
	int i=0,findnum,m=0;
	FILE *fp;
	if((fp=fopen("E:\\data.txt","rb"))==NULL)
	{
		printf("���ܴ򿪵��ļ�!\n");
		return;
	}
	while(!feof(fp))
	{
		if(fread(&dor[i],sizeof(DORM),1,fp)==1)
			m++;
	}
	if(m==0)
	{
		printf("û�м�¼!\n");
		fclose(fp);
		return;
	}
    printf("������Ҫ��ѯ�������:");
	scanf("%d",&findnum);
	for(i=0;i<m;i++)
	{
	    if(dor[i].room==findnum)
		{
            printf("\n                     ���ҵ���������Ϣ\n");
			printf("�Ա�--¥��--�����--Ӧ������--��������--��Ա����--\n");
			printf("----------------------------------------------------\n");
			printf("%-3c%-4d%-6d%-4d%-4d%-4d%-10s%-10s%-10s%-10s%-10s%-10s",dor[i].sex,dor[i].apr,dor[i].room,dor[i].area,
					 dor[i].peo,
					 dor[i].now,
					 dor[i].mem.me1,
					 dor[i].mem.me2,
					 dor[i].mem.me3,
					 dor[i].mem.me4,
					 dor[i].mem.me5,
					 dor[i].mem.me6);
			break;
		  }
		else
			return;
	}
    if(i==m)
	   printf("��������Ϣ������!\n");
}
void order()
{ 
	int i,j,m;
	DORM t;
	FILE *fp;
	if((fp=fopen("E:\\data.txt","r+"))==NULL)
	{
		printf("���ܴ򿪵��ļ�!\n");
		return;
	}
	while(!feof(fp))
	{
		if(fread(&dor[m],sizeof(DORM),1,fp)==1)
			m++;
	}
	if(m==0)
	{
		printf("û�м�¼!\n");
		fclose(fp);
		return;
	}
	for(i=0;i<m-1;i++)
	{
		for(j=i+1;j<m;j++)
		{
			if(dor[i].now>dor[j].now)
			{
				t=dor[i];
				dor[i]=dor[j];
				dor[j]=dor[i];
			}
		}
	}
	if((fp=fopen("E:\\data.txt","wb"))==NULL)
	{
		printf("���ܴ򿪵��ļ�!\n");
		return;
	}
	for(i=0;i<m;i++)
		if(fwrite(&dor[i],sizeof(DORM),1,fp)!=1)
		{
			printf("���ܱ���\n");
			getch();
		}
		fclose(fp);
		printf("����ɹ�!\n");
}
void del()
{
	int i,j,r,m;
	char ch;
	FILE *fp;
	if((fp=fopen("E:\\data.txt","r+"))==NULL)
	{
		printf("���ܴ򿪵��ļ�!\n");
		return;
	}
	while(!feof(fp))
	{
		if(fread(&dor[m],sizeof(DORM),1,fp)==1)
			m++;
	}
	if(m==0)
	{
		printf("û�м�¼!\n");
		fclose(fp);
		return;
	}
	printf("��������Ҫɾ�������᷿���:");
    scanf("%d",&r);
	for(i=0;i<m;i++)
		if(dor[i].room==r)
			break;
		if(i==m)
		{
			printf("û�ҵ���������Ϣ!\n");
			getchar();
			return;
		}
		printf("���ҵ���������Ϣ,�Ƿ�ɾ��?(y/n):");
		scanf("%c",&ch);

        if(ch=='y'||ch=='Y')
		{
			for(j=i;j<m-1;j++)
				dor[j]=dor[j+1];
			m--;
			printf("��ɾ��!\n");
		}
	if((fp=fopen("E:\\data.txt","wb"))==NULL)
	{
		printf("���ܴ򿪵��ļ�!\n");
		return;
	}
	for(j=0;j<m;j++)
		if(fwrite(&dor[j],sizeof(DORM),1,fp)!=1)
		{
			printf("���ܱ���\n");
			getch();
		}
		fclose(fp);
}
void main()
{
  
	int ch,t,i;
	char account[8]="04131094";
	char password[6]="aaaaaa";
	char acc[8],pass[7];
	for(i=0;i<3;i++)
	{
       printf("������ĵ�¼�˺�:");
	           gets(acc);
	   printf("������ĵ�¼����:");
	   for(i=0;i<6;i++)
	   {
		   pass[i]=getch();
		   printf("*");
	   }
	   pass[6]='\0';
	   if(strcmp(acc,"04131094")==0 && strcmp(pass,"aaaaaa")==0)
	   {
		   t=1;
		   break;
	   }
	   else
		   printf("�������,�ٴ�����:");
		   
	}
	if(i==3)
	{
		printf("û������!\n");
		t=0;
	}
	if(t==1)
	{
		menu();
		scanf("%d",&ch);
		while(ch)
		{
	      switch(ch)
		  {
		    case 1:input();break;
		    case 2:search();break;
		    case 3:del();break;
		    case 4:modify();break;
		    case 5:order();break;
			case 6:show();break;
		    default:break;
		  }
		  getch();
		  menu();
		  scanf("%d",&ch);
		}
	}
}
