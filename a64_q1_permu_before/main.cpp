#include <bits/stdc++.h>

using namespace std;

map<int,int> ma;

void permu(int n,vector<int> &sol,int len, vector<bool> &used) {
  if (len < n) {
    for (int i = 0;i < n;i++) {
      bool found=(ma.find(i)!=ma.end());
      if (!used[i] && (!found || (found && used[ma[i]]))) {
        sol[len] = i;
        used[i] = true;
        permu(n,sol,len+1,used);
        used[i] = false;
      }
    }
  } else {
    for (int i = 0;i < n;i++) {
      cout << sol[i] << " ";
    }
    cout << "\n";
  }
}

int main() {
  int n,m,a,b;
  cin >> n >> m;
  for (int i = 0;i < m;i++) {
    cin >> a >> b;
    ma[b]=a;
  }

  vector<int> sol(n);
  vector<bool> used(n);
  permu(n,sol,0,used);

}
