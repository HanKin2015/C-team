#include "personaldatadialog.h"
#include "ui_personaldatadialog.h"
#include <QFileDialog>
#include <QMessageBox>

PersonalDataDialog::PersonalDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonalDataDialog)
{
    ui->setupUi(this);
    QFont font;
    font.setPointSize(20);
    font.setFamily(("monaco"));
    this->setFont(font);
    this->setWindowTitle("个人资料");

    nameLabel->setText("用户名：");
    personalDataLayout->addWidget(nameLabel,0,0,1,1);
    userName->setPlaceholderText("请输入用户名");
    personalDataLayout->addWidget(userName,0,1,1,2);

    pwdLabel->setText("密码：");
    personalDataLayout->addWidget(pwdLabel,1,0,1,1);
    userPwd->setPlaceholderText("请输入密码");
    personalDataLayout->addWidget(userPwd,1,1,1,2);

    pwdLabel2->setText("再次密码：");
    personalDataLayout->addWidget(pwdLabel2,2,0,1,1);
    userPwd2->setPlaceholderText("请再次输入密码");
    personalDataLayout->addWidget(userPwd2,2,1,1,2);

    sexLabel->setText("性别：");
    personalDataLayout->addWidget(sexLabel,3,0,1,1);
    sex->setPlaceholderText("请输入性别");
    personalDataLayout->addWidget(sex,3,1,1,2);

    phoneLabel->setText("电话：");
    personalDataLayout->addWidget(phoneLabel,4,0,1,1);
    phone->setPlaceholderText("请输入电话");
    personalDataLayout->addWidget(phone,4,1,1,2);

    emailLabel->setText("邮箱：");
    personalDataLayout->addWidget(emailLabel,5,0,1,1);
    email->setPlaceholderText("请输入有效的邮箱");
    personalDataLayout->addWidget(email,5,1,1,2);
    QQLabel->setText("QQ：");
    personalDataLayout->addWidget(QQLabel,6,0,1,1);
    personalDataLayout->addWidget(QQ,6,1,1,2);

    studentIdLabel->setText("学号：");
    personalDataLayout->addWidget(studentIdLabel,7,0,1,1);
    personalDataLayout->addWidget(studentId,7,1,1,2);
    universityLabel->setText("学校：");
    personalDataLayout->addWidget(universityLabel,8,0,1,1);
    personalDataLayout->addWidget(university,8,1,1,2);
    locateAreaLabel->setText("地区：");
    personalDataLayout->addWidget(locateAreaLabel,9,0,1,1);
    personalDataLayout->addWidget(locateArea,9,1,1,2);
    imageLabel->setText("头像：");
    personalDataLayout->addWidget(imageLabel,10,0,1,1);
    imageBtn->setText("上传");
    personalDataLayout->addWidget(imageBtn,10,1,1,2);



    selfTagLabel->setText("Tag：");
    personalDataLayout->addWidget(selfTagLabel,11,0,1,1);

    QGridLayout *tagLayout = new QGridLayout(this);
    // 创建QPushButton控件
    QPushButton *btn1 = new QPushButton(this);
    btn1->setText("开朗");
    tagLayout->addWidget(btn1,0,0,1,1);

    QPushButton *btn2 = new QPushButton(this);
    btn2->setText("内向");
    tagLayout->addWidget(btn2,0,1,1,1);

    QPushButton *btn3 = new QPushButton(this);
    btn3->setText("爱笑");
    tagLayout->addWidget(btn3,1,0,1,1);
    QPushButton *btn4 = new QPushButton(this);
    btn4->setText("漂亮");
    tagLayout->addWidget(btn4,1,1,1,1);

    tag->setLayout(tagLayout);
    personalDataLayout->addWidget(tag,11,1,2,2);

    changeBtn->setText("修改");
    personalDataLayout->addWidget(changeBtn,13,0,1,1);
    confirmBtn->setText("确认");
    personalDataLayout->addWidget(confirmBtn,13,2,1,1);
    this->setLayout(personalDataLayout);
    connect(confirmBtn, &QPushButton::clicked, this, &PersonalDataDialog::on_confirmBtn_clicked);
    connect(changeBtn, &QPushButton::clicked, this, &PersonalDataDialog::on_changeBtn_clicked);
    connect(imageBtn, &QPushButton::clicked, this, &PersonalDataDialog::OpenImage);
}

PersonalDataDialog::~PersonalDataDialog()
{
    delete ui;
}

void PersonalDataDialog::on_confirmBtn_clicked()
{
    this->hide();
}

void PersonalDataDialog::on_changeBtn_clicked()
{
    this->hide();
}

void PersonalDataDialog::OpenImage()
{
    QString filename;
    filename=QFileDialog::getOpenFileName(this, tr("选择图像"), "", tr("Images (*.png *.bmp *.jpg *.tif *.GIF )"));
    if(filename.isEmpty())
    {
        return;
    }
    else {
        QImage* img=new QImage;
        if(! ( img->load(filename) ) ){ //加载图像  {
            QMessageBox::information(this,tr("打开图像失败"),tr("打开图像失败!"));
            delete img;
            return;
        }
        imageBtn->setText(filename.section('/',-1));
            //mainLayout->addWidget(img,0,0,1,1);
   }
}