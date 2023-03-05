#include <stdio.h>
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
	int a[2][2], b[2][2], c[2][2];
	int c1, c2, c3, c4, c5, c6, c7;
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
	c1 = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
	c2 = (a[1][0] + a[1][1]) * b[0][0];
	c3 = a[0][0] * (b[0][1] - b[1][1]);
	c4 = a[1][1] * (b[1][0] - b[0][0]);
	c5 = (a[0][0] + a[0][1]) * b[1][1];
	c6 = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
	c7 = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);

	c[0][0] = c1 + c4 - c5 + c7;
	c[0][1] = c3 + c5;
	c[1][0] = c2 + c4;
	c[1][1] = c1 - c2 + c3 + c6;

	printf("\n\nAfter performing multiplication\n");
	printMatrix(c);
	end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\n\nStressen's Multiplication time : %f\n", time_taken);
	return 0;
}
