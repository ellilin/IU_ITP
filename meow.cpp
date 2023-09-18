#include <bits/stdc++.h>
using namespace std;
 
int main() {
long long n, tr=1, l, wr = 0;
cin >> n;
string s, g;
vector<int>v;
for(int i = 0; i < n; i++){
	cin >> s >> g;
	tr = 1;
	if(s.size() < g.size()) cout << 0 << endl << endl;
	else{
	for(int k = 0; k < s.size() - g.size() + 1; k++){
		if(s[k] == g[0] || g[0] == '?'){
			wr = 0;
			for(int i = 1; i < g.size(); i++ ){
				if(s[k+i] != g[i] && g[i] != '?' ){
					wr++;
				}
			}
			if(wr == 0) {
			v.push_back(k);
			tr++;
		}
		}
	}
	cout << tr - 1 << endl;
	for(int q = 0; q < v.size(); q++){
		cout << v[q] << " ";
	}
	v.clear();
	cout << endl;
}
}
}