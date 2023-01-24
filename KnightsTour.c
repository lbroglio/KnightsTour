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

struct arrayWrapper{
    int arr[25];
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
    struct adjList* boardGraph = malloc(sizeof(struct adjList) * boardSize);

    //Holds connected spaces while the options are being found
    int* tempList = malloc(sizeof(int) * 8);

    //Moves through all the spaces on the board
    for(i=0; i<boardSize; i++){
        //Finds all the possible moves at the current space
        int movesPos = 0;

        int columnNum = i % numColumns;
        int rowNum = i / numColumns;
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

        if(columnNum + 1 < numColumns){
            
            if(rowNum -2 >=0 ){
                tempList[movesPos] = i - (numColumns *2) + 1;
                movesPos++;
            }
            if(rowNum + 2 < numRows){
                tempList[movesPos] = i + (numColumns *2) + 1;
                movesPos++;
            }

            if(columnNum + 2 < numColumns){
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
        int* adjListContents = malloc(sizeof(int) * movesPos);
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

/**
 * @brief Checks to see if a given space has already been included in a given tour.
 * 
 * @param tour The tour(integer array) to check for the given space
 * @param tourLength The length of the given tour
 * @param spaceToCheck The space to check if it has been visited previously 
 * @return 1 is the tour does contain the space. 0 if it does not 
 */
int checkTourContains(int* tour, int tourLength, int spaceToCheck){
    for(int i=0; i< tourLength; i++){
        int currSpace = tour[i];
        if(currSpace == spaceToCheck){
            return 1;
        }
    }
    return 0;

}


/**
 * @brief Prints the current tour to the console and given file
 * 
 * @param tourToOutput The tour to output
 * @param size Length of the tour
 * @param fileName Name of the output file
 */
void outputTour(int* tourToOutput, int size, char* fileName){
    for(int i=0;  i < size; i++){
        if(i != 0){
            printf(",");
        }
        int currOutput = tourToOutput[i];
        printf("%d",currOutput);
    }
    printf("\n");
}

/**
 * @brief Recursively finds all the possible knight's tours for a given space on the given board. Outputs its found tours to a file/ and the console
 * 
 * @param boardSize The size of the given board.
 * @param board Array of structs which represents the board as a graph
 * @param currSpace The current space the knight is at
 * @param currTour Array representing the current tour the knight is on
 * @param moveNum The current number of moves the knight has made
 * @param foundTours The number of tours that the program has found
 */
void findTours(int boardSize, struct adjList* board,int currSpace, int* currTour, int moveNum,int* foundTours, struct arrayWrapper visArr){
    currTour[moveNum] = currSpace + 1;
    visArr.arr[currSpace] = 1;

    if(moveNum == boardSize -1){
        *foundTours += 1;
        outputTour(currTour,boardSize,"foundTours.txt");
    }
    for(int i=0; i < (board[currSpace].size); i++){
        int nextSpace = board[currSpace].contents[i];

        int alreadyVisited = visArr.arr[nextSpace];

        if(alreadyVisited == 0){
            findTours(boardSize,board,nextSpace,currTour,moveNum+1,foundTours,visArr);
        }
    }


}


int main(int argc, char *argv[]) {

    int numRows = 5;
    int numCols = 5;
    int boardSize = numRows * numCols;

    struct adjList* board = generateBoard(numRows,numCols);


    struct arrayWrapper visArr;
    for(int i=0; i < boardSize; i++){
        visArr.arr[i] =0;
    }
    
    
    int numTours = 0;
    int* foundTours = &numTours;
    int tourArr[boardSize]; 

    for(int i=0; i < boardSize; i++){
        findTours(boardSize,board,i,tourArr,0,foundTours,visArr);
    }
    //printf("Found: %d tours\n",numTours);

    free(board);
    
    

  
}