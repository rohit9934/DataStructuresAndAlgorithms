#include<bits/stdc++.h>
using namespace std;
string s,s1;
/* Utility function to get max of 2 integers */
int max(int a, int b)
{
    if(a>b) return a;
    else return b;
}
//Top Down Approach for finding longest common subsequence.
int LCS(int i,int j)
{
if(i==0 or j==0)return 0;
if(s[i-1]==s[j-1])
      return LCS(i-1,j-1)+1;
else //Check for all possible combinations.
      return max(LCS(i,j-1),LCS(i-1,j));
}
int LongestCommonSubsequence(string s,string s1)
{
  int m=s.length();
  int n=s1.length();
   int lcs[m+1][n+1];
   int i, j;
  /*
  The below lines gives Longest common subsequence in Bottom-up Technique.
  */
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         lcs[i][j] = 0;
  
       else if (s[i-1] == s1[j-1])
         lcs[i][j] = lcs[i-1][j-1] + 1;
  
       else
         lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
     }
   }
    
   //After going through all possible combinations, we will return maximum of all.
   return lcs[m][n];
}
  
/* Driver program to test above function */
int main()
{
  s = "AGGTAB";
  s1 = "GXTXAYB";
  
  cout<<"The Length of Longest Common Subsequence is "<<LongestCommonSubsequence(s,s1)<<endl;
 
  return 0;
}
