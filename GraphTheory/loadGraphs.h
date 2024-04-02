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

#define V 100

struct edge
{
	int src, dest;
	int weight;
};


// graph adjacency matrix
int directedGraph[V][V];
int unDirectedGraph[V][V];

// graph adjacency list
vector<int> directedAdjacencyList[V], r_directedAdjacencyList[V];
vector<int> undirectedAdjacencyList[V];

// edges
vector<edge> edges;


int n, m; // số đỉnh, số cạnh
int parent[V], sz[V]; // parent array


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
void print(vector<int> adj[], int n)
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
void print(int graph[][V], int n)
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


void makeSet() {
	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
		sz[i] = 1;
	}
}

int find(int v) {
	if (v == parent[v])
		return v;

	return parent[v] = find(parent[v]);
}

bool Union(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a == b)
	{
		return false; // không thể gộp a, b vào với nhau
	}

	if (sz[a] < sz[b])
		swap(a, b);

	parent[b] = a;
	sz[a] += sz[b];

	return true;
}


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
				cout << "So dinh ke: " << word << endl;
			}
			else
			{
				// phần tử lẻ là đỉnh kề
				if (i % 2 == 1)
				{
					dest = stoi(word);
					cout << "Dinh ke: " << dest << endl;
				}
				else
				{
					// phần tử chẵn là trọng số
					weight = stoi(word);
					cout << "Trong so: " << weight << endl;

					if (v < dest)
					{
						e = { v, dest, weight };
						edges.push_back(e);
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


void print(vector<edge> edges) {
	for (edge e : edges)
	{
		cout << e.src << " " << e.dest << " " << e.weight << endl;
	}
}