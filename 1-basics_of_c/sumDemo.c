#include <stdio.h>
#include <conio.h>
int sum(int[], int);
int main()
{
        int i,s, x[s];
        printf("Enter a no. how many values do you want to insert in a Array: \n");
        scanf("%d",&s);
        printf("Enter values : \n");
        for(i = 0; i < s; i++){
            scanf("%d",&x[i]);
        }

        int total = sum(x, s);
        printf("Sum of Array is : %d", total);
        return 0;
}
int sum(int a[], int size)
{
        int sum = 0;
        for(int i = 0; i < size; i++){
            sum += a[i];
        }
        return sum;
}

