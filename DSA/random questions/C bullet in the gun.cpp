/*#include<bits/stdc++.h>
using namespace std;
int main()
{   ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
            {
    long    long n,h,k;
cin>>n>>h>>k;
vector<long long>a(n);

for(auto&x:a)
cin>>x;

sort(a.rbegin(),a.rend());

vector<long long>pr(n);
pr[0]=a[0];

for(int i=1;i<n;i++)
pr[i]=pr[i-1]+a[i];

long    long    global=pr[n-1];
if(global>=h)
{
for(int i=0;i<n;i++)
{
if(pr[i]>=h)
{
cout<<i+1<<"\n";
break;
}
}
continue;
}
long    long    full=h/global;
long    long    rem=h%global;

if(rem==0)
{
long    long    ans=full*n+(full-1)*k;
cout<<ans<<"\n";
}
else
{
long    long    ans=full*(n+k);

for(int i=0;i<n;i++)
{
if(pr[i]>=rem)
{
ans+=i+1;
break;
}
}

cout<<ans<<endl;
}
}
}*/




#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int tt=1;
	cin>>tt;
	while(tt--) {
        ll n,h,k,sum=0;
        cin>>n>>h>>k;
        vector<ll> v(n);
        for(int i=0;i<n;i++) {
            cin>>v[i];
            sum+=v[i];
        }
 
        ll cnt=(sum+h-1)/sum;
        ll fix=(cnt-1)*(n)+(cnt-1)*(k);
        ll rem=h%sum;
        if(rem==0)rem=sum;
 
        vector<ll> pre=v;
        for(int i=1;i<n;i++) {
            pre[i]=min(pre[i],pre[i-1]);
        }
        ll mx=0,add=n;
        for(int i=n-1;i>=0;i--) {
            // if(i==0)cout<<sum<<" "<<rem<<" "<<mx<<endl;
            if(sum>=rem || sum-pre[i]+mx>=rem)add=i+1;
            sum-=v[i];
            mx=max(mx,v[i]);
        }
        cout<<fix+add<<"\n";
    }
    return 0;
}