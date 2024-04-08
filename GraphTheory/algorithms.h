
// cấu trúc stack để giải thuật toán Kosaraju
stack<int> st;

// visited array
bool visited[V];

// mảng đánh dấu màu của các đỉnh
int color[V];

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


void bfs(int u)
{
	memset(color, -1, sizeof(color));

	queue<int> q;
	q.push(u);

	color[u] = 0; // 0 = red, 1 = blue
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		for (pair<int, int> p : adjacencyList[v])
		{
			int x = p.first;

			if (color[x] == -1)
			{
				color[x] = color[v] + 1;
				q.push(x);
			}
			else if (color[x] == color[v] && color[x] != 0)
			{
				color[x] = color[v] + 1;
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


bool isLoopEdges(int adjMatrix[][V], int n)
{
	return true;
}


bool isMultiEdges(int adjMatrix[][V], int n)
{
	return true;
}


bool isPositiveWeight(int degrees[])
{
	for (int i = 0; i < n; i++)
	{
		if (degrees[i] < 0)
		{
			return false;
		}
	}

	return true;
}



// Function to find the maximum of array
int largest(int arr[], int n)
{
	int i;

	// Initialize maximum element
	int max = arr[0];

	// Traverse array elements
	// from second and compare
	// every element with current max
	for (i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];

	return max;
}

#pragma endregion


#pragma region yêu cầu 1

int isWindmillGraph_Wd3n()
{
	/*
	In the mathematical field of graph theory, the windmill graph Wd(k,n) is an undirected graph constructed for k ≥ 2 and n ≥ 2 by joining n copies of the complete graph Kk
	at a shared universal vertex. That is, it is a 1-clique-sum of these complete graphs.

	It has n(k – 1) + 1 vertices and nk(k − 1)/2 edges,[2] girth 3 (if k > 2), radius 1 and diameter 2.

	B1: Giả sử đồ thị đã cho là Wd(3,n) thì số đỉnh của đồ thị là n*(3-1)+1 = 2n+1, số cạnh là n*3*(3 − 1)/2 = 3n,

	B2: tính số đỉnh và số cạnh của đồ thị đã cho, đặt là x và y

	B3: Do đây là đồ thị Wd(3,n) nên 2n+1 = x và 3n = y, không xác định được n nguyên dương => kết luận đây không thể là đồ thị windmill Wd(3,n)

	*/

	int x = n; // số đỉnh đồ thị đã cho
	int y = edges.size(); // số cạnh đồ thị đã cho

	//cout << "So dinh: " << x << endl;
	//cout << "So canh: " << y << endl;

	double n1 = (x - 1) / 2.0;
	double n2 = y / 3.0;

	//cout << "n1: " << n1 << endl;
	//cout << "n2: " << n2 << endl;

	if (n1 == n2)
	{
		return int(n1);
	}

	return 0;
}

int isBarbellGraph()
{
	/*
	A barbell graph is a graph consisting of a path graph and a cycle graph that are connected by a single edge.
	Barbell graphs are named for their resemblance to a barbell, with two large equal-size cliques connected by a path.

	Properties:
		The barbell graph contains cycles in it.
		The barbell graph is connected every two nodes have a path between them.
		It has a bridge between 2 complete graphs.
		Bridge may and may not have nodes in it.


	The Total number of Nodes = 2*N
	Total number of edges = 2*(number of edges in complete graph) + 1 = 2*(n*(n-1)/2)+1 = n*(n-1) + 1

	B1: nếu số đỉnh là lẻ => không là đồ thị Barbell

	B2: nếu số cạnh khác với n*(n-1) + 1 => không là đồ thị Barbell
	*/

	int x = n; // số đỉnh đồ thị đã cho
	int y = edges.size(); // số cạnh đồ thị đã cho

	//cout << "So dinh: " << x << endl;
	//cout << "So canh: " << y << endl;

	// nếu số đỉnh lẻ thì không phải là đồ thị Barbell
	if (x % 2 != 0)
	{
		return 0;
	}

	// nếu số cạnh khác với n*(n-1) + 1 thì không phải là đồ thị Barbell
	int deg = n / 2;
	int e = deg * (deg - 1) + 1;

	//cout << "bac barbell du tinh " << deg << endl;
	//cout << "so canh du tinh " << e << endl;

	if (y == e)
	{
		return deg;
	}

	return 0;

}

void kParite() {
	bfs(0);

	//for (int i = 0; i < n; i++)
	//{
	//	cout << "Dinh " << i << " co mau " << color[i] << endl;
	//}

	int count = largest(color, n);
	cout << count + 1 << "-partite ";

	for (int i = 0; i <= count; i++) {
		//cout << "Mau " << i << ": ";
		for (int j = 0; j < n; j++) {
			if (color[j] == i)
			{
				cout << j << " ";
			}
		}
		cout << "  ";
	}

	cout << endl;
}

#pragma endregion


#pragma region yêu cầu 2


/// <summary>
/// thuật toán Kosaraju để tìm thành phần liên thông mạnh
/// </summary>
/// <param name="adjacencyList"></param>
/// <param name="r_adjacencyList"></param>
/// <param name="n"></param>
int stronglyConnectedComponents(vector<pair<int, int>> adjacencyList[], vector<pair<int, int>> r_adjacencyList[], int n)
{
	memset(visited, false, sizeof(visited));

	int count = 0;

	// B1: gọi dfs trên đồ thị ban đầu
	//cout << "goi dfs tren do thi ban dau" << endl;
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
			++count;

			cout << "Thanh phan lien thong manh " << j << ": ";
			reverseDfs(u, r_adjacencyList);
			cout << endl;

			j++;
		}
	}

	return count;
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


			// Pick all vertices as destination for the above picked source
			for (j = 0; j < n; j++)
			{
				//cout << "dinh j " << j << endl;

				// If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
				if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF))
				{

					dist[i][j] = dist[i][k] + dist[k][j];

					// lấy đường đi hiện tại từ i đến k và từ k đến j
					for (int e : path[i][k])
					{
						path[i][j].push_back(e);
					}
					for (int e : path[k][j])
					{
						path[i][j].push_back(e);
					}
					path[i][j].push_back(k);
				}

			}
		}
	}

	// Print the shortest distance matrix
	printSolution(dist);
}

/* A utility function to print solution */
void printSolution(int dist[][V])
{
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		if (dist[i][j] == INF)
	//			cout << "INF"
	//			<< " ";
	//		else
	//			cout << dist[i][j] << "   ";
	//	}
	//	cout << endl;
	//}

	for (int i = 0; i < n; i++)
	{
		cout << "Duong di xuat phat tu " << i << ":" << endl;
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				continue;
			}
			else
			{
				cout << i << " -> ";
				for (int e : path[i][j])
				{
					cout << e << " -> ";
				}
				cout << j << ": " << dist[i][j];
				cout << endl;
			}

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

int getDegree(int u)
{
	return degrees[u];
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
