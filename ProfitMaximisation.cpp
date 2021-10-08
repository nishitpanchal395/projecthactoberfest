#include <iostream>
using namespace std;
 
int solve(vector<int> &A, int B) {
    priority_queue<int, vector<int>> pq;
    int n = A.size();
    
    for(int i = 0 ; i < n ; i++){
        pq.push(A[i]);
    }
    int sum = 0;
    while(B--){
        int x  = pq.top();
        sum+=x;
        pq.pop();
        pq.push(x-1);
    }
    return sum;
}


int main()
{   
    int n; cin>>n;
    vector<int>A(n);

    for(int i = 0;  i < n; i++)
        cin>>A[i];

    int B; cin>>B;

    cout<<solve(A,B)<<"\n";

    return 0;
}
