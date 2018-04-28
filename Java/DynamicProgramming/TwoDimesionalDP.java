/*
Famous Interview Problem:
Given a 2-D Matrix, where each point on row is considered as points(denoted by some number)
You can go from top row starting from any point to bottom row
in the directions: right, left, bottom right, bottom left, Print the largest number of points
you can grab.
input:
Number of Inputs, Number of rows and columns, 2D Matrix.
Input:
1
6 5
3 1 7 4 2
2 1 3 1 1
1 2 2 1 8
2 2 1 5 3
2 1 4 4 4
5 2 7 5 1

Output: 32
Path:7+1+8+5+4+7=32
*/


import java.io.*;
import java.util.*;
class TwoDimensionalDP {
	public static void main(String[] args) throws Exception{
		Scanner in = new Scanner(System.in);
		StringBuilder string = new StringBuilder();
		int[][] grid = new int[102][102];
		int t = in.nextInt();
		for(int x = 0; x < t; x++){
			int rows = in.nextInt();
			int cols = in.nextInt();
			int i, j;
			for(i = 1; i <= rows; i++){
				for(j = 1; j <= cols; j++){
					grid[i][j] = in.nextInt();
				}
				grid[i][j] = 0;
				for(j = 1; j <= cols; j++){
					grid[i][j] += max(grid[i-1][j-1], grid[i-1][j], grid[i-1][j+1]);
				}				
			}
			int r = grid[rows][1];
			for(i = 2; i <= cols; i++){
				r = max(r, grid[rows][i], 0);
			}
			string.append(r + "\n");
		}
		System.out.print(string);
	}
	
	public static int max(int a, int b, int c){
		if(a >= b && a >= c){
			return a;
		}else if(b >= c){
			return b;
		}else{
			return c;
		}
	}
}
