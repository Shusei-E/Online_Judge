#include<iostream>
using namespace std;

struct NODE{
	int id = -1;
	int parent = -1;
	int left = -1;
	int right = -1;
	int sibling = -1;
	int degree = 0;
	int depth;
	int height;
};

int depth_height(NODE *nodes, int id, int d, int h){
	nodes[id].depth = d;

	// depth
	int h1 = 0;
	int h2 = 0;

	if(nodes[id].left != -1){
		nodes[id].degree += 1;
		h1 = depth_height(nodes, nodes[id].left, d+1, h);
	}
	if(nodes[id].right != -1){
		nodes[id].degree += 1;
		h2 = depth_height(nodes, nodes[id].right, d+1, h);
	}

	h1 >= h2 ? h=h1 : h=h2;
	nodes[id].height = h;
	return h+1;

}

void show(NODE *nodes, const int &n){
	for(int i=0; i<n; ++i){
		cout << "node " << nodes[i].id << ": ";
		cout << "parent = " << nodes[i].parent << ", ";
		cout << "sibling = " << nodes[i].sibling << ", ";
		cout << "degree = " << nodes[i].degree << ", ";
		cout << "depth = " << nodes[i].depth << ", ";
		cout << "height = " << nodes[i].height << ", ";

		if(nodes[i].parent == -1){
			cout << "root";
		}else if(nodes[i].degree == 0){
			cout << "leaf";
		}else{
			cout << "internal node";
		}

		cout << endl;
	}
}

int main(){
	int n;
	cin >> n;
	NODE *nodes = new NODE[n]; 

	int id;
	for(int i=0; i<n; ++i){
		cin >> id;
		nodes[id].id = id;
		cin >> nodes[id].left >> nodes[id].right;

		nodes[ nodes[id].left ].sibling = nodes[id].right;
		nodes[ nodes[id].right ].sibling = nodes[id].left;
		if(nodes[id].right != -1)
			nodes[ nodes[id].right ].parent = id;
		if(nodes[id].left != -1)
			nodes[ nodes[id].left ].parent = id;
	}

	// Find root
	int root_id;
	for(int i=0; i<n; ++i){
		if(nodes[i].parent == -1){
			root_id = i;
			break;
		}
	}


	depth_height(nodes, root_id, 0, 0);
	show(nodes, n);

	return 0;
}
