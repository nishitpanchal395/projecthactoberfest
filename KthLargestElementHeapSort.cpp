#include <iostream>
using namespace std;
 
vector<int> solve(vector<int> &A, int B) {
    
    priority_queue <int, vector<int>, greater<int>> gq;
    int n = A.size();
    for( int i = 0 ; i < n ; i++){
        gq.push(i);
    }
    vector<int>ans;
    while(B){
        B--;
        int x = gq.top();
        gq.pop();
        ans.push_back(x);
    }
    return ans;
    
}
// Driver program
int main()
{   
    int n; cin>>n;
    vector<int>A(n),ans;

    for(int i = 0;  i < n; i++)
        cin>>A[i];

    int B; cin>>B;

    ans = solve(A,B);
    
    for(int i = 0;  i < n; i++)
        cout<<ans;
    return 0;
}
