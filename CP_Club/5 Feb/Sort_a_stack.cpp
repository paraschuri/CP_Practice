void solve(int a,stack<int>& s){
    if(s.empty() || a>=s.top()){
        s.push(a);
        return;
    }
    int x = s.top();
    s.pop();
    solve(a,s);
    s.push(x);
}
void SortedStack :: sort()
{
   //Your code here
   if(s.empty())return;
   int a = s.top();
   s.pop();
   sort();
   solve(a,s);
}