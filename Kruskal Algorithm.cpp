/*
Minimum Spanning Tree: A tree which consists of all nodes of the graph with
(nodes-1) edges and having weight minimum possible is called Minimum Spanning Tree.
For Example:
The Input for below program will give the result: 7
4 5
1 2 1
1 3 4
2 4 2
1 4 3
3 4 5

Output: 7
Algorithm:
Kruskal Algorithm is an efficient ALgorithm for finding sum of weights of Minimum Spanning
Tree of a graph.
We will sort the trees in accordance of non decreasing order of their weights.
We will Add The Edges one by one from lowest weight to highest only and only if they do not form a cycle.
We will use Disjoint Set Union instead of DFS/BFS for this because Time Complexity of DFS is O(V+E)
which can become exponential when checking for every edge.

Algorithm:
	1)Sort the Graph in non-decreasing order of edges.
	2)Pick edges one by one and check if they are already operated on contain cycle and edges which connects only 
		disconnected components.
	3)Else Add edge weight and join the two vertices.
	return Minimum cost.


	The Most Time Consuming part is Sorting which is O(LogE)
	The Time Complexity of Disjoint Sets are O(E*LogV) which is Time Complexity of the algorithm



	Uses of the Algorithm.
	Minimum spanning tree has direct application in the design of networks.
	It is used in algorithms approximating the travelling salesman problem, multi-terminal minimum cut problem and minimum-cost weighted perfect matching.
	 Other practical applications are:
		1)Cluster Analysis
		2)Handwriting recognition
		3)Image segmentation
*/

#include<bits/stdc++.h>
#define MAX 100005
using namespace std;
pair<int, pair<int,int> > graph[MAX];
int parent[MAX];
int nodes,edges,node1,node2,weight;
//This function returns the parent of the current node.
int root(int num)
{
	while(parent[num] != num){
		parent[num]= parent[parent[num]];
		num=parent[num];
	}
	return num;
}
//This Function joins two nodes using disjoint set union Algorithm
void Union(int node1,int node2){
	int p= root(node1);
	int q= root(node2);
	parent[p]=parent[q];
}
int KruskalAlgorithm(pair<int,pair<int,int > > graph[])
{
	int x,y,TemporaryCost,MinimumCost=0;
	for(int i=0;i<edges;i++)
	{
		x= graph[i].second.first;
		y= graph[i].second.second;
		TemporaryCost= graph[i].first;
		if(root(x)!=root(y))
		{
			MinimumCost+= TemporaryCost;
			Union(x,y);
		}
	}
	return MinimumCost;
}
int main(){
	for(int i=0;i<MAX;i++)
		parent[i]=i; //All the nodes i are parent of themselves initially.
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++){
		cin>>node1>>node2>>weight;
		graph[i] =make_pair(weight,make_pair(node1,node2));
	}
	int MinimumCost;
	sort(graph,graph+edges);
	//MinimumCost= KruskalAlgorithm(graph);
	cout<<KruskalAlgorithm(graph);
	return 0;
}


