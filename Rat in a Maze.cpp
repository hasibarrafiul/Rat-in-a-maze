#include <stdio.h>

#define SIZE 5

//1 is visitable and 0 is not visitable

int maze[SIZE][SIZE] = {
    {1,0,1,0,0},
    {1,1,1,1,1},
    {0,1,0,1,0},
    {1,1,0,1,1},
    {0,1,1,0,1}
};


char solution[SIZE][SIZE];

void printsolution()
{
    int i,j;
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            printf("%c\t",solution[i][j]);
        }
        printf("\n\n");
    }
}

int solvemaze(int r, int c)
{
    if((r==SIZE-1) && (c==SIZE-1))
    {
        solution[r][c] = 'P';
        return 1;
    }
    if(r>=0 && c>=0 && r<SIZE && c<SIZE && solution[r][c] == 'U' && maze[r][c] == 1)
    {
        solution[r][c] = 'P';

        if(solvemaze(r+1, c))
            return 1;

        if(solvemaze(r, c+1))
            return 1;

        if(solvemaze(r-1, c))
            return 1;

        if(solvemaze(r, c-1))
            return 1;

        solution[r][c] = 'B';
        return 0;
    }
    return 0;

}

int main()
{

    int i,j;
    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            solution[i][j] = 'U';
        }
    }
    if (solvemaze(0,0)){
        printf("The solution path is marked as P \n");
        printf("The unreachable path is marked as U \n");
        printf("The backtracking path is marked as B \n\n");
        printsolution();
    }

    else
        printf("No solution\n");
    return 0;
}
