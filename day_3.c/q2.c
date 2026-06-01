/*Write a program to Print prime numbers in a 
range.*/

#include <stdio.h>

int main() {
   int n,m,i,j,isprime=1;

   printf("enter a starting a number ");
   scanf("%d",&m);
   printf("enter a end number ");
   scanf("%d",&n);

   for (i=m;i<=n;i++)
    { if (i <=1)
      continue;
    isprime = 1;
        for (j=2;j<=i/2;j++)
        {  if ( i%j == 0){ 
         isprime = 0;
        break;
        }
        }
    
    

    if (isprime)
       printf("%d,",i);
    }

return 0;
}