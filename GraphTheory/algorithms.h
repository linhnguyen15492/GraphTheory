#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define V 100

/// @brief Duyệt đồ thị theo chiều sâu
/// @param u
void dfs(int u, vector<int> adjacencyList[], bool visited[])
{
	// thăm đỉnh u
	//cout << "tham dinh " << u << endl;

	// sau đó đánh dấu đỉnh u là đã được thăm
	visited[u] = true;

	// duyệt các đỉnh kề với đỉnh u
	for (int v : adjacencyList[u])
	{
		if (!visited[v])
		{
			dfs(v, adjacencyList, visited);
		}
	}
}


/// <summary>
/// thuật toán dfs để tìm kiếm thành phần liên thông mạnh, theo giải thuật Kosaraju
/// </summary>
/// <param name="u"></param>
/// <param name="adjacencyList"></param>
/// <param name="visited"></param>
/// <param name="st"></param>
void dfs(int u, vector<int> adjacencyList[], bool visited[], stack<int> st)
{
	// thăm đỉnh u
	//cout << "tham dinh " << u << endl;

	// sau đó đánh dấu đỉnh u là đã được thăm
	visited[u] = true;

	// duyệt các đỉnh kề với đỉnh u
	for (int v : adjacencyList[u])
	{
		if (!visited[v])
		{
			dfs(v, adjacencyList, visited);
		}
	}

	// đưa đỉnh u vào stack
	st.push(u);
}

/// <summary>
/// in ra các đỉnh thuộc thành phần liên thông mạnh
/// </summary>
/// <param name="u"></param>
/// <param name="r_adjacencyList"></param>
/// <param name="visited"></param>
void reverseDfs(int u, vector<int> r_adjacencyList[], bool visited[])
{
	// thăm đỉnh u
	cout << "tham dinh " << u << endl;

	// sau đó đánh dấu đỉnh u là đã được thăm
	visited[u] = true;

	// duyệt các đỉnh kề với đỉnh u
	for (int v : r_adjacencyList[u])
	{
		if (!visited[v])
		{
			reverseDfs(v, r_adjacencyList, visited);
		}
	}
}

/// <summary>
/// thuật toán Kosaraju để tìm các thành phần liên thông mạnh
/// </summary>
/// <param name="adjacencyList"></param>
/// <param name="r_adjacencyList"></param>
/// <param name="visited"></param>
void stronglyConnectedComponents(vector<int> adjacencyList[], vector<int> r_adjacencyList[], bool visited[])
{
	stack<int> st;
	memset(visited, false, sizeof(visited));

	// duyệt đồ thị theo chiều sâu
	for (int i = 0; i < V; i++)
	{
		if (!visited[i])
		{
			dfs(i, adjacencyList, visited, st);
		}
	}
	cout << endl;

}



/// @brief Duyệt đồ thị theo chiều rộng
/// @param u
void bfs(int u, vector<int> adjacencyList[], bool visited[])
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



/// <summary>
/// đếm số thành phần liên thông của đồ thị, áp dụng trên đồ thị vô hướng để xác định đồ thị có liên thông hay không
/// </summary>
/// <param name="adj"></param>
/// <returns></returns>
int connectedComponents(vector<int> adj[])
{
	bool visited[V];
	memset(visited, false, sizeof(visited));

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			count++;
			dfs(i, adj, visited);
		}
	}

	return count;
}


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


//void traverse(int u, bool visited[]) {
//	visited[u] = true; //mark v as visited
//	for (int v = 0; v < n; v++) {
//		if (graph[u][v]) {
//			if (!visited[v])
//				traverse(v, visited);
//		}
//	}
//}
//bool isConnected() {
//	bool* vis = new bool[n];
//	//for all vertex u as start point, check whether all nodes are visible or not
//	for (int u; u < n; u++) {
//		for (int i = 0; i < n; i++)
//			vis[i] = false; //initialize as no node is visited
//		traverse(u, vis);
//		for (int i = 0; i < n; i++) {
//			if (!vis[i]) //if there is a node, not visited by traversal, graph is not connected
//				return false;
//		}
//	}
//	return true;
//}



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