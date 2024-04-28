#include <bits/stdc++.h>
using namespace std;
double w, maxv = 0.0,tmp;
int n;
class knapsack{
    public:
        double weight;
        double value;
        knapsack(){}
        knapsack(int we,int v){
            this->weight=w;
            this->value=v;
        }
        bool operator<(const knapsack &other)const{
            return (this->value/this->weight)<(other.value/other.weight);
        }
};
vector<knapsack> datas;
double heu(int no,double wleft){
    double ansv=0;
    for(int i=no;i>=0;--i){
        //can gain the entire piece
        if (wleft>datas[i].weight){
            wleft-=datas[i].weight;
            ansv+=datas[i].value;
        }else{
            ansv+=(wleft/datas[i].weight)*datas[i].value;
            return ansv;
        }
    }
    return ansv;
}
void recur(int no, double currentw, double currentv){
    if (currentw>w) return;
    maxv=max(maxv,currentv);
    if (no<0) return ;
    if (currentv+heu(no,w-currentw)<=maxv) return ;
    //consider this item
    recur(no-1,currentw+datas[no].weight,currentv+datas[no].value);
    //ignore it
    recur(no-1,currentw,currentv);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> w >> n;
    datas.resize(n);
    for(int i=0;i<n;++i){
        cin>>tmp;
        datas[i].value=tmp;
    }
    for(int i=0;i<n;++i){
        cin>>tmp;
        datas[i].weight=tmp;
    }
    sort(datas.begin(),datas.end());
    recur(n-1,0.0,0.0);
    cout<<fixed<<setprecision(4)<<maxv<<endl;
    //for(int i=0;i<n;++i) cout<<datas[i].value/datas[i].weight<<" ";
}