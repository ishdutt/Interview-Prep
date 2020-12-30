#include<bits/stdc++.h>
using namespace std;

// HERE NO NEED FOR TWO ARRAY TO PASS ONLY ONE ARRAY WILL MAKE THE WORK

int partition(vector<int>a,vector<int>r,int i,int sum)
{
    //BASE CONDITION
    //i>=a.size() or If sum of any side equal to half 
    if(i>=a.size())
        return 0;
    
    //Calculate the sum and check
    int sumr=0;
    for(int i=0;i<r.size();i++)
        sumr+=r[i];

    if(sumr==sum/2)
    {
        for(int i=0;i<r.size();i++)
            cout<<r[i]<<" ";    
        return 1;
    }
        
    //MAIN PART 
    //IF    iTH NUMBER GOES TO L
    // l.push_back(a[i]);
    // partition(a,r,l,i+1,sum);
    // l.pop_back();    

    //HERE 2 TIMES FUNCTION IS CALLED SINCE IF WE EXCLUDE THE ELEMENT AT "I" THEN WE HAVE TO CHECK 
    //AND AGAIN DO PARITION TO CHECK IS POSSIBLE ... IN PERMUTATION THERE WAS LOOP HENCE IT WAS BALANCED

    r.push_back(a[i]);
    partition(a,r,i+1,sum);
    r.pop_back(); 
    partition(a,r,i+1,sum);
}

int main()
{
    vector<int> a={1,5,11,5};

    vector<int> r,l;
    int sum = 22;

    partition(a,r,0,sum);
    
    for(int i=0;i<r.size();i++)
        cout<<r[i]<<" ";

    cout<<"\n";
}