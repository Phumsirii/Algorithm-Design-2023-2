#include <bits/stdc++.h>
using namespace std;
int n,money;
int done[10001]; //store done data
int cash[20];
int recur(int amount){
    if (amount<0) return 1000000000;
    if (amount==0) return 0;
    if (done[amount]<10001) return done[amount];
    int newdata=10000;
    for(int i=0;i<n;++i){ //check if which case is the best case for this amount of money
        int candi=recur(amount-cash[i]);
        if (candi<newdata) newdata=candi;
    }
    done[amount]=newdata+1;
    return newdata+1;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n>>money;
    for(int i=0;i<n;++i) cin>>cash[i];
    for(int i=0;i<10001;++i) done[i]=10001;
    cout<<recur(money);
}