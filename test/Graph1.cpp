#include <iostream>
#include <queue>
using namespace std;

const int maxEdge = INT32_MAX;
template<typename EdgeType>
class Graph
{
private:
    //邻接矩阵
    struct GraphVertex
    {
        int vertex;
        EdgeType weight;
        GraphVertex* next;
        GraphVertex() : weight(0) , vertex(0) , next(NULL) {}
        GraphVertex(EdgeType mWeight,int mVertex) : weight(mWeight) , vertex(mVertex) , next(NULL) {}
    };
    GraphVertex* graphVertexs;
    bool* isVisit;
    int size;

private:
    void dfs(GraphVertex* currentVertex)
    {
        cout << currentVertex->vertex << " ";
        isVisit[currentVertex->vertex] = true;
        currentVertex = currentVertex->next;
        while (currentVertex)
        {
            if(!isVisit[currentVertex->vertex])
                dfs(graphVertexs+currentVertex->vertex);
            currentVertex = currentVertex->next;
        }
    }

    void bfs(GraphVertex* currentVertex)
    {
        queue<GraphVertex*> vertexQueue;
        vertexQueue.push(currentVertex);
        isVisit[currentVertex->vertex] = true;
        while (!vertexQueue.empty())
        {
            GraphVertex* frontVertex = vertexQueue.front();
            cout << frontVertex->vertex << " ";
            frontVertex = frontVertex->next;
            while(frontVertex)
            {
                if (!isVisit[frontVertex->vertex])
                {
                    isVisit[frontVertex->vertex] = true;
                    vertexQueue.push(graphVertexs+frontVertex->vertex);
                }
                frontVertex = frontVertex->next;
            }
            vertexQueue.pop();
        }
    }
    
public:
    Graph(int mSize = 4) : size(mSize) 
    {
        graphVertexs = new GraphVertex[mSize];
        isVisit = new bool[mSize];
        for (int i = 0 ; i < mSize ; i++)
            isVisit[i] = 0;
    }
    ~Graph()
    {
        delete[] graphVertexs;
        delete[] isVisit;
    }

    bool initGraph()
    {
        for (int i = 0 ; i < size ; i++)
        {
            GraphVertex* pGreaphVertex = graphVertexs+i;
            pGreaphVertex->vertex = i;
            for (int j = 0 ; j < size ; j++)
            {
                EdgeType num;
                cin >> num;
                if (i == j || num == -1)
                    continue;
                GraphVertex* newGraphVertex = new GraphVertex(num,j);
                pGreaphVertex->next = newGraphVertex;
                pGreaphVertex = pGreaphVertex->next;
            }
        }
        return true;
    }

    bool printGraph()
    {
        for (int i = 0 ; i < size ; i++)
        {
            GraphVertex* pGraphVertex = graphVertexs+i;
            while(pGraphVertex)
            {
                cout.width(10);
                cout << "Vertex : " << pGraphVertex->vertex << " "; //<< "   Weight : ";
                //cout << pGraphVertex->weight << " ";
                pGraphVertex = pGraphVertex->next;
            }
            cout << endl;
        }
        return true;
    }

    bool dfsTraverse()
    {
        GraphVertex* currentVertex;
        for (int i = 0 ; i < size ; i++)
        {
            currentVertex = graphVertexs+i;
            if (!isVisit[i])
            {
                dfs(currentVertex);
            }
        }
        return true;
    }

    bool bfsTraverse()
    {
        GraphVertex* currentVertex;
        for (int i = 0 ; i < size ; i++)
        {
            currentVertex = graphVertexs+i;
            if (!isVisit[i])
                bfs(currentVertex);
        }
        return true;
    }

    bool getMinDis(int vertex)
    {
        return false;
    }
};
int main()
{
/*图的数据
0 1 12 -1 -1 -1
-1 0 9 3 -1 -1
-1 -1 0 -1 5 -1
-1 -1 4 0 13 15
-1 -1 -1 -1 0 4
-1 -1 -1 -1 -1 0
*/
/*
0 1 1 -1 -1 -1 -1 -1
1 0 -1 1 1 -1 -1 -1
1 -1 0 -1 -1 1 1 -1
-1 1 -1 0 -1 -1 -1 1
-1 1 -1 -1 0 -1 -1 1
-1 -1 1 -1 -1 0 -1 1
-1 -1 1 -1 -1 -1 0 1
-1 -1 -1 1 1 1 1 0
dfs 0 1 3 7 4 5 2 5
bfs 0 1 2 3 4 5 6 7
*/
    Graph<int> mGraph(8);
    mGraph.initGraph();
    mGraph.printGraph();
    cout << endl;
#if 0
    mGraph.getMinDis(0);
    mGraph.dfsTraverse();
    mGraph.bfsTraverse();
#endif

    return 0;
}