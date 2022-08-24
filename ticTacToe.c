#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
char boardNum[10] = {'0', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
char name[20];
char playerSign, computerSign;
int turn;
void board(void);
void playerChoice(void);
void computerChoice(void);
int checkWinner(void);
int main(void)
{
    printf("\t\t\t\t\tTIC TAC TOE\t\t\t");
    printf("==> Developed by Bijay Dulal\n\n\n");
    printf("Location Guide: \n");
    printf("\t\t\t\t|---|---|---|\n");
    printf("\t\t\t\t| 1 | 2 | 3 |\n");
    printf("\t\t\t\t|---|---|---|\n");
    printf("\t\t\t\t| 4 | 5 | 6 |\n");
    printf("\t\t\t\t|---|---|---|\n");
    printf("\t\t\t\t| 7 | 8 | 9 |\n");
    printf("\t\t\t\t|---|---|---|");
    int winner;
    printf("\n\n\nEnter your name: ");
    scanf(" %s", &name);
    printf("Enter the sign you wanna play with (Either X or O): ");
    scanf(" %c", &playerSign);
    if (playerSign == 'x' || playerSign == 'o')
        playerSign -= 32;
    if (playerSign == 'X' || playerSign == 'O')
        ;
    else
    {
        do
        {
            printf("Invalid Choice (Enter either X or O): ");
            scanf(" %c", &playerSign);
            if (playerSign == 'x' || playerSign == 'o')
                playerSign -= 32;
            if (playerSign == 'X' || playerSign == 'O')
                break;
        } while (1);
    }
    computerSign = playerSign == 'X' ? 'O' : 'X';
    do
    {
        system("cls");
        printf("\t\t\t\t\tTIC TAC TOE\t\t\t");
        printf("==> Developed by Bijay Dulal\n\n\n");
        printf("Location Guide: \n");
        printf("\t\t\t\t|---|---|---|\n");
        printf("\t\t\t\t| 1 | 2 | 3 |\n");
        printf("\t\t\t\t|---|---|---|\n");
        printf("\t\t\t\t| 4 | 5 | 6 |\n");
        printf("\t\t\t\t|---|---|---|\n");
        printf("\t\t\t\t| 7 | 8 | 9 |\n");
        printf("\t\t\t\t|---|---|---|\n\n\n");
        board();
        playerChoice();
        winner = checkWinner();
        if (winner)
        {
            printf("\n");
            board();
            printf("\n");
            break;
        }
        computerChoice();
        winner = checkWinner();
        if (winner)
        {
            printf("\n");
            board();
            printf("\n");
            break;
        }
    } while (1);
    if (winner == 1 && turn)
    {
        printf("Congrats!! %s You won the game", name);
    }
    else if (winner == -1)
    {
        printf("The game is draw.");
    }
    else
    {
        printf("You lost the game %s", name);
    }
    getch();
}
void board(void)
{
    printf("|---|---|---|\n");
    printf("| %c | %c | %c |\n", boardNum[1], boardNum[2], boardNum[3]);
    printf("|---|---|---|\n");
    printf("| %c | %c | %c |\n", boardNum[4], boardNum[5], boardNum[6]);
    printf("|---|---|---|\n");
    printf("| %c | %c | %c |\n", boardNum[7], boardNum[8], boardNum[9]);
    printf("|---|---|---|\n");
}
void playerChoice(void)
{
    int playerChoice;
    turn = 1;
label:
    printf("\n%s Enter Your desired location: ", name);
    scanf(" %d", &playerChoice);
    if (playerChoice > 0 && playerChoice < 10 && boardNum[playerChoice] != 'X' && boardNum[playerChoice] != 'O')
        boardNum[playerChoice] = playerSign;
    else if (playerChoice > 0 && playerChoice < 10 && boardNum[playerChoice] == 'X' || boardNum[playerChoice] == 'O')
    {
        printf("Location is already Occupied!! \n");
        goto label;
    }
    else if (playerChoice >= 10 || playerChoice <= 0 && boardNum[playerChoice] != 'X' && boardNum[playerChoice] != 'O')
    {
        printf("Screen ma heri heri number hannu ni aaudaina bro tya %d ka xa???\n", playerChoice);
        goto label;
    }
}
void computerChoice(void)
{
    turn = 0;
A:
    srand(time(NULL));
    char computerChoice = rand() % 8 + 1;
    if (boardNum[computerChoice] != 'X' && boardNum[computerChoice] != 'O')
        boardNum[computerChoice] = computerSign;
    else
        goto A;
}
int checkWinner(void)
{
    int gameStatus;
    if ((boardNum[1] == 'X' && boardNum[2] == 'X' && boardNum[3] == 'X') || (boardNum[1] == 'O' && boardNum[2] == 'O' && boardNum[3] == 'O'))
        gameStatus = 1;
    else if ((boardNum[1] == 'X' && boardNum[4] == 'X' && boardNum[7] == 'X') || (boardNum[1] == 'O' && boardNum[4] == 'O' && boardNum[7] == 'O'))
        gameStatus = 1;
    else if ((boardNum[2] == 'X' && boardNum[5] == 'X' && boardNum[8] == 'X') || (boardNum[2] == 'O' && boardNum[5] == 'O' && boardNum[8] == 'O'))
        gameStatus = 1;
    else if ((boardNum[3] == 'X' && boardNum[6] == 'X' && boardNum[9] == 'X') || (boardNum[3] == 'O' && boardNum[6] == 'O' && boardNum[9] == 'O'))
        gameStatus = 1;
    else if ((boardNum[7] == 'X' && boardNum[8] == 'X' && boardNum[9] == 'X') || (boardNum[7] == 'O' && boardNum[8] == 'O' && boardNum[9] == 'O'))
        gameStatus = 1;
    else if ((boardNum[1] == 'X' && boardNum[5] == 'X' && boardNum[9] == 'X') || (boardNum[1] == 'O' && boardNum[5] == 'O' && boardNum[9] == 'O'))
        gameStatus = 1;
    else if ((boardNum[4] == 'X' && boardNum[5] == 'X' && boardNum[6] == 'X') || (boardNum[4] == 'O' && boardNum[5] == 'O' && boardNum[6] == 'O'))
        gameStatus = 1;
    else if ((boardNum[1] == 'X' || boardNum[1] == 'O') && (boardNum[2] == 'X' || boardNum[2] == 'O') && (boardNum[3] == 'X' || boardNum[3] == 'O') && (boardNum[4] == 'X' || boardNum[4] == 'O') && (boardNum[5] == 'X' || boardNum[5] == 'O') && (boardNum[6] == 'X' || boardNum[6] == 'O') && (boardNum[7] == 'X' || boardNum[7] == 'O') && (boardNum[8] == 'X' || boardNum[8] == 'O') && (boardNum[9] == 'X' || boardNum[9] == 'O'))
        gameStatus = -1;
    else
        gameStatus = 0;
    return gameStatus;
}
