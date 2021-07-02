#include "iomanager.h"

IOManager::IOManager(QChartView *chartView, QObject *parent) : QObject(parent),
    m_chartView(chartView)
{

}

IOManager::~IOManager()
{
    if(m_chartView != nullptr)
        delete m_chartView;
}

void IOManager::saveGraph(int option, QString fileName)
{

}

void IOManager::openHelp()
{

}
