#include<iostream> 
#include<bits/stdc++.h>
using namespace std; 
void creatAdjList(int n,vector<int> E1, vector<int> E2){
    
    map<int,set<int>> Adj;
}

int main(){
    int n;
    int e;
    cin >> n; cin >> e; 
    vector<int> E1;
    vector<int> E2;
    for(int i =0;i<e;i++){
        int x,y;
        cout << "Edge connection between :: ";
        cin >> x;cin >> y;
        E1.push_back(x);E2.push_back(y);
    }
    creatAdjList(n,E1,E2);
    return 0;
}