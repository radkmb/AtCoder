#include <stdio.h>
#include <stdlib.h>

#define INF 1111111111 
#define KI_MAX (1 << 18)

int ki[KI_MAX * 2 - 1];

void ki_set(int idx, int value) {
	int pos = KI_MAX - 1 + idx;
	ki[pos] = value;
	do {
		pos = (pos - 1) / 2;
		ki[pos] = ki[pos * 2 + 1] < ki[pos * 2 + 2] ? ki[pos * 2 + 1] : ki[pos * 2 + 2];
	} while (pos > 0);
}
 
int ki_get_i(int idx, int qstart, int qend, int sstart, int send) {
	if (qend <= sstart || send <= qstart) {
		return INF;
	} else if (qstart <= sstart && send <= qend) {
		return ki[idx];
	} else {
		int smid = sstart + (send - sstart) / 2;
		int left = ki_get_i(idx * 2 + 1, qstart, qend, sstart, smid);
		int right = ki_get_i(idx * 2 + 2, qstart, qend, smid, send);
		return left < right ? left : right;
	}
}
 
int ki_get(int start, int end) {
	return start < end ? ki_get_i(0, start, end, 0, KI_MAX) : INF;
}
 
int N;
int a[271828];
 
int ec[271828];
int* es[271828];
 
void ae(int f, int t) {
	es[f] = realloc(es[f], sizeof(*es[f]) * (ec[f] + 1));
	if (es[f] == NULL) exit(2);
	es[f][ec[f]++] = t;
}
 
int kotae[271828];
 
int mareitaso(int query) {
	int l = 0, r = N + 99;
	while (l + 1 < r) {
		int m = l + (r - l) / 2;
		if (ki_get(m, N + 100) < query) l = m; else r = m;
	}
	return l;
}
 
void dfs(int node, int parent) {
	int neko = mareitaso(a[node]) + 1;
	int bak = ki_get(neko, neko + 1);
	int i;
	if (bak > a[node]) ki_set(neko, a[node]);
	kotae[node] = mareitaso(INF);
	for (i = 0; i < ec[node]; i++) {
		int next = es[node][i];
		if (next != parent) dfs(next, node);
	}
	ki_set(neko, bak);
}
 
int main(void) {
	int i;
	if (scanf("%d", &N) != 1) 
    return 1;
	for (i = 1; i <= N; i++) {
		if (scanf("%d", &a[i]) != 1)
        return 1;
	}
	for (i = 1; i <= N + 100; i++)
    ki_set(i, INF);
	for (i = 1; i <= N - 1; i++) {
		int u, v;
		if (scanf("%d%d", &u, &v) != 2) return 1;
		ae(u, v);
		ae(v, u);
	}
	dfs(1, 0);
	
    for (i = 1; i <= N; i++) {
		printf("%d\n", kotae[i]);
	}
	return 0;
}
