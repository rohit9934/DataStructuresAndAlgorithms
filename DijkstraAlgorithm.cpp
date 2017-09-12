//This is the Simplest Implementation of Famous Dijkstra's Algorithm For finding Single source shortest path from one node to all the other nodes
// present in the graph
/*Implementation is done using vectors (adjacency list) and minimum heap as usual.
/pairs are used for implementation of minimum heap and connecting weights with vertices.*/
//Time complexity - O(E logV) where E- No. of Edges and V-No of Vertices thus this implementation fits good for a Sparse Graph.
//Space Complexity- O(logV), this implementation takes logarithmic extra space.
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
		int n,e,x,y,w,s,end;
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
		priority_queue<ii,vector< ii >,prioritize> pq;
	//cout<<"Enter source vertex and destination vertex"<<endl;
		cin>>s>>end;
		dis[s]=0;
		pq.push(ii(s,dis[s]));
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
					pq.push(ii(cn,dis[cn]));			
					}
			}
			
		}
		if(dis[end]==INT_MAX)puts("NO\n");
		//cout<<"The Shortest distance from source vertex "<<s<<" to destination vertex "<<end<<" is"<<endl;
		else cout<<dis[end]<<endl;
	}
return 0;
	}