#include <iostream>
using namespace std;
struct Node {
	int data;
	Node* left;
	Node* right;
};
typedef Node* NodePtr;
NodePtr tim( NodePtr r,int a){
	if (r == NULL) return NULL;
	else if (r->data == a) return r;
	else if (a < r->data)
		return tim(r->left, a);
	else
		return tim(r->right, a);
}
NodePtr chen(NodePtr& r, int a) {
	if (r == NULL)
	{
		NodePtr p = new Node;
		p->data = a;
		p->left = p->right = NULL;
		r = p;
	}
	else if (a < r->data)
		return chen(r->left,a);
	else if (a > r->data)
		return chen(r->right,a);
	else
		return NULL;
}
//Duyet PreOrder
void preOreder(NodePtr r)
{
	if (r == NULL) return;
	cout << " " << r->data;
	preOreder(r->left);
	preOreder(r->right);
}
//Duyet InOrder
void inOreder(NodePtr r)
{
	if (r == NULL)return;
	inOreder(r->left);
	cout << " " << r->data;
	inOreder(r->right);
}
void postOreder(NodePtr r) {
	if (r == NULL) return;
	postOreder(r->left);
	postOreder(r->right);
	cout << " " << r->data;
}
NodePtr chen(NodePtr& r,int a)
{
	if (r == NULL)
	{
		NodePtr p = newNode;
		p->data = a;
		p->left = p->right = NULL;
		r = p;
		return r;
	}
	else if (a < r->data)
		return chen(r->left, a);
	else if (a > r->data)
		return chen(r->right, a);
	else
		return NULL;
}
void xoa(NodePtr& r,int a ){
	if (r == NULL) reeturn;
	if (r - data == a)
	{
		NodePTr p = newNode;
		if (r->left == NULL)
		{
			r = r->right;
			delete p;
		}
		else if (r->right == NULL) {
			r = r->left;
			delete = p;
		}
		else
		{
			NodePtr q = r->left;
			while(q->right != NULL) q = q->right;
			p->data = q->data;
			xoa(r->left, q->data);
		}
	}
}
int main() {
	const int lenBST = 9;
	int x[lenBST] = { 60,80,40,90,70,50,20,30,26 };
	NodePtr root = NULL;
	for (int i = 0; i < lenBST; i++)
		chen(root, x[i]);
	cout << "BST created.";
	cout << "\n_______________";
	cout << "\nPreOrder: ";
	preOreder(root);
	cout << "\ninOrder: ";
	inOreder(root);
	cout << "\npostOrder: ";
	postOreder(root);
	cout << "\n_______________";
	
	return 0;
}
