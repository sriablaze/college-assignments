#include<iostream>
#include<queue>
#include<stack>
#include<limits>
using namespace std;
# define INT_MAX 1000
class graph{
	int a[100][100],b[100];
	int n,noe;
	bool visited[100];
	public:
		void input(){
			int i,p,q,r,j;
			cout<<"Enter number of vertices : ";
			cin>>n;
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					if(i==j)
						a[i][j]=0;
					else
						a[i][j]=INT_MAX;
				}
			}
			cout<<"Enter the number of edges : ";
			cin>>noe;
			cout<<"Enter the edges"<<endl;
			for(i=0;i<noe;i++){
				cin>>p>>q;
				a[--p ][--q]=1;
			}
			for(i=0;i<n;i++)
				visited[i]=false;
		}
		void displaya(){
			int i,j;
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					if(a[i][j]==INT_MAX)
						cout<<"INF\t";
					else
						cout<<a[i][j]<<"\t";
				}
				cout<<endl;
			}
		}
			
		
		void bfs(int source){
			source--; int vertex,i;//,j=0;
			queue<int> q;
			q.push(source);
			while(!q.empty()){
				vertex=q.front(); 
				visited[vertex]=true;
				cout<<vertex+1<<" ";
				q.pop();
				for(i=0;i<n;i++){
					if(a[vertex][i]==1 && visited[i]==false){
					  q.push(i); visited[i]=true;}
				}
			}
			for(i=0;i<n;i++)
				visited[i]=false;
			
		}
		void dfs(int source){
			source--; int vertex,i;//,j=0;
			stack<int> s;
			s.push(source);
			while(!s.empty()){
				vertex=s.top(); 
				visited[vertex]=true;
				cout<<vertex+1<<" ";
				s.pop();
				for(i=0;i<n;i++){
					if(a[vertex][i]==1 && visited[i]==false){
					  s.push(i); visited[i]=true;}
				}
			}
			for(i=0;i<n;i++)
				visited[i]=false;
			
	}
		
};

int main(){
	int ch=1,ver;
	graph g;
	while(ch<5)
	{
	cout<<"1.INPUT GRAPH\n2.DISPLAY ADJACENCY MATRIX\n3.PERFORM BFS\n4.PERFORM DFS\n5.EXIT"<<endl;
	
	
		cout<<"\nENTER CHOICE : ";
		cin>>ch;
		if(ch==1) g.input();
		if(ch==2) g.displaya();
		if(ch==3) {cout<<"Enter the source vertex : "; cin>>ver; g.bfs(ver);}
		if(ch==4) {cout<<"Enter the source vertex : "; cin>>ver; g.dfs(ver);}
	}
	return 0;
}
