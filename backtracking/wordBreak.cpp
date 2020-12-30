#include<bits/stdc++.h>
using namespace std;

set<string> dic ={ "i", "like", "sam", "sung", "samsung", "mobile", "ice", 
  "cream", "icecream", "man", "go", "mango"};

void wb(string &input,vector<string>&s,int pointer,string current_string)
{
    //TERMINATION 
    if(pointer==input.size())
    {
        cout<<current_string<<"\n";
        s.push_back(current_string);
        return ;
    }
    
    cout<<current_string<<endl;
    //IF Current string 
    current_string+=input[pointer];
    string temp  = current_string;
    
    //IF found then 2 choiices either break or do nothing
    if(dic.find(current_string)!=dic.end())
    {
        current_string="";
        wb(input,s,pointer+1,current_string+" ");
        current_string = temp;
    }
}

int main()
{
    string input = "ilikesamsungmobile";
    vector<string> s;
    //Pointing to location in input
    int i = 0;
    string current_string = "";
    wb(input,s,0,current_string);
}