#include <iostream>
#include<queue>
#include "TreeNode.h"
using namespace std;

// input - 1 3 2 3 4 2 5 6 1 7 1 8 0 0 0 0
TreeNode<int>* takeInputLevelwise(){
    int rootData;
    cout << "Enter root data: ";
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter number of children of " << front->data << ": ";
        int numChild;
        cin >> numChild;
        for(int i=0; i<numChild; i++){
            int childData;
            cin >> childData;
            TreeNode<int>* childNode = new TreeNode<int>(childData);
            front->children.push_back(childNode);
            pendingNodes.push(childNode);
        }
    }
    return root;
}
TreeNode<int>* takeInput(){
    // note that no base case is required just do numChild = 0
    cout << "Enter data: ";
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    cout << "Enter the number of child of " << rootData << ": ";
    int numChild;
    cin >> numChild;
    for(int i=0; i<numChild; i++){
        TreeNode<int>* childNode = takeInput();
        root->children.push_back(childNode);
    }
    return root;
}

void printTreeLevelWise(TreeNode<int>* root){
    if(root == NULL){
        return;
    }
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << " ";
        for(int i=0; i<front->children.size(); i++){
            pendingNodes.push(front->children[i]);
            // cout << front->children[i]->data << " ";
        }
        cout << endl;
    }
}
void printTree(TreeNode<int>* root){
    // note that no base is required
    // edge case
    if(root == NULL){
        return;
    }

    cout << root->data << ": ";
    for(int i=0; i<root->children.size(); i++){
        // all child of current tree node
        cout << root->children[i]->data << ",";
    }
    cout << endl;

    for(int i=0; i<root->children.size(); i++){
        // recursive call on each subtree
        printTree(root->children[i]);
    }
}
int main(){
    /*
    // manual creation of nodes
    TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* node1 = new TreeNode<int>(2);
    TreeNode<int>* node2 = new TreeNode<int>(3);
    root->children.push_back(node1);
    root->children.push_back(node2);
    */
    TreeNode<int>* root = takeInputLevelwise();
    // printing tree
    printTreeLevelWise(root);


    // TODO delete tree
    return 0;
}