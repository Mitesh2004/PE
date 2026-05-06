QUEEN 10,17,19,20
#include <stdio.h>
#include <stdlib.h>

int b[20], n, found = 0;

void solve(int r)
{
	if(r == n)
	{
		found = 1;
		printf("[");
		for(int i = 0; i < n; i++){
			printf("%d%s", b[i], i < n-1 ? ", " : "");
		}
		printf("]\n");
		return;
	}

	for(int c = 0; c < n; c++)
	{
		int ok = 1;
		for(int i = 0; i < r; i++){
			if(b[i] == c || abs(b[i] - c) == r - i){
				ok = 0;
			}
		}
		if(ok){
			b[r] = c, solve(r + 1);
		}
	}
}

int main()
{
	scanf("%d", &n);
	solve(0);

	if(!found){ printf("\nNo solution exists for n = %d\n", n);}
}
4
[1, 3, 0, 2]
[2, 0, 3, 1]
/*
   Each list represents:

   Index = row
   Value = column of queen

   So [1, 3, 0, 2] means:

   Row 0 → Col 1
   Row 1 → Col 3
   Row 2 → Col 0
   Row 3 → Col 2
   */

DFS_BFS 11,12,14
#include <stdio.h>
#include <time.h>

#define MAX 20

int g[MAX][MAX], v[MAX];

/* DFS */
void dfs(int n, int x)
{
    printf("%d ", x); 
    v[x] = 1;

    for(int i = 1; i <= n; i++)
        if(g[x][i] && !v[i])
            dfs(n, i);
}

/* BFS */
void bfs(int n, int s)
{
    int q[MAX], f = 0, r = 0, vis[MAX] = {0};

    q[r++] = s;
    vis[s] = 1;

    while(f < r)
    {
        int x = q[f++];
        printf("%d ", x);  

        for(int i = 1; i <= n; i++)
            if(g[x][i] && !vis[i])
                q[r++] = i, vis[i] = 1;
    }
}

int main()
{
    int n, s;
    clock_t start, end;
    double t;

    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &g[i][j]);

    scanf("%d", &s);

    /* DFS */
    for(int i = 0; i < MAX; i++) v[i] = 0;
    printf("DFS: ");
    start = clock();
    dfs(n, s);
    end = clock();
    t = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nDFS Time = %f sec\n", t);

    /* BFS */
    printf("BFS: ");
    start = clock();
    bfs(n, s);
    end = clock();
    t = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nBFS Time = %f sec\n", t);

    return 0;
}
4

0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0

1

DFS: 1 2 4 3
DFS Time = 0.000001 sec

BFS: 1 2 3 4
BFS Time = 0.000001 sec



/*
#include <stdio.h>

#define MAX 20

int g[MAX][MAX], v[MAX];

// DFS (recursive) 
void dfs(int n, int x)
{
    printf("%d ", x);
    v[x] = 1;

    for(int i = 1; i <= n; i++)
        if(g[x][i] && !v[i])
            dfs(n, i);
}

// BFS (queue) 
void bfs(int n, int s)
{
    int q[MAX], f = 0, r = 0, vis[MAX] = {0};

    q[r++] = s;
    vis[s] = 1;

    while(f < r)
    {
        int x = q[f++];
        printf("%d ", x);

        for(int i = 1; i <= n; i++)
            if(g[x][i] && !vis[i])
                q[r++] = i, vis[i] = 1;
    }
}

int main()
{
	int n, s;

	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &g[i][j]);

	scanf("%d", &s);

	printf("DFS: ");
	dfs(n, s);

	printf("\nBFS: ");
	bfs(n, s);

	printf("\nTime: DFS = BFS = O(V+E)");

	return 0;
}
*/

graph_color 15,18
#include <stdio.h>

#define MAX 20

int g[MAX][MAX], color[MAX], n, m;

int solve(int v)
{
    if(v == n) return 1;

    for(int c = 1; c <= m; c++)
    {
        int ok = 1;
        for(int i = 0; i < n; i++)
            if(g[v][i] && color[i] == c)
                ok = 0;

        if(ok)
        {
            color[v] = c;
            if(solve(v + 1)) return 1;
            color[v] = 0;
        }
    }
    return 0;
}

int main()
{
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &g[i][j]);

    scanf("%d", &m);

    if(solve(0))
    {
        printf("Color Assignment:\n");
        for(int i = 0; i < n; i++)
            printf("Vertex %d -> Color %d\n", i, color[i]);
    }
    else
        printf("No solution");
}
4

0 1 1 1
1 0 1 0
1 1 0 1
1 0 1 0

3
Color Assignment:
Vertex 0 -> Color 1
Vertex 1 -> Color 2
Vertex 2 -> Color 3
Vertex 3 -> Color 2


OBS 9,13
#include <stdio.h>
#include <time.h>

#define MAX 20
#define INF 9999

int sum(int f[], int i, int j)
{
    int s = 0;
    for(int k = i; k <= j; k++) s += f[k];
    return s;
}

int obst(int f[], int n)
{
    int c[MAX][MAX];

    for(int i = 0; i < n; i++)
        c[i][i] = f[i];

    for(int L = 2; L <= n; L++)
        for(int i = 0; i <= n - L; i++)
        {
            int j = i + L - 1;
            c[i][j] = INF;

            int s = sum(f, i, j);

            for(int r = i; r <= j; r++)
            {
                int x = s;
                if(r > i) x += c[i][r - 1];
                if(r < j) x += c[r + 1][j];

                if(x < c[i][j]) c[i][j] = x;
            }
        }

    return c[0][n - 1];
}

int main()
{
    int n, f[MAX], keys[MAX], cost;
    clock_t start, end;
    double t;

    printf("Enter number of keys: ");
    scanf("%d", &n);

    printf("Enter keys:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &keys[i]);   // (not used, just for input format)

    printf("Enter frequencies:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &f[i]);

    start = clock();

    cost = obst(f, n);

    end = clock();

    printf("\nOptimal Cost = %d\n", cost);

    t = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time = %f seconds\n", t);

    printf("Time Complexity = O(n^3)\n");

    return 0;
}
Enter number of keys: 3
Enter keys:
10 20 30
Enter frequencies:
34 8 50
Optimal Cost = 142
Time = 0.000001 seconds
Time Complexity = O(n^3)


/*
#include <stdio.h>
#include <time.h>

#define MAX 20
#define INF 9999

int sum(int f[], int i, int j)
{
	int s = 0;
	for(int k = i; k <= j; k++) s += f[k];
	return s;
}

int obst(int f[], int n)
{
	int c[MAX][MAX];

	for(int i = 0; i < n; i++)
		c[i][i] = f[i];

	for(int L = 2; L <= n; L++)
		for(int i = 0; i <= n - L; i++)
		{
			int j = i + L - 1;
			c[i][j] = INF;

			int s = sum(f, i, j);

			for(int r = i; r <= j; r++)
			{
				int x = s;
				if(r > i) x += c[i][r - 1];
				if(r < j) x += c[r + 1][j];

				if(x < c[i][j]) c[i][j] = x;
			}
		}

	return c[0][n - 1];
}

int main()
{
	int n, f[MAX], cost;
	clock_t start, end;
	double t;

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", &f[i]);

	// Time measurement 
	start = clock();

	cost = obst(f, n);

	end = clock();

	printf("Cost = %d\n", cost);

	t = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Time = %f seconds\n", t);

	printf("Time Complexity = O(n^3)");

	return 0;
}
*/

quick_sort 1,3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

void qs(int a[], int l, int h)
{
    if(l < h)
    {
        int p = a[h], i = l - 1;

        for(int j = l; j < h; j++)
            if(a[j] < p)
                i++, swap(&a[i], &a[j]);

        swap(&a[i+1], &a[h]);

        int pi = i + 1;

        qs(a, l, pi - 1);
        qs(a, pi + 1, h);
    }
}

int main()
{
    int a[1000], n;
    clock_t s, e;

    printf("Enter n: ");
    scanf("%d", &n);

    srand(time(0));
    for(int i = 0; i < n; i++)
        a[i] = rand() % 100;

    printf("Original:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    s = clock();
    qs(a, 0, n - 1);
    e = clock();

    printf("\nSorted:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nTime = %f sec", (double)(e - s) / CLOCKS_PER_SEC);
    printf("\nBest = O(n log n), Worst = O(n^2)");

    return 0;
}
Enter n: 5
Original:
45 12 78 23 9

Sorted:
9 12 23 45 78

Time = 0.000001 sec
Best = O(n log n), Worst = O(n^2)



/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(a[j] < pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i+1], &a[high]);
    return i+1;
}

void quickSort(int a[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int main()
{
    int a[MAX], n;
    clock_t start, end;

    printf("Enter n: ");
    scanf("%d", &n);

    //Proper random generation 
    srand(time(NULL));

    printf("\nOriginal array:\n");
    for(int i = 0; i < n; i++)
    {
        a[i] = rand() % 100 + 1;   // avoid too many zeros
        printf("%d ", a[i]);
    }

    start = clock();

    quickSort(a, 0, n - 1);

    end = clock();

    printf("\n\nSorted array:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n\nTime = %f seconds",
           (double)(end - start) / CLOCKS_PER_SEC);

    printf("\nTime Complexity: Best = O(n log n), Worst = O(n^2)");

    return 0;
}
*/

prim 6
#include <stdio.h>

#define INF 9999

int cost[20][20], v[20], n;

int main()
{
    int i, j, u, min, mincost = 0, e = 0;

    scanf("%d", &n);

    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0) cost[i][j] = INF;
        }

    v[1] = 1;

    printf("Edges:\n");

    while(e < n - 1)
    {
        min = INF;

        for(i = 1; i <= n; i++)
            if(v[i])
                for(j = 1; j <= n; j++)
                    if(!v[j] && cost[i][j] < min)
                        min = cost[i][j], u = j;

        printf("%d = %d\n", u, min);

        mincost += min;
        v[u] = 1;
        e++;
    }

    printf("Min Cost = %d", mincost);
}
4

0 2 6 3
2 0 5 0
6 5 0 4
3 0 4 0
Edges:
2 = 2
4 = 3
3 = 4
Min Cost = 9

kruskal 5
#include <stdio.h>

#define INF 9999

int cost[20][20], parent[20], n;

int find(int i)
{
    while(parent[i]) i = parent[i];
    return i;
}

int main()
{
    int i, j, u, v, min, mincost = 0, e = 0;

    scanf("%d", &n);

    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0) cost[i][j] = INF;
        }

    printf("Edges:\n");

    while(e < n - 1)
    {
        min = INF;

        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                if(cost[i][j] < min)
                    min = cost[i][j], u = i, v = j;

        int a = find(u), b = find(v);

        if(a != b)
        {
            printf("%d-%d = %d\n", u, v, min);
            mincost += min;
            e++;
            parent[b] = a;
        }

        cost[u][v] = cost[v][u] = INF;
    }

    printf("Min Cost = %d", mincost);
}
4

0 2 6 3
2 0 5 0
6 5 0 4
3 0 4 0
Edges:
1-2 = 2
1-4 = 3
3-4 = 4
Min Cost = 9

dijikstra 7
#include <stdio.h>

#define INF 9999

int cost[20][20], n;

void dijkstra(int s)
{
    int d[20], v[20]={0}, i, j, u, min;

    for(i=1;i<=n;i++)
        d[i]=cost[s][i];

    d[s]=0; v[s]=1;

    for(i=1;i<n;i++)
    {
        min=INF;
        for(j=1;j<=n;j++)
            if(!v[j] && d[j]<min)
                min=d[j], u=j;

        v[u]=1;

        for(j=1;j<=n;j++)
            if(!v[j] && d[u]+cost[u][j]<d[j])
                d[j]=d[u]+cost[u][j];
    }

    printf("\nShortest Path:\n");
    for(i=1;i<=n;i++)
        printf("%d -> %d = %d\n", s, i, d[i]);
}

int main()
{
    int i,j,s;

    scanf("%d",&n);

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0 && i!=j) cost[i][j]=INF;
        }

    scanf("%d",&s);

    dijkstra(s);

    printf("\nTime Complexity = O(V^2)");
    return 0;
}
4

0 2 4 1
2 0 0 7
4 0 0 3
1 7 3 0

1
Shortest Path:
1 -> 1 = 0
1 -> 2 = 2
1 -> 3 = 4
1 -> 4 = 1

Time Complexity = O(V^2)

/*
#include <stdio.h>

#define INF 9999

int cost[20][20], dist[20], v[20], n;

int main()
{
    int i, j, u, min, src;

    scanf("%d", &n);

    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0 && i != j) cost[i][j] = INF;
        }

    scanf("%d", &src);

    for(i = 1; i <= n; i++)
        dist[i] = cost[src][i], v[i] = 0;

    dist[src] = 0;
    v[src] = 1;

    for(i = 1; i < n; i++)
    {
        min = INF;

        for(j = 1; j <= n; j++)
            if(!v[j] && dist[j] < min)
                min = dist[j], u = j;

        v[u] = 1;

        for(j = 1; j <= n; j++)
            if(!v[j] && dist[u] + cost[u][j] < dist[j])
                dist[j] = dist[u] + cost[u][j];
    }

    printf("Shortest distances:\n");
    for(i = 1; i <= n; i++)
        printf("%d -> %d\n", i, dist[i]);

    printf("Time = O(V^2)");

    return 0;
}
*/
