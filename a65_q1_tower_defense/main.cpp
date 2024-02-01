#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,k,w,hp;
    //m is number of monsters
    //n is number of tiles
    //k is number of towers
    //w is tower's range
    map<int,int> positions_hp;
    cin>>n>>m>>k>>w;
    vector<int> positions(m);
    for (int i=0;i<m;i++) cin>>positions[i];
    for (int i=0;i<m;i++){
        cin>>hp;
        positions_hp[positions[i]]=hp;
    }
    vector<int> towerpositions(k);
    for (int i=0;i<k;i++) cin>>towerpositions[i];
    for (int &towerposition:towerpositions){
        for (int i=-w;i<=w;i++){ // check all position in range of attack
            //if out of range or there is no monster, pass this loop
            //else, attack
            if (towerposition+i>0 && towerposition+i<=n && positions_hp.find(towerposition+i)!=positions_hp.end()){
                if (positions_hp[towerposition+i]>0){
                    --positions_hp[towerposition+i];
                    break;
                }
            }
        }
    }
    int result=0;
    for (auto &x:positions_hp){
        result+=x.second;
    }
    cout<<result;
}
