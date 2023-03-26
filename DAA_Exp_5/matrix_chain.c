#include <limits.h>
#include <stdio.h>

int MatrixChainOrder(int arr[], int n)
{
	int mat[n][n], len, c, j;
	
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if(i >= j) {
				mat[i][j] = 0;
			}
		} 
	}

	for (len = 2; len < n; len++) {
		for (int i = 1; i < n - len + 1; i++) {
			j = i + len - 1;
			mat[i][j] = INT_MAX;
			for (int k = i; k <= j - 1; k++) {
				c = mat[i][k] + mat[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
				if (c < mat[i][j]) {
					mat[i][j] = c;
				}
			}
		}
	}
	
	for(int i=1;i<n;i++) {
		printf("\n");
		for(int j=1;j<n;j++) {
			printf("%d\t",mat[i][j]);
		}
	}
	
	return mat[1][n - 1];
}



int main()
{
	int n;
	//int arr[] = { 1, 2, 3, 4 };
	//int n = sizeof(arr) / sizeof(arr[0]);
	printf("\nEnter the size of array: ");
	scanf("%d", &n);
	int arr[n];
	for(int i = 0 ; i < n ; i++) {
		printf("\nEnter the %d element of the array: ", i+1);
		scanf("%d", &arr[i]);
	} 
	printf("\n\nMinimum number of multiplications: %d ",
		MatrixChainOrder(arr, n));
	return 0;
}

