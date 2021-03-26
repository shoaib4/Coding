# Find the first +ev intger

Created: Mar 11, 2021 9:22 AM
Diff Rating: 6
Scaler Link: https://www.scaler.com/academy/mentee-dashboard/classroom/array-and-math-8d001a54-085f-491f-bd37-75819c5620fc/#cplus
Topic: Array

- code

    ```jsx
    int Solution::firstMissingPositive(vector<int> &A) {
        for(int i = 0 ; i<A.size(); i++){
            if(A[i] <= 0 || A[i] > A.size() || A[i] == i+1) continue;
            while(!(A[i] <= 0 || A[i] > A.size() || A[i] == i+1)){
                int temp = A[A[i]-1];
                if( temp == A[i]) break;
                A[A[i]-1] = A[i];
                A[i] = temp;
                
            }
        }
        for(int i = 0; i< A.size(); i++){
            if(A[i] != i+1) return i+1;
        }
        return A.size()+1;
    }
    ```

- imp notes
    - Dont have to move all he -ev numbers to the end
    - if A[i] <= 0 || A[i] > A.size()  then just skip
    - else keep puting the number in the right spot till the above condition fails
    - **** c if there is an infinet cycle Avoid that by adding A[i] = i+1**