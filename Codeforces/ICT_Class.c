#include<stdio.h>

int main(){
    /*
    int year;
    printf("Enter a Year: ");
    scanf("%d", &year);

    if(year%400==0){
        printf("Leap Year\n");
    }
    else if(year%4==0 && year%100!=0){
        printf("Leap Year\n");
    }
    else{
        printf("Not Leap year\n");
    }

    */



    // problem : 1+2+3+4+.......+n
    /*
    int n;
    printf("Enter the Number: ");
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; i++){
        sum = sum + i;
    }
    printf("Sum = %d", sum);
    */

    // problem : A number is Prime or Not
    int number;
    printf("Enter the number: ");
    scanf("%d", &number);

    for (int i = 2; i <= (number - 1); i++){
        if(number%i==0){
            printf("Not Prime\n");
            break;
        }
    }
    
    printf("Number is prime\n");

    return 0;
}