#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void BoardPrint(char board[3][3])
{
    printf(" 1 2 3\n");
    for(int i=0;i<3;i++)
    {
        printf("%d", i+1);
        for(int j=0;j<3;j++)
        {
            printf("%c", board[i][j]);
            if(j<2)
            {
                printf("|");
            }
        }
        printf("\n");
        if(i<2){printf(" -----\n");}
    }
    printf("\n");
}

bool checkWinp1(char boardArray[3][3])
{
    if(boardArray[0][0]=='X' && boardArray[0][1]=='X' && boardArray[0][2]=='X'){return false;}
    else if(boardArray[1][0]=='X' && boardArray[1][1]=='X' && boardArray[1][2]=='X'){return false;}
    else if(boardArray[2][0]=='X' && boardArray[2][1]=='X' && boardArray[2][2]=='X'){return false;}
    else if(boardArray[0][0]=='X' && boardArray[1][0]=='X' && boardArray[2][0]=='X'){return false;}
    else if(boardArray[0][1]=='X' && boardArray[1][1]=='X' && boardArray[2][1]=='X'){return false;}
    else if(boardArray[0][2]=='X' && boardArray[1][2]=='X' && boardArray[2][2]=='X'){return false;}
    else if(boardArray[0][0]=='X' && boardArray[1][1]=='X' && boardArray[2][2]=='X'){return false;}
    else{return true;}
}

bool checkWinp2(char boardArray[3][3])
{
    if(boardArray[0][0]=='O' && boardArray[0][1]=='O' && boardArray[0][2]=='O'){return false;}
    else if(boardArray[1][0]=='O' && boardArray[1][1]=='O' && boardArray[1][2]=='O'){return false;}
    else if(boardArray[2][0]=='O' && boardArray[2][1]=='O' && boardArray[2][2]=='O'){return false;}
    else if(boardArray[0][0]=='O' && boardArray[1][0]=='O' && boardArray[2][0]=='O'){return false;}
    else if(boardArray[0][1]=='O' && boardArray[1][1]=='O' && boardArray[2][1]=='O'){return false;}
    else if(boardArray[0][2]=='O' && boardArray[1][2]=='O' && boardArray[2][2]=='O'){return false;}
    else if(boardArray[0][0]=='O' && boardArray[1][1]=='O' && boardArray[2][2]=='O'){return false;}
    else{return true;}
}

int main()
{
    char boardArray[3][3]={
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '},
    };
    BoardPrint(boardArray);
    int turn = 1;
    bool playing=true;
    bool win=false;
    int jogadaColuna=0;
    int jogadaLinha=0;
    int jogadasTotais=0;
    while(playing==true){

        // --------------- player 1

        printf("\nPlayer1, digite qual linha e coluna voce quer jogar separadas por um espaco EX:(1 1):: ");
        scanf("%d %d", &jogadaLinha, &jogadaColuna);
        jogadaLinha--;
        jogadaColuna--;
        if(jogadaLinha<0 || jogadaColuna<0 || jogadaLinha>2 || jogadaColuna>2 || boardArray[jogadaLinha][jogadaColuna] != ' ')
        {
            printf("Jogada invalida, tente novamente.\n");
        }
        boardArray[jogadaLinha][jogadaColuna] = 'X';
        BoardPrint(boardArray);
        win = checkWinp1(boardArray);
        if(win==false)
        {
            printf("\n--- PLAYER 1 (X) VENCEU! ---\n");
            break;
        }

        // ---------------- player 2

        printf("\nPlayer2, digite qual linha e coluna voce quer jogar separadas por um espaco EX:(1 1):: ");
        scanf("%d %d", &jogadaLinha, &jogadaColuna);
        jogadaLinha--;
        jogadaColuna--;
        if(jogadaLinha<0 || jogadaColuna<0 || jogadaLinha>2 || jogadaColuna>2 || boardArray[jogadaLinha][jogadaColuna] != ' ')
        {
            printf("Jogada invalida, tente novamente.\n");
        }
        boardArray[jogadaLinha][jogadaColuna] = 'O';
        BoardPrint(boardArray);
        win = checkWinp2(boardArray);
        if(win==false)
        {
            printf("\n--- PLAYER 2 (X) VENCEU! ---\n");
            break;
        }
    }
    printf("Jogo terminado.");
    return 0;
}
