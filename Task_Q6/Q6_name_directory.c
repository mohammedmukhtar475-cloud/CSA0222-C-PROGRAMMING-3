
#include <stdio.h>
#include <string.h>

#define MAX 500
#define LEN 30

void removeNewline(char s[])
{
    s[strcspn(s, "\n")] = '\0';
}

void sortNames(char names[][LEN], int n)
{
    char temp[LEN];

    for (int i = 1; i < n; i++)
    {
        strcpy(temp, names[i]);

        int j = i - 1;

        while (j >= 0 && strcmp(names[j], temp) > 0)
        {
            strcpy(names[j + 1], names[j]);
            j--;
        }

        strcpy(names[j + 1], temp);
    }
}

int binarySearch(char names[][LEN], int n, char key[])
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int result = strcmp(names[mid], key);

        if (result == 0)
            return mid;

        if (result < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

void findDuplicates(char names[][LEN], int n)
{
    printf("\nDuplicate Names:\n");

    int found = 0;

    for (int i = 1; i < n; i++)
    {
        if (strcmp(names[i], names[i - 1]) == 0)
        {
            printf("%s\n", names[i]);
            found = 1;
        }
    }

    if (!found)
        printf("No duplicates found\n");
}

int main(void)
{
    char names[MAX][LEN];
    char key[LEN];
    int n;

    printf("Enter number of residents: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of residents\n");
        return 1;
    }

    getchar();

    for (int i = 0; i < n; i++)
    {
        printf("Enter name %d: ", i + 1);

        if (fgets(names[i], LEN, stdin) == NULL)
            return 1;

        removeNewline(names[i]);
    }

    sortNames(names, n);

    printf("\nSorted Names:\n");

    for (int i = 0; i < n; i++)
        printf("%s\n", names[i]);

    findDuplicates(names, n);

    printf("\nEnter name to search: ");

    if (fgets(key, LEN, stdin) == NULL)
        return 1;

    removeNewline(key);

    int pos = binarySearch(names, n, key);

    if (pos != -1)
        printf("Name found at index %d\n", pos);
    else
        printf("Name not found\n");

    return 0;
}
