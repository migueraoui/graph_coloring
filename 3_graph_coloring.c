#include <stdio.h>
#define NOEUDES 6
#define COLORS 6

//Define the colors in Matrix (C does not have a String type)
char colors[COLORS][7] = {"red", "blue", "green", "yellow", "black", "gray"};

// Define the graph in matrix adjacent
int graph[NOEUDES][COLORS] = {
    {0, 1, 1, 0, 1, 1}, // A adjacent with B,C,E,F
    {1, 0, 1, 1, 0, 1}, // B adjacent with A,C,D,F
    {1, 1, 0, 1, 1, 0}, // C adjacent with B,A,D,E
    {0, 1, 1, 0, 1, 1}, // D adjacent with C,B,E,F
    {1, 0, 1, 1, 0, 1}, // E adjacent with D,C,A,F
    {1, 1, 0, 1, 1, 0}  // F adjacent with D,E,A,B
};

// Function to check if it is okay to color a noeude with a color
int isValid(int noeude, int color, int coloring[NOEUDES]){
    for(int i = 0; i < NOEUDES; i++){
        if(graph[noeude][i] && coloring[i] == color){
            return 0;
        }
    }
    return 1;
}

// Function for graph coloring
void coloringGraph(int coloring[NOEUDES], int noeude){
    if (noeude == NOEUDES) {
        // All Noeudes are colored so print the coloring
        for (int i = 0; i < NOEUDES; i++) {
            printf("%c: %s\n", 'A' + i, colors[coloring[i]]);
        }
        printf("\n");
         //return; //dis comment return; to get all solusions
    }

    for(int color = 0; color < COLORS; color++){
        if(isValid(noeude, color, coloring)){
            coloring[noeude]= color;
            coloringGraph(coloring, noeude+1);
            coloring[noeude] = -1; // Using a Backtrack algorithm
        }
    }
}


void main(int argc, char *argv){
    int coloring[NOEUDES];

    // Initialize coloring with -1  cause no color assigned
    for (int i = 0; i < NOEUDES; ++i) {
        coloring[i] = -1;
    }

    // Start coloring from the first noeude
    coloringGraph(coloring, 0);
}
