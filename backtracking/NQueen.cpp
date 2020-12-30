#include<bits/stdc++.h>
using namespace std;

//ISSafe will tell whether i and j are safe

//TODO: THINK WHY WITH VOID FUNCTION THE OUTPUT IS WRONG FOR THE PLACE FUNCTION

bool isSafe(vector<vector<int>>&board,int row,int col)
{
    cout<<"MOSHi "<<row<<" "<<col<<endl;
    int i,j;
    //i = row is different for sure so no need to check
    //IF the queen present in same column as selected one
    for(int i=0;i<board.size();i++)
        if(board[i][col])
            return 0;

    //NOw in row XXX and in col XXX
    //Now go for diagonal-> 4 diagonal but will consider only 2 on the left side since on right side no pieces
    // So left upward diagonal and dwon diagonal

    //LEFT TOP Diagonal
    for ( i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if(board[i][j]==1)
            return 0;
    
    //LEFT BOTTOM Diagonal
    for ( i = row, j = col; i <board.size() && j >= 0; i++, j--) 
        if(board[i][j]==1)
            return 0;
    
    return 1;

}

bool place(vector<vector<int>>&board,int row)
{
    if(row>=board.size())
        return 1;


    //IN each row..there are total of 8 ways for checking the 8 columns
    for(int j=0;j<board[0].size();j++)
    {
        if(isSafe(board,row,j))
        {
            board[row][j]=1;
            
            if(place(board,row+1)) return 1;
            
            //Backtrack
            board[row][j]=0;
        }
        
    }
    return 0;
}

int main()
{
    vector<vector<int>> board=
    {
        { 0, 0, 0, 0 }, 
        { 0, 0, 0, 0 }, 
        { 0, 0, 0, 0 }, 
        { 0, 0, 0, 0 }
    };

    bool posssible = place(board,0);


    for (int i = 0; i < 4; i++) { 
        for (int j = 0; j < 4; j++) 
            printf(" %d ", board[i][j]); 
        printf("\n"); 
    } 

}