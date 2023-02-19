#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void rand_filling(int a1[], int a2[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int r = rand();
		a1[i] = a2[i] = r;
	}
	FILE *fp = fopen("./mq_random.txt", "w+");
	for (int i = 0; i < n; i++)
	{
		fprintf(fp, "%d\n", a1[i]);
	}
}

void merge(int a[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];
	for (i = 0; i < n1; i++)
		L[i] = a[l + i];
	for (j = 0; j < n2; j++)
		R[j] = a[m + 1 + j];
	i = j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		a[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		a[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int a[], int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		mergeSort(a, l, m);
		mergeSort(a, m + 1, r);
		merge(a, l, m, r);
	}
}

double merge_calculation(int a[], int n)
{
	FILE *fp = fopen("./mergeSort.csv", "w+");
	double total_time = 0;
	fprintf(fp, "n, time\n");
	for (int i = 99; i <= n; i += 100)
	{
		clock_t start, end;
		double time_taken;
		start = clock();
		mergeSort(a, 0, i);
		end = clock();
		time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
		total_time += time_taken;
		fprintf(fp, "%d, %f\n", i + 1, time_taken);
		printf("Sorted from 0 to %d in %.2fs\n", i, time_taken);
	}
	fclose(fp);
	fp = fopen("./mergeSort.txt", "w+");
	for (int i = 0; i < n; i++)
	{
		fprintf(fp, "%d\n", a[i]);
	}
	fclose(fp);
	return total_time;
}

void swap(int *x, int *y)
{
	int t = *x;
	*x = *y;
	*y = t;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int a[], int low, int high)
{
	if (low < high)
	{
		int piv = partition(a, low, high);
		quickSort(a, low, piv - 1);
		quickSort(a, piv + 1, high);
	}
}

double quick_calculation(int a[], int n)
{
	FILE *fp = fopen("./quickSort.csv", "w+");
	double total_time = 0;
	fprintf(fp, "n, time\n");
	for (int i = 99; i <= n; i += 100)
	{
		clock_t start, end;
		double time_taken;
		start = clock();
		quickSort(a, 0, i);
		end = clock();
		time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
		total_time += time_taken;
		fprintf(fp, "%d, %f\n", i + 1, time_taken);
		printf("Sorted from 0 to %d in %.2fs\n", i, time_taken);
	}
	fclose(fp);
	fp = fopen("./quickSort.txt", "w+");
	for (int i = 0; i < n; i++)
	{
		fprintf(fp, "%d\n", a[i]);
	}
	fclose(fp);
	return total_time;
}

int main()
{
	int n = 100000;
	int a1[n], a2[n];
	rand_filling(a1, a2, n);
	double merge_time = merge_calculation(a1, n);
	printf("\nTime taken by  Merge Sort: %f\n", merge_time);
	double quick_time = quick_calculation(a2, n);
	printf("\nTime taken by  Quick Sort: %f\n", quick_time);
	return 0;
}