#include <bits/stdc++.h>

using namespace std;

void combi(int n, int len, vector<bool> &sol,int c,bool passed,int &k){
    if (c>=k) passed=true;
    if (len<n){
        sol[len]=false;
        combi(n,len+1,sol,0,passed,k);
        sol[len]=true;
        combi(n,len+1,sol,c+1,passed,k);
    }
    else{
        if (passed){
            for(int c=0;c<n;c++) cout<<sol[c];
            cout<<"\n";
        }
    }
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<bool> sol(n);
    combi(n,0,sol,0,false,k);
}
