#include<stdio.h>
int main ( )
{
   int b,h;
   float area;
   printf("Enter the base and height of the triangle: ");
   scanf("%d %d",&b,&h);
   area = 0.5 * b * h;
   printf("\nThe area of the triangle is: %.2f",area);
}
