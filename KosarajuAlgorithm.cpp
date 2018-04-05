
/* About Kosaraju Algorithm
KosaRaju Algorithm is used to find all the Strongly Connected Components of a graph
Strongly Connected Components:
A SCC is a subgraph of the graph in which all the nodes can be reached through any
node from that subgraph
For EG:     
Given a graph with G(nodes,edges)= (11,13)
And Connectivity of the vertices as
1->2
2->3
3->1
2->4
4->5
5->6
6->4
7->6
7->8
8->9
9->10
10->7
10->11

There will be 4 SCC's as follows
7 10 9 8 
11 
1 3 2 
4 6 5 

Applications: One of the common example we see in facebook,we know that facebook is graph of users.
facebook use this type of similar algorithm to link some group of people which are strongly connected
i.e friends and thus shows same news feed

Algorithm:
	Let ST be stack and G be the graph
	DFS(source):
		visit[source]=true
		For All neighbours N of source in G:
			if N is not visited:
				DFS(N)
0			ST.push(N)
	REVERSE THE EDGES OF THE graph
	Let new graph be REV
	while ST is NOT EMPTY:
		if ST.top is not visited
			Run DFS AGAIN on REV
		ST.pop()		
Time Complexity of the Algorithm is O(2*(Nodes+Edges)) because of 2 DFS which is as good as O(V+E)
Space Complexity is O(V) because of the stack
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+5;
vector<int> v[MAX],rev[MAX];
stack<int> st; bool mark[MAX]={};
int c=0;
void dfs(int s)
{
	mark[s]=true;
	for(vector<int>::iterator it=v[s].begin();it!=v[s].end();++it)
		if(!mark[*it])dfs(*it);
	st.push(s);
}
void dfs1(int s){
	mark[s]=true;
	cout<<s<<" ";
	for(vector<int>::iterator it=rev[s].begin();it!=rev[s].end();++it)
		if(!mark[*it])dfs1(*it);

}
int main()
{
int nodes,edges,x,y;
cin>>nodes>>edges;
for(int i=0;i<edges;i++){
cin>>x>>y;
v[x].push_back(y); rev[y].push_back(x);
}
for(int i=1;i<=nodes;i++)if(!mark[i])dfs(i);
memset(mark,false,sizeof mark);
while(!st.empty()){
		int s=st.top();
		st.pop();
		if(!mark[s]){
		dfs1(s);
		cout<<endl;
		}
	}
	return 0;
}
