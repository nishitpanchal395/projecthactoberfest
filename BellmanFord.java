
//BellmanFord checks for negative cycles too.
class Solution
{
    static int[] bellman_ford(int N, ArrayList<ArrayList<Integer>> adj, int S)
    {
        // Write your code here
        int dist[]= new int[N];
        for(int i=0;i<N;i++)
         dist[i]=100000000;
        
        dist[S]=0;
        for(int i=0;i<=N-1;i++)
        {
            for(ArrayList<Integer> node:adj)
            {
                if(dist[node.get(0)] + node.get(2)< dist[node.get(1)])
                  dist[node.get(1)]=dist[node.get(0)]+node.get(2);
            }
        }
      
        return dist;
        
    }
}

//TC: O(N-1)*E
//SC: O(N)
