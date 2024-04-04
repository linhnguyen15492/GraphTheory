
// cấu trúc stack để giải thuật toán Kosaraju
stack<int> st;

// visited array
bool visited[V];

#pragma region hàm dùng chung


/// <summary>
/// thuật toán dfs để tìm kiếm thành phần liên thông mạnh, theo giải thuật Kosaraju
/// </summary>
/// <param name="u"></param>
/// <param name="adjacencyList"></param>
void dfs(int u, vector<pair<int, int>> adjacencyList[])
{
	//thăm đỉnh u
	//cout << "tham dinh " << u << endl;

	// sau đó đánh dấu đỉnh u là đã được thăm
	visited[u] = true;

	// duyệt các đỉnh kề với đỉnh u
	for (pair<int, int> p : adjacencyList[u])
	{
		int v = p.first;

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
/// dfs đảo để tìm thành phần liên thông mạnh, thuật toán Kosaraju
/// </summary>
/// <param name="u"></param>
/// <param name="r_adjacencyList"></param>
void reverseDfs(int u, vector<pair<int, int>> r_adjacencyList[])
{
	// thăm đỉnh u
	cout << u << " ";

	// sau đó đánh dấu đỉnh u là đã được thăm
	visited[u] = true;

	// duyệt các đỉnh kề với đỉnh u
	for (pair<int, int> p : r_adjacencyList[u])
	{
		int v = p.first;

		if (!visited[v])
		{
			reverseDfs(v, r_adjacencyList);
		}
	}
}

/// <summary>
/// thuật toán bfs để duyệt đồ thị
/// </summary>
/// <param name="u"></param>
/// <param name="adjacencyList"></param>
void bfs(int u, vector<pair<int, int>> adjacencyList[])
{
	bool visited[V];
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
		for (pair<int, int> p : adjacencyList[s])
		{
			int v = p.first;
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
/// xác định đồ thị có phải là đồ thị vô hướng hay không
/// </summary>
/// <param name="adjMatrix"></param>
/// <param name="n"></param>
/// <returns></returns>
bool isUndirectedGraph(int adjMatrix[][V], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (adjMatrix[i][j] != adjMatrix[j][i])
			{
				return false;
			}
		}
	}

	return true;
}


int connectedComponents(vector<pair<int, int>> adj[], int n)
{
	memset(visited, false, sizeof(visited));

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			++count;
			dfs(i, adj);
		}
	}

	//cout << "So thanh phan lien thong: " << count << endl;

	return count;
}


#pragma endregion


#pragma region yêu cầu 2


/// <summary>
/// thuật toán Kosaraju để tìm thành phần liên thông mạnh
/// </summary>
/// <param name="adjacencyList"></param>
/// <param name="r_adjacencyList"></param>
/// <param name="n"></param>
void stronglyConnectedComponents(vector<pair<int, int>> adjacencyList[], vector<pair<int, int>> r_adjacencyList[], int n)
{
	memset(visited, false, sizeof(visited));

	// B1: gọi dfs trên đồ thị ban đầu
	cout << "goi dfs tren do thi ban dau" << endl;
	for (int i = 0; i < n; i++)
	{
		//cout << "i: " << i << endl;
		if (!visited[i])
		{
			dfs(i, adjacencyList);
		}
	}

	// reset visited array
	memset(visited, false, sizeof(visited));

	//cout << "goi dfs tren do thi dao" << endl;
	// B2: gọi dfs trên đồ thị đảo
	int j = 1; // thứ tự thành phần liên thông mạnh
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


#pragma endregion


#pragma region yêu cầu 3

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

bool merge(int a, int b)
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

bool compare(edge a, edge b)
{
	return a.weight > b.weight;
}

void kruskal()
{
	makeSet();

	// tạo cây khung cực đại rỗng
	vector<edge> mst;
	int d = 0;

	// sắp xếp các cạnh theo thứ tự giảm dần
	sort(edges.begin(), edges.end(), compare);

	//cout << "So canh: " << m << endl;
	//cout << "smt size: " << mst.size() << endl;

	// lặp
	for (int i = 0; i < edges.size(); i++)
	{
		if (mst.size() == m - 1)
		{
			break;
		}

		edge e = edges[i]; // lấy cạnh có trọng số lớn nhất

		if (merge(e.src, e.dest))
		{
			//cout << "merge: " << e.src << " " << e.dest << " " << e.weight << endl;
			mst.push_back(e);
			d += e.weight;
		}
		else {
			//cout << "khong merge: " << e.src << " " << e.dest << " " << e.weight << endl;
		}
	}

	// in ra kết quả cây khung
	cout << "Giai thuat Kruskal" << endl;
	cout << "Tap canh cua cay khung: " << endl;

	for (edge e : mst)
	{
		cout << e.src << " - " << e.dest << ": " << e.weight << endl;
	}

	cout << "Trong so cua cay khung: " << d << endl;
}

void prim()
{
	bool mstSet[V]; // mảng lưu trữ các đỉnh đã được thêm vào cây khung
	memset(mstSet, false, sizeof(mstSet));

	// tạo cây khung cực đại rỗng
	vector<edge> MST;
	int d = 0;

	int u;

	cout << "Giai thuat Prim" << endl;
	cout << "Nhap dinh bat dau: ";
	cin >> u;

	// đưa đỉnh u vào cây khung
	mstSet[u] = true;

	while (MST.size() < n - 1)
	{
		// e = {X, Y, w}: cạnh ngắn nhất có X thuộc cây khung, Y không thuộc cây khung
		int max_w = INT_MIN;
		int X, Y; // lưu 2 đỉnh cạnh e

		for (int i = 0; i < n; i++)
		{
			// nếu đỉnh i thuộc cây khung MST
			if (mstSet[i])
			{
				// duyệt danh sách kề của i, lấy ra đỉnh chưa thuộc cây khung
				for (pair<int, int> p : adjacencyList[i]) {
					int v = p.first;
					int w = p.second;

					if (!mstSet[v] && w > max_w) {
						max_w = w;
						X = i;
						Y = v;
					}
				}
			}
		}

		MST.push_back({ X, Y, max_w });
		d += max_w;
		mstSet[Y] = true; // cho đỉnh X vào V(MST), loại X khỏi V
	}


	// in ra kết quả cây khung
	for (edge e : MST)
	{
		cout << e.src << " - " << e.dest << ": " << e.weight << endl;
	}

	cout << "Trong so cua cay khung: " << d << endl;
}


#pragma endregion


#pragma region yêu cầu 4


// A function to print the solution matrix
void printSolution(int dist[][V]);

// Solves the all-pairs shortest path
// problem using Floyd Warshall algorithm
void floydWarshall(int dist[][V])
{

	int i, j, k;

	/* Add all vertices one by one to the set of intermediate vertices. ---> Before start of an iteration,
	we have shortest distances between all pairs of vertices such that the shortest distances consider only the
	vertices in set {0, 1, 2, .. k-1} as intermediate vertices.
	----> After the end of an iteration, vertex no. k is added to the set of	intermediate vertices and the set becomes {0, 1, 2, ..	k} */
	for (k = 0; k < n; k++) {
		// Pick all vertices as source one by one
		for (i = 0; i < n; i++) {
			// Pick all vertices as destination for the
			// above picked source
			for (j = 0; j < n; j++) {
				// If vertex k is on the shortest path from
				// i to j, then update the value of
				// dist[i][j]
				if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF))
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	// Print the shortest distance matrix
	printSolution(dist);
}

/* A utility function to print solution */
void printSolution(int dist[][V])
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dist[i][j] == INF)
				cout << "INF"
				<< " ";
			else
				cout << dist[i][j] << "   ";
		}
		cout << endl;
	}
}


void transformGraph(int adjacencyMatrix[][V])
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				adjacencyMatrix[i][j] = 0;
			}
			else if (adjacencyMatrix[i][j] == 0) {
				adjacencyMatrix[i][j] = INF;
			}
			else
			{
				continue;
			}
		}
	}
}

#pragma endregion


#pragma region yêu cầu 5

bool isEulerPath(int degree[], int n)
{
	int odd = 0;
	for (int i = 0; i < n; i++)
	{
		if (degree[i] % 2 != 0)
		{
			odd++;
		}
	}

	if (odd == 0 || odd == 2)
	{
		return true;
	}

	return false;
}

bool isEulerCircuit(int degree[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (degree[i] % 2 != 0)
		{
			return false;
		}
	}

	return true;
}

void euler(int v)
{
	stack<int> st;
	vector<int> eulerCircuit;

	st.push(v);

	while (!st.empty()) {
		int x = st.top();
		if (adj[x].size() != 0)
		{
			// lấy đỉnh kề đầu tiên của x đưa vào stack
			int y = *adj[x].begin();
			st.push(y);

			// xóa cạnh giữa x và y
			adj[x].erase(y);
			adj[y].erase(x);
		}
		else {
			// nếu x không có đỉnh kề nào thì đưa x vào chu trình euler
			eulerCircuit.push_back(x);
			// xóa x khỏi stack
			st.pop();
		}
	}

	// in chu trình euler
	reverse(begin(eulerCircuit), end(eulerCircuit));
	for (int e : eulerCircuit)
	{
		cout << e << " ";
	}

	cout << endl;
}

#pragma endregion 
