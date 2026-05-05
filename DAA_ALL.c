slip 1 (q1,q2)
#include <stdio.h>
#include <time.h>

void selectionSort(int a[], int n)
{
	int i,j,min,temp;

	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
				min=j;
		}

		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
}

int main()
{
	int a[100],n,i;
	clock_t start,end;
	double t;

	printf("Enter n: ");
	scanf("%d",&n);

	printf("Enter elements:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	start=clock();

	selectionSort(a,n);

	end=clock();

	printf("Sorted list:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);

	t=(double)(end-start)/CLOCKS_PER_SEC;
	printf("\nTime = %f seconds\n",t);

	return 0;
}
Enter n: 5
Enter elements:
64 25 12 22 11

Sorted list:
11 12 22 25 64 
Time = 0.000001 seconds

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

/* Swap function */
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* Partition function */
int partition(int a[], int low, int high)
{
	int pivot = a[high];
	int i = low - 1, j;

	for(j = low; j < high; j++)
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

/* Quick Sort */
void quickSort(int a[], int low, int high)
{
	if(low < high)
	{
		int pi = partition(a, low, high);
		quickSort(a, low, pi-1);
		quickSort(a, pi+1, high);
	}
}

int main()
{
	int a[MAX], n, i;
	clock_t start, end;
	double time_taken;

	printf("Enter n: ");
	scanf("%d", &n);

	/* Generate random elements */
	srand(time(0));
	for(i = 0; i < n; i++)
		a[i] = rand() % 1000;

	for(i = 0; i < n; i++)
		printf("%d\t",a[i]);
	printf("\n");


	start = clock();

	quickSort(a, 0, n-1);

	end = clock();

	printf("\nSorted elements:\n");
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);

	time_taken = (double)(end - start) / CLOCKS_PER_SEC;

	printf("\nTime taken = %f seconds", time_taken);

	return 0;
}
Enter n: 10
532	121	876	45	999	210	67	432	89	300
Sorted elements:
45 67 89 121 210 300 432 532 876 999
Time taken = 0.000002 seconds

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int a[], int low, int high)
{
	int pivot = a[high];
	int i = low - 1, j;

	for(j = low; j < high; j++)
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
		quickSort(a, low, pi-1);
		quickSort(a, pi+1, high);
	}
}

int main()
{
	FILE *fp;
	int a[MAX], n, i;
	clock_t start, end;
	double time_taken;

	fp = fopen("input.txt", "r");

	if(fp == NULL)
	{
		printf("File not found\n");
		return 1;
	}

	fscanf(fp, "%d", &n);

	for(i = 0; i < n; i++)
		fscanf(fp, "%d", &a[i]);

	fclose(fp);

	start = clock();

	quickSort(a, 0, n-1);

	end = clock();

	printf("\nSorted elements:\n");
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);

	time_taken = (double)(end - start) / CLOCKS_PER_SEC;

	printf("\nTime taken = %f seconds", time_taken);

	return 0;
}
input.txt
6 
45 12 78 34 23 90
Sorted elements:
12 23 34 45 78 90 
Time taken = 0.000001 seconds

#include <stdio.h>   
#include <stdlib.h>
#include <time.h>

int main()
{
	FILE *fp;
	int n, i;

	printf("Enter number of elements to generate: ");
	scanf("%d", &n);

	fp = fopen("input.txt", "w");

	if(fp == NULL)
	{
		printf("Error creating file!\n");
		return 1;
	}

	srand(time(0));   
	fprintf(fp, "%d\n", n);

	for(i = 0; i < n; i++)
	{
		int num = rand() % 1000;  
		fprintf(fp, "%d ", num);  
	}

	fclose(fp);

	printf("\ninput.txt file generated successfully with %d numbers.\n", n);

	return 0;
}




slip 3 (q2,q6)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

	/* Swap function */
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* Partition function */
int partition(int a[], int low, int high)
{
	int pivot = a[high];
	int i = low - 1, j;

	for(j = low; j < high; j++)
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

/* Quick Sort */
void quickSort(int a[], int low, int high)
{
	if(low < high)
	{
		int pi = partition(a, low, high);
		quickSort(a, low, pi-1);
		quickSort(a, pi+1, high);
	}
}

int main()
{
	int a[MAX], n, i;
	clock_t start, end;
	double time_taken;

	printf("Enter n: ");
	scanf("%d", &n);

	/* Generate random elements */
	srand(time(0));
	for(i = 0; i < n; i++)
		a[i] = rand() % 1000;

	for(i = 0; i < n; i++)
		printf("%d\t",a[i]);
	printf("\n");


	start = clock();

	quickSort(a, 0, n-1);

	end = clock();

	printf("\nSorted elements:\n");
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);

	time_taken = (double)(end - start) / CLOCKS_PER_SEC;

	printf("\nTime taken = %f seconds", time_taken);

	return 0;
}
Enter n: 10
532	121	876	45	999	210	67	432	89	300
Sorted elements:
45 67 89 121 210 300 432 532 876 999
Time taken = 0.000002 seconds

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int a[], int low, int high)
{
	int pivot = a[high];
	int i = low - 1, j;

	for(j = low; j < high; j++)
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
		quickSort(a, low, pi-1);
		quickSort(a, pi+1, high);
	}
}

int main()
{
	FILE *fp;
	int a[MAX], n, i;
	clock_t start, end;
	double time_taken;

	fp = fopen("input.txt", "r");

	if(fp == NULL)
	{
		printf("File not found\n");
		return 1;
	}

	fscanf(fp, "%d", &n);

	for(i = 0; i < n; i++)
		fscanf(fp, "%d", &a[i]);

	fclose(fp);

	start = clock();

	quickSort(a, 0, n-1);

	end = clock();

	printf("\nSorted elements:\n");
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);

	time_taken = (double)(end - start) / CLOCKS_PER_SEC;

	printf("\nTime taken = %f seconds", time_taken);

	return 0;
}
input.txt
6 
45 12 78 34 23 90
Sorted elements:
12 23 34 45 78 90 
Time taken = 0.000001 seconds

#include <stdio.h>   
#include <stdlib.h>
#include <time.h>

int main()
{
	FILE *fp;
	int n, i;

	printf("Enter number of elements to generate: ");
	scanf("%d", &n);

	fp = fopen("input.txt", "w");

	if(fp == NULL)
	{
		printf("Error creating file!\n");
		return 1;
	}

	srand(time(0));   
	fprintf(fp, "%d\n", n);

	for(i = 0; i < n; i++)
	{
		int num = rand() % 1000;  
		fprintf(fp, "%d ", num);  
	}

	fclose(fp);

	printf("\ninput.txt file generated successfully with %d numbers.\n", n);

	return 0;
}


#include <stdio.h>

#define MAX 20
#define INF 9999

void prim(int cost[MAX][MAX], int n)
{
	int visited[MAX] = {0};
	int i, j, min, u = 1, v = 1;
	int edge_count = 0, mincost = 0;

	visited[1] = 1;

	printf("\nEdges in MST:\n");

	while(edge_count < n-1)
	{
		min = INF;

		for(i = 1; i <= n; i++)
		{
			if(visited[i])
			{
				for(j = 1; j <= n; j++)
				{
					if(!visited[j] && cost[i][j] < min)
					{
						min = cost[i][j];
						u = i;
						v = j;
					}
				}
			}
		}

		printf("(%d -> %d) = %d\n", u, v, min);

		mincost += min;
		visited[v] = 1;
		edge_count++;
	}

	printf("\nMinimum Cost = %d\n", mincost);
}

int main()
{
	int cost[MAX][MAX], n, i, j;

	printf("Enter number of vertices: ");
	scanf("%d", &n);

	printf("Enter cost matrix:\n");

	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
		{
			scanf("%d", &cost[i][j]);

			if(cost[i][j] == 0)
				cost[i][j] = INF;
		}
	}

	prim(cost, n);

	return 0;
}
Enter number of vertices: 4
Enter cost matrix:
0 2 0 6
2 0 3 8
0 3 0 0
6 8 0 0
Edges in MST:
(1 -> 2) = 2
(2 -> 3) = 3
(1 -> 4) = 6
Minimum Cost = 11




slip 5 (q5,q10)
#include <stdio.h>

#define MAX 20
#define INF 9999

int find(int parent[], int i)
{
	while(parent[i])
		i = parent[i];
	return i;
}

void unionSet(int parent[], int i, int j)
{
	parent[j] = i;
}

int main()
{
	int cost[MAX][MAX], parent[MAX] = {0};
	int i, j, n;
	int u, v, a, b;
	int min, mincost = 0, edge_count = 0;

	printf("Enter number of vertices: ");
	scanf("%d", &n);

	printf("Enter cost matrix:\n");

	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
		{
			scanf("%d", &cost[i][j]);
			if(cost[i][j] == 0)
				cost[i][j] = INF;
		}
	}

	printf("\nEdges in MST:\n");

	while(edge_count < n-1)
	{
		min = INF;

		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= n; j++)
			{
				if(cost[i][j] < min)
				{
					min = cost[i][j];
					u = i;
					v = j;
				}
			}
		}

		a = find(parent, u);
		b = find(parent, v);

		if(a != b)
		{
			printf("(%d -> %d) = %d\n", u, v, min);
			mincost += min;
			unionSet(parent, a, b);
			edge_count++;
		}

		cost[u][v] = cost[v][u] = INF;
	}

	printf("\nMinimum Cost = %d\n", mincost);

	return 0;
}
Enter number of vertices: 4
Enter cost matrix:
0 2 0 6
2 0 3 8
0 3 0 0
6 8 0 0
Edges in MST:
(1 -> 2) = 2
(2 -> 3) = 3
(1 -> 4) = 6
Minimum Cost = 11

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node
{
	char data;
	int freq;
	struct Node *left, *right;
};

struct Node* createNode(char data, int freq)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->freq = freq;
	newNode->left = newNode->right = NULL;
	return newNode;
}

void swap(struct Node** a, struct Node** b)
{
	struct Node* t = *a;
	*a = *b;
	*b = t;
}

void sort(struct Node* arr[], int n)
{
	for(int i = 0; i < n-1; i++)
		for(int j = 0; j < n-i-1; j++)
			if(arr[j]->freq > arr[j+1]->freq)
				swap(&arr[j], &arr[j+1]);
}

void printCodes(struct Node* root, int code[], int top)
{
	if(root->left)
	{
		code[top] = 0;
		printCodes(root->left, code, top+1);
	}

	if(root->right)
	{
		code[top] = 1;
		printCodes(root->right, code, top+1);
	}

	if(!root->left && !root->right)
	{
		printf("%c : ", root->data);
		for(int i = 0; i < top; i++)
			printf("%d", code[i]);
		printf("\n");
	}
}

void huffman(char data[], int freq[], int n)
{
	struct Node* nodes[MAX];

	for(int i = 0; i < n; i++)
		nodes[i] = createNode(data[i], freq[i]);

	int size = n;

	while(size > 1)
	{
		sort(nodes, size);

		struct Node* left = nodes[0];
		struct Node* right = nodes[1];

		struct Node* newNode = createNode('$', left->freq + right->freq);
		newNode->left = left;
		newNode->right = right;

		nodes[0] = newNode;

		for(int i = 1; i < size-1; i++)
			nodes[i] = nodes[i+1];

		size--;
	}

	int code[MAX];
	printf("\nHuffman Codes:\n");
	printCodes(nodes[0], code, 0);
}

int main()
{
	char data[MAX];
	int freq[MAX], n;

	printf("Enter number of characters: ");
	scanf("%d", &n);

	printf("Enter characters:\n");
	for(int i = 0; i < n; i++)
		scanf(" %c", &data[i]);

	printf("Enter frequencies:\n");
	for(int i = 0; i < n; i++)
		scanf("%d", &freq[i]);

	huffman(data, freq, n);

	printf("\nBest Case  : O(n log n)");
	printf("\nWorst Case : O(n log n)\n");

	return 0;
}
Enter number of characters: 4
Enter characters:
A B C D
Enter frequencies:
5 9 12 13
Huffman Codes:
D : 0
C : 10
A : 110
B : 111
Best Case  : O(n log n)
Worst Case : O(n log n)




slip 6 (q6,q22)
#include <stdio.h>

#define MAX 20
#define INF 9999

void prim(int cost[MAX][MAX], int n)
{
	int visited[MAX] = {0};
	int i, j, min, u = 1, v = 1;
	int edge_count = 0, mincost = 0;

	visited[1] = 1;

	printf("\nEdges in MST:\n");

	while(edge_count < n-1)
	{
		min = INF;

		for(i = 1; i <= n; i++)
		{
			if(visited[i])
			{
				for(j = 1; j <= n; j++)
				{
					if(!visited[j] && cost[i][j] < min)
					{
						min = cost[i][j];
						u = i;
						v = j;
					}
				}
			}
		}

		printf("(%d -> %d) = %d\n", u, v, min);

		mincost += min;
		visited[v] = 1;
		edge_count++;
	}

	printf("\nMinimum Cost = %d\n", mincost);
}

int main()
{
	int cost[MAX][MAX], n, i, j;

	printf("Enter number of vertices: ");
	scanf("%d", &n);

	printf("Enter cost matrix:\n");

	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
		{
			scanf("%d", &cost[i][j]);

			if(cost[i][j] == 0)
				cost[i][j] = INF;
		}
	}

	prim(cost, n);

	return 0;
}
Enter number of vertices: 4
Enter cost matrix:
0 2 0 6
2 0 3 8
0 3 0 0
6 8 0 0
Edges in MST:
(1 -> 2) = 2
(2 -> 3) = 3
(1 -> 4) = 6
Minimum Cost = 11

#include <stdio.h>
#include <string.h>

#define MAX 100

int main()
{
	char X[MAX], Y[MAX];
	int L[MAX][MAX];
	int m, n, i, j;

	printf("Enter first string: ");
	scanf("%s", X);

	printf("Enter second string: ");
	scanf("%s", Y);

	m = strlen(X);
	n = strlen(Y);

	/* Build DP table */
	for(i = 0; i <= m; i++)
	{
		for(j = 0; j <= n; j++)
		{
			if(i == 0 || j == 0)
				L[i][j] = 0;
			else if(X[i-1] == Y[j-1])
				L[i][j] = L[i-1][j-1] + 1;
			else
				L[i][j] = (L[i-1][j] > L[i][j-1]) ? L[i-1][j] : L[i][j-1];
		}
	}

	printf("\nLength of LCS = %d\n", L[m][n]);

	return 0;
}
Enter first string: ABCDGH
Enter second string: AEDFHR
Length of LCS = 3




slip 7 (q7,q14)
#include <stdio.h>

#define MAX 20
#define INF 9999

void dijkstra(int cost[MAX][MAX], int n, int source)
{
	int dist[MAX], visited[MAX] = {0};
	int i, j, u, min;

	/* Initialize distances */
	for(i = 1; i <= n; i++)
		dist[i] = cost[source][i];

	dist[source] = 0;
	visited[source] = 1;

	for(i = 1; i < n; i++)
	{
		min = INF;

		/* Find nearest unvisited vertex */
		for(j = 1; j <= n; j++)
		{
			if(!visited[j] && dist[j] < min)
			{
				min = dist[j];
				u = j;
			}
		}

		visited[u] = 1;

		/* Update distances */
		for(j = 1; j <= n; j++)
		{
			if(!visited[j] && dist[u] + cost[u][j] < dist[j])
				dist[j] = dist[u] + cost[u][j];
		}
	}

	printf("\nShortest distances from vertex %d:\n", source);

	for(i = 1; i <= n; i++)
		printf("%d -> %d = %d\n", source, i, dist[i]);
}

int main()
{
	int cost[MAX][MAX], n, i, j, source;

	printf("Enter number of vertices: ");
	scanf("%d", &n);

	printf("Enter cost matrix:\n");

	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
		{
			scanf("%d", &cost[i][j]);

			if(cost[i][j] == 0 && i != j)
				cost[i][j] = INF;
		}
	}

	printf("Enter source vertex: ");
	scanf("%d", &source);

	dijkstra(cost, n, source);

	return 0;
}
Enter number of vertices: 4
Enter cost matrix:
0 1 4 0
1 0 4 2
4 4 0 3
0 2 3 0
Enter source vertex: 1
Shortest distances from vertex 1:
1 -> 1 = 0
1 -> 2 = 1
1 -> 3 = 4
1 -> 4 = 3

#include <stdio.h>

#define MAX 20

int stack[MAX], top = -1;

void push(int v)
{
	stack[++top] = v;
}

void DFS(int graph[MAX][MAX], int visited[], int v, int n)
{
	visited[v] = 1;

	for(int i = 1; i <= n; i++)
	{
		if(graph[v][i] && !visited[i])
			DFS(graph, visited, i, n);
	}

	push(v);
}

void topologicalSort(int graph[MAX][MAX], int n)
{
	int visited[MAX] = {0};

	for(int i = 1; i <= n; i++)
	{
		if(!visited[i])
			DFS(graph, visited, i, n);
	}

	printf("\nTopological Order:\n");

	while(top != -1)
		printf("%d ", stack[top--]);
}

int main()
{
	int graph[MAX][MAX], n, i, j;

	printf("Enter number of vertices: ");
	scanf("%d", &n);

	printf("Enter adjacency matrix:\n");

	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			scanf("%d", &graph[i][j]);

	topologicalSort(graph, n);

	return 0;
}
Enter number of vertices: 6
Enter adjacency matrix:
0 1 1 0 0 0
0 0 0 1 0 0
0 0 0 1 1 0
0 0 0 0 0 1
0 0 0 0 0 1
0 0 0 0 0 0
Topological Order:
1 3 5 2 4 6




slip 9 (q9,q18)
#include <stdio.h>

#define MAX 20
#define INF 9999

	/* Find sum of frequencies from i to j */
int sum(int freq[], int i, int j)
{
	int s = 0;
	for(int k = i; k <= j; k++)
		s += freq[k];
	return s;
}

/* OBST function */
int optimalBST(int keys[], int freq[], int n)
{
	int cost[MAX][MAX];
	int i, j, r, L;

	/* Base case: single key */
	for(i = 0; i < n; i++)
		cost[i][i] = freq[i];

	/* L = length of chain */
	for(L = 2; L <= n; L++)
	{
		for(i = 0; i <= n - L; i++)
		{
			j = i + L - 1;
			cost[i][j] = INF;

			int fsum = sum(freq, i, j);

			for(r = i; r <= j; r++)
			{
				int c = fsum;

				if(r > i)
					c += cost[i][r-1];
				if(r < j)
					c += cost[r+1][j];

				if(c < cost[i][j])
					cost[i][j] = c;
			}
		}
	}

	return cost[0][n-1];
}

int main()
{
	int keys[MAX], freq[MAX];
	int n, i;

	printf("Enter number of keys: ");
	scanf("%d", &n);

	printf("Enter keys:\n");
	for(i = 0; i < n; i++)
		scanf("%d", &keys[i]);

	printf("Enter frequencies:\n");
	for(i = 0; i < n; i++)
		scanf("%d", &freq[i]);

	int result = optimalBST(keys, freq, n);

	printf("\nOptimal BST Cost = %d\n", result);

	printf("\nBest Case  : O(n^2)");
	printf("\nWorst Case : O(n^3)\n");

	return 0;
}
Enter number of keys: 3
Enter keys:
10 20 30
Enter frequencies:
34 8 50
Optimal BST Cost = 142
Best Case  : O(n^2)
Worst Case : O(n^3)

#include <stdio.h>

#define MAX 20

int w[MAX], x[MAX];
int n, target;

/* Print subset */
void printSolution()
{
	printf("Subset: ");
	for(int i = 0; i < n; i++)
		if(x[i])
			printf("%d ", w[i]);
	printf("\n");
}

/* Backtracking function */
void sumOfSubsets(int s, int k, int r)
{
	if(s == target)
	{
		printSolution();
		return;
	}

	if(k < n)
	{
		/* Include element */
		if(s + w[k] <= target)
		{
			x[k] = 1;
			sumOfSubsets(s + w[k], k + 1, r - w[k]);
		}

		/* Exclude element */
		if(s + r - w[k] >= target)
		{
			x[k] = 0;
			sumOfSubsets(s, k + 1, r - w[k]);
		}
	}
}

int main()
{
	int total = 0;

	printf("Enter number of elements: ");
	scanf("%d", &n);

	printf("Enter elements:\n");
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &w[i]);
		total += w[i];
	}

	printf("Enter target sum: ");
	scanf("%d", &target);

	printf("\nSubsets with sum %d:\n", target);

	sumOfSubsets(0, 0, total);

	return 0;
}
Enter number of elements: 4
Enter elements:
1 2 5 6
Enter target sum: 7
Subsets with sum 7:
Subset: 1 6 
Subset: 2 5 




slip 10 (q10,q20)
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

	struct Node
{
	char data;
	int freq;
	struct Node *left, *right;
};

struct Node* createNode(char data, int freq)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->freq = freq;
	newNode->left = newNode->right = NULL;
	return newNode;
}

void swap(struct Node** a, struct Node** b)
{
	struct Node* t = *a;
	*a = *b;
	*b = t;
}

void sort(struct Node* arr[], int n)
{
	for(int i = 0; i < n-1; i++)
		for(int j = 0; j < n-i-1; j++)
			if(arr[j]->freq > arr[j+1]->freq)
				swap(&arr[j], &arr[j+1]);
}

void printCodes(struct Node* root, int code[], int top)
{
	if(root->left)
	{
		code[top] = 0;
		printCodes(root->left, code, top+1);
	}

	if(root->right)
	{
		code[top] = 1;
		printCodes(root->right, code, top+1);
	}

	if(!root->left && !root->right)
	{
		printf("%c : ", root->data);
		for(int i = 0; i < top; i++)
			printf("%d", code[i]);
		printf("\n");
	}
}

void huffman(char data[], int freq[], int n)
{
	struct Node* nodes[MAX];

	for(int i = 0; i < n; i++)
		nodes[i] = createNode(data[i], freq[i]);

	int size = n;

	while(size > 1)
	{
		sort(nodes, size);

		struct Node* left = nodes[0];
		struct Node* right = nodes[1];

		struct Node* newNode = createNode('$', left->freq + right->freq);
		newNode->left = left;
		newNode->right = right;

		nodes[0] = newNode;

		for(int i = 1; i < size-1; i++)
			nodes[i] = nodes[i+1];

		size--;
	}

	int code[MAX];
	printf("\nHuffman Codes:\n");
	printCodes(nodes[0], code, 0);
}

int main()
{
	char data[MAX];
	int freq[MAX], n;

	printf("Enter number of characters: ");
	scanf("%d", &n);

	printf("Enter characters:\n");
	for(int i = 0; i < n; i++)
		scanf(" %c", &data[i]);

	printf("Enter frequencies:\n");
	for(int i = 0; i < n; i++)
		scanf("%d", &freq[i]);

	huffman(data, freq, n);

	printf("\nBest Case  : O(n log n)");
	printf("\nWorst Case : O(n log n)\n");

	return 0;
}
Enter number of characters: 6
Enter characters:
A B C D E F
Enter frequencies:
5 9 12 13 16 45
Huffman Codes:
F : 0
C : 100
D : 101
A : 1100
B : 1101
E : 111
Best Case  : O(n log n)
Worst Case : O(n log n)

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int board[MAX], n;

/* Check if safe to place queen */
int isSafe(int row, int col)
{
	for(int i = 0; i < row; i++)
	{
		if(board[i] == col || abs(board[i] - col) == abs(i - row))
			return 0;
	}
	return 1;
}

/* Print solution */
void printSolution()
{
	printf("\nSolution:\n");

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(board[i] == j)
				printf("Q ");
			else
				printf(". ");
		}
		printf("\n");
	}
}

/* Backtracking function */
void solve(int row)
{
	if(row == n)
	{
		printSolution();
		return;
	}

	for(int col = 0; col < n; col++)
	{
		if(isSafe(row, col))
		{
			board[row] = col;
			solve(row + 1);
		}
	}
}

int main()
{
	printf("Enter number of queens: ");
	scanf("%d", &n);

	solve(0);

	return 0;
}
Enter number of queens: 4

Solution:
. Q . .
. . . Q
Q . . .
. . Q .

Solution:
. . Q .
Q . . .
. . . Q
. Q . .




slip 11 (q13,q7)
#include <stdio.h>

#define MAX 20

	int queue[MAX], front = -1, rear = -1;

	/* BFS */
void BFS(int graph[MAX][MAX], int n, int start)
{
	int visited[MAX] = {0};

	queue[++rear] = start;
	visited[start] = 1;

	printf("\nBFS: ");

	while(front != rear)
	{
		int v = queue[++front];
		printf("%d ", v);

		for(int i = 1; i <= n; i++)
		{
			if(graph[v][i] && !visited[i])
			{
				queue[++rear] = i;
				visited[i] = 1;
			}
		}
	}
}

/* DFS */
void DFS(int graph[MAX][MAX], int visited[], int v, int n)
{
	printf("%d ", v);
	visited[v] = 1;

	for(int i = 1; i <= n; i++)
	{
		if(graph[v][i] && !visited[i])
			DFS(graph, visited, i, n);
	}
}

int main()
{
	int graph[MAX][MAX], visited[MAX] = {0};
	int n, i, j, start;

	printf("Enter number of vertices: ");
	scanf("%d", &n);

	printf("Enter adjacency matrix:\n");

	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			scanf("%d", &graph[i][j]);

	printf("Enter starting vertex: ");
	scanf("%d", &start);

	printf("\nDFS: ");
	DFS(graph, visited, start, n);

	BFS(graph, n, start);

	/* Time Complexity Output */
	printf("\n\nTime Complexity:");
	printf("\nDFS = O(V + E)");
	printf("\nBFS = O(V + E)\n");

	return 0;
}
Enter number of vertices: 5
Enter adjacency matrix:
0 1 1 0 0
1 0 0 1 1
1 0 0 0 0
0 1 0 0 0
0 1 0 0 0
Enter starting vertex: 1
DFS: 1 2 4 5 3 
BFS: 1 2 3 4 5 
Time Complexity:
	DFS = O(V + E)
BFS = O(V + E)

#include <stdio.h>

#define MAX 20
#define INF 9999

void dijkstra(int cost[MAX][MAX], int n, int source)
{
	int dist[MAX], visited[MAX] = {0};
	int i, j, u, min;

	/* Initialize distances */
	for(i = 1; i <= n; i++)
		dist[i] = cost[source][i];

	dist[source] = 0;
	visited[source] = 1;

	for(i = 1; i < n; i++)
	{
		min = INF;

		/* Find nearest unvisited vertex */
		for(j = 1; j <= n; j++)
		{
			if(!visited[j] && dist[j] < min)
			{
				min = dist[j];
				u = j;
			}
		}

		visited[u] = 1;

		/* Update distances */
		for(j = 1; j <= n; j++)
		{
			if(!visited[j] && dist[u] + cost[u][j] < dist[j])
				dist[j] = dist[u] + cost[u][j];
		}
	}

	printf("\nShortest distances from vertex %d:\n", source);

	for(i = 1; i <= n; i++)
		printf("%d -> %d = %d\n", source, i, dist[i]);
}

int main()
{
	int cost[MAX][MAX], n, i, j, source;

	printf("Enter number of vertices: ");
	scanf("%d", &n);

	printf("Enter cost matrix:\n");

	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
		{
			scanf("%d", &cost[i][j]);

			if(cost[i][j] == 0 && i != j)
				cost[i][j] = INF;
		}
	}

	printf("Enter source vertex: ");
	scanf("%d", &source);

	dijkstra(cost, n, source);

	return 0;
}
Enter number of vertices: 5
Enter cost matrix:
0 10 0 30 100
10 0 50 0 0
0 50 0 20 10
30 0 20 0 60
100 0 10 60 0
Enter source vertex: 1
Shortest distances from vertex 1:
1 -> 1 = 0
1 -> 2 = 10
1 -> 3 = 50
1 -> 4 = 30
1 -> 5 = 60




slip 12 (q13,q1)
#include <stdio.h>
#include <time.h>

void selectionSort(int a[], int n)
{
	int i,j,min,temp;

	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
				min=j;
		}

		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
}

int main()
{
	int a[100],n,i;
	clock_t start,end;
	double t;

	printf("Enter n: ");
	scanf("%d",&n);

	printf("Enter elements:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	start=clock();

	selectionSort(a,n);

	end=clock();

	printf("Sorted list:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);

	t=(double)(end-start)/CLOCKS_PER_SEC;
	printf("\nTime = %f seconds\n",t);

	return 0;
}
Enter n: 6
Enter elements:
64 25 12 22 11 90
Sorted list:
11 12 22 25 64 90 
Time = 0.000001 seconds

#include <stdio.h>
#include <time.h>

#define MAX 20

int queue[MAX], front = -1, rear = -1;

/* BFS */
void BFS(int graph[MAX][MAX], int n, int start)
{
	int visited[MAX] = {0};

	front = rear = -1;   // reset queue

	queue[++rear] = start;
	visited[start] = 1;

	while(front != rear)
	{
		int v = queue[++front];
		printf("%d ", v);

		for(int i = 1; i <= n; i++)
		{
			if(graph[v][i] && !visited[i])
			{
				queue[++rear] = i;
				visited[i] = 1;
			}
		}
	}
}

/* DFS */
void DFS(int graph[MAX][MAX], int visited[], int v, int n)
{
	printf("%d ", v);
	visited[v] = 1;

	for(int i = 1; i <= n; i++)
	{
		if(graph[v][i] && !visited[i])
			DFS(graph, visited, i, n);
	}
}

int main()
{
	int graph[MAX][MAX], visited[MAX] = {0};
	int n, i, j, start;

	clock_t start_t, end_t;
	double time_taken;

	printf("Enter number of vertices: ");
	scanf("%d", &n);

	printf("Enter adjacency matrix:\n");

	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			scanf("%d", &graph[i][j]);

	printf("Enter starting vertex: ");
	scanf("%d", &start);

	/* DFS Time */
	printf("\nDFS: ");
	start_t = clock();
	DFS(graph, visited, start, n);
	end_t = clock();

	time_taken = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("\nDFS Time = %f seconds\n", time_taken);

	/* BFS Time */
	printf("\nBFS: ");
	start_t = clock();
	BFS(graph, n, start);
	end_t = clock();

	time_taken = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("\nBFS Time = %f seconds\n", time_taken);

	return 0;
}
Enter number of vertices: 5
Enter adjacency matrix:
0 1 1 0 0
1 0 0 1 1
1 0 0 0 0
0 1 0 0 0
0 1 0 0 0
Enter starting vertex: 1
DFS: 1 2 4 5 3 
DFS Time = 0.000001 seconds
BFS: 1 2 3 4 5 
BFS Time = 0.000001 seconds




slip 13 (q11,q9)
#include <stdio.h>

#define MAX 20
#define INF 999999

	/* Function to find minimum multiplications */
int matrixChain(int p[], int n)
{
	int m[MAX][MAX];
	int i, j, k, L, q;

	/* Cost = 0 when single matrix */
	for(i = 1; i < n; i++)
		m[i][i] = 0;

	/* L = chain length */
	for(L = 2; L < n; L++)
	{
		for(i = 1; i < n - L + 1; i++)
		{
			j = i + L - 1;
			m[i][j] = INF;

			for(k = i; k < j; k++)
			{
				q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];

				if(q < m[i][j])
					m[i][j] = q;
			}
		}
	}

	return m[1][n-1];
}

int main()
{
	int p[MAX];
	int n, i;

	printf("Enter number of matrices: ");
	scanf("%d", &n);

	printf("Enter dimensions (size %d):\n", n+1);

	for(i = 0; i <= n; i++)
		scanf("%d", &p[i]);

	int result = matrixChain(p, n+1);

	printf("\nMinimum multiplications = %d\n", result);

	printf("\nTime Complexity = O(n^3)");
	printf("\nSpace Complexity = O(n^2)\n");

	return 0;
}
Enter number of matrices: 3
Enter dimensions (size 4):
	10 20 30 40
	Minimum multiplications = 18000
	Time Complexity = O(n^3)
	Space Complexity = O(n^2)

#include <stdio.h>

#define MAX 20
#define INF 9999

	/* Find sum of frequencies from i to j */
	int sum(int freq[], int i, int j)
{
	int s = 0;
	for(int k = i; k <= j; k++)
		s += freq[k];
	return s;
}

/* OBST function */
int optimalBST(int keys[], int freq[], int n)
{
	int cost[MAX][MAX];
	int i, j, r, L;

	/* Base case: single key */
	for(i = 0; i < n; i++)
		cost[i][i] = freq[i];

	/* L = length of chain */
	for(L = 2; L <= n; L++)
	{
		for(i = 0; i <= n - L; i++)
		{
			j = i + L - 1;
			cost[i][j] = INF;

			int fsum = sum(freq, i, j);

			for(r = i; r <= j; r++)
			{
				int c = fsum;

				if(r > i)
					c += cost[i][r-1];
				if(r < j)
					c += cost[r+1][j];

				if(c < cost[i][j])
					cost[i][j] = c;
			}
		}
	}

	return cost[0][n-1];
}

int main()
{
	int keys[MAX], freq[MAX];
	int n, i;

	printf("Enter number of keys: ");
	scanf("%d", &n);

	printf("Enter keys:\n");
	for(i = 0; i < n; i++)
		scanf("%d", &keys[i]);

	printf("Enter frequencies:\n");
	for(i = 0; i < n; i++)
		scanf("%d", &freq[i]);

	int result = optimalBST(keys, freq, n);

	printf("\nOptimal BST Cost = %d\n", result);

	printf("\nBest Case  : O(n^2)");
	printf("\nWorst Case : O(n^3)\n");

	return 0;
}
Enter number of keys: 3
Enter keys:
10 20 30
Enter frequencies:
34 8 50
Optimal BST Cost = 142
Best Case  : O(n^2)
Worst Case : O(n^3)




slip 14 (q1,q13)
#include <stdio.h>
#include <time.h>

#define MAX 1000

void insertionSort(int a[], int n)
{
	int i, j, key;

	for(i = 1; i < n; i++)
	{
		key = a[i];
		j = i - 1;

		while(j >= 0 && a[j] > key)
		{
			a[j+1] = a[j];
			j--;
		}

		a[j+1] = key;
	}
}

int main()
{
	int a[MAX], n, i;
	clock_t start, end;
	double time_taken;

	printf("Enter number of elements: ");
	scanf("%d", &n);

	printf("Enter elements:\n");
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);

	start = clock();

	insertionSort(a, n);

	end = clock();

	printf("\nSorted elements:\n");
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);

	time_taken = (double)(end - start) / CLOCKS_PER_SEC;

	printf("\n\nTime taken = %f seconds", time_taken);

	return 0;
}
Enter number of elements: 6
Enter elements:
12 11 13 5 6 7
Sorted elements:
5 6 7 11 12 13 
Time taken = 0.000001 seconds

#include <stdio.h>

#define MAX 20

int queue[MAX], front = -1, rear = -1;

/* BFS */
void BFS(int graph[MAX][MAX], int n, int start)
{
	int visited[MAX] = {0};

	queue[++rear] = start;
	visited[start] = 1;

	printf("\nBFS: ");

	while(front != rear)
	{
		int v = queue[++front];
		printf("%d ", v);

		for(int i = 1; i <= n; i++)
		{
			if(graph[v][i] && !visited[i])
			{
				queue[++rear] = i;
				visited[i] = 1;
			}
		}
	}
}

/* DFS */
void DFS(int graph[MAX][MAX], int visited[], int v, int n)
{
	printf("%d ", v);
	visited[v] = 1;

	for(int i = 1; i <= n; i++)
	{
		if(graph[v][i] && !visited[i])
			DFS(graph, visited, i, n);
	}
}

int main()
{
	int graph[MAX][MAX], visited[MAX] = {0};
	int n, i, j, start;

	printf("Enter number of vertices: ");
	scanf("%d", &n);

	printf("Enter adjacency matrix:\n");

	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			scanf("%d", &graph[i][j]);

	printf("Enter starting vertex: ");
	scanf("%d", &start);

	printf("\nDFS: ");
	DFS(graph, visited, start, n);

	BFS(graph, n, start);

	/* Time Complexity Output */
	printf("\n\nTime Complexity:");
	printf("\nDFS = O(V + E)");
	printf("\nBFS = O(V + E)\n");

	return 0;
}
Enter number of vertices: 5
Enter adjacency matrix:
0 1 1 0 0
1 0 0 1 1
1 0 0 0 0
0 1 0 0 0
0 1 0 0 0
Enter starting vertex: 1
DFS: 1 2 4 5 3 
BFS: 1 2 3 4 5 
Time Complexity:
	DFS = O(V + E)
BFS = O(V + E)




slip 15 (q24,q17)
#include <stdio.h>

#define MAX 20

	int n, W;
	int profit[MAX], weight[MAX];
	int maxProfit = 0;

	/* Node structure */
	struct Node
{
	int level, profit, weight;
	float bound;
};

/* Calculate upper bound (using fractional knapsack idea) */
float bound(struct Node u)
{
	if(u.weight >= W)
		return 0;

	float profit_bound = u.profit;
	int j = u.level + 1;
	int totweight = u.weight;

	while(j < n && totweight + weight[j] <= W)
	{
		totweight += weight[j];
		profit_bound += profit[j];
		j++;
	}

	if(j < n)
		profit_bound += (W - totweight) * ((float)profit[j] / weight[j]);

	return profit_bound;
}

/* LCBB Knapsack */
void knapsack()
{
	struct Node u, v;

	u.level = -1;
	u.profit = 0;
	u.weight = 0;
	u.bound = bound(u);

	struct Node queue[1000];
	int front = 0, rear = 0;

	queue[rear++] = u;

	while(front != rear)
	{
		u = queue[front++];

		if(u.level == n-1)
			continue;

		/* Include next item */
		v.level = u.level + 1;
		v.weight = u.weight + weight[v.level];
		v.profit = u.profit + profit[v.level];

		if(v.weight <= W && v.profit > maxProfit)
			maxProfit = v.profit;

		v.bound = bound(v);

		if(v.bound > maxProfit)
			queue[rear++] = v;

		/* Exclude next item */
		v.weight = u.weight;
		v.profit = u.profit;
		v.bound = bound(v);

		if(v.bound > maxProfit)
			queue[rear++] = v;
	}
}

int main()
{
	printf("Enter number of items: ");
	scanf("%d", &n);

	printf("Enter profits:\n");
	for(int i = 0; i < n; i++)
		scanf("%d", &profit[i]);

	printf("Enter weights:\n");
	for(int i = 0; i < n; i++)
		scanf("%d", &weight[i]);

	printf("Enter capacity: ");
	scanf("%d", &W);

	knapsack();

	printf("\nMaximum Profit = %d\n", maxProfit);

	return 0;
}
Enter number of items: 4
Enter profits:
40 30 50 10
Enter weights:
2 5 10 5
Enter capacity: 16
Maximum Profit = 90

#include <stdio.h>

#define MAX 20

/* Check if color can be assigned */
int isSafe(int graph[MAX][MAX], int color[], int v, int c, int n)
{
	for(int i = 0; i < n; i++)
	{
		if(graph[v][i] && color[i] == c)
			return 0;
	}
	return 1;
}

/* Backtracking function */
int solve(int graph[MAX][MAX], int m, int color[], int v, int n)
{
	if(v == n)
		return 1;

	for(int c = 1; c <= m; c++)
	{
		if(isSafe(graph, color, v, c, n))
		{
			color[v] = c;

			if(solve(graph, m, color, v + 1, n))
				return 1;

			color[v] = 0;   // backtrack
		}
	}
	return 0;
}

/* Graph Coloring */
void graphColoring(int graph[MAX][MAX], int n, int m)
{
	int color[MAX] = {0};

	if(!solve(graph, m, color, 0, n))
	{
		printf("\nNo solution exists\n");
		return;
	}

	printf("\nColor Assignment:\n");
	for(int i = 0; i < n; i++)
		printf("Vertex %d -> Color %d\n", i, color[i]);
}

int main()
{
	int graph[MAX][MAX], n, m;

	printf("Enter number of vertices: ");
	scanf("%d", &n);

	printf("Enter adjacency matrix:\n");
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &graph[i][j]);

	printf("Enter number of colors: ");
	scanf("%d", &m);

	graphColoring(graph, n, m);

	return 0;
}
Enter number of vertices: 4
Enter adjacency matrix:
0 1 1 1
1 0 1 0
1 1 0 1
1 0 1 0
Enter number of colors: 3
Color Assignment:
Vertex 0 -> Color 1
Vertex 1 -> Color 2
Vertex 2 -> Color 3
Vertex 3 -> Color 2



slip 17 (q19,q25)
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

	int board[MAX], n;
	int found = 0;

	/* Check safe position */
int isSafe(int row, int col)
{
	for(int i = 0; i < row; i++)
	{
		if(board[i] == col || abs(board[i] - col) == abs(i - row))
			return 0;
	}
	return 1;
}

/* Print solution */
void printSolution()
{
	found = 1;

	printf("\nSolution:\n");

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(board[i] == j)
				printf("Q ");
			else
				printf(". ");
		}
		printf("\n");
	}
}

/* Backtracking */
void solve(int row)
{
	if(row == n)
	{
		printSolution();
		return;
	}

	for(int col = 0; col < n; col++)
	{
		if(isSafe(row, col))
		{
			board[row] = col;
			solve(row + 1);
		}
	}
}

int main()
{
	printf("Enter number of queens: ");
	scanf("%d", &n);

	solve(0);

	if(!found)
		printf("\nNo solution exists\n");

	return 0;
}
Enter number of queens: 4
Solution:
. Q . .
. . . Q
Q . . .
. . Q .
Solution:
. . Q .
Q . . .
. . . Q
. Q . .

#include <stdio.h>

#define MAX 50

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int main()
{
	int n, W;

	printf("Enter number of items: ");
	scanf("%d", &n);

	int weight[MAX], profit[MAX];

	printf("Enter weights:\n");
	for(int i = 0; i < n; i++)
		scanf("%d", &weight[i]);

	printf("Enter profits:\n");
	for(int i = 0; i < n; i++)
		scanf("%d", &profit[i]);

	printf("Enter capacity: ");
	scanf("%d", &W);

	int dp[MAX][MAX];

	/* Initialize */
	for(int i = 0; i <= n; i++)
		for(int w = 0; w <= W; w++)
			dp[i][w] = 0;

	/* Fill DP table */
	for(int i = 1; i <= n; i++)
	{
		for(int w = 1; w <= W; w++)
		{
			if(weight[i-1] <= w)
			{
				dp[i][w] = max(
						profit[i-1] + dp[i-1][w - weight[i-1]],
						dp[i-1][w]
					      );
			}
			else
			{
				dp[i][w] = dp[i-1][w];
			}
		}
	}

	printf("\nMaximum Profit = %d\n", dp[n][W]);

	return 0;
}
Enter number of items: 4
Enter weights:
2 3 4 5
Enter profits:
3 4 5 6
Enter capacity: 5
Maximum Profit = 7




slip 18 (q17,q23)
#include <stdio.h>

#define MAX 20

	/* Check if color can be assigned */
int isSafe(int graph[MAX][MAX], int color[], int v, int c, int n)
{
	for(int i = 0; i < n; i++)
	{
		if(graph[v][i] && color[i] == c)
			return 0;
	}
	return 1;
}

/* Backtracking function */
int solve(int graph[MAX][MAX], int m, int color[], int v, int n)
{
	if(v == n)
		return 1;

	for(int c = 1; c <= m; c++)
	{
		if(isSafe(graph, color, v, c, n))
		{
			color[v] = c;

			if(solve(graph, m, color, v + 1, n))
				return 1;

			color[v] = 0;   // backtrack
		}
	}
	return 0;
}

/* Graph Coloring */
void graphColoring(int graph[MAX][MAX], int n, int m)
{
	int color[MAX] = {0};

	if(!solve(graph, m, color, 0, n))
	{
		printf("\nNo solution exists\n");
		return;
	}

	printf("\nColor Assignment:\n");
	for(int i = 0; i < n; i++)
		printf("Vertex %d -> Color %d\n", i, color[i]);
}

int main()
{
	int graph[MAX][MAX], n, m;

	printf("Enter number of vertices: ");
	scanf("%d", &n);

	printf("Enter adjacency matrix:\n");
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &graph[i][j]);

	printf("Enter number of colors: ");
	scanf("%d", &m);

	graphColoring(graph, n, m);

	return 0;
}
Enter number of vertices: 4
Enter adjacency matrix:
0 1 1 1
1 0 1 0
1 1 0 1
1 0 1 0
Enter number of colors: 3
Color Assignment:
Vertex 0 -> Color 1
Vertex 1 -> Color 2
Vertex 2 -> Color 3
Vertex 3 -> Color 2

#include <stdio.h>

#define MAX 20

int graph[MAX][MAX], visited[MAX] = {0};
int queue[MAX], front = -1, rear = -1;

/* Enqueue → Live node */
void enqueue(int v)
{
	queue[++rear] = v;
}

/* Dequeue → becomes E-node */
int dequeue()
{
	return queue[++front];
}

/* Display Live Nodes */
void displayLive()
{
	printf("Live Nodes: ");
	for(int i = front + 1; i <= rear; i++)
		printf("%d ", queue[i]);
	printf("\n");
}

int main()
{
	int n, start;

	printf("Enter number of vertices: ");
	scanf("%d", &n);

	printf("Enter adjacency matrix:\n");
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &graph[i][j]);

	printf("Enter starting node: ");
	scanf("%d", &start);

	enqueue(start);
	visited[start] = 1;

	printf("\nNode Classification:\n");

	while(front != rear)
	{
		int current = dequeue();

		printf("\nE-node: %d\n", current);

		for(int i = 0; i < n; i++)
		{
			if(graph[current][i] && !visited[i])
			{
				enqueue(i);
				visited[i] = 1;
			}
		}

		displayLive();

		printf("Dead Node: %d\n", current);
	}

	return 0;
}
Enter number of vertices: 5
Enter adjacency matrix:
0 1 1 0 0
1 0 0 1 1
1 0 0 0 0
0 1 0 0 0
0 1 0 0 0
Enter starting node: 0
Node Classification:
E-node: 0
Live Nodes: 1 2 
Dead Node: 0
E-node: 1
Live Nodes: 2 3 4 
Dead Node: 1
E-node: 2
Live Nodes: 3 4 
Dead Node: 2
E-node: 3
Live Nodes: 4 
Dead Node: 3
E-node: 4
Live Nodes: 
Dead Node: 4




slip 19 (q15,q20)
#include <stdio.h>

#define MAX 20

	/* Check if vertex can be added */
int isSafe(int v, int graph[MAX][MAX], int path[], int pos)
{
	if(graph[path[pos-1]][v] == 0)
		return 0;

	for(int i = 0; i < pos; i++)
		if(path[i] == v)
			return 0;

	return 1;
}

/* Backtracking */
int solve(int graph[MAX][MAX], int path[], int pos, int n)
{
	if(pos == n)
		return graph[path[pos-1]][path[0]];

	for(int v = 1; v < n; v++)
	{
		if(isSafe(v, graph, path, pos))
		{
			path[pos] = v;

			if(solve(graph, path, pos+1, n))
				return 1;

			path[pos] = -1;  // backtrack
		}
	}
	return 0;
}

void hamiltonianCycle(int graph[MAX][MAX], int n)
{
	int path[MAX];

	for(int i = 0; i < n; i++)
		path[i] = -1;

	path[0] = 0;

	if(!solve(graph, path, 1, n))
	{
		printf("\nNo Hamiltonian Cycle exists\n");
		return;
	}

	printf("\nHamiltonian Cycle:\n");
	for(int i = 0; i < n; i++)
		printf("%d ", path[i]);

	printf("%d\n", path[0]);  // return to start
}

int main()
{
	int graph[MAX][MAX], n;

	printf("Enter number of vertices: ");
	scanf("%d", &n);

	printf("Enter adjacency matrix:\n");
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &graph[i][j]);

	hamiltonianCycle(graph, n);

	return 0;
}
Enter number of vertices: 5
Enter adjacency matrix:
0 1 0 1 0
1 0 1 1 1
0 1 0 0 1
1 1 0 0 1
0 1 1 1 0
Hamiltonian Cycle:
0 1 2 4 3 0

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int board[MAX], n;
int found = 0;

/* Check safe position */
int isSafe(int row, int col)
{
	for(int i = 0; i < row; i++)
	{
		if(board[i] == col || abs(board[i] - col) == abs(i - row))
			return 0;
	}
	return 1;
}

/* Print solution */
void printSolution()
{
	found = 1;

	printf("\nSolution:\n");

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(board[i] == j)
				printf("Q ");
			else
				printf(". ");
		}
		printf("\n");
	}
}

/* Backtracking */
void solve(int row)
{
	if(row == n)
	{
		printSolution();
		return;
	}

	for(int col = 0; col < n; col++)
	{
		if(isSafe(row, col))
		{
			board[row] = col;
			solve(row + 1);
		}
	}
}

int main()
{
	printf("Enter number of queens: ");
	scanf("%d", &n);

	solve(0);

	if(!found)
		printf("\nNo solution exists\n");

	return 0;
}
Enter number of queens: 4
Solution:
. Q . .
. . . Q
Q . . .
. . Q .
Solution:
. . Q .
Q . . .
. . . Q
. Q . .




slip 20 (q14,q19)
#include <stdio.h>

#define MAX 20

	int stack[MAX], top = -1;

void push(int v)
{
	stack[++top] = v;
}

void DFS(int graph[MAX][MAX], int visited[], int v, int n)
{
	visited[v] = 1;

	for(int i = 1; i <= n; i++)
	{
		if(graph[v][i] && !visited[i])
			DFS(graph, visited, i, n);
	}

	push(v);
}

void topologicalSort(int graph[MAX][MAX], int n)
{
	int visited[MAX] = {0};

	for(int i = 1; i <= n; i++)
	{
		if(!visited[i])
			DFS(graph, visited, i, n);
	}

	printf("\nTopological Order:\n");

	while(top != -1)
		printf("%d ", stack[top--]);
}

int main()
{
	int graph[MAX][MAX], n, i, j;

	printf("Enter number of vertices: ");
	scanf("%d", &n);

	printf("Enter adjacency matrix:\n");

	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			scanf("%d", &graph[i][j]);

	topologicalSort(graph, n);

	return 0;
}
Enter number of vertices: 6
Enter adjacency matrix:
0 1 1 0 0 0
0 0 0 1 0 0
0 0 0 1 1 0
0 0 0 0 0 1
0 0 0 0 0 1
0 0 0 0 0 0
Topological Order:
1 3 5 2 4 6

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int board[MAX], n;
int found = 0;

/* Check safe position */
int isSafe(int row, int col)
{
	for(int i = 0; i < row; i++)
	{
		if(board[i] == col || abs(board[i] - col) == abs(i - row))
			return 0;
	}
	return 1;
}

/* Print solution */
void printSolution()
{
	found = 1;

	printf("\nSolution:\n");

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(board[i] == j)
				printf("Q ");
			else
				printf(". ");
		}
		printf("\n");
	}
}

/* Backtracking */
void solve(int row)
{
	if(row == n)
	{
		printSolution();
		return;
	}

	for(int col = 0; col < n; col++)
	{
		if(isSafe(row, col))
		{
			board[row] = col;
			solve(row + 1);
		}
	}
}

int main()
{
	printf("Enter number of queens: ");
	scanf("%d", &n);

	solve(0);

	if(!found)
		printf("\nNo solution exists\n");

	return 0;
}
Enter number of queens: 4
Solution:
. Q . .
. . . Q
Q . . .
. . Q .
Solution:
. . Q .
Q . . .
. . . Q
. Q . .
