// Implementation of Dijkstra's Algorithm in CPP

#include <iostream>
#include <limits.h>
using namespace std;

void dijkstra(int graph[6][6], int source, int destination);
int minDistance(int dist[], bool sptSet[]);
void print(int dist[], int source, int destination);

int main()
{
	char source, destination;
	printf("**** Dijkstra's Algorithm ****\n");
	cout << "Enter the starting node of the graph : ";
	cin >> source;
	cout << "Enter the destination node of the graph : ";
	cin >> destination;
	int graph[6][6] = { 0, 2, 0, 0, 8, 0,
						0, 0, 1, 0, 0, 0,
						0, 0, 0, 0, 4, 5,
						1, 0, 0, 0, 0, 0,
						0, 3, 0, 1, 0, 7,
						0, 0, 0, 0, 0, 0 };
	int starting_node = (int)source - 65;
	int ending_node = (int)destination - 65;
	dijkstra(graph, starting_node, ending_node);
	return 0;
}

void dijkstra(int graph[6][6], int source, int destination)
{
	int dist[6];
	bool sptSet[6];
	for (int i = 0; i < 6; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	dist[source] = 0;

	for (int count = 0; count < 6 - 1; count++)
	{
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;

		for (int v = 0; v < 6; v++)
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}
	print(dist, source, destination);
}

int minDistance(int dist[], bool sptSet[])
{
	int min = INT_MAX, min_index;

	for (int counter = 0; counter < 6; counter++)
		if (sptSet[counter] == false && dist[counter] <= min)
			min = dist[counter], min_index = counter;

	return min_index;
}

void print(int dist[], int source, int destination)
{
	cout << "\n";
	for (int i = 0; i < 6; i++)
		if (i == destination)
			cout << "The shortest path from the source node " << (char)(source + 65) << " to node " << (char)(destination + 65) << " is " << dist[i] << "\n";
}
