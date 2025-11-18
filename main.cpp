#include <stdio.h>
#include <stdlib.h>
int** funk1(int arr, int n);

int funk2(int **arr, int n);

int funk3(int **arr, int n);

int main() 
{
	int n;
	int choice;
	int **arr;
	printf("Enter massive size:");
	scanf_s("%d", &n);
	arr=funk1(n)
	do {
		printf("\n MENU \n");
		printf("1. Find rows with all zeros\n");
		printf("2. Find rows with all even numbers\n");
		printf("3. Exit\n");
		printf("Your choice: ");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1:
		{
			funk2(arr, n);
			break;
		}
		case 2:
		{
			funk3(arr, n);
			break;
		}
		case 3:
		{
			printf("goodbye\n");
			break;
		}
		default:
			printf("Invalid choice");
		}
	} while (choice != 3);
	for (int i = 0; i < n; i++) {
		free(arr[i]);
	}
	free(arr);

	return 0;
}
int **funk1(int arr, int n)
{
	int i, j;
	int** arr = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++) {
		arr[i] = (int*)malloc(n * sizeof(int));
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf_s("%d", &arr[i][j]);
		}
	}
	return 0;
}
int funk2(int **arr, int n)
{
	int i, j;
	int found_zeros = 0;
	printf("strings that have all zeros: ");
	for (i = 0; i < n; i++)
	{
		int all_zeros = 1;
		for (j = 0; j < n; j++)
		{
			if (arr[i][j] != 0)
			{
				all_zeros = 0;
				break;
			}
		}
		if (all_zeros == 1)
		{
			printf("%d", i + 1);
			found_zeros = 1;
		}
	}
	if (found_zeros == 0)
	{
		printf("no");
	}
	printf("\n");
	return 0;
}
int funk3(int **arr, int n)
{
	int i, j;
	int found_even = 0;
	printf("which strings have all even numbers: ");
	for (i = 0; i < n; i++)
	{
		int all_even = 1;
		for (j = 0; j < n; j++)
		{
			if (arr[i][j] % 2 != 0 || arr[i][j] == 0)
			{
				all_even = 0;
			}

		}
		if (all_even == 1)
		{
			printf("%d", i + 1);
			found_even = 1;
		}
	}
	if (found_even == 0)
	{
		printf("no");
	}
	printf("\n");
	return 0;
}
