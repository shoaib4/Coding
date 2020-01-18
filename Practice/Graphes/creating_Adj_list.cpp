#include<iostream> 
#include<bits/stdc++.h>
using namespace std; 

void printAdjLink(map< int,set<int> > Adj){
    for(pair<int,set<int> > S : Adj){
        for(auto x : S.second){
            cout << x << " ";
        }
        cout << endl;
    }
}
void creatAdjList(int n,vector<int> A, vector<int> B){
    map<int,set<int> > Adj;
    for(int i=0;i<A.size();i++){
        Adj[A[i]].insert(B[i]);
    } 
    printAdjLink(Adj);
}

int main(){
    if( __cplusplus == 201103L ) std::cout << "C++11\n" ;
else if( __cplusplus == 19971L ) std::cout << "C++98\n" ;
else std::cout << "pre-standard C++\n" ;

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