#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
	ll t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[31]={0};
	    for(ll i=0;i<n;i++)
	    cin>>a[i];
	    int b[32]={0};
	    
	    for(ll j=0;j<n;j++){
	    for(ll i=0;i<=31;i++){
	    
	    //this is wrong :  if(a[j]&(1<<j)!=0)
	           if((a[j] & (1<<i))!=0){
	               b[i]++;
	           }
	        }
	    }
	    
	    ll sum=0;
	    for(ll i=0;i<=31;i++){
	        ll k=b[i];cout<<b[i]<<endl;
	        ll ans=((k)*(k-1))/2;
	       sum +=pow(2,ans);
	        
	    }
	    cout<<sum<<endl;
	    
	    
	}
	return 0;
}
