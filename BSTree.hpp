#ifndef BSTREE_HPP
#define BSTREE_HPP 1
#include "Dictionary.hpp"

template <Key, Value>
template <class Key,class Value>
class NodeBST
{
public:
	Key key;
	Value val;		
	int height;		
	int size;
	NodeBST<Key,Value> *left, *right, *parent;
	NodeBST();
	NodeBST(Key key, Value value);
};
//defining binary node here .....
template <class Key, class Value>
NodeBST<Key,Value>::NodeBST(Key key, Value value)
{
	this->left=NULL;
	this->right=NULL;
	this->parent=NULL;
	this->key=key;
	this->val=value;

}
//basic constructor...
template <class Key, class Value>
NodeBST<Key,Value>::NodeBST()
{
	this->key= Key();
	this->val= Value();
	this->left=NULL;
	this->right=NULL;
	this->parent=NULL;
}

class BSTree : public Dictionary<Key, Value> {
 class NodeBST * root;




 public:
  
 virtual void insert(class NodeBST* node, int data)
{
  if (node == NULL)
    return(newNode(data));
  else
  {
    class NodeBST *temp;
	if (data <= node->data)
    {
         temp = insert(node->left, data);
         node->left  = temp;
         temp->parent= node;
    }
    else
    {
        temp = insert(node->right, data);
        node->right = temp;
        temp->parent = node;
    }
	return node;
  }
}

  virtual int getHeight(){  
    if (node == NULL)  
        return 0;  
    else
    {  
        /* compute the depth of each subtree */
        int lDepth = getHeight(node->left);  
        int rDepth = getHeight(node->right);  
      
        /* use the larger one */ 
        if (lDepth > rDepth)	 
            return(lDepth + 1);  
        else return(rDepth + 1);                         
    }  
} 
  virtual int size(){
   if (node == NULL)  
        return 0;  
    else
        return(size(node->left) + 1 + size(node->right));  
  }
  virtual void print(int arr[],int start,int end){      
    if(start > end) 
        return; 
    print(arr, start*2 + 1, end); 
    cout << arr[start] << " "; 
    print(arr, start*2 + 2, end);  
} 

  virtual void in_order(void (*fun)(const Key& key, const Value& value)){
	if(n!=NULL){
        inorder(n->left);
        printf("%d \n",n->key);
        inorder(n->right);
    }
}
virtual void pre_order(void (*fun)(const Key& key, const Value& value)){
	if(n!=NULL){
		printf("%d \n",n->key);
        inorder(n->left);
        inorder(n->right);
    }
}
  virtual void post_order(void (*fun)(const Key& key, const Value& value)){
		if(n!=NULL){
        post_order(n->left);
        post_order(n->right);
		printf("%d \n",n->key);
    }
}
  virtual void print_in_order(){
	if(n!=NULL){
        print_in_order(n->left);
        printf("%d \n",n->key);
        print_in_order(n->right);
    }
  virtual void print_pre_order(){
	if(n!=NULL){
		printf("%d \n",n->key);
        print_pre_order(n->left);
        print_pre_order(n->right);
    }
  virtual void print_post_order(){
		if(n!=NULL){
        print_post_order(n->left);
        print_post_order(n->right);
		printf("%d \n",n->key);
    }
}
  virtual Key minimun()	{
    if(x->left==NULL){
        return x->key;
    }
        minimum(x->left);
}

  virtual Key maximum(){
    if(x->right==NULL){
        return x->key;
    }
        maximum(x->right);
}
  virtual Key successor(const Key& key){
    if(x->right!=NULL){
        min(x->right);
    }
    struct node *y;
    y=x->parent;
    while(y!=NULL && x==y->right){
        x=y;
        y=y->parent;
    }
    return y;
}
  virtual Key predecessor(const Key& key){ 
    // Base case 
    if (root == NULL)  return ; 
  
    // If key is present at root 
    if (root->key == key) 
    { 
        // the maximum value in left subtree is predecessor 
        if (root->left != NULL) 
        { 
            Node* tmp = root->left; 
            while (tmp->right) 
                tmp = tmp->right; 
            pre = tmp ; 
        } 
		return ;
	}
}
 



  virtual void insert(class NodeBST* node, int data);

  virtual int getHeight();
  virtual int size();
  virtual void print(int arr[],int start,int end);

  virtual void in_order(void (*fun)(const Key& key, const Value& value));
virtual void pre_order(void (*fun)(const Key& key, const Value& value)){
	if(n!=NULL){
		printf("%d \n",n->key);
        inorder(n->left);
        inorder(n->right);
    }
}
  virtual void post_order(void (*fun)(const Key& key, const Value& value)){
		if(n!=NULL){
        post_order(n->left);
        post_order(n->right);
		printf("%d \n",n->key);
    }
}
  virtual void print_in_order(){
	if(n!=NULL){
        print_in_order(n->left);
        printf("%d \n",n->key);
        print_in_order(n->right);
    }
  virtual void print_pre_order(){
	if(n!=NULL){
		printf("%d \n",n->key);
        print_pre_order(n->left);
        print_pre_order(n->right);
    }
  virtual void print_post_order(){
		if(n!=NULL){
        print_post_order(n->left);
        print_post_order(n->right);
		printf("%d \n",n->key);
    }
}
  virtual Key minimun()	{
    if(x->left==NULL){
        return x->key;
    }
        minimum(x->left);
}

  virtual Key maximum(){
    if(x->right==NULL){
        return x->key;
    }
        maximum(x->right);
}
  virtual Key successor(const Key& key){
    if(x->right!=NULL){
        min(x->right);
    }
    struct node *y;
    y=x->parent;
    while(y!=NULL && x==y->right){
        x=y;
        y=y->parent;
    }
    return y;
}
  virtual Key predecessor(const Key& key){ 
    // Base case 
    if (root == NULL)  return ; 
  
    // If key is present at root 
    if (root->key == key) 
    { 
        // the maximum value in left subtree is predecessor 
        if (root->left != NULL) 
        { 
            Node* tmp = root->left; 
            while (tmp->right) 
                tmp = tmp->right; 
            pre = tmp ; 
        } 
		return ;
	}
}
#endif /* ifndef BSTREE_HPP */