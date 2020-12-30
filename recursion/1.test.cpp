#include<bits/stdc++.h>
using namespace std;

//Very Very Important ... Most important recurions have similar pattern so remember it's output
int fun(int n)
{
    if(n<1)
        return 0;
    else
    {
        cout<<n<<" ";
        //STORING THE RESULT IN VARIABLE DOESN'T CHANGE ANYTHING... BUT IS EASIER TO HANDLE
        int l = fun(n-1);
        cout<<n<<" ";
    }
}

int main()
{
    int n=5;
    fun(n);
    cout<<"\n";
}