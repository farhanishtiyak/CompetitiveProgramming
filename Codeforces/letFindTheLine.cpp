#include<bits/stdc++.h>
using namespace std;
#define  ll     long long

int main()
{
	ll t;
	cin >> t;
    //ll cnt = 0;
	
	ll lo = 1,hi = t,mid;
	while(lo<=hi)
	{
        //cnt++;
		mid = lo + ((hi-lo)/2);
        cout<<"? ";
		cout<<mid<<endl;
		cout<<flush;
		char ch ;
		cin>>ch;
		if(ch=='=') break;
		if(ch=='>') hi = mid-1;
		else lo = mid+1;
	}

	ll l , r, lm, mh, mid2=mid;

    //lo = 1, hi = t;
    //cout<<"Entering 1"<<endl;

	while(lo<=mid)
	{
        //cnt++;
		lm = lo+((mid-lo)/2);
        cout<<"? ";
		cout<<lm<<endl;
		cout<<flush;
		char ch ;
		cin>>ch;
		if(ch =='=') 
		{
			l = lm;
			mid = lm-1;
		}
		if(ch=='<') lo = lm+1;
		else mid = lm-1;
	}
    //cout<<"low = "<<lo<<" hi : "<<mid<<endl;
    //cout<<"entering 2"<<endl;

	while(mid2<=hi)
	{
        //cnt++;
		mh = mid2 + ((hi-mid2)/2);
        cout<<"? ";
		cout<<mh<<endl;
		cout<<flush;
		char ch ;
		cin>>ch;
		if(ch =='=') 
		{
			r = mh;
			mid2= mh+1;
		}
		if(ch=='>') hi  = mh-1;
		else mid2= mh+1;
	}
    //cout<<"low = "<<mid2<<" hi : "<<hi<<endl;

//cout<<cnt<<endl;
	ll ans = r-l+1;
    cout<<"! ";
	cout<<ans<<endl;
	cout<<flush;
}