#include<bits/stdc++.h>
using namespace std;


//FIXME: Why after EVERY FUNCTION CALL WE HAVE TO RETURN? 

//KNIGTH HAS TOTAL OF EIGHT MOVES WHEN IN CENTER FORMING LIKE A HEXAGON

//                1-----------2                                      
//               /             \
//              /               \
//             8|                3
//              |        #       |
//              |                |
//             7\                /4
//               \              /
//                6-----------5

//The order of the x_move and y_move arrays are going to affect the running time of the algorithm 
//drastically. Think of a case, when a person chooses 6 wrong long paths and finally reaching the 
//goal in the 7th path and another case when the person took the correct path in the first turn. 
//This is also similar. The order given here is a tested one.

//IMP TO NOTE:
//1. AT THE END RETURN STATEMENT IS MUST 
//2. POINTER VECTOR HERE DOESN'T SEEM TO WORK AS REFERENCE IS FAST {DUE TO PASS BY REF AND PASS BY POINTER}
//3. AFTER EVERY RECURSIVE FUNCTION CALL RETURN STATEMENT IS MUST OTHERWISE IT FALLS INTO LOOP
//  AS IT IS A FUNCTION WHICH IS RETURNING SOMETHING SO NEED IF BLOCK TYPE FASHION TO DO IT'S WORK

//  HERE IT IS SO AS WHEN THAT FUNCTION CALL IS TRUE(DECISION) THEN WHY GOT TO THE OTHER CALLS JUST IGNORE IT 
// THUS SAVING THE TIME TO COMPLETE

//4. EXTRA PRINT STATEMENT WILL MAKE THE PROGRAM MORE DELAYED SINCE IT IS A COMPLEX PROGRAM.

bool isvalid(vector<vector<int>>&board,int i,int j)
{
    return i >= 0 && j >= 0 && i < 8 && j < 8 ;
};

// bool checkcompletion(vector<vector<int>>&board)
// {
//     for(int i=0;i<8;i++)
//     {
//         for(int j=0;j<8;j++)
//             if(board[i][j]==0)
//                 return false;
//     }
//     return true;
// }
int tour(vector<vector<int>>&board,int i,int j,int steps)
{

    //CHECK IF ALL ARE MARKED FOR TERMINATION
    if(steps==65)
    {
        for(int l=0;l<8;l++)
        {
            for(int m=0;m<8;m++)
            {
                if(board[l][m]>9)
                    cout<<" "<<board[l][m]<<" ";
                else
                    cout<<" "<<board[l][m]<<"  ";
            } 
            cout<<"\n";
        }
        return 1;
    };

    //CHECK IF IT IS A VALID STEP IF NOT VALID THEN RETURN 0
    if(!isvalid(board,i,j))
    {
        return 0;
    }

    //if(checkcompletion(board)) return 1;
    //CHECK IF THAT PLACE IS ALREADY VISITED(MOVED OUT OF ISVALID AS THAT FUNCTION ME 
    //GET A OUT OF BOUND REQUEST WHICH WILL CAUSE SEGMENTATION FAULT)

    if(board[i][j]!=0)return 0;
    

    //BACKTRACKING IDEA VARIABLE
    board[i][j]=steps++;

    if(tour(board,i+2,j+1,steps)) return 1;
    if(tour(board,i+1,j+2,steps)) return 1;
    if(tour(board,i-1,j+2,steps)) return 1;
    if(tour(board,i-2,j+1,steps)) return 1;
    if(tour(board,i-2,j-1,steps)) return 1;
    if(tour(board,i-1,j-2,steps)) return 1;
    if(tour(board,i+1,j-2,steps)) return 1;
    if(tour(board,i+2,j-1,steps)) return 1;

    board[i][j]=0;
    steps--;

    //VVIMP PAL!!!
    return 0;

}

int main()
{
    //for marking the visited part as well as noting the number os steps
    vector<vector<int>>board (8,vector<int>(8,0));
    int steps = 1;

    //int board[8][8]={0};


    //MADE steps =1 for 0,0
    //board[0][0]=++steps;
    //initil position 0,0
    tour(board,0,0,steps);

    return 0;
}