#include<stdio.h>
int main()
{
    float a,b;
    a=0.0f,b=0.0f;
    scanf("%f %f",&a,&b);
    float c=a+b;
    printf("%.2f + %.2f = %.2f",a,b,c);
    return 0;
}