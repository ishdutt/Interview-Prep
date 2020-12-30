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

//USING PREORDER AND POSTORDER AND KEEPING A LEVEL VARIABLE TO KEEP TRACK OF THE FIRST ELEMENT

void leftview(node * root,int level,vector<int>ans)
{
    if(root==NULL)  return ;

    else if(ans.size()<level)   ans.push_back(root->data);

    //FIRST VISIT LEFT SINCE WE NEED LEFT MOST ELEMENT.. WHENEVER THE FIRST LEFT IS VISITED, LEVEL 
    // LEVEL=ANS.SIZE()+1... THEN PUSH IT INTO ARRAY AND INCREMENT THE LEVEL WHEN VISITING THE 
    // LEFTMOST ELEMENT
    leftview(root->left,level+1,ans);
    leftview(root->right,level+1,ans);
}

//FOR RIGHT MOST.. JUST VISIT THE RIGHT ELEMENT FIRST USING THIS LOGIC

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
    leftview(root,1,ans);
    cout<<"\n";
    //cout<<"Moshi moshi\n";
}