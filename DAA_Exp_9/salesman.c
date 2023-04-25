#include <stdio.h>

int arr[10][10], comp[10], n, cost = 0;

int minimum(int c)
{
    int kmin, min = 999, nc = 999;
    for (int i = 0; i < n; i++)
    {
        if ((arr[c][i] != 0) && (comp[i] == 0))
            if (arr[c][i] + arr[i][c] < min)
            {
                min = arr[i][0] + arr[c][i];
                kmin = arr[c][i];
                nc = i;
            }
    }
    if (min != 999)
        cost += kmin;

    return nc;
}

void findcost(int city)
{
    int i, ncity;

    comp[city] = 1;

    printf("%d->", city + 1);
    ncity = minimum(city);

    if (ncity == 999)
    {
        ncity = 0;
        printf("%d", ncity + 1);
        cost += arr[city][ncity];

        return;
    }

    findcost(ncity);
}

int main()
{
    printf("Enter the number of Villages: ");
    scanf("%d", &n);
    // printf("\nCost Matrix\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter Elements of Row %d: ", i + 1);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }

        comp[i] = 0;
    }
    printf("\n\nCost list:");
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        for (int j = 0; j < n; j++)
        {
            printf("\t%d", arr[i][j]);
        }
    }
    printf("\n\nPath:\n");
    findcost(0);
    printf("\n\nMinimum Cost = %d\n ", cost);
    return 0;
}
// Output

// Enter the number of villages: 4

// Enter the Cost Matrix

// Enter Elements of Row: 1
// 0 4 1 3

// Enter Elements of Row: 2
// 4 0 2 1

// Enter Elements of Row: 3
// 1 2 0 5

// Enter Elements of Row: 4
// 3 1 5 0
// The cost list is:
// 0 4 1 3
// 4 0 2 1
// 1 2 0 5
// 3 1 5 0

// The Path is:
// 1—>3—>2—>4—>1

// Minimum cost is 7
