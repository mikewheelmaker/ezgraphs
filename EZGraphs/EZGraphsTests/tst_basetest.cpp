#include <QtTest>

// add necessary includes here

class BaseTest : public QObject
{
    Q_OBJECT

public:
    BaseTest();
    ~BaseTest();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

BaseTest::BaseTest()
{

}

BaseTest::~BaseTest()
{

}

void BaseTest::initTestCase()
{

}

void BaseTest::cleanupTestCase()
{

}

void BaseTest::test_case1()
{

}

QTEST_APPLESS_MAIN(BaseTest)

#include "tst_basetest.moc"
