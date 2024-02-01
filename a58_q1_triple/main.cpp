#include <bits/stdc++.h>
using namespace std;
bool find(vector<int> &datas,int &goal,int &n){
  for(int i=0;i<n;i++){
    int maxi=n-1,mini=i+1;
    while (maxi>mini){
      int target=datas[i]+datas[maxi]+datas[mini];
      if (target==goal) return true;
      else if (target<goal) ++mini;
      else --maxi;
    }
  }
  return false;
}
int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,m,data,query;
    cin>>n>>m;
    vector<int> datas(n);
    for (int i=0;i<n;i++){
        cin>>data;
        datas[i]=data;
    }
    sort(datas.begin(),datas.end());
    while (m--){
        cin>>query;
        if (find(datas,query,n)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}