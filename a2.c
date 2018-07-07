#include<stdio.h>

int min(int a,int b)
{
	return((a<b)?a:b);
}

void main()
{
	int cap,oprate,i=0,ip[10]={0},ch=0,sec=0,x,remain=0,drop=0;
	printf("\nEnter Capacity of the Bucket: ");
	scanf("%d",&cap);
	printf("\nEnter Output Rate: ");
	scanf("%d",&oprate);
	do
	{
		printf("\nEnter No. of Packets Received at second %d : ",i+1);
		scanf("%d",&ip[i]);
		printf("Enter 1 to Continue, else 0 to exit : ");
		scanf("%d",&ch);
		i++;
	}while(ch);
	
	sec=i;
	printf("\n\nSECOND\t\tRECEIVED\t\tSENT\t\tDROPPED\t\tREMAINING\n");
	for(i=0;remain||i<sec;i++)
	{
		printf("%d\t\t%d\t\t%d\t\t",i+1,ip[i],min(ip[i]+remain,oprate));
		x=ip[i]+remain-oprate;
		if(x>0)
		{
			if(x>cap)
			{
				remain=cap;
				drop=x-remain;
			}
			else
			{
				drop=0;
				remain=x;
			}
		}
		else
		{
			remain=0;
			drop=0;
		}
		printf("%d\t\t%d\n",drop,remain);
	}
				
}
