#include <stdio.h>
#include <conio.h>
int maxValue(int[], int);
int main()
{
        int i,s, x[s];
        printf("Enter along how many values do you want greater : \n");
        scanf("%d",&s);
        printf("Enter values : \n");
        for(i = 0; i < s; i++){
            scanf("%d",&x[i]);
        }

        int g = maxValue(x, s);
        printf("Greater value is : %d",g);
        return 0;
}
int maxValue(int a[], int size)
{
        int greater = a[0];
        for(int i = 1; i < size; i++){
            if(greater < a[i]){
                greater = a[i];
            }
        }
        return greater;
}
