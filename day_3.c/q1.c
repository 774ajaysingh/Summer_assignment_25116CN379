/*Write a program to Check whether a number is 
prime. */

#include<stdio.h>
int main (){
    int n, i,isprime=1;
    printf("enter a number ");
    scanf("%d",&n);

    if (n < 2)
    {isprime =0;}
    else{
        for (i=2;i<n/2;i++)
        {
            if (n % i == 0) {
                isprime = 0;
                break;
            }
        }
    }

    if(isprime ){
        printf("number is prime ");}
    else { 
        printf(" number is not prime ");
    
    }
    return 0;
}
