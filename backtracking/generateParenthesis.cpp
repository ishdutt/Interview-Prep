 //HERE L IS FOR COUNTING '(' AND R IS FOR COUNTING ')'
// GENERATING ALL PERMUTATION WITH A CONSTRAINT OF '(' > '(' IS SATISFIED WILL GIVE TLE 

//     bool validswap(string s,int i,int j)
//     {
//         int countstart=0;
//         int countend=0;
//         for(int k=0;k<i;k++)
//         {
//           if(s[k]=='(')
//                 countstart++;
//             else
//                 countend++;
//         }
//         if(s[j]=='(')countstart++;
//         else countend++;
        
//         return countstart>=countend;
           
//     }
//     void permut(set<string>&ans,string s,int n,int i)
//     {
        
//         if(i==2*n)
//         {
//             ans.insert(s);
//             return ;
//         }
        
//         //traverse to generate the whole list
//         for(int j=i;j<2*n;j++)
//         {
//             //Skiping to swap if it results in a imbalance
//             if(!validswap(s,i,j)) continue;
//             swap(s[i],s[j]);
//             permut(ans,s,n,i+1);
//             swap(s[i],s[j]);
//         }
//         return ;
            
//     }
//     vector<string> generateParenthesis(int n) {
//         string s="";
//         for(int i=0;i<n;i++)
//             s+="()";
        
//         set<string> ans;
//         permut(ans,s,n,1);
//         vector<string> output(ans.begin(),ans.end());
        
//         return output;
//     }


void permut(vector<string>&ans,string s,int n,int l,int r)
    {
        if(l==n && r==n)
            ans.push_back(s);
        else
        {
            if(l<n) permut(ans,s+'(',n,l+1,r);
            
            if(r<l) permut(ans,s+')',n,l,r+1);
        }
    }
    //MAIN FUNCTION
    vector<string> generateParenthesis(int n) {
        
        string s="";
        vector<string> ans;
        permut(ans,s,n,0,0);
        
        return ans;
    }