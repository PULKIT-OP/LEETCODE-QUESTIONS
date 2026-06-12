// Question Link: https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

// METHOD 1: 

class Solution {
	public:
	vector<int> topView(Node *root) {
		// code here
		vector<int> result;
		if (root == NULL) {
			return result;
		}
		map<int, int> mp;
		queue<pair<int, Node*>> q; // -> horizontal dist -> Node
		q.push({0, root});
		
		while (!q.empty()) {
			pair<int, Node*>temp = q.front();
			q.pop();
			int hor = temp.first;
			root = temp.second;
			if (root -> left) {
				q.push({hor - 1, root -> left});
			}
			if (mp.find(hor) == mp.end()) {
				mp[hor] = root -> data;
			}
			if (root -> right) {
				q.push({hor + 1, root -> right});
			}
		}
		
		for (auto &i : mp) {
			result.push_back(i.second);
		}
		
		return result;
	}
};
