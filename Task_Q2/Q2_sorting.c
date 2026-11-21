
#include <stdio.h>

void bubbleSort(int a[], int n)
{
    int comparisons = 0, swaps = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;

        for (int j = 0; j < n - i - 1; j++)
        {
            comparisons++;

            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;

                swaps++;
                flag = 1;
            }
        }

        if (flag == 0)
            break;
    }

    printf("Bubble Sort Comparisons: %d\n", comparisons);
    printf("Bubble Sort Swaps: %d\n", swaps);
}

void selectionSort(int a[], int n)
{
    int comparisons = 0, swaps = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
        {
            comparisons++;

            if (a[j] < a[min])
                min = j;
        }

        if (min != i)
        {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
            swaps++;
        }
    }

    printf("Selection Sort Comparisons: %d\n", comparisons);
    printf("Selection Sort Swaps: %d\n", swaps);
}

void insertionSort(int a[], int n)
{
    int comparisons = 0, shifts = 0;

    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0)
        {
            comparisons++;

            if (a[j] > key)
            {
                a[j + 1] = a[j];
                shifts++;
                j--;
            }
            else
                break;
        }

        a[j + 1] = key;
    }

    printf("Insertion Sort Comparisons: %d\n", comparisons);
    printf("Insertion Sort Shifts: %d\n", shifts);
}

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int main(void)
{
    int a[] = {45, 12, 67, 23, 9, 34};
    int b[6], c[6], n = 6;

    for (int i = 0; i < n; i++)
        b[i] = c[i] = a[i];

    bubbleSort(a, n);
    printf("Bubble Sorted: ");
    display(a, n);

    selectionSort(b, n);
    printf("Selection Sorted: ");
    display(b, n);

    insertionSort(c, n);
    printf("Insertion Sorted: ");
    display(c, n);

    return 0;
}
