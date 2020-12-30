#include<bits/stdc++.h>
using namespace std;

//READ COMMENTS FROM THE MAIN CODE PART TO UNDERSTAND IT'S WORKING

//FOLLOW THIS EXACT PATTERN--> ISVALID AND ONE RECURSIVE FUNCTION  

bool isvalid(int a[10][10], int i, int j, bool vis[10][10])
{
    return i >= 0 && j >= 0 && i < 10 && j < 10 && a[i][j] == 1 &&
				!vis[i][j];
}

int shortestpath(int a[10][10],int i,int j,int x,int y,bool vis[10][10])
{
    if(!isvalid(a,i,j,vis))return 1000000;

    if(i==x && j==y)return 0;

    vis[i][j] = true;
	int left = shortestpath(a, i, j-1, x, y, vis) + 1;
	int bottom = shortestpath(a, i+1, j, x, y, vis)+1;
	int right = shortestpath(a, i, j+1, x, y, vis)+1;
	int top = shortestpath(a, i-1, j, x, y, vis)+1;
		
	// This line makes backtracking work
	vis[i][j] = false;
	return min(min(left, bottom), min(right, top));
}

int main()
{
    int a[10][10]={
				{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
				{ 0, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
				{ 0, 0, 1, 0, 1, 1, 1, 0, 0, 1 },
				{ 1, 0, 1, 1, 1, 0, 1, 1, 0, 1 },					{ 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
				{ 1, 0, 1, 1, 1, 0, 0, 1, 1, 0 },
				{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
				{ 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
				{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
				{ 0, 0, 1, 0, 0, 1, 1, 0, 0, 1 },
			};
    
    bool vis[10][10];
    //i,j, x,y
    int result = shortestpath(a,0,0,9,9,vis);
    cout<<result;
}