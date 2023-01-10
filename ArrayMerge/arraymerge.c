#include<stdio.h>
void main()
{
	int a[10],b[10],c[20],i,j,k,n1,n2;
	printf("Enter the Limit of First Array: \n");
	scanf("%d",&n1);
	printf("Enter Elements of First Array: \n");
	for(i=0;i<n1;i++)
	{
		scanf("%d",&a[i]);	
	}
	printf("First Array is: \n");
	for(i=0;i<n1;i++)
	{
		printf("%d",a[i]);	
	}
	printf("\nEnter the Limit of Second Array: \n");
	scanf("%d",&n2);
	printf("Enter Elements of Second Array: \n");
	for(j=0;j<n2;j++)
	{
		scanf("%d",&b[j]);	
	}
	printf("Second Array is: \n");
	for(j=0;j<n2;j++)
	{
		printf("%d",b[j]);	
	}
	i=0;
	j=0;
	k=0;
	while(i<n1&&i<n2)
	{
		if(a[i]<b[j])
		{
			c[k]=a[i];
			i++;
			k++;		
		}
		else if(a[i]>b[j])
		{
			c[k]=b[j];
			j++;
			k++;		
		}
		else
		{
			c[k]=b[j];
			i++;
			j++;
			k++;
		}
	}
	while(i<n1)
	{
		c[k]=a[i];
		i++;
		k++;	
	}
	while(j<n2)
	{
		c[k]=b[j];
		j++;
		k++;	
	}
	printf("\nMerged Array is: \n");
	for(i=0;i<k;i++)
	{
		printf("%d",c[i]);
	}
}
	
