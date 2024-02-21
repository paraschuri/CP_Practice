#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    string s;
    cin>>s;
    stack<char> st;
    for(int i=0;i<s.size();i++){
        if(!st.empty() && s[i]==st.top()){
            st.pop();
        }
        else{
            st.push(s[i]);
        }
    }
    if(st.size()<1){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}