/*Write a program to Find LCM of two numbers.*/

#include<stdio.h>
int main (){
    int n,m, i,gcd;
    printf("enter a 1st number ");
    scanf("%d",&n);
    printf("enter a 1st number ");
    scanf("%d",&m);

    for (i=1;i<=n&&i<=m;i++){
        if(n %1==0 && m % i == 0)
          gcd = i;

    }
    
    printf("gcd of %d and %d= %d ",m,n,gcd );

    return 0 ;
}