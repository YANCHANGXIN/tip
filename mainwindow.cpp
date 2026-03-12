#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextCodec>
#include <QStringLiteral>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFont font;
    font.setPointSize(16);
    ui->type->setFont(font);

    // 文字居中
    ui->type->setEditable(false);
    ui->type->addItem("农业");
    ui->type->addItem("医院");
    ui->type->addItem("法律");

    ui->USER_ID->setFont(font);
    ui->USER_ID->addItem("12345");
    ui->USER_ID->addItem("23456");
    ui->USER_ID->addItem("34567");
    ui->USER_ID->addItem("45678");
    ui->USER_ID->addItem("56789");

    ui->ConverTextBox->setReadOnly(true);

    usedate.resize(5);
    usedate[0] = {"姓名：张某某", "年龄：16", "性别：女", "学历: 小学", "工作: 学生", "国籍: 日本","血型：A"};
    usedate[1] = {"姓名：严某某", "年龄：26", "性别：男", "学历: 本科", "工作: 会计", "国籍: 中国","血型：B"};
    usedate[2] = {"姓名：陈某某", "年龄：38", "性别：女", "学历: 高中", "工作: 工人", "国籍: 日本","血型：O"};
    usedate[3] = {"姓名：王某某", "年龄：50", "性别：男", "学历: 本科", "工作: 老师", "国籍: 日本","血型：O"};
    usedate[4] = {"姓名：李某某", "年龄：81", "性别：女", "学历: 小学", "工作: 无业", "国籍: 日本","血型：AB"};

    userID_=ui->USER_ID->currentText();

    ui->Demand->setStyleSheet(         //修改UI风格
    "QLineEdit{"
    "border:1px solid #333;"
    "border-radius:8px;"
    "padding:5px;"
    "}"
    );

    ui->ConverTextBox->setStyleSheet(
    "QTextEdit{"
    "border:1px solid gray;"
    "border-radius:8px;"
    "padding:6px;"
    "}"
    );

    ui->pushButton->setStyleSheet(
    "QPushButton{"
    "border:1px solid #999;"
    "border-radius:8px;"
    "padding:6px 12px;"
    "background:#f0f0f0;"
    "}"

    "QPushButton:hover{"
    "background:#e0e0e0;"
    "}"

    "QPushButton:pressed{"
    "background:#d0d0d0;"
    "}"
    );

    connect(ui->Demand, &QLineEdit::returnPressed,ui->pushButton, &QPushButton::click);
}

QString MainWindow::turnPromptGroup(QString domain)
{
    QString text = ui->Demand->text();
    QString result;

    if(text.isEmpty())
        return "";

    // ===== 目标部分 =====
    if(text.length() >= 25)
        result = "先找出冒号后文本主要目标或需求，并将这主要目标和需求作为主要回答：" + text;
    else
        result = "【目标需求】\n" + text;

    // ===== 角色 =====
    QMap<QString, QString> roleMap =
    {
        {"农业", "你是一名农业专家。"},
        {"医院", "你是一名医生。"},
        {"法律", "你是一名专业律师。"}
    };

    if(roleMap.contains(domain))
        result += "\n【角色】\n" + roleMap[domain];

    // ===== 用户信息 =====
    QString userInfo;
    for(int i = 0; i < 7; i++)
        userInfo += usedate[0][i] + "\n";

    if(count == 0)
        result += "\n【需求对象】\n" + userInfo;

    // ===== 领域逻辑 =====
    if(domain == "农业")
    {
        result += "\n【背景环境】\n"
                  "查看当下地区：气候、降雨、纬度、地形、土壤等作为背景环境。"
                  "如果问题中提到相关内容，也作为环境因素。";
    }
    else if(domain == "医院")
    {
        result += "\n【个人环境/细节】\n"
                  "查看当下地区气候、流感情况等作为背景。";

        result += "\n【可能需要补充的信息】\n"
                  "其他症状：恶心、呕吐、反酸、腹泻、发烧等\n"
                  "生活习惯：饮食、熬夜、压力、吸烟饮酒等\n"
                  "身体情况：体重变化、慢性病、家族史等\n";

        result += "\n调取该用户病史。";
        result += "\n注：以上【需求对象的个人信息】和询问的病情若基本不变，紧记【个人环境/细节】【其他症状】"
                              " 【生活习惯背景】【身体基础情况】【用户病史】等信息无需再次询问和查询。"
                              "\n   实时更新并紧记最新需求和用户个人信息。";
    }
    else if(domain == "法律")
    {
        result += "\n【背景环境】\n"
                  "查看国籍和犯罪发生地点等法律适用环境。";

        result += "\n【案件细节】\n"
                  "确认事实经过、造成后果、证据情况。";

        result += "\n确认犯罪者与被害者身份。";
        result += "\n 注：以上【需求对象】和询问的犯罪问题若基本无发生改变，【背景环境】"
                             "【犯罪细节】【犯罪者与被害者】等信息无需再次询问和查询。";
    }

    result += "\n【表达结构】\n"
              "根据需求对象的个人信息提供对方更容易理解的表达方式。";

    return result;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString type_ =ui->type->currentText();
    QString result =MainWindow::turnPromptGroup(type_);
    ui->ConverTextBox->setPlainText(result);
    count++;
    ui->Demand->clear();
}

void MainWindow::on_USER_ID_activated(const QString &arg1)
{
    if(userID_ != arg1)   // 说明ID变了
      {
          userID_ = arg1;
          count = 0;
      }
}

void MainWindow::on_type_activated(const QString &arg1)  //一般不存在此情况，但还是也写一下
{
    if(userID_ != arg1)
      {
          userID_ = arg1;
          count = 0;
      }
}

