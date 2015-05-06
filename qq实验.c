#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<dos.h>
#define LEN sizeof(struct friend)
#define FORMAT "%-15s%-20s%5c%-15s%-20s\n"
#define DATA fri[i].zhanghao,fri[i].name,fri[i].sex,fri[i].birthday,fri[i].address
struct friend
{
	char zhanghao[16];
	char name[20];
	char sex;
	char birthday[15];
	char address[20];
};
struct friend fri[100];
void menu();                 //主菜单
void input();                //输入好友信息
void search();               //查找好友信息
void dele();                 //删除好友信息
void insert();               //插入好友信息
void modify();               //修改好友信息
void show();                 //显示好友信息
void total();                //计算总人数

void menu()
{
	printf("\n\n\n\n\n");
	printf("\t|----------------------------QQfriends------------------------|\n");
	printf("\t| 0.exit                                                      |\n");
    printf("\t| 1.input                                                     |\n");
    printf("\t| 2.search                                                    |\n");
    printf("\t| 3.dele                                                      |\n");
    printf("\t| 4.insert                                                    |\n");
    printf("\t| 5.modify                                                    |\n");
    printf("\t| 6.show                                                      |\n");
    printf("\t| 7.number                                                    |\n");
    printf("\t|-------------------------------------------------------------|\n");
	printf("\t choose(0--8):");
}
int main(void)
{
	int n;
	menu();
	scanf("%d",&n);
	while(n)
	{
		switch(n)
		{
		    case 1:input();break;
            case 2:search();break;
			case 3:dele();break;
			case 4:insert();break;
			case 5:modify();break;
			case 6:show();break;
			case 7:total();break;
			default:break;
		}
		getch();
		menu();
		scanf("%d",&n);
	}
}

void input()
{
	int i,m=0;
	char ch[2];
	FILE *fp;
	if((fp=fopen("data.txt","a+"))==NULL)
	{
		printf("can not open\n");
		return;
	}
	while(!feof(fp))
	{
		if(fread(&fri[m],LEN,1,fp)==1)
			m++;
	}
	fclose(fp);
	if(m==0)
		printf("no record!\n");
	else
	{
		system("cls");
		show();
	}
	if((fp=fopen("data.txt","wb"))==NULL)
	{
		printf("can not open\n");
		return;
	}
	for(i=0;i<m;i++)
		fwrite(&fri[i],LEN,1,fp);

	printf("please input(y/n):");
	scanf("%s",ch);
	while(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)
	{
		printf("zhanghao:");
		scanf("%s",fri[m].zhanghao);
		for(i=0;i<m;i++)
			if(strcmp(fri[i].zhanghao,fri[m].zhanghao)==0)
			{
				printf("this friend is exiting,press any key to continue!");
				getch();
				fclose(fp);
				return;
			}
			printf("name:");
			scanf("%s",fri[m].name);
			fflush(stdin);
			printf("sex:");
			scanf("%c",&fri[m].sex);
			fflush(stdin);
			printf("birthday:");
			scanf("%s",fri[m].birthday);
			fflush(stdin);
			printf("address:");
			scanf("%s",fri[m].address);
			fflush(stdin);
			if(fwrite(&fri[m],LEN,1,fp)!=1)
			{
				printf("can not save!");
				getch();
			}
			else
			{
				printf("%s saved!\n",fri[m].name);
				m++;
			}
			printf("continue?(y/n):");
			scanf("%s",ch);
	}
	fclose(fp);
	printf("OK!\n");
}

void search()
{
	FILE *fp;
	char snum[20];
    int i,m=0;
	char ch[2];
	if((fp=fopen("data.txt","rb"))==NULL)
	{
		printf("can not open\n");
		return;
	}
	while(!feof(fp))
		if(fread(&fri[m],LEN,1,fp)==1)
			m++;
		if(m==0)
		{
			printf("不存在这个好友!\n");
			return;
		}
		printf("please input the zhanghao:");
		scanf("%s",snum);
		for(i=0;i<m;i++)
			if(strcmp(fri[i].zhanghao,snum)==0)
			{
				printf("find the student,show?(y/n)");
				scanf("%s",ch);
				if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)
				{
					printf("zhanghao name sex birthday address\t\n");
					printf("FORMAT,DATA");
					break;
				}
			}
			if(i==m)
				printf("can not find the QQfriend!\n");
}

void dele()
{
	FILE *fp;
	char snum[20];
	int i,j,m=0;
	char ch[2];
	if((fp=fopen("data.txt","r+"))==NULL)
	{
		printf("can not open!\n");
		return;
	}
	while(!feof(fp))
		if(fread(&fri[m],LEN,1,fp)==1)
			m++;
		fclose(fp);
		if(m==0)
		{
			printf("找不到好友信息!\n");
			return;
		}
		printf("please input zhanghao:");
		scanf("%s",snum);
		for(i=0;i<m;i++)
		{
			if(strcmp(snum,fri[i].zhanghao)==0)
				break;
		}
		printf("find the foriend,delete?(y/n)");
		scanf("%s",ch);
		if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)
			for(j=i;j<m;j++)
			{
				fri[j]=fri[j+1];
				m--;
			}
		if((fp=fopen("data.txt","wb"))==NULL)
		{
			printf("can not open\n");
			return;
		}
		for(j=0;j<m;j++)
			if(fwrite(&fri[j],LEN,1,fp)!=1)
			{
				printf("can not saved!\n");
				getch();
			}
			fclose(fp);
			printf("delete successfully!\n");
}

void modify()
{
	FILE *fp;
	int i,j,m=0;
	char snum[20];
	if((fp=fopen("data.txt","r+"))==NULL)
	{
		printf("can not open\n");
		return;
	}
	while(!feof(fp))
		if(fread(&fri[m],LEN,1,fp)==1)
			m++;
		if(m==0)
		{
			printf("找不到好友信息!\n");
			fclose(fp);
			return;
		}
		show();
		printf("please input the zhanghao of the friend which do you want to modify!\n");
		printf("modify zhanghao:");
		scanf("%s",snum);
		for(i=0;i<m;i++)
			if(strcmp(snum,fri[i].zhanghao)==0)
				break;
		printf("find the friend,you can modify!\n");

		printf("name:");
		scanf("%s",fri[m].name);
		fflush(stdin);
		printf("sex:");
		scanf("%c",&fri[m].sex);
		fflush(stdin);
		printf("birthday:");
		scanf("%s",fri[m].birthday);
		fflush(stdin);
		printf("address:");
		scanf("%s",fri[m].address);
		fflush(stdin);
		printf("modify successfully!");
		if((fp=fopen("data.txt","wb"))==NULL)
		{
			printf("can not open\n");
			return;
		}
		for(j=0;j<m;j++)
			if(fwrite(&fri[j],LEN,1,fp)!=1)
			{
				printf("can not save!");
				getch();
			}
			fclose(fp);
}

void insert()
{
	FILE *fp;
	int i,j,k,m=0;
	char snum[20];
	if((fp=fopen("data.txt","r+"))==NULL)
	{
		printf("can not open\n");
		return;
	}
	while(!feof(fp))
        if(fread(&fri[m],LEN,1,fp)==1)
			m++;
		if(m==0)
		{
			printf("找不到好友信息!\n");
			fclose(fp);
			return;
		}
		printf("please input position where do you want to insert!(input the number)\n");
		scanf("%s",snum);
		for(i=0;i<m;i++)
			if(strcmp(snum,fri[i].zhanghao)==0)
				break;
			for(j=m-1;j>i;j--)
				fri[j+1]=fri[j];
			printf("now please input the new information.\n");
			printf("zhanghao:");
			scanf("%d",&fri[i+1].zhanghao);
			for(k=0;k<m;k++)
				if(fri[k].zhanghao==fri[i+1].zhanghao)
				{
					printf("the zhanghao is existing,press any key to continue!");
					getch();
					fclose(fp);
					return;
				}
				printf("name:");
				scanf("%s",fri[i+1].name);
				fflush(stdin);
				printf("sex:");
		        scanf("%c",&fri[i+1].sex);
				fflush(stdin);
	        	printf("birthday:");
		        scanf("%s",fri[i+1].birthday);
				fflush(stdin);
		        printf("address:");
		        scanf("%s",fri[i+1].address);
				fflush(stdin);
				if((fp=fopen("data.txt","wb"))==NULL)
				{
					printf("can not open\n");
					return;
				}
				for(k=0;k<=m;k++)
					if(fwrite(&fri[k],LEN,1,fp)!=1)
					{
						printf("can not save");
						getch();
					}
					fclose(fp);
}

void show()
{
	FILE *fp;
	int i,m=0;
	fp=fopen("data.txt","rb");
	while(!feof(fp))
	{
		if(fread(&fri[m],LEN,1,fp)==1)
			m++;
	}
	fclose(fp);
	printf("zhanghao        name      sex    birthday        address\t\n");
	for(i=0;i<m;i++)
	{
		printf("FORMAT,DATA");
	}
}

void total()
{
	FILE *fp;
	int m=0;
	if((fp=fopen("data.txt","r+"))==NULL)
	{
		printf("can not open\n");
		return;
	}
	while(!feof(fp))
		if(fread(&fri[m],LEN,1,fp)==1)
			m++;
		if(m==0)
		{
			printf("找不到该好友信息!\n");
			fclose(fp);
			return;
		}
		printf("the QQfriend are %d students!\n",m);
		fclose(fp);
}
