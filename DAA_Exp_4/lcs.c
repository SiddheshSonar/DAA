#include <stdio.h>
#include <string.h>

void printTable(int arr[][20], int len1, int len2)
{
    printf("\n");
    for(int i = 0 ; i < len1+1 ; i++) {
        for(int j = 0 ; j < len2+1 ; j++) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

void findLCS(char seq1[], char seq2[])
{
    int table[20][20];
    int len1 = strlen(seq1);
    int len2 = strlen(seq2);

    for (int i = 0; i <= len1; i++)
    {
        table[i][0] = 0;
    }

    for (int i = 0; i <= len2; i++)
    {
        table[0][i] = 0;
    }

    for (int i = 1; i <= len1; i++)
        for (int j = 1; j <= len2; j++)
        {
            if (seq1[i - 1] == seq2[j - 1])
            {
                table[i][j] = table[i - 1][j - 1] + 1;
            }
            else if (table[i - 1][j] >= table[i][j - 1])
            {
                table[i][j] = table[i - 1][j];
            }
            else
            {
                table[i][j] = table[i][j - 1];
            }
        }

    int index = table[len1][len2];
    char LCS[index + 1];
    LCS[index] = '\0';

    int i = len1, j = len2;
    while (i > 0 && j > 0)
    {
        if (seq1[i - 1] == seq2[j - 1])
        {
            LCS[index - 1] = seq1[i - 1];
            i--;
            j--;
            index--;
        }

        else if (table[i - 1][j] > table[i][j - 1])
            i--;
        else
            j--;
    }

    printf("seq1 : %s \nseq2 : %s \n", seq1, seq2);
    printf("LCS: %s", LCS);
    printf("\n\nTable: \n");
    printTable(table, len1, len2);
}

int main()
{
    char seq1[20], seq2[20];
    printf("\nEnter the first sequence: ");
    scanf("%s",seq1);
    printf("\nEnter the second sequence: ");
    scanf("%s",seq2);
    // char seq1[20] = "abaaba";
    // char seq2[20] = "babbab";
    findLCS(seq1,seq2);
    printf("\n");
    return 0;
}