#include <cstdio>
#include <algorithm>
#define N 100005

int n;
int c[5];
char s[N][5], ans[N];

int main() {
    int *a = c - 'A';
    scanf("%d%d%d%d", &n, a + 'A', a + 'B', a + 'C');
    for (int i = 1; i <= n; ++i)
    scanf("%s", s[i]);
    for (int i = 1; i <= n; ++i)
        if (!a[s[i][0]] && !a[s[i][1]]) {
            puts("No");
            return 0;
        } else if (a[s[i][0]] < a[s[i][1]] || (a[s[i][0]] == a[s[i][1]] && i < n && (s[i][0] == s[i + 1][0] && s[i][1] != s[i + 1][1] || s[i][0] == s[i + 1][1] && s[i][1] != s[i + 1][0])))
            ++a[s[i][0]], --a[s[i][1]], ans[i] = s[i][0];
        else
            --a[s[i][0]], ++a[s[i][1]], ans[i] = s[i][1];
            puts("Yes");
            for (int i = 1; i <= n; ++i)
                printf("%c\n", ans[i]);
}
