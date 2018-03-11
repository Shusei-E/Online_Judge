#include<iostream>
using namespace std;

struct NODE{
	int key;
	int inserted = 0;
	NODE* parent = nullptr;
	NODE* left = nullptr;
	NODE* right = nullptr;
};

NODE* root_node = new NODE;

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
			new_node -> parent = node;
		}
		insert(node->right, insert_key);
		return;
	}else{
		if(node->left == nullptr){
			NODE *new_node = new NODE;
			node->left = new_node;
			new_node -> parent = node;
		}
		insert(node->left, insert_key);
		return;
	}

}

NODE* find(NODE *node, int &key){
	if(node->key == key){
		return node;
	}else if(node->left == nullptr && node->right==nullptr){
		return nullptr;
	}else if(node->key < key){
		if(node->right==nullptr){
			return nullptr;
		}
		return find(node->right, key);		
	}else if(key < node->key){
		if(node->left==nullptr){
			return nullptr;
		}
		return find(node->left, key);
	}
}

NODE* find_min(NODE* node){
	while (node->left != nullptr){
		node = node -> left;
	}

	// Separete the node
	if(node -> parent -> left == node)
		node -> parent -> left = node -> right;
	else
		node -> parent -> right = node -> right;
	if(node -> right != nullptr)
		node -> right -> parent = node -> parent;
	return node;
}

void del(NODE *root_node, int &key){
	NODE* del_node = find(root_node, key);
	if (del_node == nullptr)
		return;
	NODE* del_parent = del_node -> parent;

	// No children
	if(del_node->left==nullptr && del_node->right==nullptr){
		if(del_node -> parent == nullptr)
			root_node = nullptr;
		if(del_node->key < del_parent->key){
			del_node -> parent -> left = nullptr;
		}else{
			del_node -> parent -> right = nullptr;
		}

	}

	// One child
	if(del_node->left==nullptr && del_node->right!=nullptr){
		// Right child
		if(del_parent == nullptr)
			root_node = del_node -> right;
		else if(del_node -> parent->left == del_node)
			del_node -> parent -> left = del_node->right;
		else
			del_node -> parent -> right = del_node -> right;

		del_node -> right -> parent = del_node -> parent;
	}
	
	if(del_node->left!=nullptr && del_node->right==nullptr){
		// Left child
		if(del_parent == nullptr)
			root_node = del_node -> left;
		else if (del_parent->left==del_node)
			del_parent -> left = del_node -> left;
		else
			del_parent -> right = del_node -> left;

		del_node -> left -> parent = del_node -> parent;
	}
	
	// Two children
	// http://f-server.ics.kagoshima-u.ac.jp/~fuchida/algorithm/alg10-%E4%BA%8C%E5%88%86%E6%8E%A2%E7%B4%A2%E6%9C%A8.pdf
	if(del_node->left!=nullptr && del_node->right!=nullptr){
		NODE* min_right_part = find_min(del_node->right);
		
		if(del_parent == nullptr)
			root_node = min_right_part;
		else if(del_parent->left == del_node)
			del_parent -> left = min_right_part;
		else
			del_parent -> right = min_right_part;
		
		del_node -> left -> parent = min_right_part;
		
		// if(del_node -> right != min_right_part)
		// 	del_node -> right -> parent = min_right_part;
		
		min_right_part -> left = del_node -> left;
		
		if(del_node -> right != min_right_part)
			min_right_part -> right = del_node -> right;
		
		min_right_part -> parent = del_node -> parent;
	}

	return;
}


int main(){
	int m;
	cin >> m;

	char command[8];
	int key;
	NODE* node_ptr;
	for(int i=0; i<m; ++i){
		cin >> command;
		if(command[0] == 'i'){
			cin >> key;
			insert(root_node, key);
		}else if(command[0] == 'p'){
			print(root_node);
		}else if(command[0] == 'f'){
			cin >> key;
			node_ptr = find(root_node, key);
			if(node_ptr == nullptr){
				cout << "no" << endl;
			}else{
				cout << "yes" << endl;
			}

		}else if(command[0] == 'd'){
			cin >> key;
			del(root_node, key);
		}
	}
	return 0;
}
