#include <iostream>
using namespace std;

#define numv 51
#define infinity 1000
#define fals 0

class graph
{
	int n;
	int mat[numv][numv], dv[numv], pv[numv];
	int known[numv];
	public:
	graph(int num) { //to create the adjacency matrix
		n = num;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				mat[i][j]=0;
			}
		}
	}
	void init_config_table() { //to initialize the configuration table
		for(int i = 1; i <= n; i++) {
			known[i] = fals;
			dv[i] = infinity;
			pv[i] = 0;
		}
	}
	void get_edges(int ne) { //to initialise edges and their weights
		int x, y, weight;
		cout<<"For each of the "<<ne<<" edges, "<<endl
			<<"Enter the head, tail, and weight (in that order)"<<endl;
		for(int i = 0; i < ne; i++) {
			cout<<"Edge "<<(i + 1)<<": ";
			cin>>x>>y>>weight;
			mat[x][y] = weight;
		}

	}
	void disp_matrix() {//to display the adjacency matrix
		cout<<"Adjacency matrix representation of graph is: "<<endl;
		cout<<"(0: no edge; any other integer: weighted edge)"<<endl;
		cout<<"\t";
		for(int i = 1; i <= n; i++) {
			cout<<"v"<<i<<"\t";
		}
		cout<<endl;
		for(int i = 1; i <= n; i++) {
			cout<<"v"<<i<<"\t";
			for(int j = 1; j <= n; j++) {
				cout<<mat[i][j]<<"\t";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	void disp_config_table() { //to display the configuration table
		cout<<"Vertex\t";
		cout<<"Known\t";
		cout<<"dv\t";
		cout<<"pv"<<endl;
		for(int i = 1; i <= n; i++) {
			cout<<"v"<<i<<"\t";
			cout<<known[i]<<"\t";
			cout<<dv[i]<<"\t";
			cout<<pv[i]<<endl;
		}
	} 
	void dijkstra() { //to compute the shortest path
		dv[1] = 0, pv[1] = 0;
		int k = 1;
		int min = infinity, count = 1, curr = 1;
		while(count <= n) {
			known[curr] = 1;
			for(int i = 1; i <= n; i++) {
				//There is an edge from current vertex to vertex i only if mat[cur][i] is non-zero
				//mat[curr][i] : weight of path from current vertex to vertex i
				//dv[curr]: dv value of current vertex
				//dv[i]: dv value of vertex i
				if(mat[curr][i] != 0 && (mat[curr][i] + dv[curr] < dv[i])) { //then update dv[i] and pv[i]
					dv[i] = mat[curr][i] + dv[curr];
					pv[i] = curr;
				}
			}
			min = infinity; //to find unknown vertex with least dv
			for(int i = 1; i <= n; i++) {
				if(known[i] == fals && dv[i] < min) {
					curr = i;
					min = dv[i];
				}
			}
			//cout<<endl;
			//disp_config_table();
			count++;
		}
		//disp_config_table();
	}
	void result() { //to display shortest path from source vertex to each vertex
		int path[numv];
		int curr, len;
		for(int i = 2; i <= n; i++) {
			curr = i;
			len = 0;
			cout<<"Length of shortest path from v1 to v"<<i<<": "<<dv[i]<<endl;
			cout<<"Shortest path from v1 to v"<<i<<": ";
			while(dv[curr] != 0) {
				path[len] = pv[curr];
				len++;
				curr = pv[curr]; 
			} 
			//at the end, curr will always be 1; dv[1] = 0 
			while(len) {
				len--;
				cout<<"v"<<path[len]<<" -> ";
				if(!len)
					cout<<"v"<<i<<endl;		
			}
		}
	}
};

int main()
{
	int num, ne;
	cout<<"Enter the number of vertices: "; cin>>num;
	graph g(num);
	cout<<"Enter the number of edges: "; cin>>ne;
	g.get_edges(ne);
	g.disp_matrix();
	g.init_config_table();
	cout<<"Initial configuration table before applying Dijkstra's algorithm: "<<endl;
	g.disp_config_table();
	g.dijkstra();
	cout<<"\nFinal configuration table after applying Dijkstra's algorithm: "<<endl;
	g.disp_config_table();
	cout<<endl;
	g.result();
}
