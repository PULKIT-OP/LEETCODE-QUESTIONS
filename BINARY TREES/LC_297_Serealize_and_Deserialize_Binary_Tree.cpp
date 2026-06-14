// Question Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

// METHOD 1: Using PREORDER traversal

class Codec {
public:

    // Encodes a tree to a single string.
    void encode(TreeNode* root, string &ans){
        if(root == NULL){
            ans += "*,";
            return;
        }
        ans += to_string(root -> val) + ",";
        encode(root -> left, ans);
        encode(root -> right, ans);
    }
    string serialize(TreeNode* root) {
        string ans = "";
        if(root == NULL){
            ans += "*";
            return ans;
        }
        ans += to_string(root -> val) + ",";
        encode(root -> left, ans);
        encode(root -> right, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* decode(vector<string> &st, int &i){
        if(i >= st.size()){
            return NULL;
        }
        if(st[i] == "*"){
            i++;
            return NULL;
        }
        string s = st[i];
        int val = stoi(s);
        TreeNode* root = new TreeNode(val);
        i++;
        root -> left = decode(st, i);
        root -> right = decode(st, i);

        return root;
    }
    TreeNode* deserialize(string data) {
        vector<string> st;
        string curr = "";

        for(char ch : data){
            if(ch == ','){
                st.push_back(curr);
                curr = "";
            }
            else{
                curr += ch;
            }
        }
        int i = 0;
        TreeNode* root = decode(st, i);

        return root;
    }
};


// METHOD 2: Using LEVEL ORDER traversal

class Codec {
public:
    // Encodes a tree to a single string.
    void encode(TreeNode* root, string& ans) {
      // if root is NULL then just add * and return
        if (root == NULL) {
            ans += "*,";
            return;
        }
      // Now pure level order traversal
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            root = q.front();
            q.pop();
          // if root exist (means NOT NULL) then add it to string and push left right in queue
            if (root) {
                ans += to_string(root->val) + ",";
                q.push(root->left);
                q.push(root->right);
            } 
            // otherwise just push * in string
            else {
                ans += "*,";
            }
        }
    }
    string serialize(TreeNode* root) {
        string ans = "";
        encode(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
      // if provided string is NULL then return NULL
        if (data[0] == '*') {
            return NULL;
        }
      // Now extracting data from string 
        vector<string> st;
        string curr = "";

        for (char ch : data) {
          // if ',' then push the extracted string in st vector otherwise continue to collecct string in curr
            if (ch == ',') {
                st.push_back(curr);
                curr = "";
            } else {
                curr += ch;
            }
        }

      // Making root node with first character of string
        string s = st[0];
        int val = stoi(s);
        TreeNode* root = new TreeNode(val);
      // NOW PURE LEVEL ORDER TRAVERSAL
        queue<TreeNode*> q;
        q.push(root);

        int i = 1; // index to traverse in vector
        while (!q.empty()) {
            TreeNode* node = q.front();   // get front node
            q.pop();

          // check if index in boundary AND next string is valid
            if (i < st.size() && st[i] != "*") {
              // then extract next string and make a node out of it and push in queue for next level traversal
                string temp = st[i];
                int temp_val = stoi(temp);
                TreeNode* l = new TreeNode(temp_val);
                q.push(l);
                node->left = l;  // then attach it to left of parent node
            }
            i++;  // increment of index 
          // check if index in boundary AND next string is valid
            if (i < st.size() && st[i] != "*") {
               // then extract next string and make a node out of it and push in queue for next level traversal
                string temp = st[i];
                int temp_val = stoi(temp);
                TreeNode* r = new TreeNode(temp_val);
                q.push(r);
                node->right = r;  // then attach it to right of parent node
            }
            i++; // increment of index
        }

        return root;  // then at last return the ROOT node 
    }
};
