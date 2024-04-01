// GraphTheory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <sstream>  
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include "factorial.h"
#include <vector>
#include <queue>
using namespace std;

#define V 100

int n, m;
int graph[10001][1001];

// adj[i] : Lưu danh sách kề của đỉnh i
std::vector<int> adjacencyList[1001];
bool visited[1001];

/// @brief Duyệt đồ thị theo chiều sâu
/// @param u
void dfs(int u)
{
	// thăm đỉnh u
	cout << u << " ";

	// sau đó đánh dấu đỉnh u là đã được thăm
	visited[u] = true;

	// duyệt các đỉnh kề với đỉnh u
	for (int v : adjacencyList[u])
	{
		if (!visited[v])
		{
			dfs(v);
		}
	}
}

/// @brief Duyệt đồ thị theo chiều rộng
/// @param u
void bfs(int u)
{
	// tạo hàng đợi q
	queue<int> q;

	// xuất phát từ đỉnh u
	// thêm đỉnh u vào hàng đợi q
	q.push(u);

	// đánh dấu đỉnh u là đã được xét
	visited[u] = true;

	while (!q.empty())
	{
		// lấy đỉnh đầu tiên ra khỏi hàng đợi
		// thực hiện thao tác với đỉnh đó
		int s = q.front();
		q.pop();
		cout << s << " ";

		// duyệt các đỉnh kề với đỉnh s
		for (int v : adjacencyList[s])
		{
			// nếu đỉnh v chưa được xét
			if (!visited[v])
			{
				// thêm đỉnh v vào hàng đợi
				q.push(v);

				// đánh dấu đỉnh v là đã được xét
				visited[v] = true;
			}
		}
	}
}

/// @brief Đếm số thành phần liên thông của đồ thị
/// @return int
int connectedComponents()
{
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			count++;
			dfs(i);
		}
	}
	return count;
}


// Function to find the characteristic
// of the given graph
int checkConnected(int graph[][V], int n)
{

	// Check whether the graph is
	// strongly connected or not
	bool strongly = true;

	// Traverse the path matrix
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			// If all the elements are
			// not equal then the graph
			// is not strongly connected
			if (graph[i][j] != graph[j][i]) {
				strongly = false;
				break;
			}
		}

		// Break out of the loop if false
		if (!strongly) {
			break;
		}
	}
	// If true then print strongly
	// connected and return
	if (strongly) {
		cout << "Strongly Connected";
		return 0;
	}

	// Check whether the graph is
	// Unilaterally connected by
	// checking Upper Triangle element
	bool uppertri = true;

	// Traverse the path matrix
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			// If uppertriangle elements
			// are 0 then break out of the
			// loop and check the elements
			// of lowertriangle matrix
			if (i > j && graph[i][j] == 0) {
				uppertri = false;
				break;
			}
		}

		// Break out of the loop if false
		if (!uppertri) {
			break;
		}
	}

	// If true then print unilaterally
	// connected and return
	if (uppertri) {
		cout << "Unilaterally Connected";
		return 0;
	}

	// Check lowertraingle elements
	bool lowertri = true;

	// Traverse the path matrix
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			// If lowertraingle elements
			// are 0 then break cause
			// 1's are expected
			if (i < j && graph[i][j] == 0) {
				lowertri = false;
				break;
			}
		}

		// Break out of the loop if false
		if (!lowertri) {
			break;
		}
	}

	// If true then print unilaterally
	// connected and return
	if (lowertri) {
		cout << "Unilaterally Connected";
		return 0;
	}

	// If elements are in random order
	// unsynchronized then print weakly
	// connected and return
	else {
		cout << "Weakly Connected";
	}

	return 0;
}


void danhSachKe()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		adjacencyList[x].push_back(y);
		adjacencyList[y].push_back(x); // Nếu là đồ thị có hướng thì bỏ dòng này
	}

	memset(visited, false, sizeof(visited));

	for (int i = 1; i <= n; i++)
	{
		cout << i << " : ";
		for (int x : adjacencyList[i])
		{
			cout << x << " ";
		}
		cout << endl;
	}
}

/// <summary>
/// đọc file txt chứa danh sách kề của đồ thị
/// </summary>
/// <param name="fileName"></param>
/// <returns></returns>
int readFile(string fileName) {
	// Open the file
	ifstream inputFile(fileName);

	// Check if the file is opened successfully
	if (!inputFile.is_open())
	{
		cerr << "Error opening file: " << fileName << endl;
		return 1; // Return an error code
	}

	// Read and print the contents of the file
	string line;

	while (getline(inputFile, line))
	{
		cout << line << endl;

		// ss is an object of stringstream that references the S string.  
		stringstream ss(line);
		string word;

		// Use while loop to check the getline() function condition.  
		while (ss >> word)
		{ // Extract word from the stream.
			cout << word << endl;
		}

	}

	// Close the file
	inputFile.close();

	return 0;
}


class GFG {
public:
	// dfs Function to reach destination
	bool dfs(int curr, int des, vector<vector<int> >& adj,
		vector<int>& vis)
	{

		// If curr node is destination return true
		if (curr == des) {
			return true;
		}
		vis[curr] = 1;
		for (auto x : adj[curr]) {
			if (!vis[x]) {
				if (dfs(x, des, adj, vis)) {
					return true;
				}
			}
		}
		return false;
	}

	// To tell whether there is path from source to
	// destination
	bool isPath(int src, int des, vector<vector<int> >& adj)
	{
		vector<int> vis(adj.size() + 1, 0);
		return dfs(src, des, adj, vis);
	}

	// Function to return all the strongly connected
	// component of a graph.
	vector<vector<int> > findSCC(int n,
		vector<vector<int> >& a)
	{
		// Stores all the strongly connected components.
		vector<vector<int> > ans;

		// Stores whether a vertex is a part of any Strongly
		// Connected Component
		vector<int> is_scc(n + 1, 0);

		vector<vector<int> > adj(n + 1);

		for (int i = 0; i < a.size(); i++) {
			adj[a[i][0]].push_back(a[i][1]);
		}

		// Traversing all the vertices
		for (int i = 1; i <= n; i++) {

			if (!is_scc[i]) {

				// If a vertex i is not a part of any SCC
				// insert it into a new SCC list and check
				// for other vertices whether they can be
				// thr part of thidl ist.
				vector<int> scc;
				scc.push_back(i);

				for (int j = i + 1; j <= n; j++) {

					// If there is a path from vertex i to
					// vertex j and vice versa put vertex j
					// into the current SCC list.
					if (!is_scc[j] && isPath(i, j, adj)
						&& isPath(j, i, adj)) {
						is_scc[j] = 1;
						scc.push_back(j);
					}
				}

				// Insert the SCC containing vertex i into
				// the final list.
				ans.push_back(scc);
			}
		}
		return ans;
	}
};

// Driver Code Starts


int main()
{
	std::cout << "Do an Ly thuyet do thi - HK2 - 2023-2024 \n";

	sayHello();

	// Specify the file name
	string fileName = "example.txt";

	readFile(fileName);


	// Number of nodes
	int n = 3;

	// Given Path Matrix
	int graph[V][V] = {
		{ 0, 1, 1 },
		{ 0, 0, 1 },
		{ 0, 0, 0 },
	};

	// Function Call
	checkConnected(graph, n);

	// Driver Code Starts
	GFG obj;
	//int V = 5;
	vector<vector<int> > edges{
		{ 1, 3 }, { 1, 4 }, { 2, 1 }, { 3, 2 }, { 4, 5 }
	};
	vector<vector<int> > ans = obj.findSCC(V, edges);
	cout << "Strongly Connected Components are:\n";
	for (auto x : ans) {
		for (auto y : x) {
			cout << y << " ";
		}
		cout << "\n";
	}

	return 0;
}
