#include<bits/stdc++.h>
using namespace std;

int main(){
int m,n,k;
cin>>m>>n;
int g=(2*m)-2;
k=(2*m)-2;

for(int i=1;i<=m;i++){
   
   for(int p=1;p<=i-1;p++){
       cout<<" ";
   }
   int flag=0;
   int j=i;
   while(j<=n){
      
      if(flag==0){
          if(i==1){
           
              while(j<=n){

              
              cout<<j;
          for(int q=0;q<k;q++){
              cout<<" "; 

          }
          j+=k;
              }
          }else{

          
          cout<<j;
          for(int q=0;q<k-1;q++){
              cout<<" "; 
          }
          flag=1;
           j+=k;
           }
      } else {

           if(i==1 || i==m){
          for(int r=0;r<g-k;r++){
                cout<<" ";
            }
            flag=0; 
            j+=g-k;
        }else{

        
            cout<<j;
            for(int r=0;r<g-k-1;r++){
                cout<<" ";
            }
            flag=0; 
            j+=g-k;
        }
      } 


   }

   cout<<endl;
     k-=2;
}

return 0;
}