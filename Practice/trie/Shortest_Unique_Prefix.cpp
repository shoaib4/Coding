#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct TriNode{
    vector<TriNode*> alphabets;
    int count;
    TriNode() {
        count = 0;
        for(int i = 0;i<26;i++) alphabets.push_back(NULL);
    }
};
void pushToDict(string s,TriNode* Head){
    
    for(int i = 0;i <s.size();i++){
        // Head ->count += 1;
        TriNode* curr = Head->alphabets[(int)(s[i]-'a')];
        if(curr == NULL){
            Head->alphabets[(int)(s[i]-'a')] = new TriNode();
            curr = Head->alphabets[(int)(s[i]-'a')];
        }
        Head ->count += 1;
        Head = curr;
    }
}
void creatDictionary(vector<string> &A,TriNode* Head){
    for(string s : A){
        pushToDict(s,Head);
    }
}
string getPrefex(string s,TriNode* Head){
    string ans = "";
    for(int i = 0;i <s.size();i++){
        TriNode* curr = Head->alphabets[(int)(s[i]-'a')];
        ans = ans + s[i] ;
        // cout << s[i] << " -- "<< curr->count << endl; 
        if(curr->count == 1){
           break; 
        }
        Head = curr;
    }
    return ans;
}
vector<string> Solution(vector<string> &A) {
    TriNode* Head = new TriNode();
    creatDictionary(A,Head);
    vector<string> preifixArray;
    for(string s : A){
        // cout << "------------" << endl;
        preifixArray.push_back(getPrefex(s,Head));
    }
    return preifixArray;
}
