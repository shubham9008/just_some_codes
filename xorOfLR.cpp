#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mp make_pair
#define pb push_back
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fr(i,a,b) for(ll i=a;i>b;i--)
#define debug(x) cout << '>' << #x << ':' << x << endl;

/*finding max xor of 2 numbers between l & r*/

int csb(int x){
	ll ans=0;
	while(x/2!=0){
		x=x/2;	
		ans++;
	}
	return ans;
}


int main(){

while(1){
	ll l,r;
	cin>>l>>r;ll ans=0;ll msb=csb(r);ll lsb=csb(l);
	if(msb!= lsb){
		for(int i=0;i<=msb;i++){
			ans+=pow(2,i);
		}
	}
	else{
		ll pep=l^r;
    	int k = (int)(log2(pep));//finding highest set bit posn
		for(int i=0;i<=k;i++){
		ans+=pow(2,i);
		}
	}
	cout<<ans<<endl;
}
	return 0;
}


