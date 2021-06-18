#include <stdio.h>
#include <conio.h>
float avg(int[], int);
int main()
{
        int i,s, x[s];
        printf("Enter a no. how many values do you want to insert : \n");
        scanf("%d",&s);
        printf("Enter values : \n");
        for(i = 0; i < s; i++){
            scanf("%d",&x[i]);
        }

        float a = avg(x, s);
        printf("Average of Array is : %.2f",a);
        return 0;
}
float avg(int a[], int size)
{
        float sum = 0.0;
        for(int i = 0; i < size; i++){
            sum += a[i];
        }
        float avg = sum/size;
        return avg;
}
