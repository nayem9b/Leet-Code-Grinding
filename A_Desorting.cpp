#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define Faster ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);



int main(){
   Faster;
   int t;                  cin>>t;
   while(t--){
      int n;               cin>>n;
      vector<ll> a(n);
      for(int i=0;i<n;i++){
         cin>>a[i];
      }

      ll ans=LLONG_MAX;
      for(int i=1;i<n;i++){
         if(a[i]<a[i-1]){
            ans=0;
            break;
         }
         ans=min(ans,((a[i]-a[i-1])/2LL)+1LL);
      }
      
      cout<<ans<<endl;
   }
   return 0;
}
