#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <string>
using std::string;
void change_1(std::stack<std::vector<std::queue<int>>> &a, int from, int to){
    std::stack<std::vector<std::queue<int>>> tmp;
    int n=a.size();
    while (!a.empty()){
        std::vector<std::queue<int>> tmp2=a.top();
        for(std::queue<int> &q:tmp2){
            int n=q.size();
            while (n--){
                int intt=q.front();
                q.pop();
                if(intt==from) q.push(to);
                else q.push(intt);
            }
        }
        a.pop();
        tmp.push(tmp2);
    }
    while (!tmp.empty()){
        a.push(tmp.top());
        tmp.pop();
    }
}
void change_2(std::map<string, std::pair<std::priority_queue<int>, int>> &a, int from, int to){
    for(auto &x:a){
        std::pair<std::priority_queue<int>, int> &tmp=x.second;
        if (tmp.second==from) tmp.second=to;
        std::priority_queue<int> &tmp2=tmp.first;
        std::priority_queue<int> tobreplaced;
        while(!tmp2.empty()){
            int intt=tmp2.top();
            if (intt==from) tobreplaced.push(to);
            else tobreplaced.push(intt);
            tmp2.pop();
        }
        std::swap(tobreplaced,tmp2);
    }
}
void change_3(std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> &a, int from, int to){
    std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> result;
    for (auto&x:a){
        std::list<int> list_result;
        for(int i:x.first){
            if (i==from) list_result.push_back(to);
            else list_result.push_back(i);
        }
        std::map<int,std::pair<int,string>> map_result;
        for(auto&y:x.second){ //inside the map
            int map_key,map_result_first;
            if (y.first==from) map_key=to;
            else map_key =y.first;
            if (y.second.first==from) map_result_first=to;
            else map_result_first=y.second.first;
            map_result[map_key]=make_pair(map_result_first,y.second.second);
        }
        result.insert(make_pair(list_result,map_result));
    }
    std::swap(a,result);
}
#endif