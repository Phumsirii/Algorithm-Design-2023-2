#include <bits/stdc++.h>
using namespace std;
int n,e,tmp1,tmp2,tmp;
vector<int> indegree;
vector<vector<int>> departure;  
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n>>e;
    indegree.resize(n+1);departure.resize(n+1);
    for(int i=0;i<e;++i){
        cin>>tmp1>>tmp2;
        departure[tmp1].push_back(tmp2);
        indegree[tmp2]++;
    }
    //finish getting all datas
    for(int i=0;i<5;++i){
        vector<int> tmpindegree=indegree;
        vector<vector<int>> tmpdepart=departure;
        bool valid=true;
        for(int j=0;j<n;++j){
            cin>>tmp;
            //the sequence already failed qualification
            if(tmpindegree[tmp]>0) valid=false;
            //the sequence is still on the way
            else{
                vector<int> &tmparr=tmpdepart[tmp];
                //decrement in degree of all destination from tmp as tmp will be deleted
                for(int k:tmparr) tmpindegree[k]--;
            }
        }
        if (valid) cout<<"SUCCESS\n";
        else cout<<"FAIL\n";
    }
}