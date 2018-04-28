/*
Problem:  Maze is given as N*N binary matrix of blocks where source block
  is the upper left most block i.e., maze[0][0] and destination block 
  is lower rightmost block i.e., maze[N-1][N-1]. A rat starts from 
  source and has to reach destination.
  The rat can move only in two directions: forward and down.
  Print the solution
*/

 /* The function recur() solves the Maze problem using
       Backtracking. It mainly uses recur()
       to solv the problem. It returns false if no
       path is possible, otherwise return true and
       prints the path in the form of 1s. Please note
       that there may be more than one solutions, this
       function prints one of the feasible solutions.*/

class Maze
{
    final int N = 4;
 
    /* A utility function to print RatMazeution matrix
       RatMaze[N][N] */
    void printAnswer(int RatMaze[][])
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                System.out.print(" " + RatMaze[i][j] +
                                 " ");
            System.out.println();
        }
    }
    boolean isSafe(int maze[][], int x, int y) // A boolean function to check whetner the given 
    // point is valid or not
    {
        return (x >= 0 && x < N && y >= 0 &&
                y < N && maze[x][y] == 1);
    }
 
    boolean Backtrack(int maze[][])
    {
        int RatMaze[][] = {{0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        };
 
        if (recur(maze, 0, 0, RatMaze) == false)
        {
            System.out.print("Solution doesn't exist");
            return false;
        }
 
        printAnswer(RatMaze);
        return true;
    }
 
    /* A recursive utility function to RatMazeve Maze
       problem */
    boolean recur(int maze[][], int x, int y,
                          int RatMaze[][])
    {
        // if (x,y is goal) return true
        if (x == N - 1 && y == N - 1)
        {
            RatMaze[x][y] = 1;
            return true;
        }
 
        // Check if maze[x][y] is valid
        if (isSafe(maze, x, y) == true)
        {
            // mark x,y as part of RatMazeution path
            RatMaze[x][y] = 1;
 
            /* Move forward in x direction */
            if (recur(maze, x + 1, y, RatMaze))
                return true;
 
            /* If moving in x direction doesn't give
               RatMazeution then  Move down in y direction */
            if (recur(maze, x, y + 1, RatMaze))
                return true;
            RatMaze[x][y] = 0;
            return false;
        }
 
        return false;
    }
 
    public static void main(String args[])
    {
        Maze rat = new Maze();
        int maze[][] = {{1, 0, 0, 0},
            {1, 1, 0, 1},
            {0, 1, 0, 0},
            {1, 1, 1, 1}
        };
        rat.Backtrack(maze);
    }
}
