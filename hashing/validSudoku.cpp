#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<string> > board{{"5","3",".",".","7",".",".",".","."},
    {"6",".",".","1","9","5",".",".","."},
    {".","9","8",".",".",".",".","6","."},
    {"8",".",".",".","6",".",".",".","3"},
    {"4",".",".","8",".","3",".",".","1"},
    {"7",".",".",".","2",".",".",".","6"},
    {".","6",".",".",".",".","2","8","."},
    {".",".",".","4","1","9",".",".","5"},
    {".",".",".",".","8",".",".","7","9"}};

    //Check for ROws 
    int row[9][9]={0};
    int col[9][9]={0};
    //For BOX see every 9 digits in 3x3 box
    int box[3][3][9]={0}; 
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(board[i][j]!=".")
            {
                int num = stoi(board[i][j]);
                //cout<<num<<endl;
                //Checking row wise
                if(row[i][num]++)return 0;
                if(col[j][num]++)return 0;
                if(box[i/3][j/3][num]++) return 0;
            }
        }
    }
    cout<<"Mosih";
}