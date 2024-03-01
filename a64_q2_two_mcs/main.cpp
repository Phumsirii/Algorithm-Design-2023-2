#include <bits/stdc++.h>
using namespace std;
int mcs(vector<int> &cumsum,int start,int stop){
    if (start==stop) return cumsum[start];
    int m=(start+stop)/2;
    int c1=mcs(cumsum,start,m);
    int c2=mcs(cumsum,m+1,stop);
    int min_left=cumsum[m]-cumsum[start];
    for(int i=start-1;i<m;i++){
        if (i<0) continue;
        int tmp=cumsum[m]-cumsum[i];
        if (tmp<min_left)min_left=tmp;
    }
    int min_right=cumsum[m+1]-cumsum[m];
    for(int i=m+2;i<=stop;i++){
        int tmp=cumsum[i]-cumsum[m];
        if (tmp<min_right) min_right=tmp;
    }
    int c3=min_right+min_left;
    return min({c1,c2,c3});
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,data;
    cin>>n;
    vector<int> cumsum(n),datas(n);
    cin>>cumsum[0];
    datas[0]=cumsum[0];
    for(int i=1;i<n;++i){
        cin>>datas[i];
        cumsum[i]=cumsum[i-1]+datas[i];
    }
    int max_ele=*max_element(datas.begin(),datas.end());
    int min_ele=*min_element(datas.begin(),datas.end());
    if (max_ele<=0) cout<<max_ele;
    else if(min_ele>=0) cout<<cumsum[n-1];
    else cout<<cumsum[n-1]-mcs(cumsum,0,n-1);
}