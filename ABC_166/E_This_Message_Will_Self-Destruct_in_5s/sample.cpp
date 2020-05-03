#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int read() {
	int n = 0;
    bool b = 0;
    char c = getchar();

	while(c < '0' || c > '9') {
        if(c == '-')
        b = 1;
        c = getchar();
    }
	while(c >= '0' && c <= '9')
    n = (n<<3) + (n<<1) + (c^48), c = getchar();
	return b ? -n : n;
}

int cnt[400100];
int n, ans;

main()
{
	n = read();
	for(int i = 1; i <= n; ++i)
	{
		int a = read();
		if(i >= a && i - a <= 400001)
        ans += cnt[i - a];
		++cnt[min(400010ll, i + a)];
	}
	cout<<ans;
	return 0;
}
