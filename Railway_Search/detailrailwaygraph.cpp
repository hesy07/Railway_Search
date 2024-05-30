#include "detailrailwaygraph.h"
#include "ui_detailrailwaygraph.h"

DetailRailwayGraph::DetailRailwayGraph(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetailRailwayGraph)
{
    ui->setupUi(this);
}

DetailRailwayGraph::~DetailRailwayGraph()
{
    delete ui;
}
