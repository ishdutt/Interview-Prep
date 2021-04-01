#include<bits/stdc++.h>
using namespace std;

//FIRST NEGATIVE IN EVERY SUBARRAY

int main()
{
    vector<int>a={1,-5,4,-7,3,-79,-9,7,3,-10};
    int k=3;


    //BRUTE FORCE
    // for(int i=0;i<a.size()-k+1;i++)
    // {
    //     int flag=0;
    //     for(int j=0;j<k&& i+j<a.size();j++)
    //     {
    //         if(a[i+j]<0)
    //         {
    //             cout<<a[i+j]<<" ";
    //             flag=1;
    //             break;
    //         }
    //     }
    //     if(flag==0)
    //         cout<<0<<" ";
    // }
    // cout<<endl;

    deque<int>dq;

    int i=0,j=0;
    while(j<a.size())
    {
        //cout<<j<<endl;
        int flag=0;
        if(j<k-1)
        {
            if(a[j]<0)
            {
                if(flag==1)
                    cout<<a[j]<<" ";
                dq.push_back(j);
                flag=1;
            }
            j++;
        }
        else
        {  
            
            if(!dq.empty() && dq.front() < i)
            {
                //cout<<"TEST="<<dq.front()<<endl;
                dq.pop_front();
            }
            i++;
            j++;

            if(a[j]<0)
                dq.push_back(j);
            
            if(!dq.empty())
            cout<<a[dq.front()]<< " ";

            else
                cout<<0<<" ";
            
        }
    }
    cout<<endl;



    // vector<int>neg;

    // int i=0,j=0;
    // while(j<a.size())
    // {
    //     if(j<k)
    //     {
    //         if()
    //     }
    // }
    
}