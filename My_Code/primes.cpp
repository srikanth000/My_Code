#include <bits/stdc++.h>
using namespace std;
int a[100000];
void SieveOfEratosthenes(long long int x,long long int y)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[y+1];
    memset(prime, true, sizeof(prime));

    for (long long int p=2; p*p<=1000000; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=y; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
     int c=0,c1=0,prev=0;
    for (long long int p=x; p<=y; p++)
    {
       
       
          if(prime[p])
       	 printf("%d\n",p);
      }
}

// Driver Program to test above function
int main()
{
    int n = 30;
    int t;
    scanf("%d",&t);
    while(t--)
    {
           long long int x,y;
            scanf("%lld%lld",&x,&y);
            SieveOfEratosthenes(x,y);
    }   
    return 0;
}