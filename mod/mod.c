#include <stdio.h>
int main()
{
FILE *input=NULL;
int n=0;
int a=0,q=0,b=0,r=0;
input=fopen("in.txt","rt");
printf("a=qb+r\n"); 
fscanf(input,"%d %d",&a,&b);
q= a/b;
r=a- (q*b);
printf("%d=(%d)(%d)+%d \n",a,q,b,r);

//a=qb +r

fclose(input);
return 0; 
}
