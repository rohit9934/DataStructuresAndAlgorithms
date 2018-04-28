/*
About KMP Algorithm......
a  b  x  a  b  c  a  b  c  a  b  y
Pattern - a  b  c  a  b  y
 LPS    - 0  0  0  1  2  0
Pattern Size is n and text size is m then time complexity of kmp is
O(m)+O(n)= O(m+n) where O(n) to build lps array and O(m) for the search
Algorithm-
function LPS():
    j=0,i=1
    while(i<n)
        if pat[j]==pat[i]:
            j++,lps[i]=j,i++;
        else
            if j==0:
                lps[i++]=0
            else j=lps[j-1]
function KMP():
    while i<M:
    if pat[j]==text[i]:
        i++,j++
    else if j==N:
        return i-j
    else if i<N and pat[j]!=text[i]:
        if j==0:
            i++
        else:
            j=lps[j-1]
Short Note:
first check whether the word is matched or not if yes, then increment both
i and j, else check for lps array and return highest prefix which is also a 
suffix
*/
public class KMPAlgorithm
{
    void KMPSearch(String substring, String Text)
    {
        int M = substring.length();
        int N = Text.length();
        int lps[] = new int[M];
        int j = 0;  
        LongestPrefixSuffix(substring,M,lps);
        int i = 0; 
        while (i < N)
        {
            if (substring.charAt(j) == Text.charAt(i))
            {
                j++;
                i++;
            }
            if (j == M)
            {
                System.out.println("Found Pattern "+
                              "at index " + (i-j));
                j = lps[j-1];
            }
            else if (i < N && substring.charAt(j) != Text.charAt(i))
            {
                if (j != 0)
                    j = lps[j-1];
                else
                    i = i+1;
            }
        }
    }
 
    void LongestPrefixSuffix(String substring, int M, int lps[])
    {
        int len = 0;
        int i = 1;
        lps[0] = 0;  
        while (i < M)
        {
            if (substring.charAt(i) == substring.charAt(len))
            {
                len++;
                lps[i] = len;
                i++;
            }
            else  
            {
                if (len != 0)
                {
                    len = lps[len-1];
                }
                else 
                {   lps[i] = len;
                    i++;
                }
            }
        }
    }
    public static void main(String args[])
    {
        String Text = "abxabcabcaby";
        String substring = "abcaby";
        new KMPAlgorithm().KMPSearch(substring,Text);
    }
}
