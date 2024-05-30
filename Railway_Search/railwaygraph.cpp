#include "railwaygraph.h"
//铁路图构造函数
RailwayGraph::RailwayGraph()
{
    //构建题目所给的铁路图
    this->vexnum =7; this->arcnum =10;
    vexs[0] = "北京";  vexs[1] = "西安";
    vexs[2] = "郑州";  vexs[3] = "徐州";
    vexs[4] = "成都";  vexs[5] = "广州";
    vexs[6] = "上海";
    for(int i=0;i<vexnum;i++)
        for (int j = 0; j < vexnum; j++){
            distArcs[i][j] = MaxInt;
            timeArcs[i][j] = MaxInt;
            feeArcs[i][j] = MaxInt;
            transitArcs[i][j] = MaxInt;
        }
    //通过int v1[10]和int v2[10]两个数组构建图的边，其中v1为起始点，v2为终点，v1[0]-v2[0]构成一条边
    //数组中存储的数据是顶点在顶点数组中的序号
    int v1[10] = { 0,0,0,1,1,2,2,3,4,5 };
    int v2[10] = { 1,2,3,2,4,3,5,6,5,6 };
    //填入边的权值
    int distWeight[10] = {2523,695,704,511,812,349,1579,651,2368,1385};//距离权值
    double timeWeight[10] = {8,2.3,2.5,1.5,7,1.2,5,2,7,4};//时间权值
    int feeWeight[10] = {885,202,225,148,283,112,495,162,684,386};//费用权值
    int transitWeight[10] = { 1,1,1,1,1,1,1,1,1,1 };//中转权值
    for (int k = 0; k < arcnum; k++)
    {   //构建邻接矩阵
        int i = v1[k]; int j = v2[k];

        distArcs[i][j] = distWeight[k];  //距离邻接矩阵赋权
        timeArcs[i][j] = timeWeight[k];  //时间邻接矩阵赋权
        feeArcs[i][j] = feeWeight[k];
        transitArcs[i][j] = transitWeight[k];

        distArcs[j][i] = distArcs[i][j];
        timeArcs[j][i] = timeArcs[i][j];
        feeArcs[j][i] = feeArcs[i][j];
        transitArcs[j][i] = transitArcs[i][j];
    }
}
void RailwayGraph::pathToWay(int way[], int path[], int v1)
{//通过path数组获取路径，存储到way数组中
    int count = 0;//统计路径中结点的个数
    int v = v1;
    //统计结点个数
    while (path[v] != -1)
    {
        v = path[v];
        ++count;
    }
    ++count;
    /*--统计工作完成--*/
    //依次存储结点
    v = v1;
    for (int i = count-1 ;i >= 0; i--)
    {
        way[i] = v;
        v = path[v];
    }
    /*--存储工作完成--*/
}
//距离迪杰斯特拉算法
QString RailwayGraph:: DistShortestPath_Dijkstra(RailwayGraph G, int v0, int v1)
     {//求距离最优方案
         if (v0 == v1)
         {
             return "起始地不能与目的地相同";
         }
         //初始化工作
         int n = G.getVexnum();    //n为G中顶点的个数
         bool S[MaxVNum] = { false };//S集合，存放已找出路径的顶点的集合，初始置为空
         int Dist[MaxVNum] = {0};
         int Path[MaxVNum] = { 0 };
             for (int v = 0; v < n; ++v)
             {
                 Dist[v] = G.distArcs[v0][v];
                 if (Dist[v] < MaxInt)
                     Path[v] = v0;
                 else
                     Path[v]=-1;
             }
             S[v0] = true;
             Dist[v0] = 0;
             /*--初始化工作结束--*/
             for (int i = 1; i < n; ++i)
             {//每轮寻找离集合S最近的结点
                 int min = MaxInt;
                 int min_v = 0;
                 for(int w=0;w<n;w++)
                     if (!S[w] && Dist[w] < min){
                         min_v = w; min = Dist[w];
                     }
                 S[min_v] = true;
                 for (int w = 0; w < n; ++w)     //更新Dist[]数组和Path[]数组
                     if (Dist[w] > Dist[min_v] + distArcs[min_v][w])
                     {
                         Dist[w] = Dist[min_v] + distArcs[min_v][w];
                         Path[w] = min_v;
                     }//if
             }//for
             //通过path获取路径数组
             int way[MaxVNum] ;//存放最短路径所经结点的数组
             for (int i = 0; i < MaxVNum; i++)//将该数组中的数值初始化为-1
                 way[i] = -1;
             //通过path数组获取路径，存储到way数组中
             pathToWay(way, Path, v1);
             //记录路径所需的距离、时间、费用和中转次数
             int distNum = 0,  feeNum = 0, transitNum = 0;
             double timeNum = 0;
             for (int i = 0; way[i+1] != -1; i++)
             {
                 distNum += G.distArcs[way[i]][way[i + 1]];
                 timeNum += G.timeArcs[way[i]][way[i + 1]];
                 feeNum += G.feeArcs[way[i]][way[i + 1]];
                 transitNum += G.transitArcs[way[i]][way[i + 1]];
             }
             //对数据的相关细节进行修改
             transitNum = transitNum - 1;//实际中转次数需要减1
             int Hour_timeNum = int(timeNum / 1);
             double Min_timeNum = (timeNum - Hour_timeNum) * 60;
             if (Path[v1] == -1)
             {
                 return "查找失败,没有路线可以到达目的地";
             }
             QString Strway="路线:";
             for (int i = 0; way[i] != -1; i++) {
                 Strway += G.vexs[way[i]];
                 if (way[i + 1] != -1)
                     Strway += "->";
             }
             QString StrDistNum=QString::number(distNum);
             QString StrHour_timeNum=QString::number(Hour_timeNum);
             QString StrMin_timeNum=QString::number(Min_timeNum);
             QString StrFeeNum=QString::number(feeNum);
             QString StrTransitNum=QString::number(transitNum);
             return "\n"+Strway+"\n"+"\n"+
                     "距离:" + StrDistNum+
                     "km| 约" +StrHour_timeNum + "小时" + StrMin_timeNum +
                     "分钟|￥" + StrFeeNum +
                     "元|"+StrTransitNum + "次中转";
     }
QString RailwayGraph:: timeShortestPath_Dijkstra(RailwayGraph G, int v0, int v1)
     {//求时间最优方案
         if (v0 == v1)
         {
             return "起始地不能与目的地相同";
         }
         //初始化工作
         int n = G.getVexnum();    //n为G中顶点的个数
         bool S[MaxVNum] = { false };//S集合，存放已找出路径的顶点的集合，初始置为空
         double Dist[MaxVNum] = {0};
         int Path[MaxVNum] = { 0 };
             for (int v = 0; v < n; ++v)
             {
                 Dist[v] = G.timeArcs[v0][v];
                 if (Dist[v] < MaxInt)
                     Path[v] = v0;
                 else
                     Path[v]=-1;
             }
             S[v0] = true;
             Dist[v0] = 0;
             /*--初始化工作结束--*/
             for (int i = 1; i < n; ++i)
             {//每轮寻找离集合S最近的结点
                 double min = MaxInt;
                 int min_v = 0;
                 for(int w=0;w<n;w++)
                     if (!S[w] && Dist[w] < min){
                         min_v = w; min = Dist[w];
                     }
                 S[min_v] = true;
                 for (int w = 0; w < n; ++w)     //更新Dist[]数组和Path[]数组
                     if (Dist[w] > Dist[min_v] + timeArcs[min_v][w])
                     {
                         Dist[w] = Dist[min_v] + timeArcs[min_v][w];
                         Path[w] = min_v;
                     }//if
             }//for
             //通过path获取路径数组
             int way[MaxVNum] ;//存放最短路径所经结点的数组
             for (int i = 0; i < MaxVNum; i++)//将该数组中的数值初始化为-1
                 way[i] = -1;
             //通过path数组获取路径，存储到way数组中
             pathToWay(way, Path, v1);
             //记录路径所需的距离、时间、费用和中转次数
             int distNum = 0,  feeNum = 0, transitNum = 0;
             double timeNum = 0;
             for (int i = 0; way[i+1] != -1; i++)
             {
                 distNum += G.distArcs[way[i]][way[i + 1]];
                 timeNum += G.timeArcs[way[i]][way[i + 1]];
                 feeNum += G.feeArcs[way[i]][way[i + 1]];
                 transitNum += G.transitArcs[way[i]][way[i + 1]];
             }
             //对数据的相关细节进行修改
             transitNum = transitNum - 1;//实际中转次数需要减1
             int Hour_timeNum = int(timeNum / 1);
             double Min_timeNum = (timeNum - Hour_timeNum) * 60;
             if (Path[v1] == -1)
             {
                 return "查找失败,没有路线可以到达目的地";
             }
             QString Strway="路线:";
             for (int i = 0; way[i] != -1; i++) {
                 Strway += G.vexs[way[i]];
                 if (way[i + 1] != -1)
                     Strway += "->";
             }
             QString StrDistNum=QString::number(distNum);
             QString StrHour_timeNum=QString::number(Hour_timeNum);
             QString StrMin_timeNum=QString::number(Min_timeNum);
             QString StrFeeNum=QString::number(feeNum);
             QString StrTransitNum=QString::number(transitNum);
             return "\n"+Strway+"\n"+"\n"+
                     "距离:" + StrDistNum+
                     "km| 约" +StrHour_timeNum + "小时" + StrMin_timeNum +
                     "分钟|￥" + StrFeeNum +
                     "元|"+StrTransitNum + "次中转";
     }
QString RailwayGraph:: feeShortestPath_Dijkstra(RailwayGraph G, int v0, int v1)
     {//求费用最优方案
         if (v0 == v1)
         {
             return "起始地不能与目的地相同";
         }
         //初始化工作
         int n = G.getVexnum();    //n为G中顶点的个数
         bool S[MaxVNum] = { false };//S集合，存放已找出路径的顶点的集合，初始置为空
         int Dist[MaxVNum] = {0};
         int Path[MaxVNum] = { 0 };
             for (int v = 0; v < n; ++v)
             {
                 Dist[v] = G.feeArcs[v0][v];
                 if (Dist[v] < MaxInt)
                     Path[v] = v0;
                 else
                     Path[v]=-1;
             }
             S[v0] = true;
             Dist[v0] = 0;
             /*--初始化工作结束--*/
             for (int i = 1; i < n; ++i)
             {//每轮寻找离集合S最近的结点
                 int min = MaxInt;
                 int min_v = 0;
                 for(int w=0;w<n;w++)
                     if (!S[w] && Dist[w] < min){
                         min_v = w; min = Dist[w];
                     }
                 S[min_v] = true;
                 for (int w = 0; w < n; ++w)     //更新Dist[]数组和Path[]数组
                     if (Dist[w] > Dist[min_v] + feeArcs[min_v][w])
                     {
                         Dist[w] = Dist[min_v] + feeArcs[min_v][w];
                         Path[w] = min_v;
                     }//if
             }//for
             //通过path获取路径数组
             int way[MaxVNum] ;//存放最短路径所经结点的数组
             for (int i = 0; i < MaxVNum; i++)//将该数组中的数值初始化为-1
                 way[i] = -1;
             //通过path数组获取路径，存储到way数组中
             pathToWay(way, Path, v1);
             //记录路径所需的距离、时间、费用和中转次数
             int distNum = 0,  feeNum = 0, transitNum = 0;
             double timeNum = 0;
             for (int i = 0; way[i+1] != -1; i++)
             {
                 distNum += G.distArcs[way[i]][way[i + 1]];
                 timeNum += G.timeArcs[way[i]][way[i + 1]];
                 feeNum += G.feeArcs[way[i]][way[i + 1]];
                 transitNum += G.transitArcs[way[i]][way[i + 1]];
             }
             //对数据的相关细节进行修改
             transitNum = transitNum - 1;//实际中转次数需要减1
             int Hour_timeNum = int(timeNum / 1);
             double Min_timeNum = (timeNum - Hour_timeNum) * 60;
             if (Path[v1] == -1)
             {
                 return "查找失败,没有路线可以到达目的地";
             }
             QString Strway="路线:";
             for (int i = 0; way[i] != -1; i++) {
                 Strway += G.vexs[way[i]];
                 if (way[i + 1] != -1)
                     Strway += "->";
             }
             QString StrDistNum=QString::number(distNum);
             QString StrHour_timeNum=QString::number(Hour_timeNum);
             QString StrMin_timeNum=QString::number(Min_timeNum);
             QString StrFeeNum=QString::number(feeNum);
             QString StrTransitNum=QString::number(transitNum);
             return "\n"+Strway+"\n"+"\n"+
                     "距离:" + StrDistNum+
                     "km| 约" +StrHour_timeNum + "小时" + StrMin_timeNum +
                     "分钟|￥" + StrFeeNum +
                     "元|"+StrTransitNum + "次中转";
     }
QString RailwayGraph:: transitShortestPath_Dijkstra(RailwayGraph G, int v0, int v1)
     {//求中转最优方案(优化：考虑到最少中转次数易出现相同情况，故进行优化，当中转次数相同时，采用时间更少的方案)
         if (v0 == v1)
         {
             return "起始地不能与目的地相同";
         }
         //初始化工作
         int n = G.getVexnum();    //n为G中顶点的个数
         bool S[MaxVNum] = { false };//S集合，存放已找出路径的顶点的集合，初始置为空
         int Dist[MaxVNum] = {0};
         double t_Dist[MaxVNum]={0}; //考虑到中转次数容易出现相等情况，创建时间较短辅助数组，当两个路程中转次数相等时，比较两路程所需时间长短，优先选择时间花费短的路程
         int Path[MaxVNum] = { 0 };
             for (int v = 0; v < n; ++v)
             {
                 Dist[v] = G.transitArcs[v0][v];
                 t_Dist[v]=G.timeArcs[v0][v];
                 if (Dist[v] < MaxInt)
                     Path[v] = v0;
                 else
                     Path[v]=-1;
             }
             S[v0] = true;
             Dist[v0] = 0;
             /*--初始化工作结束--*/
             for (int i = 1; i < n; ++i)
             {//每轮寻找离集合S最近的结点
                 int min = MaxInt;
                 int min_v = 0;
                 for(int w=0;w<n;w++)
                     if (!S[w]&& ((Dist[w] < min) ||(Dist[w] == min && t_Dist[w] < t_Dist[min_v])) )//若点w不在集合S中 且:
                                                           //（点w到集合S的距离小于最小值）或（点w到集合S的距离等于最小值但时间更短）
                     {   min_v = w; min = Dist[w]; }
                 S[min_v] = true;
                 for (int w = 0; w < n; ++w)     //更新Dist[]数组和Path[]数组
                     if (Dist[w] > Dist[min_v] + transitArcs[min_v][w])
                     {
                         Dist[w] = Dist[min_v] + transitArcs[min_v][w];
                         t_Dist[w]=t_Dist[min_v]+timeArcs[min_v][w];
                         Path[w] = min_v;
                     }//if
             }//for
             //通过path获取路径数组
             int way[MaxVNum] ;//存放最短路径所经结点的数组
             for (int i = 0; i < MaxVNum; i++)//将该数组中的数值初始化为-1
                 way[i] = -1;
             //通过path数组获取路径，存储到way数组中
             pathToWay(way, Path, v1);
             //记录路径所需的距离、时间、费用和中转次数
             int distNum = 0,  feeNum = 0, transitNum = 0;
             double timeNum = 0;
             for (int i = 0; way[i+1] != -1; i++)
             {
                 distNum += G.distArcs[way[i]][way[i + 1]];
                 timeNum += G.timeArcs[way[i]][way[i + 1]];
                 feeNum += G.feeArcs[way[i]][way[i + 1]];
                 transitNum += G.transitArcs[way[i]][way[i + 1]];
             }
             //对数据的相关细节进行修改
             transitNum = transitNum - 1;//实际中转次数需要减1
             int Hour_timeNum = int(timeNum / 1);
             double Min_timeNum = (timeNum - Hour_timeNum) * 60;
             if (Path[v1] == -1)
             {
                 return "查找失败,没有路线可以到达目的地";
             }
             QString Strway="路线:";
             for (int i = 0; way[i] != -1; i++) {
                 Strway += G.vexs[way[i]];
                 if (way[i + 1] != -1)
                     Strway += "->";
             }
             QString StrDistNum=QString::number(distNum);
             QString StrHour_timeNum=QString::number(Hour_timeNum);
             QString StrMin_timeNum=QString::number(Min_timeNum);
             QString StrFeeNum=QString::number(feeNum);
             QString StrTransitNum=QString::number(transitNum);
             return "\n"+Strway+"\n"+"\n"+
                     "距离:" + StrDistNum+
                     "km| 约" +StrHour_timeNum + "小时" + StrMin_timeNum +
                     "分钟|￥" + StrFeeNum +
                     "元|"+StrTransitNum + "次中转";
     }


