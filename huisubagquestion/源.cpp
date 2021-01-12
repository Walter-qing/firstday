#include<iostream>
using namespace std;

int n, w;
int vmax;
int w0[50], v[50];

int bagquestion(int i,int tw,int tv,int op[]) {
	if (i > n) {
		if (tw <= w && tv > vmax) {
			vmax = tv;
			
		}
	}
	else {
		op[i] = 1;
		bagquestion(i + 1, tw + w0[i - 1], tv + v[i - 1], op);
		op[i] = 0;
		bagquestion(i + 1, tw, tv, op);
	}
	return vmax;
}

int main() {
	cin >> n >> w;
	for (int i = 0;i < n;i++) {
		cin >> w0[i] >> v[i];

	}

	int op[50];
	vmax = bagquestion(1,0,0,op);
	cout << vmax << endl;

	return 0;
}