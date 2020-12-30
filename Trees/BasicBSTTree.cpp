//                                                       BST hai ye... but not balanced
//                  APPROACH: ALL ARE MOSTLY RECURSIVE SOLUTION.. SO PURA RECURSION HI CHALEGA ISME ;)
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node *left;
        node *right;
    //constructor
    node(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
};
//1.SEARCHING FOR A NODE IN BST
node* search(node *root,int k)
{
    if(root->left==NULL && root->right==NULL&&root->data!=k)
    {
        cout<<"Nai mila re baba\n";
        return NULL;
    }
        
    else if(root->data==k)
    {
        cout<<"mil gaya re baba\n";
        return root;
    }
        
    else if(root->data > k)
        search(root->left,k);
    else
    {
        search(root->right,k);
    }
    
}
//2.INSERTION OF A NODE IN BST
void insertion(node *root,node *newNode)
{
    cout<<root->data<<endl;
    //don't know about right but left part is null(the position where to be inserted)
    if(root->left==NULL&&root->data > newNode->data)
    {
        cout<<"Inserted node at left\n";
        root->left=newNode;
    }
    //don't know about left but right aprt is null(the position where to be inserted)
    else if(root->right==NULL&&root->data < newNode->data)
    {
        cout<<"Inserted node at right\n";
        root->right=newNode;
    }
    else if(root->data < newNode->data)
        insertion(root->right,newNode);
    else
    {
        insertion(root->left,newNode);
    }
    
}
//3.DELETION OF A NODE IN BST
void deletion(node *root,int k)
{
    node *nodeToBeDeleted=search(root,k);
    //no child of the node to be deleted
    if(nodeToBeDeleted->left==NULL||nodeToBeDeleted->right==NULL)
        delete(nodeToBeDeleted);
    //one child of the node to be delted
    if(nodeToBeDeleted->left==NULL&&nodeToBeDeleted->right!=NULL)
    {
        nodeToBeDeleted->data=nodeToBeDeleted->right->data;
        delete(nodeToBeDeleted->right);
    }
    //delete the left single child
    if(nodeToBeDeleted->right==NULL&&nodeToBeDeleted->left!=NULL)
    {
        nodeToBeDeleted->data=nodeToBeDeleted->left->data;
        delete(nodeToBeDeleted->left);
    }
    //Two childs are present
    if(nodeToBeDeleted->right!=NULL&&nodeToBeDeleted->left!=NULL)
    {
        //searchin the predecesor
        cout<<"Last case hai re baaba\n";
        node *pred=nodeToBeDeleted->left;
        cout<<pred->data<<endl;
        while((pred->right!=NULL))
            pred=pred->right;
        cout<<"Element to be replaced is "<<pred->data<<endl;
        nodeToBeDeleted->data=pred->data;
        delete(pred);
    }
}

//4.HEIGTH OF THE BST TREE
int height(node *root)
{
    //when root is null
    if(root==NULL)
            return 0;
        //when leaf node 
        if(root->right==NULL && root->left==NULL)
            return 1;
        //when intermediate node.. IT  IS NOT BACLANCED BST SO THAT THE HEIGHT WILL ALWAYS BE ON THE LEFT SIDE
        //ONLY CONDITION, PREORDER WILL GIVE ASENDING ORDER NUMBERS ;)
        else if(root->right!=NULL && root->left!=NULL)
        {
            return max(height(root->left),height(root->right))+1;
        }
        //wheen only single child
        else if(root->left==NULL)
            return height(root->right)+1;
        else
            return height(root->left)+1;
}

//5.TRAVERSALS
void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
void preorder(node *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);   
    }
}
void postorder(node *root)
{
    if(root!=NULL)
    {
        preorder(root->left);
        postorder(root->right);   
        cout<<root->data<<" ";
    }
}
int main()
{

 /*
                     10
                   /    \
                  5      15
                 / \     / \
                3   7    12 18
                     \
                      8
    */

    //adding the intial element
    node *root=new node(10);
    root->left=new node(5);
    root->left->left=new node(3);
    root->left->right=new node(7);
    root->left->right->right=new node(8);
    //rught subtree
    root->right=new node(15);
    root->right->left=new node(12);
    root->right->right=new node(18);
    //cout<<"Moshi MOshi\n";
    // int n;
    // cout<<"Enter the value of node to be deleted ";
    // cin>>n;
    // node *newNode=new node(n);
    // deletion(root,n);
    int r=height(root);
    cout<<"THe max height if the tree is "<<r<<"\n";
    inorder(root);
    cout<<"\n";
    //cout<<"Moshi moshi\n";
}