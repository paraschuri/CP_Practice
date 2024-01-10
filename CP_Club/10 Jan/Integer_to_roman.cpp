class Solution {
public:
    string intToRoman(int num) {
        // map<int,string> mp={
        //     1:"I",
        //     2:"I",
        //     3:"III",
        //     4:"IV",
        //     5:"V",
        //     6:"VI",
        //     7:"VII",
        //     8:"VIII",
        //     9:"IX",
        // }
        string ans="",s=to_string(num);
        int len=s.size();
        for(int i=0;i<len;i++){
            int dig = s[i]-'0';
            if(dig>=5 && dig<9){
                switch(len-i){
                    case 1:
                        ans+="V"+string(dig-5,'I');
                        break;
                    case 2:
                        ans+="L"+string(dig-5,'X');
                        break;
                    case 3:
                        ans+="D"+string(dig-5,'C');
                        break;
                }
            }
            else if(dig==4){
                switch(len-i){
                    case 1:
                        ans+="IV";
                        break;
                    case 2:
                        ans+="XL";
                        break;
                    case 3:
                        ans+="CD";
                        break;
                }
            }
            else if(dig==9){
                switch(len-i){
                    case 1:
                        ans+="IX";
                        break;
                    case 2:
                        ans+="XC";
                        break;
                    case 3:
                        ans+="CM";
                        break;
                }
            }
            else{
                switch(len-i){
                    case 1:
                        ans+=string(dig,'I');
                        break;
                    case 2:
                        ans+=string(dig,'X');
                        break;
                    case 3:
                        ans+=string(dig,'C');
                        break;
                    case 4:
                        ans+=string(dig,'M');
                        break;
                }
            }
        }
        return ans;
    }
};