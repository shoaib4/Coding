#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// 5
// 43 13 51 97 29
// 9 136
int subsetCoutInSumRange(vector<int> A, int B , int C,int start){
    if(start >= A.size()) return 0;
    //  *********** wrong code ************
    // int v =0;
    // if(A[start] >= B && A[start] <=C) v =1;
    // else if(A[start] > C) return 0;

    // return v + 
    //         subsetCoutInSumRange(A,B,C,start+1) +
    //         subsetCoutInSumRange(A,B-A[start],C-A[start],start+1); 

    // ********** wrong answer too shit bro code *********
    // if(A[start] > C){
    //     return subsetCoutInSumRange(A,B,C,start+1);
    // }else{
    //     return 1 + 
    //         subsetCoutInSumRange(A,B,C,start+1) +
    //         subsetCoutInSumRange(A,B-A[start],C-A[start],start+1);
    // }

    // correct ans 
    int k = (1<<A.size()) -1;
    int count = 0;
    for(int j = 0;j <= k; j++){
        int mask = j;
        int index = A.size()-1;
        int sum = 0;
        while(mask > 0){
            if(mask & 1){
                sum += A[index];
            }
            index--;
            mask = mask >> 1;
        }
        if(sum >= B && sum <= C) {count++;};
    }
    return count;
}

bool isPrime(int n){
    for(int i = 2;i*i <= n; ++i){
        if(n % i == 0) return false;
    }
    return true;
}
int main(){
    int n; cin >> n;
    vector<int> arr;
    while(n--){
        int x; cin >> x;
        arr.push_back(x);
    }
    int L,R;
    cin >> L; cin >> R;
    cout << "total ::::: " << endl; 
    int ans = subsetCoutInSumRange(arr,L,R,0);
    cout << ans << endl;
    cout << "compsit ::::: " << endl; 
    vector<int> composits;
    for(int a : arr){
        if(!isPrime(a)){
            composits.push_back(a);
        }
    }
    ans -= subsetCoutInSumRange(composits,L,R,0);
    cout << ans << endl;
}