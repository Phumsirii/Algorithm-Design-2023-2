#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,data;
    cin>>n;
    vector<int> cumsum(n),datas(n);
    int max1=-2000000000,max2=-2000000000;
    cin>>cumsum[0];
    datas[0]=cumsum[0];
    for(int i=1;i<n;i++) {
        cin>>data;
        cumsum[i]=max(data+cumsum[i-1],0);
        datas[i]=data;
        if (cumsum[i]>max1){
            int tmp=max1;
            max1=cumsum[i];
        }
        else if (cumsum[i]>max2) max2=cumsum[i];
    }
    if (max1==0 && max2==0) cout<<*max_element(datas.begin(),datas.end());
    else cout<<max1+max2;
}