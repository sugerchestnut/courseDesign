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
	 printf("\n\n---------------------宿舍信息管理系统---------------\n");
	 printf("0>退出--------------------------------------------------\n");
	 printf("1>输入--------------------------------------------------\n");
	 printf("2>查询--------------------------------------------------\n");
	 printf("3>删除--------------------------------------------------\n");
	 printf("4>修改--------------------------------------------------\n");
	 printf("5>排序--------------------------------------------------\n");
	 printf("6>输入--------------------------------------------------\n");
     printf("-----------------choose(0--6):");
}
void show()
{
	int i=0,m=0;
	FILE *fp;
	if((fp=fopen("E:\\data.txt","rb"))==NULL)
	{
		printf("不能打开的文件!\n");
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
		printf("没有记录!\n");
		return;
	}
	printf("\n\n    ----------宿舍学生信息表---------\n\n");
    printf("性别--楼号--房间号--面积-----应有人数-----现有人数-----人员姓名--\n");
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
		printf("不能打开的文件!\n");
		return;
	}
	while(!feof(fp))
	{
		if(fread(&dor[m],sizeof(DORM),1,fp)==1)
			m++;
	}
    fclose(fp);
	if(m==0)
		printf("没有找到!\n");
	else
	{
			system("cls");
			show();
	}
	if((fp=fopen("E:\\data.txt","wb"))==NULL)
	{
		printf("不能打开!\n");
		return;
	}
	for(i=0;i<m;i++)
		fwrite(&dor[i],sizeof(DORM),1,fp);

	printf("是否输入信息(y/n):");
	printf("hello\n");
	scanf("%c",&ch);

	while(ch=='y'||ch=='Y')
	{
		printf("\n\n\t\t------录入宿舍学生信息(最多200个宿舍)以宿舍性别为'*'时结束\n");
		printf("\n             第%d个宿舍",i+1);
		printf("\n             性别:");
		fflush(stdin);
		scanf("%c",&dor[i].sex);

		if(dor[i].sex=='*')
			break;
		printf("\n             楼号:");
		scanf("%d",&dor[i].apr);
		fflush(stdin);
		printf("\n             房间号:");
		scanf("%d",&dor[i].room);
		fflush(stdin);
		printf("\n             面积:");
		scanf("%d",&dor[i].area);
		fflush(stdin);
		printf("\n             应有人数:");
		scanf("%d",&dor[i].peo);
		fflush(stdin);
		printf("\n             现有人数:");
		scanf("%d",&dor[i].now);
		fflush(stdin);
		printf("\n             人员姓名:");
		scanf("%s%s%s%s%s%s",dor[i].mem.me1,dor[i].mem.me2,dor[i].mem.me3,dor[i].mem.me4,dor[i].mem.me5,dor[i].mem.me6);
		if(fwrite(&dor[i],sizeof(DORM),1,fp)!=1)
		{
			printf("不能保存!\n");
			getch();
		}
		else
		{
			printf("%s已经保存",dor[i].room);
			m++;
		}
		printf("是否继续?(y/n):");
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
		printf("不能打开的文件!\n");
		return;
	}
	while(!feof(fp))
	{
		if(fread(&dor[i],sizeof(DORM),1,fp)==1)
			m++;
	}
	if(m==0)
	{
		printf("没有记录!\n");
		fclose(fp);
		return;
	}
	printf("\n          请输入要修改的宿舍门号:");
	scanf("%d",&modifynum);
	for(i=0;i<m;i++)
	{
		if(dor[i].room==modifynum)
		{
			printf("\n                     已找到该宿舍信息\n");
			printf("性别--楼号--房间号--面积--应有人数--现有人数--人员姓名--\n");
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
		printf("\n       该商品不存在!\n");
	else
	{
			printf("\n                  你要修改哪一项？\n");
			printf("\n                      1.性别\n");
			printf("\n                      2.楼号\n");
			printf("\n                      3.房间号\n");
			printf("\n                      4.应有人数\n");
			printf("\n                      5.现有人数\n");
			printf("\n                      6.人员姓名\n");
			printf("\n                  选择(1-6):");
			scanf("%d",&ch1);
			switch(ch1)
			{
			    case 1:printf("\n           输入修改后的性别:");
						   scanf("%c",&dor[i].sex);
						     break;
			    case 2:printf("\n           输入修改后的楼号:");
						   scanf("%d",&dor[i].apr);
						     break;
				case 3:printf("\n           输入修改后的房间号:");
						   scanf("%d",&dor[i].room);
						     break;
				case 4:printf("\n           输入修改后的应有人数:");
						   scanf("%d",&dor[i].peo);
						     break;
				case 5:printf("\n           输入修改后的现有人数:");
						   scanf("%d",&dor[i].now);
						     break;
				case 6:printf("             输入修改后的宿舍成员:");
						scanf("%s%s%s%s%s%s",dor[i].mem.me1,dor[i].mem.me2,dor[i].mem.me3,dor[i].mem.me4,dor[i].mem.me5,dor[i].mem.me6);
						     break;
			}

				printf("\n                 修改成功后的宿舍信息\n");
				printf("性别--楼号--房间号--面积--应有人数--现有人数--人员姓名--\n");
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
		printf("不能打开的文件!\n");
		return;
	}
	for(j=0;j<m;j++)
		if(fwrite(&dor[j],sizeof(DORM),1,fp)!=1)
		{
			printf("不能保存\n");
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
		printf("不能打开的文件!\n");
		return;
	}
	while(!feof(fp))
	{
		if(fread(&dor[i],sizeof(DORM),1,fp)==1)
			m++;
	}
	if(m==0)
	{
		printf("没有记录!\n");
		fclose(fp);
		return;
	}
    printf("请输入要查询的宿舍号:");
	scanf("%d",&findnum);
	for(i=0;i<m;i++)
	{
	    if(dor[i].room==findnum)
		{
            printf("\n                     已找到该宿舍信息\n");
			printf("性别--楼号--房间号--应有人数--现有人数--人员姓名--\n");
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
	   printf("该宿舍信息不存在!\n");
}
void order()
{ 
	int i,j,m;
	DORM t;
	FILE *fp;
	if((fp=fopen("E:\\data.txt","r+"))==NULL)
	{
		printf("不能打开的文件!\n");
		return;
	}
	while(!feof(fp))
	{
		if(fread(&dor[m],sizeof(DORM),1,fp)==1)
			m++;
	}
	if(m==0)
	{
		printf("没有记录!\n");
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
		printf("不能打开的文件!\n");
		return;
	}
	for(i=0;i<m;i++)
		if(fwrite(&dor[i],sizeof(DORM),1,fp)!=1)
		{
			printf("不能保存\n");
			getch();
		}
		fclose(fp);
		printf("保存成功!\n");
}
void del()
{
	int i,j,r,m;
	char ch;
	FILE *fp;
	if((fp=fopen("E:\\data.txt","r+"))==NULL)
	{
		printf("不能打开的文件!\n");
		return;
	}
	while(!feof(fp))
	{
		if(fread(&dor[m],sizeof(DORM),1,fp)==1)
			m++;
	}
	if(m==0)
	{
		printf("没有记录!\n");
		fclose(fp);
		return;
	}
	printf("请输入你要删除的宿舍房间号:");
    scanf("%d",&r);
	for(i=0;i<m;i++)
		if(dor[i].room==r)
			break;
		if(i==m)
		{
			printf("没找到该宿舍信息!\n");
			getchar();
			return;
		}
		printf("已找到该宿舍信息,是否删除?(y/n):");
		scanf("%c",&ch);

        if(ch=='y'||ch=='Y')
		{
			for(j=i;j<m-1;j++)
				dor[j]=dor[j+1];
			m--;
			printf("已删除!\n");
		}
	if((fp=fopen("E:\\data.txt","wb"))==NULL)
	{
		printf("不能打开的文件!\n");
		return;
	}
	for(j=0;j<m;j++)
		if(fwrite(&dor[j],sizeof(DORM),1,fp)!=1)
		{
			printf("不能保存\n");
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
       printf("输入你的登录账号:");
	           gets(acc);
	   printf("输入你的登录密码:");
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
		   printf("输入错误,再次输入:");
		   
	}
	if(i==3)
	{
		printf("没机会了!\n");
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
