/*
Given two strings FirstString and SecondString and below operations that can performed on FirstString. Find minimum number of edits (operations) required to convert ‘FirstString’ into ‘SecondString’.

Insert
Remove
Replace
All of the above operations are of equal cost.

Examples:
Input:   FirstString = "geek", SecondString = "gesek"
Output:  1
We can convert FirstString into SecondString by inserting a 's'.

Input:   FirstString = "cat", SecondString = "cut"
Output:  1
We can convert FirstString into SecondString by replacing 'a' with 'u'.

Input:   FirstString = "sunday", SecondString = "saturday"
Output:  3
Last three and first characters are same.  We basically
need to convert "un" to "atur".  This can be done using
below three operations. 
Replace 'n' with 'r', insert t, insert a

*/


class EditDistace
{
    static int min(int x,int y,int z)
    {
        if (x <= y && x <= z) return x;
        if (y <= x && y <= z) return y;
        else return z;
    }
 
    static int EditDistDP(String From, String To, int m, int n)
    {
        int LookupTable[][] = new int[m+1][n+1];
        for (int i=0; i<=m; i++)
        {
            for (int j=0; j<=n; j++)
            {
                if (i==0)
                    LookupTable[i][j] = j; 
                else if (j==0)
                    LookupTable[i][j] = i; 
                else if (From.charAt(i-1) == To.charAt(j-1))
                    LookupTable[i][j] = LookupTable[i-1][j-1];
                else
                    LookupTable[i][j] = 1 + min(LookupTable[i][j-1],  // Insert
                                       LookupTable[i-1][j],  // Remove
                                       LookupTable[i-1][j-1]); // Replace
            }
        }
  
        return LookupTable[m][n];
    }
    public static void main(String args[])
    {
        String From = "FOOD";
        String To = "MONEY";
        System.out.println( EditDistDP( From , To , From.length(), To.length()) );
    }
}
