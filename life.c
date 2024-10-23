#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRID 5
#define GENERATIONS 6  

void initialize(int grid[GRID][GRID]);
void display(int grid[GRID][GRID], int generation);
void live_cells(int grid[GRID][GRID]);
int live_neighbors(int grid[GRID][GRID], int row, int col);
void update(int current[GRID][GRID], int next[GRID][GRID]);
void copy(int src[GRID][GRID], int dest[GRID][GRID]);

int main() {
    char game_start;
    printf("Welcome! Press 'q' to quit or any other key to continue:\n");
    scanf(" %c", &game_start);

    while (game_start != 'q') {
        int currentGrid[GRID][GRID];
        int nextGrid[GRID][GRID];

        initialize(currentGrid);
        live_cells(currentGrid);

        for (int generation = 0; generation <= GENERATIONS; generation++) {
            display(currentGrid, generation);

            if (generation == GENERATIONS) {
                printf("Good life!\n");
                break;
            }

            update(currentGrid, nextGrid);
            copy(nextGrid, currentGrid);  
        }

        printf("Press 'q' to quit or any other key to continue:\n");
        scanf(" %c", &game_start);
    }

    printf("Bye Bye!\n");
    return 0;
}

void initialize(int grid[GRID][GRID]) {
    for (int i = 0; i < GRID; i++) {
        for (int j = 0; j < GRID; j++) {
            grid[i][j] = 0;  
        }
    }
}

void display(int grid[GRID][GRID], int generation) {
    printf("generation = %d:\n", generation);
    for (int i = 0; i < GRID; i++) {
        for (int j = 0; j < GRID; j++) {
            if (grid[i][j] == 1) {
                printf("*");  
            } else {
                printf(" "); 
            }
        }
        printf("\n");
    }
}

void live_cells(int grid[GRID][GRID]) {
    printf("Enter the offsets for the live cells:\n");
    char input[100];
    scanf("%s", input);
    int offset;
    char *token = strtok(input, ",");
    while (token != NULL) {
        offset = atoi(token);
        if (offset >= 0 && offset < GRID * GRID) {
            grid[offset / GRID][offset % GRID] = 1;  
        } else {
            printf("Invalid offset: %d\n", offset);  
        }
        token = strtok(NULL, ",");
    }
}

int live_neighbors(int grid[GRID][GRID], int row, int col) {
    int Live_Neighbors = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;  
            int neighbor_row = row + i;
            int neighbor_col = col + j;

            if (neighbor_row >= 0 && neighbor_row < GRID && neighbor_col >= 0 && neighbor_col < GRID) {
                Live_Neighbors += grid[neighbor_row][neighbor_col];
            }
        }
    }
    return Live_Neighbors;
}

void update(int current[GRID][GRID], int next[GRID][GRID]) {
    for (int i = 0; i < GRID; i++) {
        for (int j = 0; j < GRID; j++) {
            int Live_Neighbors = live_neighbors(current, i, j);

            if (current[i][j] == 1) {  
                if (Live_Neighbors < 2 || Live_Neighbors > 3) {
                    next[i][j] = 0;  
                } else {
                    next[i][j] = 1;  
                }
            } else {  
                if (Live_Neighbors == 3) {
                    next[i][j] = 1;  
                } else {
                    next[i][j] = 0;  
                }
            }
        }
    }
}

void copy(int src[GRID][GRID], int dest[GRID][GRID]) {
    for (int i = 0; i < GRID; i++) {
        for (int j = 0; j < GRID; j++) {
            dest[i][j] = src[i][j];
        }
    }
}
