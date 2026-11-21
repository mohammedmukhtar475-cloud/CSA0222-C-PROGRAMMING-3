
#include <stdio.h>

#define ROW 3
#define COL 4

void rowTotal(int rain[ROW][COL])
{
    printf("\nAnnual Total Per District:\n");

    for (int i = 0; i < ROW; i++)
    {
        int total = 0;

        for (int j = 0; j < COL; j++)
            total += rain[i][j];

        printf("District %d: %d\n", i + 1, total);
    }
}

void columnAverage(int rain[ROW][COL])
{
    printf("\nMonthly Average:\n");

    for (int j = 0; j < COL; j++)
    {
        int total = 0;

        for (int i = 0; i < ROW; i++)
            total += rain[i][j];

        printf("Month %d: %.2f\n", j + 1,
               (float)total / ROW);
    }
}

void maximumRainfall(int rain[ROW][COL])
{
    int max = rain[0][0];
    int district = 0, month = 0;

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (rain[i][j] > max)
            {
                max = rain[i][j];
                district = i;
                month = j;
            }
        }
    }

    printf("\nMaximum Rainfall: %d\n", max);
    printf("District: %d Month: %d\n",
           district + 1, month + 1);
}

void deficientDistricts(int rain[ROW][COL])
{
    int total = 0;

    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            total += rain[i][j];

    float average = (float)total / (ROW * COL);

    printf("\nState Average: %.2f\n", average);
    printf("Deficient Districts:\n");

    for (int i = 0; i < ROW; i++)
    {
        int districtTotal = 0;

        for (int j = 0; j < COL; j++)
            districtTotal += rain[i][j];

        if (districtTotal < 0.6 * average * COL)
            printf("District %d\n", i + 1);
    }
}

int main(void)
{
    int rain[ROW][COL] =
    {
        {100, 120, 80, 90},
        {50, 60, 40, 30},
        {150, 130, 160, 140}
    };

    rowTotal(rain);
    columnAverage(rain);
    maximumRainfall(rain);
    deficientDistricts(rain);

    return 0;
}
