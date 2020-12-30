//                              BFS OF THE TREE: ALWAYS QUEUE HI USE KARNA.. FOR GRAPH AS WELL
//                              SAME APPROACH...TRAVERSE LEFT AND RIGHT.. PRINT THE NEW FRONT ELEMENT
//                              AND ADD THE LEFT AND RIGHT COUNTERPART OF THE FIRST ELEMENT 
//                              IF AVAILABLE IN THE QUEUE POP THE FRONT ELEMENT FROM THE QUEUE;)
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

void levelorder(node * root,vector<int>ans)
{
    queue<node *>q;

    if(root==NULL)  return ;
    
    q.push(root);

    while (!q.empty())
    {
        //ALSO FOR LEAF NODE
        if(root==NULL)  return ;

        cout<<q.front()->data<<" ";
        
        //add the left and right counterpart
        if(q.front()->left!=NULL)
            q.push(q.front()->left);
        
        if(q.front()->right!=NULL)
            q.push(q.front()->right);
        
        //  REMOVE THE FRNOT ELEMENT ;)
        q.pop();
    }
    
    return ;
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

    vector<int>ans;
    levelorder(root,ans);
    cout<<"\n";
    //cout<<"Moshi moshi\n";
}