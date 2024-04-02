#pragma once


#include <iostream>
#include <vector>
using namespace std;

void printAdjacencyList(vector<int> adj[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int x : adj[i])
		{
			cout << x << " ";
		}
		cout << endl;
	}
}


void printAdjacencyMatrix(int graph[][V], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}