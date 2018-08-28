/*
About the Data-Structure:
Segment tree is a binary tree which stores Queries of Range Interval in the
parent tree.
The Segment tree came into the picture based on the fact that it takes O(logN)
time in processing the Queries between ranges suppose L to R where N is the length
of the array where Normal Brute Force method would take O(R-L) time.



Problem: You are Given an Array consisting of Not more than 10^5 elements.
ALso your queries can go upto 10^5 elements. You have to find sum between range x and y.
Also you have to update the element at position p simultaneously if required
If user input is M followed by two inputs(RANGE), print the range,
else update the element with following value.

*/
#include <bits/stdc++.h> 
using namespace std;
int a[100001],seg[400004],lazy[400004];


//To build the Segment tree we would need O(4*N) extra spaace because of formation of binary tree.

//We move from node 1 and use recursion to store sum of 2*p+1 and 2*p to p.
void build(int p,int s,int e){	//p is the root of the segment tree.
	if(s==e){ seg[p]=a[s]; return;}
 	build(2*p,s,(s+e)/2); build(2*p+1,(s+e)/2 +1, e);
	seg[p]=seg[2*p]+seg[2*p+1];
}

/*
Query is done using concept of overlapping.
There are three types of overlapping:
1.Total overlap: when s and e are completely within l and r, return our result
2.No overlap: ignore that interval
3. Partial overlap: Dive on both childrens of the node using recursion.
*/
int query(int l,int r,int s,int e,int p){
	if(l<=s and r>=e)return seg[p];
	if(l>e or s>r)return 0;
	return query(l,r,s,(s+e)/2,2*p)+query(l,r,(s+e)/2 +1,e,2*p+1);
}



void update(int i,int val,int s,int e,int p){
if(s==e)a[i]=val,seg[p]=val;
else{
	i>=s and i<=(s+e)/2 ? update(i,val,s,(s+e)/2,2*p):update(i,val,(s+e)/2 +1,e,2*p+1);
	seg[p]=seg[2*p]+seg[2*p+1];
	}
}


//Lazy Propogation for Updating intervals.
void lazyProp(int l,int r,int val,int s,int e,int p) 
{
if(l>e or s>r)return;
if(lazy[p]!=0){	seg[p]+=lazy[p];
if(s!=e)lazy[2*p]+=lazy[p],lazy[2*p+1]+=lazy[p];
lazy[p]=0;
}
if(l<=s and r>=e){ seg[p]+=val; 
if(s!=e)lazy[2*p]+=lazy[p],lazy[2*p+1]+=lazy[p];
return;
}
 	lazyProp(l,r,val,s,(s+e)/2,p); lazyProp(l,r,val,(s+e)/2 +1,e,p);
	seg[p]=seg[2*p]+seg[2*p]+1;
}



int lazyquery(int l,int r,int s,int e,int p){
	if(l>e or s>r)return 0;
	if(lazy[p]!=0){
		seg[p]+=lazy[p];
		if(s!=e)lazy[2*p]+=lazy[p],lazy[2*p+1]+=lazy[p];
		lazy[p]=0;
}
if(l<=s and r>=e)return seg[p];
return lazyquery(l,r,s,(s+e)/2,p)+lazyquery(l,r,(s+e)/2 +1,e,p);
}

/* 
INPUT:
5 3
2 4 1 7 9
M 2 5
U 3 4
M 2 5
*********************



OUTPUT:
21
24


*/

int main()
{ char c;  int n,q,x,y; cin>>n>>q;
for(int i=1;i<=n;i++)cin>>a[i];
build(1,1,n); 
while(q--){
	cin>>c>>x>>y;
	if(c=='M')
		cout<<query(x,y,1,n,1)<<endl;
	else update(x,y,1,n,1);
}	return 0;
}
