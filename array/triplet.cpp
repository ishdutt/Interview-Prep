#include<bits/stdc++.h>
using namespace std;


// USING CLASSICAL 3 SUM APPROACH
int main()
{
    vector<int> array = {1, 4, 20, 3, 10, 5};
    int sum = 100;
    int l,h;
    sort(array.begin(),array.end());
    for(int i=0;i<array.size()-2;i++)
    {
        l=i+1, h=array.size()-1;
        while(l<h)
        {
            if(array[i]+array[l]+array[h]==sum)
            {
                cout<<array[i]<<" "<<array[h]<<" "<<array[l]<<endl;
                return 0;
            }
            if(array[i]+array[l]+array[h]>sum) h--;

            else if(array[i]+array[l]+array[h]<sum) l++;
        }
    }
    cout<<"TRIPLET nOT FOUND\n";

}