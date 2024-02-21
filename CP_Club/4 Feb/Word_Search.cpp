int drow[]={0,1,-1,0},dcol[]={1,0,0,-1};
class Solution {
public:
    bool solve(int i,int j,int k,vector<vector<char>>& board, string &s){
        if(s[k]!=board[i][j])return false;
        if(k==s.size()-1)return true;
        int ans=0;
        for(int x=0;x<4;x++){
            int nr = drow[x]+i, nc = dcol[x]+j;
            if(nr>=0 && nr<board.size() && nc>=0 &&  nc<board[0].size() && board[nr][nc]!='$'){
                board[i][j]='$';
                ans |= solve(nr,nc,k+1,board,s);
                board[i][j]=s[k];
            }
        }
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()==1 && board[0].size()==1 && word.size()==1){
            return board[0][0]==word[0];
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(solve(i,j,0,board,word)){
                    return true;
                }
            }
        }
        return false;
    }
};