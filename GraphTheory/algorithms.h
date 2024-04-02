#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define V 100

stack<int> st;

// visited array
bool visited[V];


/// <summary>
/// thuật toán dfs để tìm kiếm thành phần liên thông mạnh, theo giải thuật Kosaraju
/// </summary>
/// <param name="u"></param>
/// <param name="adjacencyList"></param>
void dfs(int u, vector<int> adjacencyList[])
{
	// thăm đỉnh u
	//cout << "tham dinh " << u << endl;

	// sau đó đánh dấu đỉnh u là đã được thăm
	visited[u] = true;

	// duyệt các đỉnh kề với đỉnh u
	for (int v : adjacencyList[u])
	{
		//cout << "dinh ke: " << v << endl;
		if (!visited[v])
		{
			dfs(v, adjacencyList);
		}
	}

	//cout << "da duyet xong dinh " << u << endl;
	// đưa đỉnh u vào stack
	st.push(u);
}


/// <summary>
/// in ra các đỉnh thuộc thành phần liên thông mạnh
/// </summary>
/// <param name="u"></param>
/// <param name="r_adjacencyList"></param>
void reverseDfs(int u, vector<int> r_adjacencyList[])
{
	// thăm đỉnh u
	cout << u << " ";

	// sau đó đánh dấu đỉnh u là đã được thăm
	visited[u] = true;

	// duyệt các đỉnh kề với đỉnh u
	for (int v : r_adjacencyList[u])
	{
		if (!visited[v])
		{
			reverseDfs(v, r_adjacencyList);
		}
	}
}

/// <summary>
/// thuật toán Kosaraju để tìm thành phần liên thông mạnh
/// </summary>
/// <param name="adjacencyList"></param>
/// <param name="r_adjacencyList"></param>
/// <param name="n"></param>
void stronglyConnectedComponents(vector<int> adjacencyList[], vector<int> r_adjacencyList[], int n)
{
	//stack<int> st;
	memset(visited, false, sizeof(visited));

	// B1: gọi dfs trên đồ thị ban đầu
	//cout << "goi dfs tren do thi ban dau" << endl;
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			dfs(i, adjacencyList);
		}
	}
	cout << endl;

	// reset visited array
	memset(visited, false, sizeof(visited));

	//cout << "goi dfs tren do thi dao" << endl;
	// B2: gọi dfs trên đồ thị đảo
	int j = 1;
	while (!st.empty())
	{
		int u = st.top();
		st.pop();

		if (!visited[u])
		{
			cout << "Thanh phan lien thong manh " << j << ": ";
			reverseDfs(u, r_adjacencyList);
			cout << endl;

			j++;
		}
	}
}



/// <summary>
/// thuật toán bfs để duyệt đồ thị
/// </summary>
/// <param name="u"></param>
/// <param name="adjacencyList"></param>
void bfs(int u, vector<int> adjacencyList[])
{
	memset(visited, false, sizeof(visited));

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



/// <summary>
/// đếm số thành phần liên thông của đồ thị, áp dụng trên đồ thị vô hướng để xác định đồ thị có liên thông hay không
/// </summary>
/// <param name="adj"></param>
/// <returns></returns>
int connectedComponents(vector<int> adj[], int n)
{
	memset(visited, false, sizeof(visited));

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			count++;
			dfs(i, adj);
		}
	}

	return count;
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
	vector<vector<int> > findSCC(int n, vector<vector<int>>& a)
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