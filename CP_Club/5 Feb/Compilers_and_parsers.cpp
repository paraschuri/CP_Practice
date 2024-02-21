#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int cnt=0,n = s.size(),ans=0;
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]=='<'){
                st.push(s[i]);
            }
            else{
                if(!st.empty()){
                    cnt+=2;
                    st.pop();
                }
                else{
                    break;
                }
            }
            if(st.empty())ans=max(ans,cnt);
        }
        cout<<ans<<endl;
    }
}