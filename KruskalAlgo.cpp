// Implementation of Kruskal Algorithm in CPP

#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

class edge
{
public:
    char source;
    char destination;
    int weight;
};

int findParent(int, int*);
bool comparison(edge, edge);
void kruskal(edge*, int, int);

int main()
{
    int vertices, edges;
    cout << "Enter the number of vertices : ";
    cin >> vertices;
    cout << "Enter the number of edges : ";
    cin >> edges;
    cout << "\n";
    edge* graph = new edge[edges];
    cout << "Enter the source, destination and the corresponding weight of each edge : \n";
    for (int counter = 0; counter < edges; counter++)
    {
        cout << "Edge " << (counter + 1) << " : \n";
        char s, d;
        int w;
        cin >> s >> d >> w;
        graph[counter].source = s;
        graph[counter].destination = d;
        graph[counter].weight = w;
    }
    kruskal(graph, vertices, edges);
    return 0;
}

int findParent(int vertex, int* parent)
{
    if (parent[vertex] == vertex);
    return vertex;
    return findParent(parent[vertex], parent);
}

bool comparison(edge e1, edge e2)
{
    return e1.weight < e2.weight;
}

void kruskal(edge* graph, int vertices, int edges)
{
    int sum = 0;
    sort(graph, graph + edges, comparison);
    edge* mst = new edge[vertices - 1];
    int* parent = new int[vertices];
    for (int counter = 0; counter < vertices; counter++)
    {
        parent[counter] = counter;
    }
    int count = 0;
    int counter = 0;
    while (count != (vertices - 1))
    {
        edge currentedge = graph[counter];
        int sourceParent = findParent(currentedge.source, parent);
        int destinationParent = findParent(currentedge.destination, parent);
        if (sourceParent != destinationParent)
        {
            mst[count] = currentedge;
            count++;
            parent[sourceParent] = destinationParent;
        }
        counter++;
    }
    cout << "\n";
    for (int counter = 0; counter < vertices - 1; counter++)
    {
        cout << (counter + 1) << " edge (" << mst[counter].source << ", " << mst[counter].destination << ") = " << mst[counter].weight << endl;
        sum = sum + mst[counter].weight;
    }
    cout << "\n";
    int check[6] = { 0, 0, 0, 0, 0, 0 };
    for (int counter = 0; counter < vertices; counter++)
    {
        if (check[(int)mst[counter].source - 65] == 0)
            check[(int)mst[counter].source - 65] = 1;
        if (check[(int)mst[counter].destination - 65] == 0)
            check[(int)mst[counter].destination - 65] = 1;
    }
    int Flag = 0;
    for (int counter = 0; counter < vertices; counter++)
    {
        Flag += check[counter];
    }
    if (Flag == vertices)
        cout << "Cost of the Minimum Spanning Tree = " << sum << "\n";
    else
        cout << "The Graph is disconnected.\nMinimum spanning tree cannot be implemented for the given graph using Kruskal's algorithm.\n";
}
