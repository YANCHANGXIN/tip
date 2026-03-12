#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QList>
#include <QVector>
#include <QList>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr); 
    ~MainWindow();
    QString turnPromptGroup(QString input);  //优化为提示词组
    int count=0;                         //用户查询次数
    QString userID_;                     //用户id确认
private slots:
    void on_pushButton_clicked();

    void on_USER_ID_activated(const QString &arg1);

    void on_type_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QVector<QList<QString>> usedate;     //用户个人信息数据
};


#endif // MAINWINDOW_H
