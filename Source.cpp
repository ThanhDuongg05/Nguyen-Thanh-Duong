#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
const int MAXV = 20;

struct NODE {
	int trongso;
	int dinhke;
	NODE* link;
};
struct DanhSachKe {
	NODE* dsk[MAXV];
	int n;// so dinh cua do thi khi thay doi
};
bool docDanhSachKe(DanhSachKe& x , const char*tenFile)
{
	FILE* f = fopen(tenFile, "r");
	if (f == NULL)
		return false;
	fscanf(f, "%d", &x.n);
	for (int i = 0; i < x.n; i++)
		x.dsk[i] = NULL;
	for (int i = 0; i < x.n; i++)
	{
		int m;//bien dung luu tru dinh ke
		fscanf(f, "%d", &m);
		for (int j = 0; j < m; j++) {
			NODE* p = new NODE;
			fscanf(f, "%d%d", &p->dinhke, &p->trongso); // 2 gia tri nen dung %d%d
			p->link = NULL;
			if (x.dsk[i] == NULL)
				x.dsk[i] = p;
			else {
				NODE* q = x.dsk[i];
				while (q->link != NULL)
					q = q->link;
				q->link = p;
			}
		}
	}
	fclose(f);
	return true;
}
void xuatDanhSachKe(DanhSachKe x)
{
	for (int i = 0; i < x.n; i++)
	{
		cout << "Dinh " << i << ": ";
		NODE* p = x.dsk[i];
		while (p != NULL)
		{
			cout << p->dinhke << "(" << p->trongso << ") ";
			p = p->link;
		}
		cout << endl;
	}
}
int bacRa(DanhSachKe x, int u)
{
	if (u < 0 || u >= x.n)
	{
		cout<< "Dinh khong hop le!" << endl;
		return -1;
	}
	int bac = 0;
	NODE* p = x.dsk[u];
	while (p != NULL)
	{
		bac++;
		p = p->link;
	}
	return bac;
}
int bacVao(DanhSachKe x, int v)
{
	if (v < 0 || v >= x.n)
	{
		cout << "Dinh khong hop le!" << endl;
		return -1;
	}
	int bac = 0;
	for (int i = 0; i < x.n; i++)
	{
		NODE* p = x.dsk[i];
		while (p != NULL)
		{
			if (p->dinhke == v)
				bac++;
			p = p->link;
		}
	}
	return bac;
}
int main()
{
	DanhSachKe a;
	if (docDanhSachKe(a, "Text.txt") == true)
	{
		cout << "Doc danh sach ke thanh cong!" << endl;
		xuatDanhSachKe(a);
		cout << "Bac ra cua dinh 3: " << bacRa(a, 3) << endl;
		cout << "Bac vao cua dinh 3: " << bacVao(a, 3) << endl;
	}
	else {
		cout << "Doc danh sach ke that bai!" << endl;
	}
	return 0;
}