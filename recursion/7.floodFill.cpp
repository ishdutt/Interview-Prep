#include<bits/stdc++.h>
using namespace std;
//      TEACHES US HOW TO USE RECURSION IN MATRIX
//                       FLOOD FILL : FILL A CERTAIN AREA WITH CERTAIN COLOUR(CHANGE IT'S MATRIX VALUE)

void colourFill(vector<vector<int>>&a,int x, int y, int colour,int oldcolour)
{

    //base condition->reaches the end of matrix
    if(x==0|| y== 0 || x== a[0].size() || y == a[0].size())
    {
        return ;
    }
    //if same colour then make it's colour change else leave it and move to other boxes
    if(a[x][y]!=oldcolour)
        return;
    //THIS STEP WILL DECREASE THE REPITITION
    if(a[x][y]==colour)
        return ;
    
    //COLOUR CHANGED
    a[x][y]=colour;

    //NOW TAKE CARE OF THE SURROUNDING 4 BLOCKS EITHER USE RECURION OR JUST WRITE THE SENTENCES
    colourFill(a,x+1,y,colour,oldcolour);
    colourFill(a,x-1,y,colour,oldcolour);
    colourFill(a,x,y+1,colour,oldcolour);
    colourFill(a,x,y-1,colour,oldcolour);
}

int main()
{
    vector<vector<int>> a = {{1, 1, 1, 1, 1, 1, 1, 1}, 
                            {1, 1, 1, 1, 1, 1, 0, 0}, 
                            {1, 0, 0, 1, 1, 0, 1, 1}, 
                            {1, 2, 2, 2, 2, 0, 1, 0}, 
                            {1, 1, 1, 2, 2, 0, 1, 0}, 
                            {1, 1, 1, 2, 2, 2, 2, 0}, 
                            {1, 1, 1, 1, 1, 2, 1, 1}, 
                            {1, 1, 1, 1, 1, 2, 2, 1}};
    //STARTING CO-ORDINATES AND NEW COLOUR
    int x = 4,y = 4,colour = 8;
    colourFill(a,x,y,colour,a[x][y]);

    //print the list
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a[0].size();j++)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
}