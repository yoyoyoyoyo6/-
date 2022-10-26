//图的邻接矩阵（Adjacency Matrix）存储方式是用两个数组来表示图。一个一维数组存储图中顶点信息，一个二维数组（称为邻接矩阵）存储图中的边或弧的信息。

/*图反映的信息方便：判定任意两结点是否有边；知道某结点的度，其实就是这个顶点 vi 在邻接矩阵中第i行/列的元素之和；求顶点的所有邻接点就是将矩阵中第i行元素扫描一遍，
arc[i][j]为1的就是该顶点的邻接点。
注意：有向图中顶点的入度是该顶点列各数之和，出度是该顶点行各数之和。*/

typedef char VertexType; //顶点类型
typedef int EdgeType; //边上的权值类型
#define MAXVER 100  //最大顶点数
#define INFINITY 9999  //用该数来代替无穷大，网无指向时就用无穷代替

//存储结构
typedef struct MGraph {
	VertexType vexs[MAXVER];  //顶点表
	EdgeType arc[MAXVER][MAXVER]; //领接矩阵，边表
	int numVertexes, numEdges; //图中当前顶点数和边数
}MGraph;

//创建邻接矩阵
void createMGraph(MGraph* G)
{
	printf("请输入顶点数和边数:");
	int n, m;
	scanf("%d %d", &n, &m);
	G->numVertexes = n;
	G->numEdges = m;
	printf("请输入%d个顶点\n", n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", G->vexs[i]); //顶点编号
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			G->arc[i][j] = INFINITY;
		}
	}
}


//打印领接矩阵的图
void printMGraph(MGraph *G) {
	for (int i = 0; i < G->numVertexes; i++) {
		printf("第%d个顶点是%s\n", i + 1, G->vexs[i]);
	}
}

//测试
int main()
{
	MGraph G;
	createMGraph(&G);
	printMGraph(&G);
	return 0;
}
