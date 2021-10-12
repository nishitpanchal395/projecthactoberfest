// Word Break Medium
// Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary words.
// Note: From the dictionary B each word can be taken any number of times and in any order.


#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        unordered_map<string, int> dypr;
        int len = A.length();
        if(len == 0) return 1;
        if(dypr[A] !=0) return dypr[A];
        
        for(int i=1; i<=len;i++){
            int flag =0;
            string str = A.substr(0,i);
            for(int j=0; j<B.size();j++){
                
                if(str.compare(B[j]) == 0){
                    flag =1; break;
                }
            }
                if(flag == 1 and wordBreak(A.substr(i, len-i), B) == 1) return dypr[A]=1;
            }
            return dypr[A]= 0;
       
    }
};



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
