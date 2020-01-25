
// You are given an integer N. You have to smallest 
// multiple of N which consists of digits 0 and 1 only. 
// Since this multiple could be large, return it in form of a string.

// Note:

// Returned string should not contain leading zeroes.
// For example,

// For N = 55, 110 is smallest multiple consisting of digits 0 and 1.
// For N = 2, 10 is the answer.

// ************************ solution ******************
// simple queue sloution will not work 
// u neew to store "0" and "1" and node leve and recompute the arr at the end of solution
// obesly will store "0" and "1" in arr and will also maintain parent array for final tracking
#include <iostream>
#include <bits/stdc++.h>
#include <chrono> 
using namespace std;
using namespace std::chrono;
string toString(int a){
    string s = "";
    while(a){
        if(a&1){
            s = "1" + s ;
        }else{
            s = "0" + s ; 
        }
        a /= 2;
    }
    return s;
}
string Solution(int A) {
    queue <int> Q;
    vector<int> reminder(A,0);
    Q.push(1);
    reminder[1] = 1;
    if(A == 1) return "1";
    cout << "start :: " << endl;
    vector<char> digit(A,-1);
    vector<int> parent(A,-1);
    digit[1] ='1';
    int size = 1;
    int loopCOunt = 0;
    while(1){
        loopCOunt++;
        int top = Q.front();
        if(top == 0 ){
            string s = "";
            int curr = top;
            while(curr != -1){
                s = digit[curr] + s;
                curr = parent[curr];
            }
            return s;
        }
        Q.pop();
        int mod0 = (top*10)%A;
        int mod1 = (top*10+1)%A;
        if(reminder[mod0] != 1){
            reminder[mod0] = 1;
            Q.push(mod0);
            digit[mod0] = '0';
            parent[mod0] = top;
            size++;
        }
        if(reminder[mod1] != 1){
            reminder[mod1] = 1;
            Q.push(mod1);
            digit[mod1] = '1';
            parent[mod1] = top;
            size++;
        }
    }
}

int main(){
    int x ;
    cin  >> x;
    auto start = high_resolution_clock::now(); 
    cout << Solution(x)<< endl;
    auto stop = high_resolution_clock::now(); 
    cout << "time taken "<< duration_cast<microseconds>(stop - start).count()/1000000 << endl;
    string sss = "100011011100100111101011"; 
    cout << sss.size() << endl; 
    sss = "1101110101010110111101011010110101001"; 
    cout << sss.size() << endl; 
}