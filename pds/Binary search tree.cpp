#include <iostream>
#include <cassert>
using namespace std;

class student
{
  string name;
  string fname;
  string mname;
  string mobno;
  string address;
public:
    friend ostream& operator<<(ostream &out,student &s);
    friend istream & operator >>(istream &in,student &s);
    bool operator <(student s)
    {
      return (name<s.name);
    };
    bool operator >(student s)
    {
      return (name>s.name);
    };
    bool operator == (student s)
    {
      return(name==s.name);
    }    

};

istream& operator >>(istream &in,student &s)
{
	cout<<"\nEnter Name,Father's name,Mother's name,Mobile number and address: ";
	in>>s.name>>s.fname>>s.mname>>s.mobno>>s.address;
	return in;  
}
ostream& operator<<(ostream &out,student &s)
{
	out<<"\nName:"<<s.name;
	out<<"\nFather's Name:"<<s.fname;
	out<<"\nMother's Name:"<<s.mname;
	out<<"\nMobile number:"<<s.mobno;
	out<<"\nAddress:"<<s.address;
}


template<typename T>
class BST{
	struct node{
		T element;
		node *left,*right;
	};	
	node *tree;
public:
	BST(){
		tree=NULL;
	};
	void insert_h(T ele){
		insert(tree,ele);
	};
	void insert(node *&root,T ele){
		if(root == NULL){
			root = new node;
			root->left= root->right = NULL;
			root->element = ele;
			return;
		}
		if(ele <= root->element)
			insert(root->left,ele);
		else
			insert(root->right,ele);
	}
	void Delete_h(T ele){
		Delete(tree,ele);
	}
	void Delete(node *&root,T ele){
		if(root == NULL)
			return;
		if(ele < root->element)
			Delete(root->left,ele);
		else if(ele > root->element)
		Delete(root->right,ele);
		else {
			if(root->left!=NULL && root->right!=NULL){
				node *temp=root->right;
				T tmp ;
				while(temp!=NULL){
					tmp=temp->element;
					temp=temp->left;
				}
				root->element = tmp;
				Delete(root->right,root->element);
			}
			else{
				node *temp=root;
				root = (root->left != NULL) ? root->left : root->right;
				delete temp;	
			}
		}

	}
	void find_h(T ele){
		if(find(tree,ele)){
	 		cout<<"Element found \n";
		}
		else cout<<"Element not found \n";
	}
	bool find(node* root,T ele){
		if(root == NULL)
			return false;
		if( ele < root->element)
			return find(root->left,ele);
		else if( ele > root->element)
			return find(root->right,ele);
		else{
			return true;
		}
		return false;
	}
	void Preorder_h(){
		cout<<"Preorder traversal is \n";
		Preorder(tree);
	}
	void Preorder(node *root){
		if(root ==NULL)return;
		cout<<root->element<<endl;
		Preorder(root->left);
		Preorder(root->right);
	}
	void Inorder_h(){
		cout<<"Inorder Traversal is \n";
		Inorder(tree);
	}
	void Inorder(node *root){
		if(root ==NULL)return;
		Inorder(root->left);
		cout<<root->element<<endl;
		Inorder(root->right);
	}
	void Postorder_h(){
		cout<<"Postorder Traversal is \n";
		Postorder(tree);
	}
	void Postorder(node *root){
		if(root ==NULL)return;
		Postorder(root->left);
		Postorder(root->right);
		cout<<root->element<<endl;
	}

};

int main(){
	BST<int> bst;
	int ch;
	int ele;
	int n;
	do{
		cout<<"Menu \n";
		cout<<"1.Build a binary search tree \n";
		cout<<"2.Insert an element \n";
		cout<<"3.Delete an element \n";
		cout<<"4.Find an element \n";
		cout<<"5.Preorder traversal \n";
		cout<<"6.Inorder traversal(Ascending order) \n";
		cout<<"7.Postorder traversal \n";
		cout<<"Enter your choice\n";		
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"Enter the number of elements to insert";
				cin>>n;
				for(int i = 0;i < n; i++){
					int ele;
					cout<<"Enter element \n";
					cin>>ele;
					bst.insert_h(ele);
				}
				break;
			case 2:
				cout<<"Enter the element to insert\n";
				bst.insert_h(ele);
				break;
			case 3:
				cout<<"Enter the element to delete \n";
				cin>>ele;
				bst.Delete_h(ele);
				break;
			case 4:
				cout<<"Enter the element to find\n";
				cin>>ele;
				bst.find_h(ele);
				break;
			case 5:
				bst.Preorder_h();
				break;
			case 6:
				bst.Inorder_h();
				break;
			case 7:
				bst.Postorder_h();
				break;
		}
	}while(1);
}
