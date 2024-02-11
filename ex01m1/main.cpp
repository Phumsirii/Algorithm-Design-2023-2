#include <bits/stdc++.h>
using namespace std;
void place(int x1,int y1,int x2,int y2,int bx,int by){
    if(x1==x2 && y1==y2) return;
    int mx=(x1+x2)/2;
    int my=(y1+y2)/2;
    int type;
    //q2
    if (bx<=mx && by<=my){
        type=0;
        place(x1,y1,mx,my,bx,by);
        place(mx+1,y1,x2,my,mx+1,my);
        place(x1,my+1,mx,y2,mx,my+1);
        place(mx+1,my+1,x2,y2,mx+1,my+1);
    }
    //q1
    else if (bx>mx && by<=my){
        type=1;
        place(mx+1,y1,x2,my,bx,by);
        place(x1,y1,mx,my,mx,my);
        place(x1,my+1,mx,y2,mx,my+1);
        place(mx+1,my+1,x2,y2,mx+1,my+1);
    }
    //q3
    else if (bx<=mx && by>my){
        type=2;
        place(x1,my+1,mx,y2,bx,by);
        place(x1,y1,mx,my,mx,my);
        place(mx+1,y1,x2,my,mx+1,my);
        place(mx+1,my+1,x2,y2,mx+1,my+1);
    }
    //q4
    else if (bx>mx && by>my){
        type=3;
        place(mx+1,my+1,x2,y2,bx,by);
        place(x1,y1,mx,my,mx,my);
        place(mx+1,y1,x2,my,mx+1,my);
        place(x1,my+1,mx,y2,mx,my+1);
    }
    else return;
    cout<<type<<" "<<mx<<" "<<my<<"\n";
}
int main(){
    int l,x,y;
    cin>>l>>x>>y;
    cout<<(int)pow(l,2)/3<<"\n";
    place(0,0,l-1,l-1,x,y);
}