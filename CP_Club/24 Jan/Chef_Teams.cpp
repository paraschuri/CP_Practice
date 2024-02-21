#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
	int n;
	cin>>n;
	set<pair<int,int>> s1,s2;
	int sum1=0,sum2=0;
	for(int i=0;i<n;i++){
	    int a,b;
	    cin>>a>>b;
	    if(s1.size() == s2.size()){
	        if(!s2.empty() && a>(*s2.begin()).first){
	            s1.insert(*s2.begin());
	            sum1+=(*s2.begin()).second;
	            sum2-=(*s2.begin()).second;
	            s2.erase(s2.begin());
	            s2.insert({a,b});
	            sum2+=b;
	        }
	        else{
	            s1.insert({a,b});
	            sum1+=b;
	        }
	    }
	    else{
	        if(a<(*s1.rbegin()).first){
	            s2.insert(*s1.rbegin());
	            sum2+=(*s1.rbegin()).second;
	            sum1-=(*s1.rbegin()).second;
	            s1.erase(--s1.end());
	            s1.insert({a,b});
	            sum1+=b;
	        }
	        else{
	            s2.insert({a,b});
	            sum2+=b;
	        }
	    }
	    cout<<abs(sum1-sum2)<<endl;
	}
}