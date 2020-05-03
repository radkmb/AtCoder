#include <stdio.h>
#include <limits.h>
#define min(rhs, lhs) ((rhs) < (lhs) ? (rhs) : (lhs))

typedef struct{
    long f, s;
    long long t;
} three;

static inline void swap(three *rhs, three *lhs){
    three tmp = *rhs;
    *rhs = *lhs;
    *lhs = tmp;
}

three pq[1000000];

static inline void pqinsert(three elem) {
    pq[0].f++;
    pq[pq[0].f] = elem;
    long i = pq[0].f;
    while(i / 2){
        if(pq[i].t < pq[i / 2].t)swap(&pq[i], &pq[i / 2]);
        i /= 2;
    }
}

static inline three pqpop() {
    three ret = pq[1];
    pq[1].t = LLONG_MAX;
    swap(&pq[1], &pq[pq[0].f]);
    pq[0].f--;
    long mi, i = 1;

    while(i * 2 + 1 <= pq[0].f + 1) {
        mi = pq[i * 2].t > pq[i * 2 + 1].t ? i * 2 + 1 : i * 2; 
        if(pq[mi].t < pq[i].t)
        swap(&pq[mi], &pq[i]);
        i = mi;
    }
    return ret;
}

int main(void) {
    register long i, j;
    int n, m, tu, tv;
    long s, ta, tb;
    scanf("%d%d%ld",&n, &m, &s);
    static three train[50][49];
    static int trarp[50];
    for(i = 0; i < m; i++) {
        scanf("%d%d%ld%ld",&tu ,&tv ,&ta ,&tb);
        tu--;
        tv--;
        train[tu][trarp[tu]] = (three){tv, ta, tb};
        train[tv][trarp[tv]] = (three){tu, ta, tb};
        trarp[tu]++;
        trarp[tv]++;
    }
    static long excm[50], exct[50];
    for(i = 0; i < n; i++)
    scanf("%ld%ld",&excm[i], &exct[i]);
    static long long dp[50][2501];

    for(i = 0; i < 50; i++)
    for(j = 0; j <= 2500; j++)
    dp[i][j] = LLONG_MAX;
    for(i = 1; i < 100000; i++)
    pq[i] = (three){0, 0, LLONG_MAX};
    s = min(s, 2500);
    pqinsert((three){0, s, 0});

    while(pq[0].f) {
        three cur = pqpop();
        if(dp[cur.f][cur.s] <= cur.t)
        continue;
        dp[cur.f][cur.s] = cur.t;

        for(i = 0; i < trarp[cur.f]; i++)
        if(train[cur.f][i].s <= cur.s)
            pqinsert((three){train[cur.f][i].f, cur.s - train[cur.f][i].s, cur.t + train[cur.f][i].t});
            
            if(cur.s == 2500)
            continue;
            pqinsert((three){cur.f, min(cur.s + excm[cur.f], 2500), cur.t + exct[cur.f]});
    }
    static long long mins[50];
    for(i = 0; i < n; i++)
    mins[i] = LLONG_MAX;
    for(i = 1; i < n; i++)
    for(j = 0; j < 2501; j++)
    mins[i] = min(dp[i][j], mins[i]);
    for(i = 1; i < n; i++)
    printf("%lld\n",mins[i]);
}
