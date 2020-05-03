#include <bits/stdc++.h>
using namespace std;

int n;
bool s[504], t[504], bans=1;
unsigned long long u[504], v[504], ans[504][504];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
    cin >> s[i];
	for (int i = 0; i < n; i++)
    cin >> t[i];
	for (int i = 0; i < n; i++)
    cin >> u[i];
	for (int i = 0; i < n; i++)
    cin >> v[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans[i][j] = u[i];
		}
	}
	for (int j = 0; j < n; j++) {
		if (t[j]) {
			unsigned long long tmp = 0;
			for (int i = 0; i < n; i++)
            tmp|=ans[i][j];
			for (unsigned long long bit = 0; bit < 64; bit++) {
				if ((tmp&(1LL<<bit)) == ((v[j]&(1LL<<bit))))
                continue;
				if ((v[j]&(1LL<<bit))) {
					if (j & 1) {
						for (int i = 0; i < n; i++) {
							if (s[i])
                            continue;
							if ((ans[i][j]&(1LL<<bit)) == 0) {
								ans[i][j]|=(1LL<<bit);
								break;
							}
						}
					} else {
						for (int i = n - 1; i >= 0; i--) {
							if (s[i])
                            continue;
							if ((ans[i][j]&(1LL<<bit)) == 0) {
								ans[i][j]|=(1LL<<bit);
								break;
							}
						}
					}
				} else {
					for (int i = 0; i < n; i++)
                    ans[i][j]&=(~(1LL<<bit));
				}
			}
		} else {
			unsigned long long tmp = (~0);
			for (int i = 0; i < n; i++)
            tmp&=ans[i][j];
			for (unsigned long long bit = 0; bit < 64; bit++) {
				if ((tmp&(1LL<<bit)) == ((v[j]&(1LL<<bit))))
                continue;
				if ((v[j]&(1LL<<bit))) {
					for (int i = 0; i < n; i++)
                    ans[i][j]|=(1LL<<bit);
				} else {
					if (j&1){
						for (int i = 0; i < n; i++) {
							if (!s[i])
                            continue;
							if ((ans[i][j]&(1LL<<bit))) {
								ans[i][j]&=(~(1LL<<bit));
								break;
							}
						}
					} else {
						for (int i = n - 1; i >= 0; i--) {
							if (!s[i])
                            continue;
							if ((ans[i][j]&(1LL<<bit))) {
								ans[i][j]&=(~(1LL<<bit));
								break;
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
			if (s[i]) {
				unsigned long long tmp = 0;
				for (int j = 0; j < n; j++)
                tmp|=ans[i][j];
				if (tmp != u[i])
                bans=0;
			} else {
				unsigned long long tmp=(~0);
				for (int j = 0; j < n; j++)
                tmp&=ans[i][j];
				if (tmp != u[i])
                bans=0;
			}
		}
		if (!bans) {
			cout << "-1\n";
			return 0;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << ans[i][j] << " ";
			}
			cout << "\n";
		}
}
