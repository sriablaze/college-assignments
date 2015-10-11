#include<iostream>

using namespace std;

#define numv 21
#define infinity 1000

class graph
{
	int n;
	int mat[numv][numv];
	int d[numv][numv];
	int path[numv][numv];
	public:
	graph(int num) { //to create the adjacency matrix
		n = num;
		for(int i = 1; i <= n; i++)	{
			for(int j = 1; j <= n; j++) {
				mat[i][j] = 0;
			}
		}
	}
	void get_edges(int ne) { //to accept the edges
		cout<<"For each of the "<<ne<<" edges, "<<endl
		<<"Enter the head, tail, and weight (in that order)"<<endl;
		int x, y, weight;
		for(int i = 1; i <= ne; i++) {
			cout<<"Edge "<<i<<": ";
	        cin>>x>>y>>weight;
	        mat[x][y] = weight;
	    }
	}
	void init_matrices() { //initialize distance and path matrices
		for(int i = 1; i <= n; i++) { 
			for(int j = 1; j <= n; j++) {
				if(i == j) 
					d[i][j] = 0;
				else
					d[i][j] = infinity; 
				path[i][j] = -1;
			}
		}
	}
	void set_matrices() { //set values of distance and path matrices
		for(int i = 1; i <= n; i++) { 
			for(int j = 1; j <= n; j++) {
				if(mat[i][j] != 0) {
					d[i][j] = mat[i][j];
					path[i][j] = j;
				}
			}
		}	
	}
	void floyd_warshall() { //floyd-warshall implementation
		for(int k = 1; k <= n; k++) { 
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= n; j++) {
					if(d[i][k] + d[k][j] < d[i][j]) {
						d[i][j] = d[i][k] + d[k][j];
						path[i][j] = path[i][k];
					}
				}
			}
		}
	}
	void disp_dist_matrix() {
		cout<<"\nDistance matrix: "<<endl;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++)
				cout<<" "<<d[i][j];
			cout<<"\n";
		}	
	}
	void disp_path_matrix() {
		cout<<"\nPath matrix:\n";
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++)
			  cout<<" "<<path[i][j];
			cout<<"\n";
		}
	}
	void compute_path(int u, int v) { //to display shortest path between vertex u and vertex v
		int x = u, y = v;
		if(path[u][v] == (-1))
			cout<<"ERROR: No path exists from v"<<u<<" to v"<<v<<endl;
		else {
			cout<<"Length of shortest path from v"<<u<<" to v"<<v<<" is: "<<d[u][v]<<endl;
			int ans[10], len = 0;
			ans[len++] = u;
			while(u != v) {
				u = path[u][v];
				ans[len++] = u;	
			}
			cout<<"The shortest path from v"<<x<<" to v"<<y<<" is: ";
			for(int i = 0; i < len; i++) {
				cout<<"v"<<ans[i];
				if(i + 1 != len)
					cout<<" -> ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
};

int main()
{
	int n, ne;
	cout<<"Enter the number of vertices: "; cin>>n;
	graph g(n);
    cout<<"Enter the number of edges: "; cin>>ne;
	g.get_edges(ne);
	g.init_matrices();
	g.set_matrices();
	g.floyd_warshall();
	g.disp_dist_matrix();
	g.disp_path_matrix();
	cout<<endl;
	
	/*for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			g.compute_path(i, j);
		}
	}*/
	
	int v1,v2;
	int opt;
	do
	{
		cout<<"Enter the source vertex: "; cin>>v1;
		cout<<"Enter the destination vertex: "; cin>>v2;
		g.compute_path(v1, v2);
		cout<<"Do you wish to continue? ";
		cin>>opt;
	}
	while(opt);
}
