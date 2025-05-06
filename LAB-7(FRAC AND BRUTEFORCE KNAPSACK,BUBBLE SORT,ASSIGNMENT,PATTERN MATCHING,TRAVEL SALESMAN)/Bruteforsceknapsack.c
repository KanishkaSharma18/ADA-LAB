#include <stdio.h>

int knapsack(int values[], int weights[], int n, int W) {
    int maxValue = 0;
    for (int i = 0; i < (1 << n); i++) {
        int totalWeight = 0, totalValue = 0;

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                totalWeight += weights[j];
                totalValue += values[j];
            }
        }
        if (totalWeight <= W && totalValue > maxValue) {
            maxValue = totalValue;
        }
    }

    return maxValue;
}

int main()
{
    int values[]={60,100,120};
    int weights[]={10,20,30};
    int W=50;
    int n=sizeof(values)/sizeof(values[0]);

    int maxValue=knapsack(values,weights,n,W);
    printf("Maximum value of knapsack is : %d",maxValue);
    return 0;

}
