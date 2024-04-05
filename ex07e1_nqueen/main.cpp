#include <bits/stdc++.h>
using namespace std;
int n,cnt;
vector<int> row_col;
vector<bool> col_used;
void recur(int currentr){
    if (currentr<n){
        //check for all possible col for this row
        for(int i=0;i<n;++i){
            if (!col_used[i]){
                col_used[i]=true;
                row_col[currentr]=i;
                bool pass=true;
                //check all col of previous rows
                for(int r=0;r<currentr;++r){
                    if (abs(r-currentr)==abs(row_col[r]-row_col[currentr])){
                        pass=false;
                        break;
                    }
                }
                if (pass) recur(currentr+1);
                col_used[i]=false;
            }
        }
    }else{ //have iterate through all cases
        //check for diagonal of all pairs from n queens
        bool failed=false;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                int r1=i,c1=row_col[i];
                int r2=j,c2=row_col[j];
                if (abs(r1-r2)==abs(c1-c2)){
                    failed=true;
                    break;
                }
            }
            if (failed) break;
        }
        if (!failed) ++cnt;
    }
}
int main(){
    cin>>n;
    row_col.resize(n,-1);col_used.resize(n,false);
    recur(0);
    cout<<cnt;
}