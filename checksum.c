#include<stdio.h>
#include<math.h>
 
 int sender(int b[10],int k)
 {
 	int checksum,sum=0,i;
        	printf("\n****SENDER****\n");
     
for(i=0;i<k;i++)
      		sum+=b[i];
      		printf("SUM IS: %d",sum);
                     
    	checksum=~sum;
    	printf("\nSENDER's CHECKSUM IS:%d",checksum);
    	return checksum;
}
 
int receiver(int c[10],int k,int scheck)
{
int checksum,sum=0,i;
     	printf("\n\n****RECEIVER****\n");
     	for(i=0;i<k;i++)
      		sum+=c[i];
      	printf(" RECEIVER SUM IS:%d",sum);
      	sum=sum+scheck;
      	checksum=~sum;
      	printf("\nRECEIVER's CHECKSUM IS:%d",checksum);
      		return checksum;
  }
   int main()
   {
     	int a[10],i,m,scheck,rcheck,ch;
     	printf("\nENTER SIZE OF THE STRING:");
     	scanf("%d",&m);
     	printf("\nENTER THE ELEMENTS OF THE ARRAY:");
     	for(i=0;i<m;i++)
    	scanf("%d",&a[i]);
    	scheck=sender(a,m);
    	rcheck=receiver(a,m,scheck);

 printf("\nTest error detection 0(yes) 1(no)? : ");
 scanf("%d",&ch);
  if(ch==0)
  {
    do{
      do{
          printf("\nEnter the position where error is to be inserted(or 0 to stop) : ");
           scanf("%d",&ch);
      }while(ch>m-1);
      a[ch]++;
    }while(ch!=0);      
  }
   for(i=0;i<m;i++)
   printf("%d",a[i]);
    	rcheck=receiver(a,m,scheck);
  // Output the checksum
  printf("\nValidated checksum = %d\n", rcheck);



    	if(rcheck==0)
      		printf("\n\nNO ERROR IN TRANSMISSION\n\n");
    	else
      		printf("\n\nERROR DETECTED");
return 0;
               
} 	
