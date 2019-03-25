#include <iostream>
#include <queue>
using namespace std;

const int maxEdge = INT32_MAX;
template<typename EdgeType>
class Graph
{
private:
    //邻接矩阵
    EdgeType** arc;
    bool* vertexIsVisit;
    int size;

private:
    void dfs(int currentVertex)
    {
        cout << currentVertex << " ";
        vertexIsVisit[currentVertex] = true;
        for (int i = 0 ; i < size ; i++)
        {
            if(arc[currentVertex][i] != maxEdge && vertexIsVisit[i] == false)
                dfs(i);
        }
    }

    void bfs(int currentVertex)
    {
        queue<int> bfsQueue;
        bfsQueue.push(currentVertex);
        vertexIsVisit[currentVertex] = true;
        while(!bfsQueue.empty())
        {
            int frontVertex = bfsQueue.front();
            cout << frontVertex << endl;
            for (int i = 0 ; i < size ; i++)
            {
                if (vertexIsVisit[i] == false && arc[frontVertex][i] != maxEdge)
                {
                    bfsQueue.push(i);
                    vertexIsVisit[i] = true;
                }
            }
            bfsQueue.pop();
        }
    }
public:
    Graph(int mSize = 4) : size(mSize) 
    {
        arc = new EdgeType*[size];
        vertexIsVisit = new bool[size];
        for (int i = 0 ; i < size ; i++)
        {
            *(arc+i) = new EdgeType[size];
        }
    }
    ~Graph()
    {
        for (int i = 0 ; i < size ; i++)
        {
            delete[] *(arc+i);
        }
        delete[] arc;
        delete[] vertexIsVisit;
    }

    bool initGraph()
    {
        for (int i = 0 ; i < size ; i++)
        {
            vertexIsVisit[i] = false;
            for (int j = 0 ; j < size ; j++)
            {
                cin >> arc[i][j];
                if (arc[i][j] == -1)
                    arc[i][j] = maxEdge;
            }
        }
        return true;
    }

    bool printGraph()
    {
        for (int i = 0 ; i < size ; i++)
        {
            for (int j = 0 ; j < size ; j++)
            {
                cout.width(15);
                cout << arc[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }

    bool dfsTraverse()
    {
        for (int i = 0 ; i < size ; i++)
        {
            if (vertexIsVisit[i] == false)
                dfs(i);
        }
        return true;
    }

    bool bfsTraverse()
    {
        for (int i = 0 ; i < size ; i++)
        {
            if (vertexIsVisit[i] == false)
                bfs(i);
        }
        return true;
    }

    bool getMinDis(int vertex)
    {
        bool book[size];
        int dis[size];
        //初始化相关数据 book为顶点是否处理完毕 dis为vertex定点到各个点的最短距离
        for (int i = 0 ; i < size ; i++)
        {
            book[i] = false;
            dis[i] = arc[vertex][i];
        }

        book[vertex] = true;
        for (int i = 0 ; i < size-1 ; i++)
        {
            //扫描距离获取最近的顶点
            int min = maxEdge;
            int minVertex;
            for (int j = 0 ; j < size ; j++)
            {
                if (book[j] == false && arc[vertex][j] < min)
                {
                    min = arc[vertex][j];
                    minVertex = j;
                }
            }
            book[minVertex] = true;
            for (int j = 0 ; j < size ; j++)
            {
                if (arc[minVertex][j] < maxEdge)
                {
                    if (dis[j] > dis[minVertex]+arc[minVertex][j])
                        dis[j] = dis[minVertex]+arc[minVertex][j];
                }
            }
            vertex = minVertex;
            for (auto num : dis)
                cout << num << " ";
            cout << endl;
        }
        return true;
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
    Graph<int> mGraph(6);
    mGraph.initGraph();
    mGraph.printGraph();
    cout << endl;
    mGraph.getMinDis(0);
#if 0
    mGraph.dfsTraverse();
    mGraph.bfsTraverse();
#endif

    system("pause");
    return 0;
}
