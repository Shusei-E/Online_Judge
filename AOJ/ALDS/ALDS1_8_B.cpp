#include<iostream>
using namespace std;

struct NODE{
	int key;
	int inserted = 0;
	NODE* parent = nullptr;
	NODE* left = nullptr;
	NODE* right = nullptr;
};

void show_key(NODE *node){
	cout << " " << node->key;
}

void show_preorder(NODE *node){
	show_key(node);
	if(node->left != nullptr)
		show_preorder(node->left);
	if(node->right != nullptr)
		show_preorder(node->right);
}

void show_inorder(NODE *node){
	if(node->left != nullptr)
		show_inorder(node->left);

	show_key(node);

	if(node->right != nullptr)
		show_inorder(node->right);
}

void print(NODE *node){
	show_inorder(node);
	cout << endl;
	show_preorder(node);
	cout << endl;
}

void insert(NODE *node, int &insert_key){
	if(!node->inserted){ // If not inserted
		node->key = insert_key;
		node->inserted = 1;
		return;
	}else if(node->key < insert_key){
		if(node->right == nullptr){
			NODE *new_node = new NODE; 
			node->right = new_node;
		}
		insert(node->right, insert_key);
		return;
	}else{
		if(node->left == nullptr){
			NODE *new_node = new NODE;
			node->left = new_node;
		}
		insert(node->left, insert_key);
		return;
	}

}

void find(NODE *node, int &key){
	if(node->key == key){
			cout << "yes" << endl;
	}else if(node->left == nullptr && node->right==nullptr){
		cout << "no" << endl;
	}else if(node->key < key){
		find(node->right, key);		
	}else if(key < node->key){
		find(node->left, key);
	}
}

int main(){
	int m;
	cin >> m;

	char command[8];
	int insert_key;
	int key;
	NODE* root_node = new NODE;
	for(int i=0; i<m; ++i){
		cin >> command;
		if(command[0] == 'i'){
			cin >> insert_key;
			insert(root_node, insert_key);
		}else if(command[0] == 'p'){
			print(root_node);
		}else if(command[0] == 'f'){
			cin >> key;
			find(root_node, key);
		}
	}
	return 0;
}
