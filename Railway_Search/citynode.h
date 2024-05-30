#ifndef CITYNODE_H
#define CITYNODE_H

#include <QObject>

class CityNode : public QObject
{
    Q_OBJECT
public:
    explicit CityNode(QObject *parent = nullptr);
private:
    int distance,cost;
   // typedef struct
   // {};


signals:

public slots:
};

#endif // CITYNODE_H
