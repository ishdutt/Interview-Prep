#include<bits/stdc++.h>
using namespace std;


//SLIDING WINDOW TO BE DONE AFTER ARRAY
int main()
{
    string s="AAA";
    string t = "AAA";
    vector<string> v;
    string ans="";
    // cout<<s.find("x");
    //BRUTE FORCE
    int flag=0;
    int maxlen = 0;
    for(int i=0;i<s.size();i++)
    {
        for(int j=i+1;j<s.size()+1;j++)
        {
            //NOW SEARCH FOR THE CHARCTERS
            //string tmp(s.begin()+i,s.begin()+j);
            string tmp;
            //cout<<i<<j<<endl;
            for(int l=i;l<j;l++)
                tmp.push_back(s[l]);

            //cout<<tmp<<endl;
            flag=0;
            for(int k=0;k<t.size();k++)
            {  
                if(tmp.find(t[k])==string::npos)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0 && maxlen<tmp.size())
            {
                //cout<<tmp<<endl;
                ans = tmp;
                //break;
            }
                
        }
    }
    cout<<ans<<endl;

}