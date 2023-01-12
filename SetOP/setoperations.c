#include<stdio.h>
#include<string.h>

void intr(char*,char*,char*);
void uni(char*,char*,char*);
void diff(char*,char*,char*);

void main()
{
	char s1[10],s2[10],s3[40];
	
	printf("Enter the First Set:\n");
	scanf("%s",s1);
	printf("Enter the Second Set:\n");
	scanf("%s",s2);
	printf("First Set is:{%s}\n",s1);
	printf("Second Set is:{%s}\n",s2);
	uni(s1,s2,s3);
	printf("Union Is:\n%s\n",s3);
	intr(s1,s2,s3);
	printf("Intersection Is:\n%s\n",s3);
	diff(s1,s2,s3);
	printf("Difference Is:\n%s\n",s3);
}
void intr(char*s1,char*s2,char*s3)
{
	int i,l;
	l=strlen(s1);
	for(i=0;i<l;i++)
	{
		if(s1[i]=='1' && s2[i]=='1')
		{
			s3[i]='1';
		}
		else
		{
			s3[i]='0';
		}
	}
	s3[i]='\0';
}
void uni(char*s1,char*s2,char*s3)
{
	int i,l;
	l=strlen(s1);
	for(i=0;i<l;i++)
	{
		if(s1[i]=='0' && s2[i]=='0')
		{
			s3[i]='0';
		}
		else
		{
			s3[i]='1';
		}
	}
}
void diff(char*s1,char*s2,char*s3)
{
	int i,l;
	l=strlen(s1);
	for(i=0;i<l;i++)
	{
		if(s1[i]=='1' && s2[i]=='0')
		{
			s3[i]='1';
		}
		else
		{
			s3[i]='0';
		}
	}
	s3[i]='\0';
}

