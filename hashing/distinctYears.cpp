#include<bits/stdc++.h> 
using namespace std;

int main()
{
    string s="UN was established on 24-10-1945. India got freedom on 15-08-1945.";
    
    unordered_set<string> years;
    int countdash=0;
    //Scrapping the useless part
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='-')
            countdash++;
        
        if(countdash==2)
        {
            //cout<<"MOshi";
            if(isdigit(s[i+1]))
            {
                countdash=0;
                string temp="";
                temp = temp+s[i+1]+s[i+2]+s[i+3]+s[i+4];
                years.insert(temp);
                i=i+3;
            }
        }
    }
    cout<<years.size()<<endl;
}