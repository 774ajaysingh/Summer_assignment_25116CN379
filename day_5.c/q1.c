/*Write a program to Check perfect number. */
#include<stdio.h>
int main(){
    int num,i=1,m;
    printf("enter a numbers ");
    scanf("%d", &num);

        for (i  ;i< num; i++) {
         if(  num% i==0)
        {
            m = m+i;

        }
        }
    if (m==num){
        printf("%d is a perfect number ",num);
    }
return 0;
}