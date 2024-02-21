class Solution {
public:
    string decodeString(string s) {
        vector<string> st;
        for(int i=0;i<s.size();i++){
            if(s[i]==']'){
                string temp = st.back();
                st.pop_back();
                int occ = stoi(st.back());
                st.pop_back();
                string changed = "";
                while(occ--)changed+=temp;
                st.push_back(changed);
                while(st.size()>1){
                    int n=st.size();
                    if(!isdigit(st[n-2][0])){
                        st[n-2]+=st.back();
                        st.pop_back();
                    }
                    else{
                        break;
                    }
                }
            }
            else if(s[i]!='['){
                if(isdigit(s[i])){
                    string temp ="";
                    temp+=s[i];
                    if(isdigit(s[i+1])){
                        temp+=s[i+1];
                        if(isdigit(s[i+2])){
                            temp+=s[i+2];
                        }
                    }
                    st.push_back(temp);
                    i+=temp.size()-1;
                }
                else{
                    string temp="";
                    int j=i;
                    while(j<s.size() && (s[j]>='a' && s[j]<='z')){
                        temp+=s[j++];
                    }
                    st.push_back(temp);
                    while(st.size()>1){
                        int n=st.size();
                        if(!isdigit(st[n-2][0])){
                            st[n-2]+=st.back();
                            st.pop_back();
                        }
                        else{
                            break;
                        }
                    }
                    i=j-1;
                }
            }
        }
        string ans ="";
        for(auto i: st)ans+=i;
        return ans;
    }
};