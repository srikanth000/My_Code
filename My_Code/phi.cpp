#include<bits/stdc++.h>
#include<cstdio>
#include <string.h>
#include <math.h>
#include <iostream> 

#include<cmath>    // std::cout
#include <algorithm>  
using namespace std;
#include<vector>
#define N 1000000
#define MAXN 1000000
int phi[MAXN + 1], prime[MAXN/10], sz=0;
vector<bool> mark(MAXN + 1);
/*long long int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

// A simple method to evaluate Euler Totient Function
long long int phi(unsigned int n)
{
    unsigned int result = 1;
    for (int i=2; i < n; i++)
        if (gcd(i, n) == 1)
            result++;
    return result;
}*/
int main()
{
	phi[1] = 1; 
   for (int i = 2; i <= MAXN; i++ ){
    if(!mark[i]){
        phi[i] = i-1;
        prime[sz++]= i;
    }
    for (int j=0; j<sz && prime[j]*i <= MAXN; j++ ){
        mark[prime[j]*i]=1;
        if(i%prime[j]==0){
            int ll = 0;int xx = i;
            while(xx%prime[j]==0)
            {
                           xx/=prime[j];
                           ll++;         
                       }
            int mm = 1;
            for(int k=0;k<ll;k++)mm*=prime[j];
            phi[i*prime[j]] = phi[xx]*mm*(prime[j]-1);
            break;
    }
        else phi[i*prime[j]] = phi[i]*(prime[j]-1 );
    }
}
	long long int t,c1;
	long long int c[1000000];
	memset(c,0,sizeof(c));
	scanf("%lld",&t);
	while(t--)
	{
		//printf("df\n");
		long long int n,v;
		c1=0;
		scanf("%lld",&n);
		for(long long int i=0;i<n;i++)
			for(long long int j=0;j<n;j++)
			{
				long long int s=(i+1)+(j+1);
				//if(c[s]==0)
				{
					c1=c1+phi[s];
					
				}
				//else
				
				
				//printf("(%lld,%lld)=%lld\n",i+1,j+1,s);

			}
			printf("%lld\n",c1);
	}
	
	return 0;
}
