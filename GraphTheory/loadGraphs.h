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

#pragma region khai báo cấu trúc dữ liệu

struct edge
{
	int src, dest;
	int weight;
};

// graph adjacency matrix
int adjacencyMatrix[V][V]; // ma trận kề của đồ thị, dùng để xác định có vô hướng hay không

// graph adjacency list with weight
vector<pair<int, int>> adjacencyList[V], r_adjacencyList[V];
vector<pair<int, int>> undirected_adjacencyList[V]; // danh sách kề của đồ thị vô hướng, dùng để xác định có liên thông hay không

// edges
vector<edge> edges; // danh sách cạnh có trọng số

int n, m; // số đỉnh, số cạnh
int parent[V], sz[V]; // parent array

set<int> adj[V];
int degree[V]; // bậc của đỉnh

// reset graph
void resetGraph();

#pragma endregion


#pragma region load graphs từ file txt

void loadGraph(string fileName)
{
	// reset cấu trúc dữ liệu graph
	resetGraph();

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
				int deg = stoi(word);
				degree[v] = deg;
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

					// danh sách kề của đồ thị đảo chiều
					r_adjacencyList[dest].push_back({ v, weight });

					// đồng thời tạo ma trận kề
					adjacencyMatrix[v][dest] = weight;

					// đưa vào danh sách kề không trọng số
					adj[v].insert(dest);

					// tạo danh sách kề của đồ thị vô hướng
					undirected_adjacencyList[v].push_back({ dest, weight });
					undirected_adjacencyList[dest].push_back({ v, weight });
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
/// tạo danh sách các cạnh có trọng số từ file txt
/// </summary>
/// <param name="fileName"></param>
void loadEdges(string fileName)
{
	// reset cấu trúc dữ liệu graph
	resetGraph();

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


#pragma endregion


#pragma region print graphs

/// <summary>
/// in ra ma trận kề
/// </summary>
/// <param name="graph"></param>
void printGraph(int graph[][V], int n)
{
	cout << "Ma tran ke co trong so: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}


void printGraph(vector<edge> edges)
{
	cout << "Danh sach cac canh: " << endl;
	for (edge e : edges)
	{
		cout << e.src << " " << e.dest << " " << e.weight << endl;
	}
}

void printGraph(vector<pair<int, int>> edgeList[], int n)
{
	cout << "Danh sach ke: " << endl;
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

void printGraph(set<int> adj[], int n)
{
	cout << "Danh sach ke khong trong so: " << endl;
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

void printDegree(int degree[], int n)
{
	cout << "Bac cua cac dinh: ";
	for (int i = 0; i < n; i++)
	{
		cout << degree[i] << " ";
	}
	cout << endl;
}


#pragma endregion

#pragma region reset graph

void resetGraph()
{
	// clear adjacency list
	for (int i = 0; i < n; i++)
	{
		adjacencyList[i].clear();
		r_adjacencyList[i].clear();
		adj[i].clear();
	}

	fill_n(adjacencyMatrix[0], V * V, 0);
	fill_n(degree, V, 0);
}

#pragma endregion
