#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int n, m;
int a[10001][1001];

// adj[i] : Lưu danh sách kề của đỉnh i
vector<int> adj[1001];
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
	for (int v : adj[u])
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
		for (int v : adj[s])
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