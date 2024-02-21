class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int> ans;
    	queue<Node*> q;
    	q.push(root);
    	int f = 0;
    	while(!q.empty()){
    	    int a = q.size();
    	    vector<int> temp;
    	    while(a--){
    	        Node* node = q.front();
    	        q.pop();
    	        if(node->left)q.push(node->left);
    	        if(node->right)q.push(node->right);
    	        temp.push_back(node->data);
    	    }
    	    if(f)reverse(temp.begin(),temp.end());
    	    f^=1;
    	    for(auto i: temp)ans.push_back(i);
    	}
    	return ans;
    }
};