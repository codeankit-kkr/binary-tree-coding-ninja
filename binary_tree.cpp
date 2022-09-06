#include <bits/stdc++.h>
#include<queue>

using namespace std;

template <typename T>
class Node {
   public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template<class t>
struct btree{
    t data;
    btree* left;
    btree* right;

    btree(t dat){
        data = dat;
        left = NULL;
        right  = NULL;
    }
    ~btree(){
        delete left;
        delete right;
    }
};

btree<int>* takeinput(){
    cout<<"Enter data: "<<endl;
    int rdata;
    cin>>rdata;

    if(rdata==-1){
        return NULL;
    }
    btree<int>* root = new btree<int>(rdata);
    // root->data = rdata;
    btree<int>* left = takeinput();
    btree<int>* right = takeinput();
    root->left = left;
    root->right = right;
    return root;
}

void printtree(btree<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" : ";
    if(root->left){
        cout<<"L -> "<<root->left->data;        
    }
    if(root->right){
        cout<<" R -> "<<root->right->data;
    }
    cout<<endl;
    printtree(root->left);
    printtree(root->right);
}

btree<int>* levelwiseinput(){
    cout<<"Enter root data : "<<endl;
    int rdata;
    cin>>rdata;
    if(rdata==-1){
        return NULL;
    }
    btree<int>* root = new btree<int>(rdata);
    queue<btree<int>*> q;
    q.push(root);
    while(!q.empty()){
        btree<int>* roota = q.front();
        q.pop();
        int l;
        cout<<"Enter left data of "<<roota->data<<endl;
        cin>>l;
        if(l!=-1){
            btree<int>* left = new btree<int>(l);
            q.push(left);
            roota->left = left;
        }
        int r ;
        cout<<"Enter right data of "<<roota->data<<endl;
        cin>>r;
        if(r!=-1){
            btree<int>* right = new btree<int>(r);
            q.push(right);
            roota->right = right;
        }
    }
    return root;
}

void printlevelwise(btree<int>* root){
    if(root==NULL){
        return;
    }
    
    queue<btree<int>*> q;
    q.push(root);
    // btree<int> * ide = new btree<int>(-1);
    // q.push(ide);
    while(!q.empty()){
        btree<int>* roota = q.front();
        // if(roota != ide)        
            cout<<roota->data<<" : ";
        
        // else if(roota == ide)
        // {
        //     cout << endl;
        //     q.push(ide);            
        // }        
        q.pop();
        // if(roota != ide)
        // {
        if(roota->left!=NULL){
            
            q.push(roota->left);
        }
        else{
            // cout<<"L : "<<-1;
        }

        if(roota->right!=NULL){

            // cout<<"R : "<<roota->right->data;
            q.push(roota->right);
        }
        else{
            // cout<<"R : "<<-1;
        }
        // cout<<endl;
        // }
        
    }
}

int countAllnodes(btree<int>* root){
    if(root==NULL){
        return 0;
    }
    int l = countAllnodes(root->left);
    int r = countAllnodes(root->right);

    return l + r + 1;
}

int ispresent(btree<int>* root,int key){
    if(root==NULL){
        return 0;
    }
    if(root->data == key){
        return 1;
    }
    int k = ispresent(root->left,key);
    int m = ispresent(root->right,key);
    if(k==1 || m==1){
        return 1;
    }
    else{
        return 0;
    }
}

int height(btree<int>* root){
    if(root==NULL){
        return 0;
    }
    int l = height(root->left);
    int r = height(root->right);
    if(l>=r){
        return l+1;
    }
    else {
        return r+1;
    }
}


void printZigZag(btree<int>* root){
    stack<btree<int>*> st1,st2;
    st1.push(root);
    while(1){
        if(st1.empty() && st2.empty()){
            break;
        }
        btree<int>* top = st1.top();
        // st1.pop();
        while(!st1.empty()){
            if(top->left){

            st2.push(top->left);
            }
            if(top->right){
                
            st2.push(top->right);
            }
            cout<<top->data<<" ";
            st1.pop();

            if(!st1.empty()){
                top = st1.top();
            }
        }cout<<endl;

        btree<int>* top2 = st2.top();
        while(!st2.empty()){
            if(top2->right){
                
            st1.push(top2->right);
            }
            if(top2->left){

            st1.push(top2->left);
            }
            
            cout<<top2->data<<" ";
            st2.pop();
            if(!st2.empty()){
                top2 = st2.top();
            }
        }cout<<endl;
    }
}

void reverselevel(btree<int>* root){
    if(root==NULL){
        return;
    }
    
    queue<btree<int>*> q;
    q.push(root);
    while(!q.empty()){
        btree<int>* roota = q.front();
        q.pop();
        cout<<roota->data<<"  ";
        if(roota->right!=NULL){

            // cout<<"R : "<<roota->right->data;
            q.push(roota->right);
        }
        else{
            // cout<<"R : "<<-1;
        }
        if(roota->left!=NULL){

            // cout<<"L : "<<roota->left->data;
            q.push(roota->left);
        }
           
        
    }
}

btree<int>* pretotree(int* pre ,int* inor ,int preS,int preE,int inS,int inE){
    if(inS>inE){
        return NULL;
    }
    int data = pre[preS];
    int index = -1;
    for(int i =inS;i<=inE;i++){
        if(inor[i]==data){
            index=i;
            break;
        }
    }
    
    btree<int>* root=new btree<int>(data);
    int inLS = inS;
    int inLE = index-1;
    int preLS = preS+1;
    int preLE = preLS+inLE-inLS;
    int inRS = index+1;
    int inRE = inE;
    int preRS = preLE+1;
    int preRE = preE;
    btree<int>* leftchild = pretotree(pre,inor,preLS,preLE,inLS,inLE);
    btree<int>* rightchild = pretotree(pre,inor,preRS,preRE,inRS,inRE);
    root->left=leftchild;
    root->right=rightchild;

    return root;
}

btree<int>* postotree(int * post,int * inor,int inS,int inE,int postS,int postE){
    if(inS>inE){
        return NULL;
    }
    int rdata = post[postE];
    int index = -1;
    for(int i = inS;i<=inE;i++){
        if(inor[i]==rdata){
            index= i;
            break;
        }
    }
    btree<int>* root = new btree<int>(rdata);
    int inRS = index+1;
    int inRE = inE;
    int postRE = postE-1;
    int postRS = postRE-(inRE-inRS);
    int inLS = inS;
    int inLE = index -1;
    int postLE = postRS-1;
    int postLS = postLE-(inLE-inLS);
    root->left = postotree(post,inor,inLS,inLE,postLS,postLE);
    root->right = postotree(post,inor,inRS,inRE,postRS,postRE);

    return root;

}

int diameter(btree<int>* root){
    if(root==NULL){
        return 0;
    }
    int option1 = height(root->left)+height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);
    return max(option1,max(option2,option3));
}

pair<int,int> minandmax(btree<int>* root){
    if(root==NULL){
        return make_pair(100000,-100000);
    }
    // int k = root->data;
    
    

    pair<int,int> mp1 = minandmax(root->left);
    pair<int,int> mp2 = minandmax(root->right);
    int min1 = min(min(root->data,mp1.first),mp2.first);
    int maxy = max(max(root->data,mp1.second), mp2.second);
    
    
    return make_pair(min1,maxy);
}

int sumofAllNodes(btree<int>* root){
    if(root==NULL){
        return 0;
    }
    int sum =root->data;
    sum+= sumofAllNodes(root->left)+sumofAllNodes(root->right);

    return sum;
}

int depth(btree<int>* root){
    if(root==NULL){
        return 0;
    }
    int left = depth(root->left);
    int right = depth(root->right);
    if(left >right){
        return left+1;
    }
    else {
        return right+1;
    }
    // return 0;

}

int isbalanced(btree<int>* root){
    if(root==NULL){
        return 0;
    }
    int depthl = depth(root->left);
    int depthr = depth(root->right);
    if(abs(depthl-depthr)<=1){
        return 1;
    }
    else{
        return 0;
    }
}

btree<int>* deleteleaf(btree<int>* root){
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right== NULL){
        delete root;
        return NULL;
    }
    // btree<int>* newRoot;
    root->left = deleteleaf(root->left);
    root->right = deleteleaf(root->right);
    // newRoot = deleteleaf(root->left);
    // root = deleteleaf(root->right);

    return root;
}

vector<Node<int>*> treetolist(btree<int>* root){
    vector<Node<int>*> ans;
    if(root==NULL){
        return ans;
    }
    
    queue<btree<int>*> q;
    q.push(root);
    q.push(NULL);
    // list<int> l;
    Node<int>* head= NULL;
    Node<int>* tail = NULL;
    bool newNode = true;
    
    
    while(!q.empty()){
        btree<int>* roota = q.front();
        q.pop();
        if(roota==NULL){
            if(q.empty()){
                ans.push_back(head);
                break;
            }
            ans.push_back(head);
            q.push(NULL);
            head = tail = NULL;
            newNode = true;
        }
        else{
            if(newNode){
                head = new Node<int>(roota->data);
                tail = head;
                newNode = false;
            }
            else{
                Node<int> * node = new Node<int>(roota->data);
                tail->next= node;
                tail = node;
            }
            if(roota->left!=NULL){
                q.push(roota->left);
            }
            if(roota->right!=NULL){
                q.push(roota->right);
            }
        }
    }
    return ans;

}




int main(){
    btree<int>* root = levelwiseinput();
    // printlevelwise(root);
    // cout<<endl;
    // cout<<countAllnodes(root)<<endl;
    // cout<<ispresent(root,10)<<endl;
    // cout<<height(root)<<endl;
    // // reverselevel(root);
    // int n;
    // printf("Enter the value of n : ");
    // cin>>n;

    // int *post = (int*)malloc(n*sizeof(int));
    // for(int i =0;i<n;i++){
    //     cin>>post[i];
    // }
    // int *inor = (int*)malloc(n*sizeof(int));
    // for(int i =0;i<n;i++){
    //     cin>>inor[i];
    // }
    // btree<int>* root = postotree(post,inor,0,n-1,0,n-1);
    // root = deleteleaf(root);
    vector<Node<int>*> listing = treetolist(root);
    // for (std::list<int>::iterator it = listing.begin(); it != listing.end(); it++) {
    //     if (*it==-1) {
    //         // it = listing.erase(it);
    //         cout<<endl;
    //     } else {
    //         // ++it;
    //         cout<<it.<<" ";
    //     }
    // }
    for(int i = 0;i<listing.size();i++){
        while(listing[i]!=NULL){
            cout<<listing[i]->data<<" ";
            listing[i]=listing[i]->next;
        }cout<<endl;
    }
    printtree(root);
    printZigZag(root);
    // cout<<minandmax(root).first<<endl;
    
    // cout<<diameter(root)<<endl;
    // cout<<sumofAllNodes(root)<<endl;
    // cout<<isbalanced(root)<<endl;
    

    return 0;
}