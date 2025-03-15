
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* right;
    Node* left;
    Node(int val){
        data = val;
        right = left = NULL;
    }
};
void postorder(Node* root){
    if(root == NULL){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data;
}
void inorder(Node* root){
    if(root == NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
// isse bfs bhi bolte mere bhai 

void levelordertraversal(Node* root){
    //ek chota sa queue banaya hai jisme hamne pehle root push kara aur ek separator bananae ke liye null
    queue<Node*> q;
    q.push(root);
    q.push(NULL);// ye hai separator
    while(!q.empty()){//aagr queue empty nai toh loop on
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<< endl;//agar temp mein null ayaa hai isme matlab abb separator hai toh next level pe jaana uske enter maar meri jaan
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";//yahan pe data print hua 
        if(temp->left){
            q.push(temp->left);// here we traverse more deep and boom push into queue bitch
        }
        if(temp->right){
            q.push(temp->right);
        }
        }

    }
}
//making tree using bfs
Node* maketreebfs(){
    queue <Node*> q;
    int data;
    cout<<"enter root niggs";
    cin>>data;
    Node* root = new Node(data);
    q.push(root);
    if(data == -1){
        return NULL;
    }
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout<<"left mein daalo"<<temp->data<<"ke";
        int leftd;
        cin>>leftd;
        if(leftd != -1){
            temp->left = new Node(leftd);
            q.push(temp->left);
        }
        cout<<"right mein daalo"<<temp->data<<"ke";
        int rightd;
        cin>>rightd;
        if(rightd != -1){
            temp->right = new Node(rightd);
            q.push(temp->right);
        }
    }
    return root;
}

//height of tree

int height(Node* root){
    if(root == NULL){
        return 0;
    }
    else{
        int lefth = height(root->left);
        int righth = height(root->right);
        if(lefth<righth){
            return (righth+1);
        }
        else{
            return (lefth+1);
        }
    }
}

//diameter of tree this one uses O(n2)
int diameter(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftd=diameter(root->left);
    int rightd = diameter(root->right);
    int lefth = height(root->left);
    int righth = height(root->right);


    return max(max(leftd,rightd),lefth+righth);
}

// diameter but uses o(n)
pair<int,int> pairdiameter(Node* root){
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }
    pair <int,int> left = pairdiameter(root->left);
    pair<int,int> right = pairdiameter(root->right);
    int op1 = left.first;
    int op2 = right.first;
    int op3 = right.second + left.second;
    pair<int ,int > ans;
    ans.first = max(op1 , max(op2,op3));
    ans.second = max(left.second, right.second) + 1; 
    return ans;
}
// reverse level order
//balanced tree height(left)- height(right)<=1
 bool isbalanced(Node *root){
    if(root == NULL){
        return true;
    }
    bool left = isbalanced(root->left);
    bool right = isbalanced(root->right);

    bool diff = abs(height(root->left) - height(root->right))<= 1;
    if(left && right && diff){
        return true;
    }
    return false;
 }

void reversebfs(Node* root){
    queue<Node*> q;
    
}

Node* tree(Node* root) {
    int data;
    cout << "Enter data: ";
    cin >> data;
    root = new Node(data);
    if (data == -1) {
        return NULL;
    }
    cout << "Enter data for left child of " << data << ": ";
    root->left = tree(root->left);
    cout << "Enter data for right child of " << data << ": ";
    root->right = tree(root->right);
    return root;
}
//sum tree given node should = left +right
pair<bool, int> issumtree(Node* root) {
    if (root == NULL) {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    if (root->left == NULL && root->right == NULL) {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> lefta = issumtree(root->left);
    pair<bool, int> righta = issumtree(root->right);
    
    bool leftb = lefta.first;
    bool rightb = righta.first;
    int leftSum = lefta.second;
    int rightSum = righta.second;

    bool tot = (leftb && rightb) && (leftSum + rightSum == root->data);
    
    pair<bool, int> ans;

    if (tot) {
        ans.first = true;
        ans.second = root->data + leftSum + rightSum;
    } else {
        ans.first = false;
        ans.second = root->data;
    }

    return ans;
}
//zigzag traversal
vector<int> zigzag(Node* root){
    vector<int> res;
    if(root == NULL){
        return res;
    }
    queue<Node*> q;
    q.push(root);
    bool ltor = true;
    while(!q.empty()){
        int size = q.size();
        vector<int>  ans;
        for(int i=0;i<size;i++){
            Node* curr = q.front();
            q.pop();

            int flag = ltor ? i:size-i-1;
            ans[flag] = curr->data;
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
            for(auto i:ans){
                res.push_back(i);
            }
        }
    }
    return res;
}
//;eft traversal for boundary traversal 
void traverseleft(Node* root, vector<int> &ans){
    if(root == NULL || root->left == NULL && root->right==NULL){
        return ;
    }
    ans.push_back(root->data);
    if(root->left){
        traverseleft(root->left,ans);
    } 
    else{
        traverseleft(root->right,ans); 
    }
}
//right traversal for boundary
void traverseright(Node* root , vector<int> &ans){
    if(root == NULL || root->left == NULL && root->right==NULL){
        return ;
    }
    ans.push_back(root->data);
    if(root->right){
        traverseright(root->right,ans);
    }
}
// boundary traversal
//first go for left side then for leaf node then rigght from down
// vector<int> boundarytarversal(Node* root){
//     vector<int> ans;
//     if(root == NULL){
//         return ans;
//     }
//     ans.push_back(root->data);

// }
void traverseleaf(Node* root, vector<int> &ans){
    if(root == NULL){
        return ;
    }
    if(root->left == NULL && root->right){
        ans.push_back(root->data);
        return ;
    }
    traverseleaf(root->left, ans);
    traverseleaf(root->right,ans);
}
Node* createbt(){
        int n;
    int data;
    cout<<"Input number of nodes";
    cin>>n;
    Node* nigga = NULL;
    Node* node = NULL;
    for(int i=0;i<n;i++){
        cout<<"enter data and help ayush to make a gf";
        cin>>data;
        if(nigga == NULL){
            nigga = new Node(data);
        }
        else{
            Node* temp = nigga;
            while(true) {
                if(data < temp->data) {
                    if(temp->left == NULL) {
                        temp->left = new Node(data);
                        break;
                    }
                    else {
                        temp = temp->left;
                    }
                }
                else {
                    if(temp->right == NULL) {
                        temp->right = new Node(data);
                        break;
                    }
                    else {
                        temp = temp->right;
                    }
                }
            }
        }
    }
    return nigga;
}
int main(){
    // Node* nigga =maketreebfs();
    // Node* nigga =createbt();
    Node* nigga = NULL;
    tree(nigga);
    // createbt(nigga);
    // levelordertraversal(nigga);
    // cout<<diameter(nigga)<<endl;
    // cout<<pairdiameter(nigga).first;
    cout<<issumtree(nigga).first;
    // // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    // inorder(nigga);
    // levelordertraversal(nigga);
    // cout<< height(nigga);
    // postorder(nigga);
}
