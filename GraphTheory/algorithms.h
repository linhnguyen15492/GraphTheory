#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


//int n, m;
//int graph[10001][1001];

// adj[i] : Lưu danh sách kề của đỉnh i
//std::vector<int> adjacencyList[1001];
//bool visited[1001];

/// @brief Duyệt đồ thị theo chiều sâu
/// @param u
//void dfs(int u)
//{
//	// thăm đỉnh u
//	cout << u << " ";
//
//	// sau đó đánh dấu đỉnh u là đã được thăm
//	visited[u] = true;
//
//	// duyệt các đỉnh kề với đỉnh u
//	for (int v : adjacencyList[u])
//	{
//		if (!visited[v])
//		{
//			dfs(v);
//		}
//	}
//}


/// @brief Duyệt đồ thị theo chiều sâu
/// @param u
void dfs(int u, bool visited[], vector<int> adjacencyList[])
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
			dfs(v, visited, adjacencyList);
		}
	}
}

/// @brief Duyệt đồ thị theo chiều rộng
/// @param u
//void bfs(int u)
//{
//	// tạo hàng đợi q
//	queue<int> q;
//
//	// xuất phát từ đỉnh u
//	// thêm đỉnh u vào hàng đợi q
//	q.push(u);
//
//	// đánh dấu đỉnh u là đã được xét
//	visited[u] = true;
//
//	while (!q.empty())
//	{
//		// lấy đỉnh đầu tiên ra khỏi hàng đợi
//		// thực hiện thao tác với đỉnh đó
//		int s = q.front();
//		q.pop();
//		cout << s << " ";
//
//		// duyệt các đỉnh kề với đỉnh s
//		for (int v : adjacencyList[s])
//		{
//			// nếu đỉnh v chưa được xét
//			if (!visited[v])
//			{
//				// thêm đỉnh v vào hàng đợi
//				q.push(v);
//
//				// đánh dấu đỉnh v là đã được xét
//				visited[v] = true;
//			}
//		}
//	}
//}



/// @brief Đếm số thành phần liên thông của đồ thị
/// @return int
//int connectedComponents()
//{
//	int count = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (!visited[i])
//		{
//			count++;
//			dfs(i);
//		}
//	}
//	return count;
//}


// Function to find the characteristic
// of the given graph
//int checkConnected(int graph[][V], int n)
//{
//	// Check whether the graph is
//	// strongly connected or not
//	bool strongly = true;
//
//	// Traverse the path matrix
//	for (int i = 0; i < n; i++) {
//
//		for (int j = 0; j < n; j++) {
//
//			// If all the elements are
//			// not equal then the graph
//			// is not strongly connected
//			if (graph[i][j] != graph[j][i]) {
//				strongly = false;
//				break;
//			}
//		}
//
//		// Break out of the loop if false
//		if (!strongly) {
//			break;
//		}
//	}
//	// If true then print strongly
//	// connected and return
//	if (strongly) {
//		cout << "Strongly Connected" << endl;;
//		return 0;
//	}
//
//	// Check whether the graph is
//	// Unilaterally connected by
//	// checking Upper Triangle element
//	bool uppertri = true;
//
//	// Traverse the path matrix
//	for (int i = 0; i < n; i++) {
//
//		for (int j = 0; j < n; j++) {
//
//			// If uppertriangle elements
//			// are 0 then break out of the
//			// loop and check the elements
//			// of lowertriangle matrix
//			if (i > j && graph[i][j] == 0) {
//				uppertri = false;
//				break;
//			}
//		}
//
//		// Break out of the loop if false
//		if (!uppertri) {
//			break;
//		}
//	}
//
//	// If true then print unilaterally
//	// connected and return
//	if (uppertri) {
//		cout << "Unilaterally Connected" << endl;
//		return 0;
//	}
//
//	// Check lowertraingle elements
//	bool lowertri = true;
//
//	// Traverse the path matrix
//	for (int i = 0; i < n; i++) {
//
//		for (int j = 0; j < n; j++) {
//
//			// If lowertraingle elements
//			// are 0 then break cause
//			// 1's are expected
//			if (i < j && graph[i][j] == 0) {
//				lowertri = false;
//				break;
//			}
//		}
//
//		// Break out of the loop if false
//		if (!lowertri) {
//			break;
//		}
//	}
//
//	// If true then print unilaterally
//	// connected and return
//	if (lowertri) {
//		cout << "Unilaterally Connected" << endl;
//		return 0;
//	}
//
//	// If elements are in random order
//	// unsynchronized then print weakly
//	// connected and return
//	else {
//		cout << "Weakly Connected" << endl;;
//	}
//
//	return 0;
//}