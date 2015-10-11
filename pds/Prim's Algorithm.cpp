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
		char u, v;
		cout<<"For each of the "<<ne<<" edges, "<<endl
			<<"Enter the head, tail, and weight (in that order)"<<endl;
		for(int i = 1; i <= ne; i++) {
			cout<<"Edge "<<i<<": ";
			cin>>u>>v>>weight;
			switch(u) {
				case 'a':
					x = 1;
				break;	
				case 'b':
					x = 2;
				break;
				case 'c':
					x = 3;
				break;
				case 'd':
					x = 4;
				break;
				case 'e':
					x = 5;
				break;
				case 'f':
					x = 6;
				break;
			}
			switch(v) {
				case 'a':
					y = 1;
				break;	
				case 'b':
					y = 2;
				break;
				case 'c':
					y = 3;
				break;
				case 'd':
					y = 4;
				break;
				case 'e':
					y = 5;
				break;
				case 'f':
					y = 6;
				break;
			}
			mat[x][y] = weight;
			mat[y][x] = weight;
		}

	}
	void disp_matrix() {//to display the adjacency matrix
		cout<<"Adjacency matrix representation of graph is: "<<endl;
		cout<<"(0: no edge; any other integer: weighted edge)"<<endl;
		cout<<"\t";
		cout<<"a\tb\tc\td\te\tf"<<endl;
		cout<<endl;
		for(int i = 1; i <= n; i++) {
			cout<<char(i + 96)<<"\t";
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
			cout<<char(i + 96)<<"\t";
			cout<<known[i]<<"\t";
			cout<<dv[i]<<"\t";
			cout<<pv[i]<<endl;
		}
	}
	void prim() { //begin implementation of prim's algorithm for MST
		dv[1] = 0, pv[1] = 0;
		int k = 1;
		int min = infinity, curr = 1;
		int end = 0;
		while(!end) {
			known[curr] = 1;
			for(int i = 1; i <= n; i++) {
				//There is an edge from current vertex to vertex i only if mat[cur][i] is non-zero
				//mat[curr][i] : weight of path from current vertex to vertex i
				//dv[curr]: dv value of current vertex
				//dv[i]: dv value of vertex i
				//update dv value ONLY if it is unknown i.e., (known[i] == fals)
				if(mat[curr][i] != 0 && (mat[curr][i] < dv[i]) && known[i] == fals) { 
					//update dv[i] and pv[i]
					dv[i] = mat[curr][i];
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
			if(min == infinity)
				end = 1;
			cout<<endl;
			disp_config_table();

		}
		//disp_config_table();
	}
	void result() { //to display edges in the MST and total cost
		char u, v;
		int total_cost = 0;
		cout<<"The edges in the MST are as follows: "<<endl;
		cout<<"(Start vertex) (End vertex) (Edge weight)"<<endl;
		for(int i = 2; i <= n; i++) {
			switch(i) {	
				case 2:
					u = 'b';
				break;
				case 3:
					u = 'c';
				break;
				case 4:
					u = 'd';
				break;
				case 5:
					u = 'e';
				break;
				case 6:
					u = 'f';
				break;
			}
			switch(pv[i]) {
				case 1:
					v = 'a';
				break;	
				case 2:
					v = 'b';
				break;
				case 3:
					v = 'c';
				break;
				case 4:
					v = 'd';
				break;
				case 5:
					v = 'e';
				break;
				case 6:
					v = 'f';
				break;
			}
			cout<<u<<" "<<v<<" "<<dv[i]<<endl;
			total_cost += dv[i];
		}
		cout<<"Total cost: "<<total_cost<<endl;
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
	g.prim();
	cout<<endl;
	g.result();
}
