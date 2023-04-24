#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int num;
int pf[100];
int wt[100];
bool temp[100];

int cap = 0;
int maxval = 0;

void getWeightAndProfit(bool inKnap[num], int *weight, int *profit)
{
    int i, w = 0, v = 0;
    for (i = 0; i < num; ++i)
    {
        if (inKnap[i])
        {
            w += wt[i];
            v += pf[i];
        }
    }
    *weight = w;
    *profit = v;
}

void printProfit(bool inKnap[num])
{
    int val = 0;
    for (int i = 0; i < num; ++i)
    {
        if (inKnap[i])
        {
            val += pf[i];
        }
    }
    printf("\nMax Profit = %d", val);
}

void knapSack(bool inKnap[num], int i)
{
    int currwt, currval;
    getWeightAndProfit(inKnap, &currwt, &currval);
    if (currwt <= cap)
    {
        if (currval > maxval)
        {
            memcpy(temp,inKnap,sizeof(temp));
            maxval = currval;
        }
    }
    if (i == num || currwt >= cap)
    {
        return;
    }
    int x = wt[i];
    bool use[num], waste[num];
    memcpy(use, inKnap, sizeof(use));
    memcpy(waste, inKnap, sizeof(waste));
    use[i] = true;
    waste[i] = false;
    knapSack(use, i + 1);
    knapSack(waste, i + 1);
}

void printTable(int num, int wt[], int pf[])
{
    printf("|\tItem\t|\tWeight\t|\tProfit\t|\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < num; i++)
    {
        printf("|\t%d\t|\t%d\t|\t%d\t|\n",i+1,wt[i],pf[i]);
    }
}

int main()
{
    printf("Enter the number of items: ");
    scanf(" %d", &num);
    bool inKnap[num];
    int i;
    for (i = 0; i < num; ++i)
    {
        printf("\nWeight of item %d: ", i + 1);
        scanf("%d", &wt[i]);
        printf("\nProfit of item %d: ", i + 1);
        scanf("%d", &pf[i]);
        inKnap[i] = false;
    }
    printf("\nEnter capacity of Knapsack: ");
    scanf(" %d", &cap);
    printf("\nInput Table:\n\n");
    printTable(num,wt,pf);
    knapSack(inKnap, 0);
    printProfit(temp);
    return 0;
}

/**
    Sample input:
    4
    1 15
    5 10
    3 9
    4 5
    8
    Sample output:
    Included = { 1 }; Total profit = 15
    Included = { 1 5 }; Total profit = 25
    Included = { 1 3 4 }; Total profit = 29
*/
