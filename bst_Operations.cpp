#include<iostream>
using namespace std;

struct node{
    int data;
    node *left,*right;
};
node *root;
class Bst{
    public:

        void create();
        void add(node*,node*);
        void show(node*);
        void seaRch(node *,int);
        void findMin(node*);
        void findMax(node*);
        int ncountLeafNodes(node* );
        int countNodes(node* );
        int height(node *);
        Bst()
        {
            root=NULL;
        }
};
void Bst::create()
{
    char ch;
    do{
        node *nn;
        nn=new node;
        nn->left=NULL;
        nn->right=NULL;
        cout<<"Enter Data..";
        cin>>nn->data;

        if(root==NULL)
            root=nn;
        else
            add(root,nn);

        cout<<"Do you want to Contine....(y/n)...";
        cin>>ch;
    }while(ch=='y');
}
void Bst::add(node *root, node *nn)
{
    if(root->data>nn->data)
    {
        if(root->left==NULL)
            root->left=nn;
        else
            add(root->left,nn);
    }
    else
    {
        if(root->right==NULL)
            root->right=nn;
        else
            add(root->right,nn);
    }

}
void Bst::show(node *root)
{
    node *t;
    t=root;
    if(t!=NULL){
        show(t->left);
        cout<<t->data<<"  ";
        show(t->right);
    }
}
void Bst::seaRch(node *root,int key)
{


    if(root->data==key)
    {
        cout<<endl<<"Found"<<endl;
    }
    else if(key<root->data)
    {
        seaRch(root->left,key);
    }
    else
    {
        seaRch(root->right,key);
    }

}
void Bst::findMin(node *root)
{
    node *t=root;
    while(t->left!=NULL)
    {
        t=t->left;
    }
    cout<<"Smallest Element= "<<t->data<<endl;
}
void Bst::findMax(node *root)
{
    node *t=root;
    while(t->right!=NULL)
    {
        t=t->right;
    }
    cout<<"Largest Element= "<<t->data;
}
int countLeafNodes(node* root) {
    if (root == nullptr) {
        return 0;
    }
    // Check if the node is a leaf node
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    // Recursively count leaf nodes in left and right subtrees
    int leftLeaves = countLeafNodes(root->left);
    int rightLeaves = countLeafNodes(root->right);

    // Return the total count of leaf nodes
    return leftLeaves + rightLeaves;
}
int countNodes(node* root) {
    if (root == nullptr) {
        return 0;
    }
    // Recursively count nodes in left and right subtrees
    int leftNodes = countNodes(root->left);
    int rightNodes = countNodes(root->right);

    // Return the total count of nodes including the current node
    return 1 + leftNodes + rightNodes;
}
int height(node *root)
{
    if (root == nullptr) {
        return 0;
    }

    int l=height(root->left);
    int r=height(root->right);

    if(l>r)
        return(1+l);
    else
        return(1+r);

}

int main()
{
    Bst b;
    cout<<"**********BST Operations*************"<<endl;
    cout<<"1. Create & Insert Nodes"<<endl;
    b.create();
    cout<<"2. Display..."<<endl;
    b.show(root);
    cout<<endl<<"3. Search key from Tree..."<<endl;
    int key;
    cout<<endl<<"Enter Key to be search....";
    cin>>key;
    b.seaRch(root,key);
    cout<<endl<<"4. Find MIN & MAX..."<<endl;
    b.findMin(root);
    b.findMax(root);
    cout<<endl<<"5. Count Leaf Nodes ";
     int leafCount = countLeafNodes(root);
    cout <<endl<< "Total number of leaf nodes: " << leafCount << std::endl;
    cout<<endl<<"6. Count Total Nodes "<<endl;
    int totalNodes = countNodes(root);
    cout << "Total number of nodes in the BST: " << totalNodes << std::endl;
    cout<<endl<<"7. Height of  Total  "<<endl;
    int h=height(root);
    cout<<"Height of Tree: "<<h;



    return 0;
}













