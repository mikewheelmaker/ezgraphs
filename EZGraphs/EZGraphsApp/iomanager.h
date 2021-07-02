#ifndef IOMANAGER_H
#define IOMANAGER_H

#include <QChartView>

#include "utilities.h"

Q_DECLARE_LOGGING_CATEGORY(ioManager)

class IOManager : public QObject
{
    Q_OBJECT
public:
    explicit IOManager(QChartView *chartView, QObject *parent = nullptr);
    virtual ~IOManager();

    void saveGraph(int option, QString fileName);
    void openHelp();

private:
    QChartView *m_chartView;
};

#endif // IOMANAGER_H
