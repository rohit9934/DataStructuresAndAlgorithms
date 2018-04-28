/*
Disjoint-Set Union.
Disjoint-Set Union is a very clever technique when two or more points are
connected to each other in some computer science problem, 
Consider the folowing problem:
There are N friends connected. 1,2,3,4..........N.
Friend 1 is connected 2, Friend 3 is connected to 4 and 
Friend 2 is connected to 3. Here 1 and 3 are connected via 2. So if 
connections breaks between 2 and 3, then 1 also losts it's connection to 3 and 4.
These types of problems can be tackled with Disjoint Set Union.
Problem Statement: Consider a graph with nodes and edges, tell if graph is cyclic or not?
Connectivity can be visualise with the help of graphs but the DFS/BFS
approach will take O(V+E) where V is number of vertices and E is Number of Edges.
Here Disjoint set will take O(E) time and can be furthur optimised to O(LogE)

There are 2 basic functions in DisJoint Union:
1. Union(x,y) connects x to y.
2. Find(i) finds parent of vertex i.
*/


import java.util.*;
import java.lang.*;
import java.io.*;
 
class Graph
{
    //Number of vertices and edges.
    int V, E;    
    Edge edge[]; 
 
    class Edge
    {
        int Source, Destination;
    };
 //Constructor that will create a graph with V vertices and E edges
    Graph(int v,int e)
    {
        V = v;
        E = e;
        edge = new Edge[E];
        for (int i=0; i<e; ++i)
            edge[i] = new Edge();
    }

    int find(int parent[], int i)// To find parent of an element using recursion
    {
        if (parent[i] == -1)
            return i;
        return find(parent, parent[i]);
    }
    void Union(int parent[], int x, int y)//Connect two elements together
    {
        int p = find(parent, x);
        int q = find(parent, y);
        parent[p] = q;
}
//Function to check whether graph contains cycles or not
    int containCycles( Graph graph)
    {
        int parent[] = new int[graph.V];
 
        // Set Parent of every element to -1.
        for (int i=0; i<graph.V; ++i)
            parent[i]=-1;
 
        // Iterate through all edges of graph, find subset of both
        // vertices of every edge, if both subsets are same, then
        // there is cycle in graph.
        for (int i = 0; i < graph.E; ++i)
        {
            int x = graph.find(parent, graph.edge[i].Source);
            int y = graph.find(parent, graph.edge[i].Destination);
 
            if (x == y)
                return 1;
 
            graph.Union(parent, x, y);
        }
        return 0;
    }
 
    // Driver Method
    public static void main (String[] args)
    {
        /* Let us create following graph
         0
        |  \
        |    \
        1-----2 */
        int V = 3, E = 3;
        Graph graph = new Graph(V, E);
 
        // add edge 0-1
        graph.edge[0].Source = 0;
        graph.edge[0].Destination = 1;
 
        // add edge 1-2
        graph.edge[1].Source = 1;
        graph.edge[1].Destination = 2;
 
        // add edge 0-2
        graph.edge[2].Source = 0;
        graph.edge[2].Destination = 2;
 
        if (graph.containCycles(graph)==1)
            System.out.println( "contains cycle" );
        else
            System.out.println( " doesn't contain cycle" );
    }
}
