#include "./numberShiftingheader.h"
int num[ROW][COL] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 32}};
int movesleft = MAX_MOVE;
void shuffleBoard(void);
void drawBoard(void);
void slideNumbers(void);
int checkWin(void);
void resetGame(void);
void swap(int *, int *);
int main(void)
{
    char name[30];
    printf("\t\t\t\t\t Number Sliding Game\n\n");
    printf("\t\t\t\t\t\t\t -Developed By Bijay Dulal\n\n\n");
    printf(" Enter Your name: ");
    gets(name);
    system("cls");
    while (1)
    {
        printf("\n\t\t\t\t\t Number Sliding Game\n\n");
        printf("\t\t\t\t\t\t\t\t -Developed By Bijay Dulal\n\n");
        printf("\t\t\t\t\t Rule of the Game: \n\n");
        printf("    1) You can move 1 step at a time using arrow key: \n");
        printf("\t - Move UP using UP ARROW KEY\n");
        printf("\t - Move Down using DOWN ARROW KEY\n");
        printf("\t - Move Left using LEFT ARROW KEY\n");
        printf("\t - Move Right using RIGHT ARROW KEY\n");
        printf("\n    2) Move numbers at empty position\n");
        printf("\n    3) You'll get a limited number of moves\n");
        printf("\n    4) You'll win the game if you manage to put all numbers in respective places\n\n");
        for (int i = 1; i < 6; i++)
            printf("\t");
        printf("Winning Situation:\n\n");
        drawBoard();
        printf("\n    5) You can exit the game by pressing ESC button\n");
        printf("\n    6) Try to Win the game in least number of moves\n");
        printf("\n\t\t\t\t\t GOOD LUCK \n\n");
        printf("     Press any Key to start the game: ");
        getch();
        shuffleBoard();
        do
        {
            system("cls");
            printf("\t\t\t\t\t Moves Left: %d\n\n\n", movesleft);
            drawBoard();
            slideNumbers();
            if (checkWin() || !movesleft)
                break;
        } while (1);
        if (!movesleft)
        {
            system("cls");
            printf("\t\t\t\t\t Moves Left: %d\n\n\n", movesleft);
            drawBoard();
            printf("\n\n %s, You Lost the game.", name);
            getch();
        }
        else
        {
            system("cls");
            printf("\t\t\t\t\t Moves Left: %d\n\n\n", movesleft);
            drawBoard();
            printf("\n\n %s, You won the game.", name);
            getch();
        }
        printf("\n Wanna Play the game again( y/n): ");
        fflush(stdin);
        char playGameAgain = getchar();
        if (playGameAgain != 'y')
            break;
        resetGame();
        system("cls");
    }
}
void resetGame(void)
{
    movesleft = MAX_MOVE;
    int k = 1;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (i == ROW - 1 && j == COL - 1)
                break;
            num[i][j] = k;
            k++;
        }
    }
    num[ROW - 1][COL - 1] = 32;
}
int checkWin(void)
{
    int winSituation[ROW][COL] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 32}}, i, j;
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            if (num[i][j] != winSituation[i][j])
                break;
        }
        if (j < COL)
            break;
    }
    if (i == ROW)
        return 1;
    return 0;
}
int slideUp(void)
{
    int i, j;
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            if (num[i][j] == 32)
                break;
        }
        if (j < COL)
            break;
    }
    if (i == 0) // swapping not possible
    {
        movesleft++;
        return 0;
    }
    swap(&num[i][j], &num[i - 1][j]);
    return 1;
}
int slideDown(void)
{
    int i, j;
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            if (num[i][j] == 32)
                break;
        }
        if (j < COL)
            break;
    }
    if (i == ROW - 1) //swapping not possible
    {
        movesleft++;
        return 0;
    }
    swap(&num[i][j], &num[i + 1][j]);
    return 1;
}
int slideLeft(void)
{
    int i, j;
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            if (num[i][j] == 32)
                break;
        }
        if (j < COL)
            break;
    }
    if (j == 0) // swapping not possible
    {
        movesleft++;
        return 0;
    }
    swap(&num[i][j], &num[i][j - 1]);
}
int slideRight(void)
{
    int i, j;
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            if (num[i][j] == 32)
                break;
        }
        if (j < COL)
            break;
    }
    if (j == COL - 1) // swapping not possible
    {
        movesleft++;
        return 0;
    }
    swap(&num[i][j], &num[i][j + 1]);
}
void swap(int *x, int *y)
{
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}
void slideNumbers(void)
{
    char input = getch();
    switch (input)
    {
    case ESCAPE:
        exit(0);
    case kEY_UP:
        slideUp();
        movesleft--;
        break;
    case KEY_DOWN:
        slideDown();
        movesleft--;
        break;
    case KEY_LEFT:
        slideLeft();
        movesleft--;
        break;
    case KEY_RIGHT:
        slideRight();
        movesleft--;
        break;
    }
}
void shuffleBoard(void)
{
    srand(time(NULL));
    int i, j, temp, rowPos, colPos;
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            rowPos = rand() % ROW;
            colPos = rand() % COL;
            temp = num[i][j];
            num[i][j] = num[rowPos][colPos];
            num[rowPos][colPos] = temp;
        }
    }
}
void drawBoard(void)
{
    int i, j;
    for (i = 1; i < 5; i++)
        printf("\t");
    for (i = 1; i < 34; i++)
        printf("-");
    printf("\n");
    for (i = 0; i < ROW; i++)
    {
        for (int k = 1; k < 5; k++)
            printf("\t");
        for (j = 0; j < COL; j++)
        {
            if (num[i][j] == 32)
            {
                printf("|  %3c  %s", num[i][j], (j == COL - 1) ? "|" : "");
            }
            else
            {
                printf("|  %3d  %s", num[i][j], (j == COL - 1) ? "|" : "");
            }
        }
        printf("\n");
    }
    for (i = 1; i < 5; i++)
        printf("\t");
    for (i = 1; i < 34; i++)
    {
        printf("-");
    }
    printf("\n");
}
