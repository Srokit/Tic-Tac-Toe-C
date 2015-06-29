//Tic tac toe 2 player game

#include <stdio.h>

char grid[3][3];

void clearGrid(){

    int row, col;
    for(row = 0; row < 3; row++){
        for(col = 0; col < 3; col++){
            grid[row][col] = '-'; 
        }
    }
}

void printGrid(){

    printf("\n");
    int i;
    for(i = 0; i < 3; i++){
        int j;
        for(j = 0; j < 3; j++){
            printf("[%s]\t");
        }
        printf("\n");
    }
}

//returns 1 if valid 0 otherwise
int checkMove(row, col){

    if((row < 1 || row > 3) || (col < 1 || col > 3)){
        return 0;
    }
    else if(grid[row][col] != '-'){
        return 0;
    }
    else{
        return 1;
    }
}

int checkReplayIn(input){
    if(tolower(input) == 'y'){
        return 1;
    }
    else if(tolower(input) == 'n'){
        return 2;
    }
    else{
        return 0;
    }
}

//returns 1 if X won, 2 if O won, 0 if no win
int checkWin(){
    
    int row;
    for(row = 0; row < 3; row++){
        if(grid[row][0] == 'X' && grid[row][1] == 'X' && grid[row][2] == 'X'){
            return 1;
        }
        else if(grid[row][0] == 'O' && grid[row][1] == 'O' && grid[row][2] == 'O'){
            return 2;
        }
    }

    int col;
    for(col = 0; col < 3; col++){
        if(grid[col][0] == 'X' && grid[col][1] == 'X' && grid[col][2] == 'X'){
            return 1;
        }
        else if(grid[col][0] == 'O' && grid[col][1] == 'O' && grid[col][2] == 'O'){
            return 2;
        } 
    }
    
    if((grid[0][0] == 'X' && grid[1][1] == 'X' && grid[2][2] == 'X') ||
    (grid[0][2] == 'X' && grid[1][1] == 'X' && grid[2][0] == 'X')){
        return 1;
    }

    else if((grid[0][0] == 'O' && grid[1][1] == 'O' && grid[2][2] == 'O') ||
    (grid[0][2] == 'O' && grid[1][1] == 'O' && grid[2][0] == 'O')){
        return 2;
    }

    else{
        return 0;
    }
}

int main(){
    
    printf("---TIC-TAC-TOE---\n");    

    int replay = 0;
    do{

        //bool to decide winner
        int winnerIsX;
        clearGrid();

        int playing = 1;
        int isXTurn = 1;

        //turn loop
        while (playing){

            int row = 0;
            int col = 0;

            if(isXTurn){
                printf("Player X, your move.\n");
            }
            else{
                printf("Player O, your move.\n");
            }

            printf("Row: ");
            //checks to see if an int was read
            if(!scanf("%d", &row)){
                playing = 0;
                printf("Invalid move.\n");
                continue;
            }

            printf("Column: ");
            if(!scanf("%d", &col)){
                playing = 0;
                printf("Invalid move.\n");
                continue;
            }
            
            else if(!checkMove(row, col)){
                playing = 0;
                printf("Invalid move,\n");
                continue;
            }

            switch(checkWin()){
                case 0:
                    break;
                case 1:
                    winnerIsX  = 1;
                    playing = 0;
                    break;
                case 2:
                    winnerIsX = 0;
                    playing = 0;
                    break;
            }
            //only switches if this point in loop is reached
            isXTurn = !isXTurn;
        }

        if(winnerIsX){
            printf("X Wins!\n");
        }
        else{
            printf("O Wins!\n");
        }

        char replayIn;
        int invalidIn = 1;
        //loop to check input
        while(invalidIn){
            printf("Play again? (y or n): ");
            scanf("%c", &replayIn);

            switch(checkReplayIn(replayIn)){
                case 0:
                    printf("Invalid. Try again\n");
                    break;
                case 1:
                    invalidIn = 0;
                    replay = 1;
                    break;
                case 2:
                    invalidIn = 0;
                    replay = 0;
                    break;
            }
        }
    }while(replay);

    return 0;
}
