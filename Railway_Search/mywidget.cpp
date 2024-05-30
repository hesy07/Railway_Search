#include "mywidget.h"
#include "ui_mywidget.h"
#include<QDialog>
#include<QAction>
#include<QTime>
#include<QComboBox>
#include<QMessageBox>
#include<QGraphicsEffect>
#include<QAbstractAnimation>
#include<QPropertyAnimation>
#include "detailrailwaygraph.h"
MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    //设置主窗口logo
    setWindowIcon(QIcon(":/res/Logo.png"));
    //设置主窗口背景
    QPixmap pixmap = QPixmap(":/res/background8.png").scaled(this->size());
    QPalette  palette (this->palette());
    palette .setBrush(QPalette::Background, QBrush(pixmap));
    this-> setPalette( palette );
   //设置主窗口大小
    this->setMinimumSize(645,490);
    this->setMaximumSize(645,490);
    //初始化部分控件状态
   ui->tabWidget->setHidden(true);
    bluePointHidden();
    ui->label_5->clear();
    ui->comboBox_2->setCurrentIndex(5);
    //查找按钮添加图片
    QSize* size=new QSize(50,50);
    ui->pushButton->setIconSize(*size);
    //查找按钮的连接
    connect(ui->pushButton,&QAbstractButton::clicked,this,&MyWidget::on_pushbutton_press1);
    //切换方案标签页的连接
    connect(ui->tabWidget,&QTabWidget::currentChanged,this,&MyWidget::on_tabwidget_currentChanged);
}

/*--窗口界面创建完成--*/

//查找按钮的相应槽函数
void MyWidget::on_pushbutton_press1()
{
  if(this->search==false){
    //增加窗口大小的最大值，方便下拉动画实现
    this->setMaximumSize(645,490);
    //每一次点击查询按钮，刷新各控件状态
    ui->tabWidget->setHidden(true);
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    ui->textEdit_3->clear();
    ui->textEdit_4->clear();
    ui->label_5->clear();
    bluePointHidden();
    //若起始地与目的地详图，弹出提示并返回
    if(ui->comboBox->currentIndex()==ui->comboBox_2->currentIndex())
    {
        QMessageBox::warning(this,"提示","起始地与目的地不能相同");
        ui->label_5->clear();
        return;
    }
    //开始执行算法，查找最短路径
    this->search=true;
    RailwayGraph G;
    ui->label_5->setText("查找中.");
    //延时功能
    QTime dieTime1 = QTime::currentTime().addMSecs(250);

        while (QTime::currentTime() < dieTime1)
        {
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }
        ui->label_5->setText("查找中..");
 QTime dieTime2 = QTime::currentTime().addMSecs(250);
            while (QTime::currentTime() < dieTime2)
            {
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);}
        ui->label_5->setText("查找中...");
                    QTime dieTime3 = QTime::currentTime().addMSecs(250);
        while (QTime::currentTime() < dieTime3)
        {
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);}

        //查找完成
    ui->label_5->setText("已为您查找到以下方案：");
    //tabwidget方案页下拉动画弹出
    //为主窗口新建动画对象
    QPropertyAnimation * pWidgetProcessUp = new QPropertyAnimation(this, "geometry");
    if(this->search==true){
         this->setMaximumSize(637,670);
           pWidgetProcessUp->setStartValue(geometry());
           pWidgetProcessUp->setEndValue(QRect(geometry().x(), geometry().y(), width(), height() + 150));//结束值
           pWidgetProcessUp->setDuration(260);
           pWidgetProcessUp->setEasingCurve(QEasingCurve::Linear);
           pWidgetProcessUp->start(QAbstractAnimation::DeleteWhenStopped);

    }
    //下拉动画完成
    //显示标签页
    ui->tabWidget->setHidden(false);
//tabwidget展示结果
    //获取最短距离方案的结果文字
    QString distResText=(G.DistShortestPath_Dijkstra(G,ui->comboBox->currentIndex(),ui->comboBox_2->currentIndex()));
    //获取最短时间方案的结果文字
    QString timeResText=(G.timeShortestPath_Dijkstra(G,ui->comboBox->currentIndex(),ui->comboBox_2->currentIndex()));
    //获取最少费用方案的结果文字
     QString feeResText=(G.feeShortestPath_Dijkstra(G,ui->comboBox->currentIndex(),ui->comboBox_2->currentIndex()));
     //获取最少中转次数方案的结果文字
     QString transitResText=(G.transitShortestPath_Dijkstra(G,ui->comboBox->currentIndex(),ui->comboBox_2->currentIndex()));
    //为各文本框添加结果
    ui->textEdit->append(distResText);
    ui->textEdit_2->append(timeResText);
    ui->textEdit_3->append(feeResText);
    ui->textEdit_4->append(transitResText);
    //将tabwidget的文字结果展示到图中
   //若当前标签页结果文本中包含了某个城市，就在图中显示蓝点
    bluePointShow(ui->tabWidget->currentIndex());
    this->search=false;}
}
//切换标签页的相应槽函数
void MyWidget::on_tabwidget_currentChanged()
{//切换标签页
    //隐藏蓝点
    bluePointHidden();
    //show blue points by current tab's text
    bluePointShow(ui->tabWidget->currentIndex());
}

void MyWidget::mousePressEvent(QMouseEvent *event)
{

    if(event->button()==Qt::LeftButton)
    {
        mouse_press=true;
        mousePoint=event->globalPos()-this->pos();
    }

}
void MyWidget::mouseMoveEvent(QMouseEvent *event)
{
    //窗口随鼠标位置移动而移动
    if(mouse_press){
        move(event->globalPos()-mousePoint);
    }
}
void MyWidget::mouseReleaseEvent(QMouseEvent *event)
{
    mouse_press=false;
}
void MyWidget::bluePointHidden()
{   //将所有蓝点隐藏
    ui->label_7->setHidden(true);
    ui->label_8->setHidden(true);
    ui->label_9->setHidden(true);
    ui->label_10->setHidden(true);
    ui->label_11->setHidden(true);
    ui->label_12->setHidden(true);
    ui->label_13->setHidden(true);
}
void MyWidget::bluePointShow(int currentIndex)
{   //根据文本中含有的城市控制蓝点出现
    QString resText;
    if(currentIndex==0)       resText=ui->textEdit->toPlainText();
    else if(currentIndex==1)  resText=ui->textEdit_2->toPlainText();
    else if(currentIndex==2)  resText=ui->textEdit_3->toPlainText();
    else if(currentIndex==3)  resText=ui->textEdit_4->toPlainText();
    if (resText.contains("北京",Qt::CaseSensitive))
        ui->label_7->setHidden(false);
    if (resText.contains("郑州",Qt::CaseSensitive))
        ui->label_8->setHidden(false);
    if (resText.contains("西安",Qt::CaseSensitive))
        ui->label_9->setHidden(false);
    if (resText.contains("成都",Qt::CaseSensitive))
        ui->label_10->setHidden(false);
    if (resText.contains("广州",Qt::CaseSensitive))
        ui->label_11->setHidden(false);
    if (resText.contains("上海",Qt::CaseSensitive))
        ui->label_12->setHidden(false);
    if (resText.contains("徐州",Qt::CaseSensitive))
        ui->label_13->setHidden(false);
}
void MyWidget::on_pushButton_2_clicked()
{//查看详图按钮
    //若详图窗口未打开，显示窗口
    if(detailshow==false){
        //创建子窗口
        dlg=new DetailRailwayGraph(this);
        dlg->setWindowTitle("铁路详图");
        //设置固定大小
        dlg->setFixedSize(559,450);
        //设置对话框背景
        QPixmap pixmap1 = QPixmap(":/res/detailDialogBackground3.png").scaled(dlg->size());
        QPalette  palette1 (dlg->palette());
        palette1 .setBrush(QPalette::Background, QBrush(pixmap1));
        dlg-> setPalette( palette1 );
        //设置窗口初始位置
        QPoint globalPos = this->mapToGlobal(QPoint(0, 0));
        dlg->move(globalPos.x() +  this->width(), globalPos.y() );
        dlg->setAttribute(Qt::WA_DeleteOnClose);
        //删除对话框左上角自带的问号按钮
       // dlg->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);
        //显示窗口
        dlg->show();
        ui->pushButton_2->setText("收起");
        detailshow=true;
    }
    //若详图窗口已打开，关闭窗口
    else if(detailshow==true)
    {
        dlg->close();
        detailshow=false;
        ui->pushButton_2->setText("查看详图");
    }
}

MyWidget::~MyWidget()
{
    delete ui;
}




