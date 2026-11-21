
#include <stdio.h>

#define MAX_CANDIDATES 12
#define MAX_VOTES 500000

int main(void)
{
    int candidates;
    int votes;
    int count[MAX_CANDIDATES] = {0};

    int valid = 0;
    int invalid = 0;

    printf("Enter number of candidates: ");
    scanf("%d", &candidates);

    if (candidates < 1 || candidates > MAX_CANDIDATES)
    {
        printf("Invalid candidate count\n");
        return 1;
    }

    printf("Enter number of votes: ");
    scanf("%d", &votes);

    if (votes < 0 || votes > MAX_VOTES)
    {
        printf("Invalid vote count\n");
        return 1;
    }

    printf("Enter votes:\n");

    for (int i = 0; i < votes; i++)
    {
        int vote;
        scanf("%d", &vote);

        if (vote >= 1 && vote <= candidates)
        {
            count[vote - 1]++;
            valid++;
        }
        else
        {
            invalid++;
        }
    }

    int id[MAX_CANDIDATES];

    for (int i = 0; i < candidates; i++)
        id[i] = i + 1;

    /* Sort candidates by votes in descending order */

    for (int i = 0; i < candidates - 1; i++)
    {
        for (int j = i + 1; j < candidates; j++)
        {
            if (count[id[j] - 1] > count[id[i] - 1])
            {
                int temp = id[i];
                id[i] = id[j];
                id[j] = temp;
            }
        }
    }

    printf("\nValid Votes: %d\n", valid);
    printf("Invalid Votes: %d\n", invalid);

    printf("\nCandidate Vote Results:\n");

    for (int i = 0; i < candidates; i++)
    {
        printf("Candidate %d: %d votes\n",
               id[i], count[id[i] - 1]);
    }

    int maximum = count[id[0] - 1];
    int tie = 0;

    for (int i = 1; i < candidates; i++)
    {
        if (count[id[i] - 1] == maximum)
            tie = 1;
        else
            break;
    }

    if (tie)
    {
        printf("\nElection Result: TIE\n");
        printf("Candidates with highest votes:\n");

        for (int i = 0; i < candidates; i++)
        {
            if (count[id[i] - 1] == maximum)
                printf("Candidate %d\n", id[i]);
        }
    }
    else
    {
        printf("\nWinner: Candidate %d\n", id[0]);
    }

    return 0;
}
