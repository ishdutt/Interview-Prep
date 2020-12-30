#include<bits/stdc++.h>
using namespace std;

//APROACH: CREATE A RIGHTMAX ARRAY CONTAINING THE MAX ELEMENT FROM THAT INDEX TO THE RIGHTMOST EXTREME
// IMPORTANT APPROACH USED IN TRAPPING WATER PROBLEM TOO.
int main()
{
    vector<int> array = { 16, 17, 4, 3, 5, 2};
    vector<int> rightmax(array.size()-1);
    int maax = array[array.size()-1];
    for(int i=array.size()-1;i>-1;i--)
    {
        maax = max(maax,array[i]);
        rightmax[i]=maax;
    }
    for(int i=0;i<array.size();i++)
    if(array[i]==rightmax[i])
        cout<<array[i]<<endl;

}