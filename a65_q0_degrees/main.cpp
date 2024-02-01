#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,data;
    cin>>n;
    vector<int> count_no_of_existence(n+1);
    for(int i=0;i<n;++i){
        int count=0;
        for (int j=0;j<n;j++){
            cin>>data;
            if (data) count++;
        }
        count_no_of_existence[count]++;
    }
    while(count_no_of_existence[n]==0) n--;
    for(int i=0;i<=n;i++){
        cout<<count_no_of_existence[i]<<" ";
    }
}