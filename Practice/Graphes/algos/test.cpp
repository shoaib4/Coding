#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int x = 10;
    if((x>10 ? x++ : --x)<10){
        cout << "1";
    }
    if(x<10) cout << '2';
}