#ifndef DETAILRAILWAYGRAPH_H
#define DETAILRAILWAYGRAPH_H
//"铁路详图"对话框窗口类
#include <QDialog>

namespace Ui {
class DetailRailwayGraph;
}

class DetailRailwayGraph : public QDialog
{
    Q_OBJECT

public:
    explicit DetailRailwayGraph(QWidget *parent = nullptr);
    ~DetailRailwayGraph();

private:
    Ui::DetailRailwayGraph *ui;
};

#endif // DETAILRAILWAYGRAPH_H
