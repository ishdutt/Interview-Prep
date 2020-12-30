//knights tour problem

#include<bits/stdc++.h>
using namespace std;

int n=8;

int func(int arr[8][8],int row,int col,int cnt)
{
    
    if(cnt==(n*n)+1)
    {
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                if(arr[i][j]>9)
                    cout<<" "<<arr[i][j]<<" ";
                else
                    cout<<" "<<arr[i][j]<<"  ";
            } 
            cout<<"\n";
        }
        return 1;
    }
    
    //check if the row and col are valid
    if(row<0 || row>=n)
    {
        return 0;
    }
    if(col<0 || col>=n)
    {
        return 0;
    }
    
    if(arr[row][col]==0)//not visited
    {

        arr[row][col]=cnt++;//mark visited
        
        
        // if(func(arr,row-2,col-1,cnt))return 1;
        // if(func(arr,row-2,col+1,cnt))return 1;
        // if(func(arr,row-1,col-2,cnt))return 1;
        // if(func(arr,row-1,col+2,cnt))return 1;
        // if(func(arr,row+1,col-2,cnt))return 1;
        // if(func(arr,row+1,col+2,cnt))return 1;
        // if(func(arr,row+2,col-1,cnt))return 1;
        // if(func(arr,row+2,col+1,cnt))return 1;

        func(arr,row-2,col-1,cnt);
        func(arr,row-2,col+1,cnt);
        func(arr,row-1,col-2,cnt);
        func(arr,row-1,col+2,cnt);
        func(arr,row+1,col-2,cnt);
        func(arr,row+1,col+2,cnt);
        func(arr,row+2,col-1,cnt);
        func(arr,row+2,col+1,cnt);
        
        
        //tried all possible moves
        arr[row][col]=0;
        cnt=cnt-1;
    }
    
    return 0;
}

int main()
{
    
    int arr[8][8];
    int row=0;
    int col=0;
    int cnt=1;
    
    memset(arr,0,sizeof(arr));
    
    func(arr,row,col,cnt);
    
    return 0;
    
}