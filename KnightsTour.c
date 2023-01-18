#include<stdio.h>
#include<stdlib.h>


/**
 * @brief Structure used to create the graphs stores the length of a list with its contents. 
 * 
 */
struct adjList{
    int size;
    int* contents;
};

/**
 * @brief 
 * Generates a graph that represents the board with the nodes connected if the knight could traverse them. The graph is stored as an adjacency list
 * @param numRows The number of rows on the chess board
 * @param numColumns The number of columns on the chess board
 * @return A graph which stores the board 
 */
struct adjList* generateBoard(int numRows, int numColumns){
    //Variable Declarations
    int i, j;
    int boardSize = numRows * numColumns;

    //Declaration for the adjacency list
    struct adjList* boardGraph = (struct adjList*) malloc(sizeof(struct adjList) * boardSize);

    //Holds connected spaces while the options are being found
    int* tempList = (int*) malloc(sizeof(int) * 8);

    //Finds all the possible moves at the current space
    for(i=0; i<boardSize; i++){
        int movesPos = 0;

        int columnNum = i % numColumns;
        int rowNum = i / numRows;
        if(columnNum -1 >= 0){
            if(rowNum -2 >=0 ){
                tempList[movesPos] = i - (numColumns *2) - 1;
                movesPos++;
            }
            if(rowNum + 2 < numRows){
                tempList[movesPos] = i + (numColumns *2) - 1;
                movesPos++;
            }

            if(columnNum - 2 >= 0){
                if(rowNum - 1 >=0 ){
                    tempList[movesPos] = i - (numColumns) - 2;
                    movesPos++;
                }
                if(rowNum + 1 < numRows){
                    tempList[movesPos] = i + (numColumns) - 2;
                    movesPos++;
                }
            }
        }

        if(columnNum + 1 >= 0){
            
            if(rowNum -2 >=0 ){
                tempList[movesPos] = i - (numColumns *2) + 1;
                movesPos++;
            }
            if(rowNum + 2 < numRows){
                tempList[movesPos] = i + (numColumns *2) + 1;
                movesPos++;
            }

            if(columnNum + 2 >= 0){
                if(rowNum - 1 >=0 ){
                    tempList[movesPos] = i - (numColumns) + 2;
                    movesPos++;
                }
                if(rowNum + 1 < numRows){
                    tempList[movesPos] = i + (numColumns) + 2;
                    movesPos++;
                }
            }
        }

        //Assigns the current squares adjacency list
        int* adjListContents = (int*)malloc(sizeof(int) * movesPos);
        for(j=0; j < movesPos; j++){
            adjListContents[j] = tempList[j];
        }
        struct adjList temp;

        temp.size = movesPos;
        temp.contents = adjListContents;

        boardGraph[i] = temp;

    }
    free(tempList);

    return boardGraph;
    
}




int main(int argc, char *argv[]) {

    struct adjList* board = generateBoard(5,5);

    for(int i=0; i<25;  i++){
        int* curList = board[i].contents;
        int listSize = board[i].size;
        printf("%d: ",i+1);

        for(int j=0; j < listSize; j++){
            printf("%d, ",curList[j] +1);
        }
        printf("\n");
    }
    

  
}