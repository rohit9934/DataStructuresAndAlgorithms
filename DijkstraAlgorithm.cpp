//This is the Simplest Implementation of Famous Dijkstra's Algorithm For finding Single source shortest path from one node to all the other nodes
// present in the graph
/*Implementation is done using vectors (adjacency list) and minimum heap as usual.
/pairs are used for implementation of minimum heap and connecting weights with vertices.*/
//Time complexity - O(E logV) where E- No. of Edges and V-No of Vertices thus this implementation fits good for a Sparse Graph.
//Space Complexity- O(V), this implementation takes Linear extra space.
/*
Algorithm:

1) Initialize distances of all vertices as infinite.

2) Create an empty priority_queue pq.  Every item
   of pq is a pair (weight, vertex). Weight (or 
   distance) is used used as first item  of pair
   as first item is by default used to compare
   two pairs

3) Insert source vertex into pq and make its
   distance as 0.

4) While either pq doesn't become empty
    a) Extract minimum distance vertex from pq. 
       Let the extracted vertex be p.(parent node)
    b) Loop through all adjacent of p and do 
       following for every vertex cn.(current node)
    c) Let the weight from p to cn is cd(current distance).
           // If there is a shorter path to current node
           // through p. 
           If dist[cn] > dist[p] + cd

               (i) Update distance of cn, i.e., do
                     dist[cn] = dist[p] + weight(cn, p)
               (ii) Insert cn into the pq (Even if cn is
                    already there)
               
5) Print distance array dist[] to print all shortest
   paths. 
*/
#include<bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
class prioritize
{
	public:
	int operator()(const ii &a,const ii &b)
	{
	return a.second<b.second;	
	}
	
};
int main()
{
	int t;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>t;
	while(t--)
	{
		int n,e,x,y,w,start,end;
		//cout<<"Enter no. of vertices and no. of edges"<<endl;
		cin>>n>>e;
		vector<ii> v[n+1];
		//cout<<"Enter two connected vertices along with weights."<<endl;
		for(int i=0;i<e;i++)
		{
			cin>>x>>y>>w;
			v[x].push_back(make_pair(y,w));
		}
		bool mark[n+1]={0};
		int dis[n+1];
		for(int i=1;i<=n;i++)dis[i]=INT_MAX;
		priority_queue<pair<int,int>,vector< pair<int,int> >,prioritize> pq;
	//cout<<"Enter source vertex and destination vertex"<<endl;
		cin>>start>>end; //start and end
		dis[start]=0;
		pq.push(make_pair(s,dis[s]));
		while(!pq.empty())
		{
			int p=pq.top().first;
			pq.pop();
			if(mark[p])continue;
			mark[p]=true;
			for(vector<ii>::iterator it=v[p].begin();it!=v[p].end();++it)
			{
				int cn=it->first;
				int cd=it->second;
				if(dis[cn]>dis[p]+cd)
				{
					dis[cn]=dis[p]+cd;
					pq.push(make_pair(cn,dis[cn]));			
					}
			}
			
		}
		if(dis[end]==INT_MAX)puts("NO\n");
		//cout<<"The Shortest distance from source vertex "<<s<<" to destination vertex "<<end<<" is"<<endl;
		else cout<<dis[end]<<endl;
	}
return 0;
	}
