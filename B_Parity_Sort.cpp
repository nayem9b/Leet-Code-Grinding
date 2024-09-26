#include <bits/stdc++.h>
using namespace std;
int main(){
   int t;                  cin>>t;
   while(t--){
      int n;               cin>>n;
      vector<int> a(n);
      for(int i=0;i<n;i++){
         cin>>a[i];
      }

      vector<bool> isOdd(n,false);
      vector<int> even,odd;
      for(int i=0;i<n;i++){
         if(a[i]%2==1){
            isOdd[i]=true;
            odd.push_back(a[i]);
         }
         else{
            even.push_back(a[i]);
         }
      }

      sort(even.begin(),even.end(),greater<int>());
      sort(odd.begin(),odd.end(),greater<int>());

      for(int i=0;i<n;i++){
         if(isOdd[i]){
            a[i]=odd.back();
            odd.pop_back();
         }
         else{
            a[i]=even.back();
            even.pop_back();
         }
      }


      if(is_sorted(a.begin(),a.end())){
         cout<<"YES"<<endl;
      }
      else{
         cout<<"NO"<<endl;
      }


   }
   return 0;
}
