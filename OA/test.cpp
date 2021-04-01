#include<bits/stdc++.h>
using namespace std;

int main()
{
    double a=14.4;
    double b=16.3;

    map<double,string>m;
    m[0.01]="PENNY";
    m[0.05]="NICKEL";
    m[0.10]="DIME";
    m[0.25]="QUATER";
    m[0.50]="HALF DOLLAR";
    m[1]="ONE";
    m[2]="TWO";
    m[5]="FIVE";
    m[10]="TEN";
    m[20]="TWENTY";
    m[50]="FIFTY";
    m[100]="ONE HUNDERED";
    
    int change=a-b;
    vector<string>ans;

    vector<int>a={1,5,10,25,50};

    int withoutdeci=change%1;
    vector<int>decimal={1,5,10,20,50,100};

    dou deci=change-withoutdeci;



    for (int i = 4; i >= 0; i--)
    {
        while (num >= v[i])
        {
            cout << m[v[i]] << " ";
            num -= v[i];
        }
    }


}