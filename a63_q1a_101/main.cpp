#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin>>n;
    if (n<=2){
        cout<<pow(2,n);
        return 0;
    }
    //each columns represent length n bitstring ending with 00 01 10 11
    vector<vector<int>> done(2,vector<int> (4,0));
    for(int i=0;i<4;++i) done[0][i]=1;
    for(long long i=3;i<=n;++i){
        cout<<i<<"\n";
        done[i%2][0]=(done[(i-1)%2][0]+done[(i-1)%2][2])%100000007;
        done[i%2][1]=done[(i-1)%2][0];
        done[i%2][2]=(done[(i-1)%2][1]+done[(i-1)%2][3])%100000007;
        done[i%2][3]=(done[(i-1)%2][1]+done[(i-1)%2][3])%100000007;
    }
    int ans=0;
    for(int i=0;i<4;++i) ans=(ans+done[n%2][i])%100000007;
    cout<<ans;
}