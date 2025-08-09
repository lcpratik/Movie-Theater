#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 26
#define MAX_COLS 100

void FillMovieTheater(char MovieTheater[MAX_ROWS][MAX_COLS], int rows, int cols, const char *data)
{
    int index = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            MovieTheater[i][j] = data[index++];
        }
    }
}

void PrintSeatMap(char MovieTheater[MAX_ROWS][MAX_COLS], int rows, int cols)
{
    printf("\n    ");
    for (int j = 1; j <= cols; j++)
    {
        printf("Seat %-3d", j);
    }
    printf("\n");

    for (int i = 0; i < rows; i++)
    {
        printf("Row %c", 'A' + i);
        for (int j = 0; j < cols; j++)
        {
            printf("    %c", MovieTheater[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int IsSeatSold(char MovieTheater[MAX_ROWS][MAX_COLS], int row, int col)
{
    if (MovieTheater[row][col] == 'X')
    {
        return 1;
    }
    else
    {
        MovieTheater[row][col] = 'X';
        return 0;
    }
}

void WriteMovieTheater(char MovieTheater[MAX_ROWS][MAX_COLS], int rows, int cols)
{
    char outputFileName[100];
    FILE *outputFile = NULL;

    printf("Enter output filename: ");
    scanf("%s", outputFileName);

    outputFile = fopen(outputFileName, "w+");
    if (!outputFile)
    {
        printf("File did not open...exiting\n");
        return;
    }

    fprintf(outputFile, "%d %d\n", rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            fprintf(outputFile, "%c", MovieTheater[i][j]);
        }
        fprintf(outputFile, "\n");
    }

    fclose(outputFile);
}

int main(void)
{
    int ticketsPurchased = 0, ticketsSold = 0;
    int ArrayRow = 0, ArrayCol = 0;
    int rows = 0, cols = 0;
    char rowChar;
    int seatNum;
    char MovieTheater[MAX_ROWS][MAX_COLS] = {0};
    FILE *inputFile = NULL;
    char inputFileName[100];
    char seatData[MAX_ROWS * MAX_COLS + 1] = {0};

    printf("Enter the name of your Movie Theater file: ");
    scanf("%s", inputFileName);

    inputFile = fopen(inputFileName, "r");
    if (!inputFile)
    {
        printf("File did not open...exiting\n");
        return 1;
    }

    fscanf(inputFile, "%d %d ", &rows, &cols);
    fgets(seatData, sizeof(seatData), inputFile);
    fclose(inputFile);

    FillMovieTheater(MovieTheater, rows, cols, seatData);

    printf("How many tickets would you like to purchase? (limit 4): ");
    scanf("%d", &ticketsPurchased);

    while (ticketsPurchased < 1 || ticketsPurchased > 4)
    {
        printf("This is a special showing - limit of 4 tickets per purchase\n");
        printf("How many tickets would you like to purchase? (limit 4): ");
        scanf("%d", &ticketsPurchased);
    }

    if (ticketsPurchased == 0)
    {
        printf("No movie for you!\n");
        return 0;
    }

    while (ticketsSold < ticketsPurchased)
    {
        PrintSeatMap(MovieTheater, rows, cols);

        printf("Enter seat choice by entering the row and seat\n");
        printf("Please pick a seat: ");
        scanf(" %c%d", &rowChar, &seatNum);

        rowChar = toupper(rowChar);
        ArrayRow = rowChar - 'A';
        ArrayCol = seatNum - 1;

        if (ArrayRow < 0 || ArrayRow >= rows || ArrayCol < 0 || ArrayCol >= cols)
        {
            printf("That seat is not in this theater!!\n");
        }
        else if (IsSeatSold(MovieTheater, ArrayRow, ArrayCol))
        {
            printf("Seat %c%d is already sold. Pick a different seat.\n", rowChar, seatNum);
        }
        else
        {
            ticketsSold++;
        }
    }

    printf("Please find your way to your seats using this map...\n");
    PrintSeatMap(MovieTheater, rows, cols);
    printf("Enjoy your movie!\n");

    WriteMovieTheater(MovieTheater, rows, cols);

    return 0;
}