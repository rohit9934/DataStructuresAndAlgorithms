/*

Algorithm
1) Create a set markSet (shortest path tree set) that keeps track of vertices
 included in shortest path tree, i.e., whose minimum distance from source is 
 calculated and finalized. Initially, this set is empty.
2) Assign a distance value to all vertices in the input graph.
 Initialize all distance values as INFINITE. Assign distance 
 value as 0 for the source vertex so that it is picked first.
3) While markSet doesn’t include all vertices
….a) Pick a vertex u which is not there in markSetand has minimum distance value.
….b) Include u to markSet.
….c) Update distance value of all adjacent vertices of u.
 To update the distance values, iterate through all adjacent vertices.
  For every adjacent vertex v, if sum of distance value of u (from source) and weight of edge u-v, 
  is less than the distance value of v, then update the distance value of v.


Time Complexity: O(V*V) where V is vertex of the graph

*/



import java.util.*;
import java.lang.*;
import java.io.*;
 
class ShortestPath
{
    static final int V=9;
    int ShortestDistance(int dist[], Boolean mark[])
    {
        int min = Integer.MAX_VALUE, min_index=-1;
 
        for (int v = 0; v < V; v++)
            if (mark[v] == false && dist[v] <= min)
            {
                min = dist[v];
                min_index = v;
            }
 
        return min_index;
    }
    void PathPrinting(int dist[], int n)
    {
        System.out.println("Vertex   Distance from Source");
        for (int i = 0; i < V; i++)
            System.out.println(i+" tt "+dist[i]);
    }
    void dijkstra(int graph[][], int src)
    {
        int dist[] = new int[V]; 
        Boolean mark[] = new Boolean[V];
        for (int i = 0; i < V; i++)
        {
            dist[i] = Integer.MAX_VALUE;
            mark[i] = false;
        }
        dist[src] = 0;
        for (int it = 0; it < V-1; it++)
        {
            int u = ShortestDistance(dist, mark);
            mark[u] = true;

            //This is the main Algorithm , update the distance if it founds shorter than the current path.
            for (int v = 0; v < V; v++)
                if (!mark[v] && graph[u][v]!=0 &&
                        dist[u] != Integer.MAX_VALUE &&
                        dist[u]+graph[u][v] < dist[v])
                    dist[v] = dist[u] + graph[u][v];
        }
        PathPrinting(dist, V);
    }
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int v=sc.nextInt();
		int e= sc.nextInt();
		int adjacencyMatrix[][] = new int[v][v];
		for(int i=0;i<e;i++){
			int v1=sc.nextInt();
			int v2=sc.nextInt();
			int weight= sc.nextInt();
			adjacencyMatrix[v1][v2]=weight;
			adjacencyMatrix[v2][v1]=weight;
		}
		ShortestPath obj = new ShortestPath();
        obj.dijkstra(graph, 0);
	}
}
