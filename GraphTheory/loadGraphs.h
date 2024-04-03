using namespace std;
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <sstream>  
#include <set>  

#define V 100

struct edge
{
	int src, dest;
	int weight;
};

// graph adjacency matrix
int directedGraph[V][V];
int undirectedGraph[V][V];
int adjacencyMatrix[V][V];

// graph adjacency list without weight
vector<int> directedAdjacencyList[V], r_directedAdjacencyList[V];
vector<int> undirectedAdjacencyList[V];

// graph adjacency list with weight
vector<pair<int, int>> adjacencyList[V], r_adjacencyList[V];
vector<pair<int, int>> undirected_adjacencyList[V];

// edges
vector<edge> edges;

int n, m; // số đỉnh, số cạnh
int parent[V], sz[V]; // parent array

set<int> adj[V];
int degree[V]; // bậc của đỉnh

/// <summary>
/// tạo danh sách kề từ file txt, đồ thị có hướng
/// </summary>
/// <param name="fileName"></param>
/// <param name="adj"></param>
void loadDirectedGraph(string fileName, vector<int> adj[], int n) {
	// Open the file
	ifstream inputFile(fileName);

	// Check if the file is opened successfully
	if (!inputFile.is_open())
	{
		cerr << "Error opening file: " << fileName << endl;
		return; // Return an error code
	}

	// Read and print the contents of the file
	string line;

	// đọc số đỉnh
	getline(inputFile, line);
	n = stoi(line);

	// Use while loop to check the getline() function condition.
	int v = 0; // index cho từng đỉnh của vector adj
	while (getline(inputFile, line))
	{
		// ss is an object of stringstream that references the S string.  
		stringstream ss(line);
		string word;

		// index cho từng phần tử của mỗi dòng
		int i = 0;
		while (ss >> word) // Extract word from the stream.
		{
			// phần tử đầu tiên là số đỉnh kề
			if (i != 0)
			{
				// phần tử lẻ là đỉnh kề
				if (i % 2 == 1)
				{
					//cout << "Dinh ke: " << word << endl;
					int value = stoi(word);
					adj[v].push_back(value);
				}
			}
			// di chuyển đến phần tử tiếp theo
			i++;

		}
		// di chuyển đến đỉnh tiếp theo
		v++;
	}

	// Close the file
	inputFile.close();
}


void loadDirectedGraph(string fileName) {
	// Open the file
	ifstream inputFile(fileName);

	// Check if the file is opened successfully
	if (!inputFile.is_open())
	{
		cerr << "Error opening file: " << fileName << endl;
		return; // Return an error code
	}

	// Read and print the contents of the file
	string line;

	// đọc số đỉnh
	getline(inputFile, line);
	n = stoi(line);

	// Use while loop to check the getline() function condition.
	int v = 0; // index cho từng đỉnh của vector adj
	while (getline(inputFile, line))
	{
		// ss is an object of stringstream that references the S string.  
		stringstream ss(line);
		string word;

		// index cho từng phần tử của mỗi dòng
		int i = 0;
		while (ss >> word) // Extract word from the stream.
		{
			// phần tử đầu tiên là số đỉnh kề
			if (i != 0)
			{
				// phần tử lẻ là đỉnh kề
				if (i % 2 == 1)
				{
					//cout << "Dinh ke: " << word << endl;
					int value = stoi(word);
					directedAdjacencyList[v].push_back(value);
				}
			}
			// di chuyển đến phần tử tiếp theo
			i++;
		}
		// di chuyển đến đỉnh tiếp theo
		v++;
	}

	// Close the file
	inputFile.close();
}


/// <summary>
/// tạo danh sách kề từ file txt, đồ thị có hướng, gồm cả transpose graph
/// </summary>
/// <param name="fileName"></param>
/// <param name="adj"></param>
int loadDirectedGraph(string fileName, vector<int> adj[], vector<int> r_adj[]) {
	// Open the file
	ifstream inputFile(fileName);

	// Check if the file is opened successfully
	if (!inputFile.is_open())
	{
		cerr << "Error opening file: " << fileName << endl;
		return 0; // Return an error code
	}

	// Read and print the contents of the file
	string line;

	// đọc số đỉnh
	getline(inputFile, line);
	int n = stoi(line);

	// Use while loop to check the getline() function condition.
	int v = 0; // index cho từng đỉnh của vector adj
	while (getline(inputFile, line))
	{
		// ss is an object of stringstream that references the S string.  
		stringstream ss(line);
		string word;

		// index cho từng phần tử của mỗi dòng
		int i = 0;
		while (ss >> word) // Extract word from the stream.
		{
			// phần tử đầu tiên là số đỉnh kề
			if (i != 0)
			{
				// phần tử lẻ là đỉnh kề
				if (i % 2 == 1)
				{
					//cout << "Dinh ke: " << word << endl;
					int value = stoi(word);
					adj[v].push_back(value);
					r_adj[value].push_back(v);
				}
			}
			// di chuyển đến phần tử tiếp theo
			i++;
		}
		// di chuyển đến đỉnh tiếp theo
		v++;
	}

	//cout << "Success" << endl;

	// Close the file
	inputFile.close();

	return n;
}


void loadGraph(string fileName)
{
	// Open the file
	ifstream inputFile(fileName);

	// Check if the file is opened successfully
	if (!inputFile.is_open())
	{
		cerr << "Error opening file: " << fileName << endl;
		return; // Return an error code
	}

	// Read and print the contents of the file
	string line;

	// đọc số đỉnh
	getline(inputFile, line);
	n = stoi(line);

	// Use while loop to check the getline() function condition.
	int v = 0; // index cho từng đỉnh của vector adj
	while (getline(inputFile, line))
	{
		// ss is an object of stringstream that references the S string.  
		stringstream ss(line);
		string word;

		// index cho từng phần tử của mỗi dòng
		int i = 0;
		int dest, weight;
		while (ss >> word) // Extract word from the stream.
		{
			// phần tử đầu tiên là số đỉnh kề
			if (i == 0)
			{
			}
			else
			{
				// phần tử lẻ là đỉnh kề
				if (i % 2 == 1)
				{
					dest = stoi(word);
				}
				else
				{
					// phần tử chẵn là trọng số
					weight = stoi(word);

					// đưa vào danh sách kề có trọng số
					adjacencyList[v].push_back({ dest, weight });

					// đồng thời tạo ma trận kề
					adjacencyMatrix[v][dest] = weight;

					// đưa vào danh sách kề không trọng số
					adj[v].insert(dest);
					adj[dest].insert(v);
					degree[v]++;
					degree[dest]++;
				}
			}

			// di chuyển đến phần tử tiếp theo
			i++;
		}
		// di chuyển đến đỉnh tiếp theo
		v++;
	}

	// Close the file
	inputFile.close();
}


/// <summary>
/// tạo danh sách kề từ file txt, đồ thị vô hướng
/// </summary>
/// <param name="fileName"></param>
/// <param name="adj"></param>
void loadUndirectedGraph(string fileName, vector<int> adj[], int n) {
	// Open the file
	ifstream inputFile(fileName);

	// Check if the file is opened successfully
	if (!inputFile.is_open())
	{
		cerr << "Error opening file: " << fileName << endl;
		return; // Return an error code
	}

	// Read and print the contents of the file
	string line;

	// đọc số đỉnh
	getline(inputFile, line);
	n = stoi(line);

	// Use while loop to check the getline() function condition.
	int v = 0; // index cho từng đỉnh của vector adj
	while (getline(inputFile, line))
	{
		// ss is an object of stringstream that references the S string.  
		stringstream ss(line);
		string word;

		// index cho từng phần tử của mỗi dòng
		int i = 0;
		while (ss >> word) // Extract word from the stream.
		{
			// phần tử đầu tiên là số đỉnh kề
			if (i != 0)
			{
				// phần tử lẻ là đỉnh kề
				if (i % 2 == 1)
				{
					//cout << "Dinh ke: " << word << endl;
					int value = stoi(word);
					adj[v].push_back(value);
					adj[value].push_back(v);
				}
			}
			// di chuyển đến phần tử tiếp theo
			i++;
		}
		// di chuyển đến đỉnh tiếp theo
		v++;
	}

	// Close the file
	inputFile.close();
}


/// <summary>
/// tạo ma trận kề từ file txt, đồ thị có hướng
/// </summary>
/// <param name="filename"></param>
/// <param name="graph"></param>
void loadGraphAdjMatrix(string filename, int graph[][V])
{
	int n = 0; // số đỉnh

	vector<int> adj[100]; // danh sách kề
	loadDirectedGraph(filename, adj, n);

	// tạo ma trận kề
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < adj[i].size(); j++)
		{
			graph[i][adj[i][j]] = 1;
		}
	}
}


/// <summary>
/// in ra danh sách kề
/// </summary>
/// <param name="adj"></param>
void printGraph(vector<int> adj[], int n)
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


/// <summary>
/// in ra ma trận kề
/// </summary>
/// <param name="graph"></param>
void printGraph(int graph[][V], int n)
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

/// <summary>
/// tạo danh sách các cạnh có trọng số từ file txt
/// </summary>
/// <param name="fileName"></param>
void loadEdges(string fileName)
{
	// Open the file
	ifstream inputFile(fileName);

	// Check if the file is opened successfully
	if (!inputFile.is_open())
	{
		cerr << "Error opening file: " << fileName << endl;
		return; // Return an error code
	}

	// Read and print the contents of the file
	string line;

	// đọc số đỉnh
	getline(inputFile, line);
	n = stoi(line);

	// Use while loop to check the getline() function condition.
	int v = 0; // index cho từng đỉnh của vector adj
	while (getline(inputFile, line))
	{
		// ss is an object of stringstream that references the S string.  
		stringstream ss(line);
		string word;

		// index cho từng phần tử của mỗi dòng
		int i = 0;
		int dest, weight;
		edge e;
		while (ss >> word) // Extract word from the stream.
		{
			// phần tử đầu tiên là số đỉnh kề
			if (i == 0)
			{
			}
			else
			{
				// phần tử lẻ là đỉnh kề
				if (i % 2 == 1)
				{
					dest = stoi(word);
				}
				if (i % 2 == 0)
				{
					// phần tử chẵn là trọng số
					weight = stoi(word);

					if (v < dest)
					{
						// đưa vào danh sách edges
						e = { v, dest, weight };
						edges.push_back(e);

						// đưa vào danh sách cạnh vector pair
						adjacencyList[v].push_back({ dest, weight });
						adjacencyList[dest].push_back({ v, weight });

						m++;
					}
				}
			}

			// di chuyển đến phần tử tiếp theo
			i++;
		}
		// di chuyển đến đỉnh tiếp theo
		v++;
	}

	// Close the file
	inputFile.close();
}


void printGraph(vector<edge> edges)
{
	for (edge e : edges)
	{
		cout << e.src << " " << e.dest << " " << e.weight << endl;
	}
}

void printGraph(vector<pair<int, int>> edgeList[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << i << ": ";
		for (pair<int, int> p : edgeList[i])
		{
			cout << "(" << p.first << "," << p.second << ")" << " ";
		}
		cout << endl;
	}
}

void printDegree(int degree[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << i << ": " << degree[i] << endl;
	}
}

void printGraph(set<int> adj[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << i << ": ";
		for (int x : adj[i])
		{
			cout << x << " ";
		}
		cout << endl;
	}
}

void resetGraph()
{
	// clear adjacency list
	for (int i = 0; i < n; i++)
	{
		directedAdjacencyList[i].clear();
		r_directedAdjacencyList[i].clear();
		adjacencyList[i].clear();
		r_adjacencyList[i].clear();
		adj[i].clear();
	}

	fill_n(directedGraph[0], V * V, 0);
	fill_n(undirectedGraph[0], V * V, 0);
	fill_n(adjacencyMatrix[0], V * V, 0);
}