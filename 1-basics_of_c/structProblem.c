#include<conio.h>
#include<stdio.h>
          struct temp {
                    int min;
                    int max;
          };
float minAvg(struct temp days[], int totalDays);
float maxAvg(struct temp days[], int totalDays);

int main() {

          float minAv, maxAv;
          int i, totalDays;
          struct temp days[totalDays];
          printf("Enter no of how many days do you want to calculate mix and max temp : \n");
          scanf("%d", &totalDays);
          for(i = 0; i < totalDays; i ++){
                    printf("Enter min temp value of day %d : ",(i+1));
                    scanf("%d", &days[i].min);
                    printf("Enter max temp value of day %d : ",(i+1));
                    scanf("%d", &days[i].max);
          }
         minAv = minAvg(days, totalDays);
         printf("\n\nAverage of min temp temp is : %.2f\n", minAv);
         maxAv = maxAvg(days, totalDays);
         printf("Average of max temp temp is : %.2f\n", maxAv);
        return 0;
}
float minAvg(struct temp days[], int totalDays){

        int j;
        float sum = 0, totalMin = 0;

          for(j = 0; j < totalDays; j++){
                    sum += days[j].min;
                    totalMin++;
          }
          float avg = sum/totalMin;
          return avg;

}
float maxAvg(struct temp days[], int totalDays){

        int j;
        float sum = 0, totalMax = 0;

          for(j = 0; j < totalDays; j++){
                    sum += days[j].max;
                    totalMax++;
          }
          float avg = sum/totalMax;
          return avg;

}
