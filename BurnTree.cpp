class Solution {
  public:
    Node*mappingNodeToPar(Node*root,int k,map<Node*,Node*>&ntop){
        Node*ans=NULL;            // returning target node as well reduce time complexity
        queue<Node*>q;
        q.push(root);
        ntop[root]=NULL;
        while(!q.empty()){
            Node*frnt=q.front();
            q.pop();
            
            if(frnt->data==k)
            ans=frnt;
            
            if(frnt->left){
                ntop[frnt->left]=frnt;
                q.push(frnt->left);
            }
            if(frnt->right){
                ntop[frnt->right]=frnt;
                q.push(frnt->right);
            }
        }
        return ans;
    }
    void burnTree(Node*root,map<Node*,Node*>nodeToPar,int&ans){
        map<Node*,bool>visited;
        queue<Node*>q;
        q.push(root);
        visited[root]=1;
        while(!q.empty()){
            bool flag=0;
            int size=q.size();
            for(int i=0;i<size;i++){
                Node*frnt=q.front();
                q.pop();
                if(frnt->left && visited[frnt->left]==false){
                    flag=1;
                    visited[frnt->left]=1;
                    q.push(frnt->left);
                }
                if(frnt->right && visited[frnt->right]==false){
                    flag=1;
                    visited[frnt->right]=1;
                    q.push(frnt->right);
                }
                if(nodeToPar[frnt] && visited[nodeToPar[frnt]]==false){
                    flag=1;
                    visited[nodeToPar[frnt]]=1;
                    q.push(nodeToPar[frnt]);
                }
            }
            if(flag)ans++;
        }
    }
        
    int minTime(Node* root, int target) 
    {   int ans=0;    // time
        map<Node*,Node*>nodeToPar;
        Node*muchh=mappingNodeToPar(root,target,nodeToPar);
        burnTree(muchh,nodeToPar,ans);
        return ans;
    }
};     
