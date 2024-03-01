#include <bits/stdc++.h>
using namespace std;
//return indices of students chosen
void combi_kn_exact(int n,int len,int k,vector<int> &sol,int chosen,vector<vector<int>> &results){
    if (len<n){
        if (len-chosen<n-k){
            sol[len]=0;
            combi_kn_exact(n,len+1,k,sol,chosen,results);
        }
        if (chosen<k){
            sol[len]=1;
            combi_kn_exact(n,len+1,k,sol,chosen+1,results);
        }
    }
    else{
        vector<int> r(k);
        int it=0;
        for(int i=0;i<n;i++){
            if (sol[i]) r[it++]=i;
        }
        results.push_back(r);
    }
}
int main(){
    int n,m,nd,d;
    cin>>n>>m;
    vector<vector<int>> students_free(m);
    for(int i=0;i<m;i++){
        cin>>nd;
        vector<int> tmp(nd);
        for(int j=0;j<nd;++j){
            cin>>tmp[j];
        }
        students_free[i]=tmp;
    }
    for(int i=1;i<m;i++){
        //select exactly i students
        vector<vector<int>> results;
        vector<int> sol(m,0);
        combi_kn_exact(m,0,i,sol,0,results);
        for(vector<int> x:results){
            //for each cases of i students
            set<int> s;
            for(int y:x){
                //for each student the combination
                vector<int> student(students_free[y]);
                for(int z:student){
                    //insert all days a student is free
                    s.insert(z);
                }
            }
            if (s.size()==n){
                cout<<i;
                return 0;
            }
        }
    }
    cout<<m;
}