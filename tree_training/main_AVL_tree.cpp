#include <bits/stdc++.h>

using namespace std;

class Node {
	public:
		Node() {}
		Node(const Node &node) { *this = node; }

		~Node() {}

		Node	&operator=(const Node &node) {
			key = node.key;
			left = node.left;
			right = node.right;
			height = node.height;

			return *this;
		}

		int		key;
		Node	*left;
		Node	*right;
		int		height;
};

class AVLTree {
	public:
		AVLTree() : _root(NULL) {}

//		AVLTree	&operator=(const AVLTree &tree) {
//			_root = tree._
//			return *this;
//		}

		~AVLTree() { destroyTree(); }

		int	height(Node *node) {
			if (!node)
				return 0;
			return node->height;
		}

		int	max(int a, int b) {
			return (a > b) ? a : b;
		}

		void	destroyTree() {
			destroyTree(_root);
		}

		void	insert(int key) {
			_root = insert(_root, key);
		}

		void	printTree() {
			preOrder(_root);
		}

	private:
		Node	*newNode(int key) {
			Node	*node = new Node();

			node->key = key;
			node->left = NULL;
			node->right = NULL;
			node->height = 1;

			return (node);
		}

		Node	*rightRotate(Node *y) {
			Node	*x = y->left;
			Node	*T2 = x->right;

			x->right = y;
			y->left = T2;

			y->height = max(height(y->left), height(y->right)) + 1;
			x->height = max(height(x->left), height(x->right)) + 1;

			return x;
		}

		Node	*leftRotate(Node *x) {
			Node	*y = x->right;
			Node	*T2 = y->left;

			y->left = x;
			x->right = T2;

			x->height = max(height(x->left), height(x->right)) + 1;
			y->height = max(height(y->left), height(y->right)) + 1;

			return y;
		}

		int	getBalance(Node *node) {
			if (!node)
				return 0;
			return height(node->left) - height(node->right);
		}

		Node	*insert(Node *node, int key) {
			if (!node)
				return (newNode(key));

			if (key < node->key)
				node->left = insert(node->left, key);
			else if (key > node->key)
				node->right = insert(node->right, key);
			return node;

			node->height = 1 + max(height(node->left), height(node->right));

			int balance = getBalance(node);

			if (balance > 1 && key < node->left->key)
				return rightRotate(node);

			if (balance < -1 && key > node->right->key)
				return leftRotate(node);

			if (balance > 1 && key > node->left->key) {
				node->left = leftRotate(node->left);
				return rightRotate(node);
			}

			if (balance < -1 && key < node->right->key) {
				node->right = rightRotate(node->right);
				return leftRotate(node);
			}

			return node;
		}

		void	preOrder(Node *root) {
			if (root) {
				cout << root->key << " ";
				preOrder(root->left);
				preOrder(root->right);
			}
		}

		void	destroyTree(Node *leaf) {
			if (leaf) {
				destroyTree(leaf->left);
				destroyTree(leaf->right);
				delete leaf;
			}
		}

		Node	*_root;
};

int	main() {
	AVLTree	avl;

	avl.insert(0);
	avl.insert(2);
	avl.insert(1);
	avl.insert(3);
	avl.insert(7);
	avl.insert(4);
	avl.insert(5);
	avl.insert(6);
	avl.insert(9);
	avl.insert(10);
	avl.insert(11);
	avl.insert(8);
	avl.insert(12);
	avl.insert(13);
	avl.insert(15);
	avl.insert(14);
	avl.insert(16);
	avl.printTree();

	return 0;
}
