/*Hello everyone!! I am Pratyush and below is C++ code to find the prime factors of an inputed number n using Sieve of Eratosthenes. It is an efficient way to find the prime factors.

In this we will first find all prime numbers before n, then we will assign a vector of pairs having first element as integer and second as bool, second bool element will help us to check whether a number is prime or not.

After that except 2 we will remove all even numbers and then multiples of other numbers like 3, 5, 7 etc will be assigned false as they are not prime. This assignation of false to the multiples of a number i will start from i*i because before it, its other multiples will already be falsed by smaller primes

by this we will find all primes before n and then we will one by one check if that number is divisible by those primes, if it is divisible, we will start the checking loop again from beginning because it is possible that number n is again divisible by that same prime number

At last we will show all primes that perfectly divided n */

#include<bits/stdc++.h>

using namespace std;

void prime_factorisation( vector<pair<int, bool>> primes , long long int n ) 
{
	primes.push_back(make_pair(2, true));
	
	long long int temp=n;
	
	vector<int> factors;
	
	for(long long int i=3; i<=n ; i+=2){
		primes.push_back(make_pair(i, true));    //assigning all odd number(except 1) with 2 to this vector
		}
		
	for(long long int i=3; i<=floor(sqrt(n)); i+=2){
		if(primes[ceil(i/2)].second==true){
		
			for(long long int j=i*i; j<n; j+=i){        // loop will start from i*i as mentioned in above explanation
				primes[ceil(j/2)].second=false;     // assigning multiples of primes as false
				}
			}
		}
		
	for(long long int i=0; i<primes.size(); i++){
		if(temp%primes[i].first==0 and primes[i].second==true){   // checking if these primes divide n
			factors.push_back(primes[i].first);
			temp=temp/primes[i].first;
			i=-1;                                          // i=-1 to run the loop again from start
			}
		else continue;
		}
		
	cout<<endl<<"prime factorisation of "<< n << " is : ";
	
	if(factors.empty()==0){
		for(long long int i=0; i<factors.size(); i++){
		
			if(i!=factors.size()-1){
				cout<<factors[i]<<" *";                         //showing the prime factors
			}
			else cout<<factors[i]<<endl;
		}
	}
		
	if(factors.empty()==1){ 
			cout<<n<<endl;                                         // if number is itself its prime factor
			}
	
	cout<<endl;
}
			

int main()
{
	vector<pair<int, bool>> v;
	long long int n;
    
	cout<<"enter the number whose prime factorisation you want!!"<<endl;
	cin>>n;
    
	prime_factorisation( v, n );
	return 0;
    
}
