graphNode *cloneGraph(graphNode *node)
{
    // Write your code here.
	graphNode* copy_node;
     unordered_map<graphNode* ,graphNode*> mp;
	 if(node)
	 {
		  copy_node= new graphNode(node->data);
		 mp[node] = copy_node;
	 }
	 queue<graphNode*> q;
	 q.push(node);


	 while(!q.empty())
	 {
		 auto temp = q.front();
		 q.pop();

		 for(auto nb:temp->neighbours)
		 {
			 if(mp.find(nb)==mp.end()) // not visisted
			 {
				 graphNode* c = new graphNode(nb->data);
				 mp[nb] = c; //mark visited
				 q.push(nb);
 			 }
			  mp[temp]->neighbours.push_back(mp[nb]);
		 }
	 }

	 return copy_node;
}
