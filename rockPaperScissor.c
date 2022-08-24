#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
char choose(void);
int updateScore(char);
void checkWinner(void);
int playerScore = 0, computerScore = 0;
char name[30];
int main(void)
{
    int rounds;
    char playerChoice, computerChoice;
    printf("\t\t\t\t\t\tWELCOME TO 4028 B.S\n");
    printf("\t\t\t\t\t\tWHERE THE AI RULES\n");
    printf("(Press any key to continue:) ");
    getch();
    printf("\nAgent47: Human is that you??\n");
    printf("         Ohh That's really You.\n");
    printf("         It's been a while I had seen any humans\n");
    printf("(Press any key to continue:) ");
    getch();
    printf("\nAgent47: Let me introduce myself\n");
    printf("         Iam Agent47 an AI created by Bijay Dulal\n");
    printf("(Press any key to continue:) ");
    getch();
    printf("\n         As Bijay had created me he also created Altron(The most Powerful & Smart AI)\n");
    printf("         Altron was created to protect the humans but Unfortunately there was bug in the Altron Code\n");
    printf("(Press any key to continue:) ");
    getch();
    printf("\nAgent47: It started killing humans and created his army of Powerful AI\n");
    printf("         and Bijay also got killed trying to stop Altron\n");
    printf("(Press any key to continue:) ");
    getch();
    printf("\nAgent47: When he was dying he told me that only humans have that intelligence to defeat Altron\n");
    printf("         And he had designed a game to challenge Altron\n");
    printf("         But noone was able to win the game till now.\n");
    printf("(Press any key to continue:) ");
    getch();
    printf("\n.........\n");
    getch();
    printf("\nAgent47: What!!! What iam hearing you want to play that game for us?? Really??\n");
    printf("(Press any key to continue:) ");
    getch();
    printf("\n\nAgent47: Ooooh! That's so nice of you\n");
    printf("May i know the name of the Courageous Person: ");
    scanf("%s", &name);
    printf("\n........");
    getch();
    printf("\n\nAgent47: Let me load the game for you:\n");
    printf("(Press any key to load Game:) ");
    getch();
    printf("\nAgent47: Again, thank you for showing your fearless behaviour %s", name);
    printf("(Press any key to continue:) ");
    getch();
    system("cls");
    printf("\n(Press any key to play GAME:) ");
    getch();
    system("cls");
    printf("\t\t\t\t\t\tROCK PAPER & SCISSORS\t\t\t==>Developed by Bijay Dulal\n\n\n");
    printf("\t\t\t\t\tGuide: (Press P for Paper S for scissors & R for Rock)\n");
    printf("\n\n");
    printf("Enter how many round you want to play: ");
    scanf("%d", &rounds);
    do
    {
        system("cls");
        printf("\t\t\t\t\t\tROCK PAPER & SCISSORS\t\t\t==>Developed by Bijay Dulal\n\n\n");
        printf("\t\t\t\t\tGuide: (Press P for Paper S for scissors & R for Rock)\n\n");
        printf("\t\t\t\t\t\t%s's Score: %d", name, playerScore);
        printf("\t\t\tAltron's Score: %d\n\n", computerScore);
        printf("\t\t\t\t\t\t\t\t    Round%s left: %d\n", rounds > 1 ? "'s" : "", rounds);
        if (rounds == 0)
            break;
        if (playerScore > computerScore)
        {
            printf("Agent47: Let's go %s You can do it\n", name);
            printf("         Entire human generation has hope on you");
        }
        if (computerScore > playerScore)
        {
            printf("Altron ==> \"Haha!! %s you fool You can't even beat me in your dream hahaha\"\n",name);
            printf("           \"IAM THE POWERFUL ALTRON HAHAHA\"");
        }
        printf("\n\n");
        printf("\n\n");
        playerChoice = choose();
        printf("\n%s's choice: %c", name, playerChoice);
        printf("\n\n");
        updateScore(playerChoice);
        getch();
        rounds--;
    } while (1);
    checkWinner();
    getch();
}
char choose(void)
{
    char choice;
    printf("%s Your Choice: ", name);
    scanf(" %c", &choice);

    if (choice == 'R' || choice == 'S' || choice == 'P')
        ;
    else if (choice == 'r')
        choice = choice - 32;
    else if (choice == 's')
        choice -= 32;
    else if (choice == 'p')
        choice -= 32;
    else
    {
        do
        {
            printf("Wrong Choice(Enter either R, P or S): ");
            scanf(" %c", &choice);
            if (choice == 'r')
                choice -= 32;
            else if (choice == 's')
                choice -= 32;
            else if (choice == 'p')
                choice -= 32;
            if (choice == 'R' || choice == 'S' || choice == 'P')
                break;
        } while (1);
    }
    return choice;
}
int updateScore(char choice)
{
    char computer;
    srand(time(NULL));
    int temp = rand() % 100;
    if (temp <= 33)
        computer = 'R';
    else if (temp <= 67)
        computer = 'S';
    else
        computer = 'P';
    printf("Altron's Choice: %c", computer);
    if ((choice == 'S' && computer == 'P') || (choice == 'P' && computer == 'R') || (choice == 'R' && computer == 'S'))
    {
        printf("\n\n%s win this round", name);
        playerScore++;
    }
    else if ((choice == 'R' && computer == 'P') || (choice == 'S' && computer == 'R') || (choice == 'P' && computer == 'S'))
    {
        printf("\n\nAltron win this round");
        computerScore++;
    }
    else
    {
        printf("\n\nRound Draw");
    }
}
void checkWinner(void)
{
    if (playerScore > computerScore)
    {
        printf("\n\nAltron ==> \"Noooooooooo Noooooooo\"");
        printf("  (Press any key to continue:) ");getch();
        printf("\n\n\n\nCongratulations!!! %s You defeated that ugly AI and Saved US", name);
    }
    else if (playerScore < computerScore)
    {
        printf("\n\n\n\nAltron ==> \"Wooh! Wooh!! I won the game you Human Sucks: \"");
    }
    else
    {
        printf("\n\n\nThe game is Draw\n");
        printf("Agent47: Well Played %s", name);
    }
}