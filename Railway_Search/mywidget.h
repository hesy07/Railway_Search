#ifndef MYWIDGET_H
#define MYWIDGET_H
#include <QMouseEvent>
#include <QWidget>
#include"student.h"
#include"teacher.h"
#include"railwaygraph.h"
#include"detailrailwaygraph.h"
//主窗口类
QT_BEGIN_NAMESPACE
namespace Ui { class MyWidget; }
QT_END_NAMESPACE

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    //构造函数、析构函数
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();
protected:
    //鼠标控制事件，实现窗口拖动功能
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent*event);
    void mouseReleaseEvent(QMouseEvent *event);
private:
    DetailRailwayGraph*dlg;//详图窗口对象
    QPoint mousePoint;      //当前鼠标坐标，用于鼠标控制事件
    bool mouse_press=false;//鼠标按压状态，用于鼠标控制事件
    bool search=false;      //查找状态，用于查找按钮和下拉动画实现
    bool detailshow=false;//判断显示详图界面是否打开
    void bluePointHidden();//控制蓝点隐藏
     void bluePointShow(int);//控制相应蓝点显示
public slots:
    void on_pushbutton_press1();//查找按钮槽函数
    void on_tabwidget_currentChanged();//切换标签页槽函数
    void on_pushButton_2_clicked();//查看详图按钮槽函数

private:
    Ui::MyWidget *ui;
};
#endif // MYWIDGET_H
