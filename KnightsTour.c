#include<stdio.h>
#include<stdlib.h>


/**
 * @brief 
 * Generates a graph that represents the board with the nodes connected if the knight could traverse them. The graph is stored as an adjacency matrix
 * @param numRows The number of rows on the chess board
 * @param numColumns The number of columns on the chess board
 * @return A graph which stores the board 
 */
int** generateBoard(int numRows, int numColumns){
    //Variable Declarations
    int i, j, diff, tempPos;
    int boardSize = numRows * numColumns;

    //Declaration for the adjacency matrix
    int** boardGraph = (int**) malloc(sizeof(int*) * boardSize);

    //Allocates memory for the matrix
    for(i =0; i<boardSize;  i++){
        *(boardGraph+i) = (int*) malloc (sizeof(int) * boardSize);
        for(j=0; j<boardSize; j++){
            boardGraph[i][j] = 0;
        }
    }

    //Sets the values to 1 that are adjacent
    for(i=0; i<boardSize; i++){
        diff = i % numColumns;

        if((i - numColumns) >= 0){
            tempPos = i - numColumns;

            if(diff >  1){
                boardGraph[i][tempPos-2] = 1;
                boardGraph[tempPos -2][i] = 1;
            }

            if(diff < 3){
                boardGraph[i][tempPos + 2] = 1;
                boardGraph[tempPos + 2][i] = 1;
            }
        }

        if((i + numColumns) < boardSize){
            tempPos = i + numColumns;

            if(diff >  1){
                boardGraph[i][tempPos -2] = 1;
                boardGraph[tempPos -2][i] = 1;
            }

            if(diff < 3){
                boardGraph[i][tempPos + 2] = 1;
                boardGraph[tempPos + 2][i] = 1;
            }
        }

    }


    return boardGraph;

}



int main(int argc, char *argv[]) {
    int i,j;

    int** boardMatrx = generateBoard(5,5);
    for(int i=0; i < 25; i++){
        for(int j=0; j < 25; j++){
        printf("%d ", boardMatrx[i][j]);
    }
        printf("\n");
    }
}