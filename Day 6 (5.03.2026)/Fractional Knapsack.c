#include<stdio.h>
int main()
{
    int i, j, n = 7;
    float weight[7] = {2, 5, 7, 3, 1, 4, 6};
    float profit[7] = {10, 25, 35, 15, 8, 20, 30};
    float ratio[7], capacity = 15;
    float totalProfit = 0, temp;
    for(i = 0; i < n; i++)
    {
        ratio[i] = profit[i] / weight[i];
    }
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(ratio[i] < ratio[j])
            {
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;
                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;
            }
        }
    }
    for(i = 0; i < n; i++)
    {
        if(weight[i] <= capacity)
        {
            totalProfit = totalProfit + profit[i];
            capacity = capacity - weight[i];
        }
        else
        {
            totalProfit = totalProfit + (ratio[i] * capacity);
            break;
        }
    }
    printf("Maximum Profit = %.2f", totalProfit);
    return 0;
}

/*
Output:
Maximum Profit = 78.00
*/