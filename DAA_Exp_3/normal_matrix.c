#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void takeInput(int a[][2], char b)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("\nEnter %c%d%d = ", b, i + 1, j + 1);
			scanf("%d", &a[i][j]);
		}
	}
}

void printMatrix(int a[][2])
{
	for (int i = 0; i < 2; i++)
	{
		printf("\n");
		for (int j = 0; j < 2; j++)
			printf("%d\t", a[i][j]);
	}
}

int main()
{
    int a[2][2], b[2][2], c[2][2], i, j, k;

    
    clock_t start, end;
    double time_taken;
    printf("\nEnter the 4 elements of first matrix\n");
	takeInput(a, 'a');
	printf("\nEnter the 4 elements of second matrix\n");
	takeInput(b, 'b');
	printf("\n\nThe first matrix is\n");
	printMatrix(a);
	printf("\n\nThe second matrix is\n");
	printMatrix(b);
    start = clock();
    printf("\n\nMatrix after multiplication:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < 2; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
	printMatrix(c);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\n\nNormal mult time : %f\n", time_taken);
    return 0;
}