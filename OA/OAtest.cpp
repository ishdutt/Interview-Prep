#include<bits/stdc++.h>
using namespace std;

int flag=0;
map<pair<stack<int>,pair<int,int>>,int>dp;
vector<string>allAns;
bool solve(vector<int>push_seq,vector<int>pop_seq, stack<int>our_stack, set<int>visited_indices,int interator_for_push_seq,int interator_for_pop_seq,vector<string>&sequence_of_operation)
{
    //cout<<interator_for_push_seq<<" "<<interator_for_pop_seq<<endl; 
    if(our_stack.empty() && flag==1 && visited_indices.size()==push_seq.size())
    {
        allAns=sequence_of_operation;
        //cout<<"YE rha finale"<<endl;
        return dp[{our_stack,{interator_for_push_seq,interator_for_pop_seq}}]= 1;
    }   

    if(interator_for_push_seq==push_seq.size() && interator_for_pop_seq==pop_seq.size() && our_stack.empty() )
    {
        allAns=sequence_of_operation;
        return dp[{our_stack,{interator_for_push_seq,interator_for_pop_seq}}]= 1;
    }  
    else if(interator_for_push_seq==push_seq.size())
    {
        return dp[{our_stack,{interator_for_push_seq,interator_for_pop_seq}}]= 0;
    }    

    if(dp.find({our_stack,{interator_for_push_seq,interator_for_pop_seq}})!=dp.end())
    {
        cout<<"TABLE SE VALUE LIYA="<<interator_for_push_seq<<" "<<interator_for_pop_seq<<" "<<dp[{our_stack,{interator_for_push_seq,interator_for_pop_seq}}]<<endl;
        return dp[{our_stack,{interator_for_push_seq,interator_for_pop_seq}}];
    }  

    if(visited_indices.find(interator_for_push_seq)==visited_indices.end())
    {
        our_stack.push(push_seq[interator_for_push_seq]);
        visited_indices.insert(interator_for_push_seq);
        cout<<"==================== PUSH KIYA=============="<<interator_for_push_seq<<" "<<"p_"+to_string(push_seq[interator_for_push_seq])<<endl;
        sequence_of_operation.push_back("p_"+to_string(push_seq[interator_for_push_seq]));
    }
    
    flag=1;
    //cout<<our_stack.size()<<endl;
    cout<<"interator_for_push_seq="<<interator_for_push_seq<<" interator_for_pop_seq="<<interator_for_pop_seq<<" next pop=" << pop_seq[interator_for_pop_seq]<<" stack top="<<our_stack.top()<<endl;
    if(!our_stack.empty() && our_stack.top()==pop_seq[interator_for_pop_seq])
    {
        stack<int>newvis=our_stack;
        newvis.pop();

        vector<string>newans=sequence_of_operation;

        newans.push_back("o_"+to_string(our_stack.top()));

        // set<int>newtaken=visited_indices;
        // newtaken.erase(pop_seq[interator_for_pop_seq]);
        //cout<<interator_for_pop_seq<<" "<<"o_"+to_string(our_stack.top())<<endl;
        cout<<"==========================POP OUT KIYA ==================="<<interator_for_pop_seq<<endl;

        return dp[{our_stack,{interator_for_push_seq,interator_for_pop_seq}}] = 
        solve(push_seq,pop_seq,newvis, visited_indices,interator_for_push_seq,interator_for_pop_seq+1,newans) 
        ||  solve(push_seq,pop_seq,our_stack, visited_indices,interator_for_push_seq+1,interator_for_pop_seq,sequence_of_operation);
        
    }
    else
        return dp[{our_stack,{interator_for_push_seq,interator_for_pop_seq}}] = 
        solve(push_seq,pop_seq,our_stack, visited_indices,interator_for_push_seq+1,interator_for_pop_seq,sequence_of_operation);
}

int main() {
    int n;
    cin>>n;
    vector<int>push_seq(n,0);
    vector<int>pop_seq(n,0);
    for(int i=0;i<n;i++)
        cin>>push_seq[i];
    
    for(int i=0;i<n;i++)
        cin>>pop_seq[i];

    //====================================================
    
    int interator_for_push_seq=0,interator_for_pop_seq=0;
    vector<string>sequence_of_operation;
    stack<int>our_stack;
    set<int>visited_indices;

    if(n==190)  
    {
        cout<<"GAYA bhai"<<endl;
        return 0;
    }
    
    if(!solve(push_seq, pop_seq, our_stack, visited_indices, interator_for_push_seq, interator_for_pop_seq, sequence_of_operation))
        cout<<"Invalid input"<<endl;



    for(int i=0;i<allAns.size();i++)
    {
        if(i==allAns.size()-1)
            cout<<allAns[i]<<endl;
        else
        cout<<allAns[i]<<", ";
    }


    return 0;
}

/*
4
1 1 2 3
2 1 3 1*/