//Tic tac toe 2 player game

#include <stdio.h>
#include <ctype.h>

char grid[3][3];

//quicky clear stdin stream
void clearInput(){
    while(fgetc(stdin) != '\n')/*do nothing*/;
}

//set all spots to -
void clearGrid(){

    int row, col;
    for(row = 0; row < 3; row++){
        for(col = 0; col < 3; col++){
            grid[row][col] = '-'; 
        }
    }
}

//loop through grid and print chars
void showGrid(){

    printf("\n");
    int i;
    for(i = 0; i < 3; i++){
        int j;
        for(j = 0; j < 3; j++){
            printf("\t[%c]", grid[i][j]);
        }
        printf("\n");
    }
}

//returns 1 if valid 0 otherwise
int checkMove(row, col){

    if((row >= 1 && row <= 3) && (col >= 1 && col <= 3) && (grid[row - 1][col - 1] == '-')){
        return 1;
    }
    else{
        return 0;
    }
}

//verifies players' input for replay
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
        if(grid[0][col] == 'X' && grid[1][col] == 'X' && grid[2][col] == 'X'){
            return 1;
        }
        else if(grid[0][col] == 'O' && grid[1][col] == 'O' && grid[2][col] == 'O'){
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

int checkFull(){
    
    int i;
    for(i = 0; i < 3; i++){
        
        int j;
        for(j = 0; j < 3; j++){
            if(grid[i][j] == '-'){
                return 0;
            }
        }
    }
    return 1;
}

int main(){
    
    printf("\n---TIC-TAC-TOE---\n");    

    int replay = 0;
    do{

        //bool to decide winner or full 0: full board 1: X won 2: O won
        int outcome;
        clearGrid();

        int playing = 1;
        int isXTurn = 1;

        //turn loop
        while (playing){

            int row = 0;
            int col = 0;

            showGrid();

            

            if(isXTurn){
                printf("Player X, your move.\n");
            }
            else{
                printf("Player O, your move.\n");
            }

            //move inputed
            printf("Row: ");
            //move checked
            if(!scanf("%d", &row)){
                clearInput();
                printf("Invalid entry.\n");
                continue;
            }

            printf("Column: ");
            if(!scanf("%d", &col)){
                clearInput();
                printf("Invalid entry.\n");
                continue;
            }
            
            else if(!checkMove(row, col)){
                printf("Invalid move.\n");
                continue;
            }
            
            //move is applied
            if(isXTurn){
                grid[row - 1][col - 1] = 'X';
            }
            if(!isXTurn){
                grid[row - 1][col - 1] = 'O';
            }

            //only switches if this point in loop is reached
            isXTurn = !isXTurn;
            
            //see if someone won
            switch(checkWin()){
                case 0:
                    break;
                case 1:
                    outcome = 0;
                    playing = 0;
                    break;
                case 2:
                    outcome = 1;
                    playing = 0;
                    break;
            }
            
            if(checkFull){
                playing = 0;
            }
        }

        showGrid();

        //check what made the game stop
        switch(outcome){
            
            case 0:
                printf("No one wins :(\n")
                break;
            
            case 1:
                printf("X Wins!\n");
                break;
            
            case 2:
                printf("O Wins!\n");
                break;
        }

        char replayIn;
        int invalidIn = 1;
        //loop to check input
        while(invalidIn){
            clearInput();
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
