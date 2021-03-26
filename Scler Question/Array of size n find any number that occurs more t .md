# Array of size n find any number that occurs more that n/3 times

Created: Mar 11, 2021 9:16 AM
Diff Rating: 6
Scaler Link: https://www.scaler.com/academy/mentee-dashboard/classroom/array-and-math-8d001a54-085f-491f-bd37-75819c5620fc/#cplus
Topic: Array, Math

- Question

    **N/3 Repeat Number**

    You're given a read only array of n integers. Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space.

    If so, return the integer. If not, return -1.

    If there are multiple solutions, return any one.

    **Example :**

    ```
    Input : [1 2 3 1 1]
    Output : 1
    1 occurs 3 times which is more than 5/3 times.
    ```

- code

    ```jsx
    #define For for(int i =0; i<A.size(); i++)
    struct ele{
      int num = INT_MAX;
      int freq = 0;
    };
    int Solution::repeatedNumber(const vector<int> &A) {
        ele f;
        ele s;
        For{
            if(A[i] == f.num){
                f.freq++;
            }else if(A[i] == s.num){
                s.freq++;
            }else if(f.freq == 0){
                f.num = A[i];
                f.freq++;
            }else if(s.freq == 0){
                s.num = A[i];
                s.freq++;
            }else{
                f.freq--;
                s.freq--;
            }
        }
        int ans = f.num;
        int count = 0;
        For{
            if(A[i] == ans){
                count++;
            }
        }
        if(count > A.size()/3)  return ans;
        ans = s.num;
        count = 0;
        For{
            if(A[i] == ans){
                count++;
            }
        }
        if(count > A.size()/3)  return ans;
        return -1;
        
    }
    ```

- imp note
    - if 3 different number remove them
    - store 2 number and keep processing on others
    - **at the end answer counld be in any of the 2 stored numbers**