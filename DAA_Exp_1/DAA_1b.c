#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void filling(int a1[], int a2[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int rnum = rand();
        a1[i] = a2[i] = rnum;
    }
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void selection(int arr[], int n)
{
    int min;
    FILE *fp = fopen("./selection.csv", "w");
    fprintf(fp, "n, time\n");
    for (int k = 100; k < n; k += 100)
    {
        clock_t start, end;
        double time_taken;
        start = clock();
        for (int i = 0; i < k; i++)
        {
            min = i;
            for (int j = i + 1; j < k; j++)
            {
                if (arr[j] < arr[min])
                {
                    min = j;
                }
            }
            swap(&arr[min], &arr[i]);
        }
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        fprintf(fp, "%d, %f\n", k, time_taken);
        printf("\nSorted 0 to %d in %.2f seconds\n", k, time_taken);
    }
    fclose(fp);
    fp = fopen("./selection.txt", "w");
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%d\n", arr[i]);
    }
    fclose(fp);
}

void insertion(int arr[], int n)
{
    FILE *fp = fopen("./insertion.csv", "w");
    fprintf(fp, "n, time\n");
    for (int k = 100; k < n; k += 100)
    {
        clock_t start, end;
        double time_taken;
        start = clock();
        for (int i = 0; i < k - 1; i++)
        {
            if (arr[i + 1] < arr[i])
            {
                swap(&arr[i], &arr[i + 1]);
            }
            for (int j = i; j > 0; j--)
            {
                if (arr[j] < arr[j - 1])
                {
                    swap(&arr[j], &arr[j - 1]);
                }
            }
        }
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        fprintf(fp, "%d, %f\n", k, time_taken);
        printf("\nSorted 0 to %d in %.2f seconds\n", k, time_taken);
    }
    fclose(fp);
    fp = fopen("./insertion.txt", "w");
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%d\n", arr[i]);
    }
    fclose(fp);
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int n = 100000;
    int a1[n], a2[n];   // will be same
    filling(a1, a2, n); // a1 and a2 filling with 1lakh random numbers
    insertion(a1,n);
    selection(a2,n);
    return 0;
}