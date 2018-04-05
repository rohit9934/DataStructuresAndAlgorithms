/*
About KMP Algorithm......
a  b  x  a  b  c  a  b  c  a  b  y
Pattern - a  b  c  a  b  y
 LPS    - 0  0  0  1  2  0
Output: 7
Description: KMP Algorithm is used to search for a given pattern in a text.
Time-Complexity- If Pattern Size is n and text size is m then time complexity of kmp is
O(m)+O(n)= O(m+n) where O(n) to build lps array and O(m) for the search
*******************************************Algorithm*******************************************
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
	while i<N:
	if pat[j]==text[i]:
		i++,j++
	else if j==M:
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
#include <bits/stdc++.h> 
using namespace std;
int lps[100005];
string s,s1;

void ps(int n){
	int j=0,i=1;
	lps[0]=0;
	while(i<n){
		if(s1[i]==s1[j])lps[i]=++j,i++;
		else {
			if(j==0)lps[i]=0,i++;
			else j=lps[j-1];
		}
	}
}
void kmp(string s,string s1){
	int i=0,j=0,m=s.length(),n=s1.length();
	ps(n);// For Generating LPS array of the pattern
	while(i<m){
		if(s1[j]==s[i])i++,j++;
		if(j==n){cout<<1+(i-j)<<endl;j = lps[j-1]; }
		else if(i<m and s1[j]!=s[i]){
			if(j==0)i++;
			else j=lps[j-1];
		}
	}
	
}
int main()
{	//Taking two strings as raw_input.
	cin>>s>>s1;
	kmp(s,s1);
	return 0;
}
