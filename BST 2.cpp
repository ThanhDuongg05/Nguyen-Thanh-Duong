#include <iostream>
using namespace std;
struct Node {
	int data;
	int height;
	Node* left;
	Node* right;
};
typedef Node* NodePtr;

//Duyet PreOrder
void preOreder(NodePtr r)
{
	if (r == NULL)return;
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
int Height(NodePtr r) {
	if (r == NULL) return 0;
	else
		return r-> height ;
}
void rotateRight(NodePtr& r) {
	if (r == NULL || r->left == NULL || r->right == NULL)return;
	NodePtr p = r->left;
	r -> left = p->right;
	p->right = r;

	int rl = Height(r->left);
	int rr = Height(r->right);
	r->height = (rl > rr ? rl : rr) + 1;

	int pl = Height(p->left);
	int pr = Height(p->right);
	p->height = (pl > pr ? pl : pr) + 1;
	r = p;
}
void rotateLeft(NodePtr r) {
	if (r == NULL || r->left == NULL || r->right == NULL)return;
	NodePtr p = r->right;
	r->left = p->right;
	p->right = r;

	int rr = Height(r->right);
	int rl = Height(r->left);
	r->height = (rr > rl ? rr : rl) + 1;

	int pr = Height(p->right);
	int pl = Height(p->left);
	p->height = (pr > pl ? pr : pl) + 1;
	r = p;
}
void rotateLeftRight(NodePtr& r) {
	if (r == NULL || r->left == NULL || r->right == NULL)return;
	rotateLeft(r->left);
	rotateRight(r);
}
void rotateRightLeft(NodePtr& r) {
	if (r == NULL || r->left == NULL || r->right == NULL)return;
	rotateRight(r->right);
	rotateLeft(r);
}
int main() {
	const int lenBST = 9;
	int x[lenBST] = { 60,80,40,90,70,50,20,30,26 };
	NodePtr root = NULL;

	return 0;
}
