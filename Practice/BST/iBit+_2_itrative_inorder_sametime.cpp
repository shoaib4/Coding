#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
int Solution(TreeNode* A, TreeNode* B) {
stack<TreeNode*> sA;
    stack<TreeNode*> sB;
    sA.push(A);
    sB.push(B);
    int ans = 0;
    while(!(sB.empty() || sA.empty() )){
        TreeNode* currA = sA.top();
        TreeNode* currB = sB.top();
        while(currA -> left != NULL){
            TreeNode* p =  currA -> left;
            sA.push(p);
            currA->left = NULL;
            currA = p;
        }
        currA = sA.top();
        
        while(currB -> left != NULL){
            TreeNode* p =  currB -> left;
            sB.push(p);
            currB->left = NULL;
            currB = p;
        }
        currB = sB.top();
        
        if(currA->val == currB->val){
            ans += currA->val;
            sA.pop();
            if(currA -> right) sA.push(currA -> right);
            sB.pop();
            if(currB -> right) sB.push(currB -> right);        
        }else if(currA->val > currB->val){
            sB.pop();
            if(currB -> right != NULL) {sB.push(currB -> right);}
        }else{
            sA.pop();
            if(currA -> right) sA.push(currA -> right);
        }
        
    }
    return ans;
}