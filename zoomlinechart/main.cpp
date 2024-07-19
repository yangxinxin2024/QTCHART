


// Copyright (C) 2023 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
#include <QDateTime>
#include "chart.h"
#include "chartview.h"
#include <QApplication>
#include <QDateTimeAxis>
#include <QLineSeries>
#include <QRandomGenerator>
#include <QChart>
#include <QChartView>
#include <QMainWindow>
#include <cmath>
#include <QApplication>
#include <QLineSeries>
#include <QMainWindow>
#include <QRandomGenerator>
#include <QtMath>
#include <QValueAxis>
#include <QValueAxis>
#include <QDate>
#include<QDebug>
#include <QTimer>

#include <QEventLoop>
#include <QTimer>

void delay(int milliseconds) {
    QEventLoop loop;
    QTimer::singleShot(milliseconds, &loop, &QEventLoop::quit);
    loop.exec();
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int type=0;
    //![1]
    //!
    //!
    auto series1 = new QLineSeries;
    /* for (int j(0); j < 1440; j++) {

        qreal x(0);
        qreal y(0);
        switch (type) {
        case 0:
            y = 2*qSin(M_PI / 360 * j*4) +20;//+ QRandomGenerator::global()->generateDouble();
            x = j;
            break;
        case 1:
            // linear data
            x = j;
            y = (qreal) j / 5;
            break;
        default:
            // unknown, do nothing
            break;
        }
        QPointF p(x,y);
        *series1 << p;
    }
*/

    auto series2 = new QLineSeries;
    /*for (int j(0); j < 1440; j++) {

        qreal x(0);
        qreal y(0);
        switch (type) {
        case 0:
            y = 2*qSin(M_PI / 360 * j*4) +13;// QRandomGenerator::global()->generateDouble();
            x = j;
            break;
        case 1:
            // linear data
            x = j;
            y = (qreal) j / 5;
            break;
        default:
            // unknown, do nothing
            break;
        }
        QPointF p(x,y);
        *series2 << p;
    }
*/

    auto series3 = new QLineSeries;
    /* for (int j(0); j < 1440; j++) {

        qreal x(0);
        qreal y(0);
        switch (type) {
        case 0:
            y = 2*qSin(M_PI / 360 * j*4) +8;//+QRandomGenerator::global()->generateDouble();
            x = j;
            break;
        case 1:
            // linear data
            x = j;
            y = (qreal) j / 5;
            break;
        default:
            // unknown, do nothing
            break;
        }
        QPointF p(x,y);
        *series3 << p;
    }
*/

    auto series4 = new QLineSeries;
    /* for (int j(0); j < 1440; j++) {
        //_sleep(1);
        qreal x(0);
        qreal y(0);
        switch (type) {
        case 0:
            y =2*qSin(M_PI / 360 * j*4)+3;
            x = j;
            break;
        case 1:
            // linear data
            x = j;
            y = (qreal) j / 5;
            break;
        default:
            // unknown, do nothing
            break;
        }
        QPointF p(x,y);
        *series4 << p;
    }*/



    //![1]

    auto chart = new Chart;
    series1->setUseOpenGL(true);//show chart signals ***
    series2->setUseOpenGL(true);
    series3->setUseOpenGL(true);
    series4->setUseOpenGL(true);
    chart->addSeries(series1);
    chart->addSeries(series2);
    chart->addSeries(series3);
    chart->addSeries(series4);
    chart->setTitle("MY CHARTS");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setTheme(chart->ChartThemeDark);
    //  chart->legend()->hide();
    auto axisX = new QValueAxis();
    //axisX->setFormat("hh:mm:ss"); // 设置时间格式
    axisX->setTickCount(11); // 设置刻度位置
    axisX->setMin(0);
    axisX->setMax(1440);
    axisX->setTitleText("time");
    auto axisY = new QValueAxis();
    axisY->setMin(0);
    axisY->setMax(30);
    axisY->setTickCount(11);
    axisY->setTitleText("signals");
    chart->createDefaultAxes();
    auto chartView = new ChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chart->setAxisX(axisX, series1);
    chart->setAxisY(axisY, series1);
    chart->setAxisX(axisX, series2);
    chart->setAxisY(axisY, series2);
    chart->setAxisX(axisX, series3);
    chart->setAxisY(axisY, series3);
    chart->setAxisX(axisX, series4);
    chart->setAxisY(axisY, series4);
    // 创建一个QTimer对象，用于控制数据点的添加
    QTimer *timer = new QTimer();
    timer->setInterval(100);
    int count=1440;
    // 获取当前时间戳
    QDateTime now = QDateTime::currentDateTime();
    qint64 timestamp1 = now.toMSecsSinceEpoch(); // 获取当前时间戳，单位为毫秒
    QObject::connect(timer, &QTimer::timeout, [series1,series2,series3,series4,count,timestamp1]() {
        // 清空当前的数据点
        if(series1->count()>=count || series2->count()>=count || series3->count()>=count || series4->count()>=count)
        {
            series1->clear();
            series2->clear();
            series3->clear();
            series4->clear();
        }
        else
        {
            QVector<QPointF> points1 = series1->pointsVector();
            QVector<QPointF> points2 = series2->pointsVector();
            QVector<QPointF> points3 = series3->pointsVector();
            QVector<QPointF> points4 = series4->pointsVector();
            int pointscount1 = points1.count();
            int pointscount2 = points2.count();
            int pointscount3 = points3.count();
            int pointscount4 = points4.count();
            if(pointscount1 <=0 ||  pointscount2 <=0 || pointscount3 <=0 ||pointscount4 <=0)
            {
                for(int j=0;j<144;j++)
                {
                    qreal inix = qreal(j);
                    qreal inxy1 = 2*qSin(M_PI / 360 * inix*4) + 24;
                    qreal inxy2 = 2*qCos(M_PI / 360 * inix*4) + 18;
                    qreal inxy3 = 2*qSin(M_PI / 360 * inix*4) + 12;
                    qreal inxy4 = 2*qCos(M_PI / 360 * inix*4) + 6;
                    points1.append( QPointF(inix, inxy1));
                    points2.append( QPointF(inix, inxy2));
                    points3.append( QPointF(inix, inxy3));
                    points4.append( QPointF(inix, inxy4));
                }
            }
            else
            {
                //计算接下来的144个点坐标
                int reg = pointscount1/144;
                for(int j=reg*144;j<reg*144+144;j++)
                {
                    qreal inix = qreal(j);
                    qreal inxy1 = 2*qSin(M_PI / 360 * inix*4) + 24;
                    qreal inxy2 = 2*qCos(M_PI / 360 * inix*4) + 18;
                    qreal inxy3 = 2*qSin(M_PI / 360 * inix*4) + 12;
                    qreal inxy4 = 2*qCos(M_PI / 360 * inix*4) + 6;
                    points1.append( QPointF(inix, inxy1));
                    points2.append( QPointF(inix, inxy2));
                    points3.append( QPointF(inix, inxy3));
                    points4.append( QPointF(inix, inxy4));
                }
            }
            series1->replace(points1);
            series2->replace(points2);
            series3->replace(points3);
            series4->replace(points4);

        }
        qDebug()<<"[newx,newy]series1->count()="<<series1->count();
    });
    // 启动定时器，每秒添加一次数据
    timer->start();
    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(400, 300);
    window.grabGesture(Qt::PanGesture);
    window.grabGesture(Qt::PinchGesture);
    window.show();

    return a.exec();
}
