#ifndef RAILWAYGRAPH_H
#define RAILWAYGRAPH_H
#define MaxVNum 100
#define MaxInt 32767
#include<QString>
#include<QDebug>
class RailwayGraph
{
private:
    int vexnum, arcnum;//顶点数量、边数量
    QString vexs[MaxVNum];  //顶点表（存放广州、北京等）
    int distArcs[MaxVNum][MaxVNum];     //距离邻接矩阵
    double timeArcs[MaxVNum][MaxVNum];  //时间邻接矩阵
    int feeArcs[MaxVNum][MaxVNum];      //费用邻接矩阵
    int transitArcs[MaxVNum][MaxVNum];  //中转邻接矩阵
public:
        RailwayGraph();//RailwayGraph类的构造函数
        int getVexnum()
        {
            return vexnum;
        }
        //距离最短路径迪杰斯特拉算法
        QString DistShortestPath_Dijkstra(RailwayGraph G, int v0, int v1);
        //时间最短路径迪杰斯特拉算法
        QString timeShortestPath_Dijkstra(RailwayGraph G, int v0, int v1);
        //费用最短路径迪杰斯特拉算法
        QString feeShortestPath_Dijkstra(RailwayGraph G, int v0, int v1);
        //中转最短路径迪杰斯特拉算法
        QString transitShortestPath_Dijkstra(RailwayGraph G, int v0, int v1);
        void pathToWay(int way[], int path[], int v1);//用于迪杰斯特拉算法中
    };

#endif // RAILWAYGRAPH_H
