#include<stdio.h>
void main()
{
	int a[10],t=0,i,n;
	printf("enter the array size");
	scanf("%d",&n);
	printf("enter the array elements");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
	t=t+a[i];
	}
	printf("%d",t);
	
}