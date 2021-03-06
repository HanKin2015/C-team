#include "registerdialog.h"
#include "ui_registerdialog.h"
#include <QMessageBox>
#include "logindialog.h"
#include <QFileDialog>
#include "globalvariable.h"
#include "base64.h"

RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);

    QFont fontStyle = GetFont();
    this->setFont(fontStyle);
    this->setStyleSheet(GetStyle());
    this->setWindowTitle("注册");

    nameLabel->setText("用户名：");
    registerLayout->addWidget(nameLabel,0,0,1,1);
    userName->setPlaceholderText("请输入用户名");
    registerLayout->addWidget(userName,0,1,1,2);

    pwdLabel->setText("密码：");
    registerLayout->addWidget(pwdLabel,1,0,1,1);
    userPwd->setEchoMode(QLineEdit::Password);
    userPwd->setPlaceholderText("请输入密码");
    registerLayout->addWidget(userPwd,1,1,1,2);

    pwdLabel2->setText("再次密码：");
    registerLayout->addWidget(pwdLabel2,2,0,1,1);
    userPwd2->setPlaceholderText("请再次输入密码");
    userPwd2->setEchoMode(QLineEdit::Password);
    registerLayout->addWidget(userPwd2,2,1,1,2);

    sexLabel->setText("性别：");
    registerLayout->addWidget(sexLabel,3,0,1,1);
    sexType->addItem("男");
    sexType->addItem("女");
    registerLayout->addWidget(sexType,3,1,1,2);

    phoneLabel->setText("电话：");
    registerLayout->addWidget(phoneLabel,4,0,1,1);
    phone->setPlaceholderText("请输入电话");
    registerLayout->addWidget(phone,4,1,1,2);

    emailLabel->setText("邮箱：");
    registerLayout->addWidget(emailLabel,5,0,1,1);
    email->setPlaceholderText("请输入有效的邮箱");
    registerLayout->addWidget(email,5,1,1,2);
    QQLabel->setText("QQ：");
    registerLayout->addWidget(QQLabel,6,0,1,1);
    QQ->setPlaceholderText("请输入QQ号");
    registerLayout->addWidget(QQ,6,1,1,2);

    studentIdLabel->setText("学号：");
    registerLayout->addWidget(studentIdLabel,7,0,1,1);
    studentId->setPlaceholderText("请输入有效的学号");
    registerLayout->addWidget(studentId,7,1,1,2);
    universityLabel->setText("学校：");
    registerLayout->addWidget(universityLabel,8,0,1,1);
    university->setPlaceholderText("请输入学校");
    registerLayout->addWidget(university,8,1,1,2);
    locateAreaLabel->setText("地区：");
    registerLayout->addWidget(locateAreaLabel,9,0,1,1);
    locateArea->setPlaceholderText("请输入地区");
    registerLayout->addWidget(locateArea,9,1,1,2);
    security->setText("密保问题");
    registerLayout->addWidget(security,10,0,1,1);
    securityQuestion->addItem("你的爸爸叫什么？");
    securityQuestion->addItem("你的妈妈叫什么？");
    securityQuestion->addItem("你的姐姐叫什么？");
    securityQuestion->addItem("你的哥哥叫什么？");
    registerLayout->addWidget(securityQuestion,10,1,1,2);
    securityAnswer->setPlaceholderText("密保问题可以找回密码");
    registerLayout->addWidget(securityAnswer,11,1,1,2);
//    imageLabel->setText("头像：");
//    registerLayout->addWidget(imageLabel,12,0,1,1);
//    imageBtn->setText("上传");
//    registerLayout->addWidget(imageBtn,12,1,1,2);
/*
    selfTagLabel->setText("Tag：");
    registerLayout->addWidget(selfTagLabel,11,0,1,1);

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
*/
    signatureLabel->setText("个性签名:");
    registerLayout->addWidget(signatureLabel,12,0,1,1);
    signature->setPlaceholderText("请输入你的个性签名");
    registerLayout->addWidget(signature,12,1,2,2);

    backBtn->setText("返回");
    registerLayout->addWidget(backBtn,14,0,1,1);
    confirmBtn->setText("确认");
    registerLayout->addWidget(confirmBtn,14,2,1,1);
    this->setLayout(registerLayout);
    connect(confirmBtn, &QPushButton::clicked, this, &RegisterDialog::ConfirmBtnClicked);
    connect(backBtn, &QPushButton::clicked, this, &RegisterDialog::BackBtnClicked);
//    connect(imageBtn, &QPushButton::clicked, this, &RegisterDialog::OpenImage);
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::ConfirmBtnClicked()
{

    //std::string encoded = base64_encode(reinterpret_cast<const unsigned char*>(s.c_str()), s.length());
    //std::string decoded = base64_decode(encoded);
    if(JudgeEmpty()) {
        /*注册*/
        struct userStruct user;
        std::string s = email->text().toStdString();
        user.Email = base64_encode(reinterpret_cast<const unsigned char*>(s.c_str()), s.length());
        s = sexType->currentText().toStdString();
        user.Gender= base64_encode(reinterpret_cast<const unsigned char*>(s.c_str()), s.length());
        s = "";
        user.Image= base64_encode(reinterpret_cast<const unsigned char*>(s.c_str()), s.length());
        s = locateArea->text().toStdString();
        user.LocateArea = base64_encode(reinterpret_cast<const unsigned char*>(s.c_str()), s.length());
        s = userPwd->text().toStdString();
        user.PassWord= base64_encode(reinterpret_cast<const unsigned char*>(s.c_str()), s.length());
        s = phone->text().toStdString();
        user.Phone= base64_encode(reinterpret_cast<const unsigned char*>(s.c_str()), s.length());
        user.PlayTime= 0;
        s = signature->toPlainText().toStdString();
        user.SelfTag = base64_encode(reinterpret_cast<const unsigned char*>(s.c_str()), s.length());
        s = studentId->text().toStdString();
        user.StudentId = base64_encode(reinterpret_cast<const unsigned char*>(s.c_str()), s.length());
        s = university->text().toStdString();
        user.University = base64_encode(reinterpret_cast<const unsigned char*>(s.c_str()), s.length());
        s = userName->text().toStdString();
        user.UserName = base64_encode(reinterpret_cast<const unsigned char*>(s.c_str()), s.length());
        s = QQ->text().toStdString();
        user.UserQQ = base64_encode(reinterpret_cast<const unsigned char*>(s.c_str()), s.length());
        user.PlayTime = 0;

        if (client.Register(user)) {
            bool  flag = client.SetSecurity(QStringToStdString(userName->text()), QStringToStdString(securityQuestion->currentText()),QStringToStdString(securityAnswer->text()));
//            if(flag) {

//                QMessageBox::information(this, tr("Welcome"), tr("插入密保问题成功！"), QMessageBox::tr("确定"));
//            }
            QMessageBox::information(this, tr("Welcome"), tr("恭喜注册成功！"), QMessageBox::tr("确定"));
            this->hide();
            LoginDialog *loginDlg = new LoginDialog;
            loginDlg->show();
        }
        else {
            QMessageBox::information(this, tr("提示"), tr("此用户名已注册！请使用另外的用户名。"), QMessageBox::tr("确定"));

        }
    }
    return ;
}

/***
  *判断一个字符串是否为纯数字
  */
bool RegisterDialog::isNotDigitStr(QString src)
{
    QByteArray ba = src.toLatin1();//QString 转换为 char*
     const char *s = ba.data();

    while(*s && (*s<'0' || *s>'9')) s++;

    if (*s)
    { //含有数字
        return false;
    }
    else
    { //不含数字
        return true;
    }
}

bool RegisterDialog::isDigitStr(QString src)
{
    QByteArray ba = src.toLatin1();//QString 转换为 char*
     const char *s = ba.data();

    while(*s && *s>='0' && *s<='9') s++;

    if (*s)
    { //不是纯数字
        return false;
    }
    else
    { //纯数字
        return true;
    }
}

bool RegisterDialog::JudgeEmpty()
{
    if(userName->text() == NULL) {
        QMessageBox::warning(this, tr("提示"), tr("用户名不能为空！"), QMessageBox::tr("确定"));
        return false;
    }
    if(userPwd->text() == NULL) {
        QMessageBox::warning(this, tr("提示"), tr("密码不能为空！"), QMessageBox::tr("确定"));
        return false;
    }
    if(userPwd2->text() == NULL) {
        QMessageBox::warning(this, tr("提示"), tr("请再次输入密码！"), QMessageBox::tr("确定"));
        return false;
    }
    if(userPwd2->text() != userPwd->text()) {
        QMessageBox::warning(this, tr("提示"), tr("前后密码不一致！"), QMessageBox::tr("确定"));
        return false;
    }
    if(phone->text().length() == NULL || phone->text().size() != 11) {
        QMessageBox::warning(this, tr("提示"), tr("请输入有效的电话！"), QMessageBox::tr("确定"));
        return false;
    }
    if(email->text() == NULL) {
        QMessageBox::warning(this, tr("提示"), tr("请输入邮箱！"), QMessageBox::tr("确定"));
        return false;
    }
    if(email->text() != NULL) {
        QString str = email->text().right(4);

        if(str != ".com") {
            QMessageBox::warning(this, tr("提示"), tr("请输入有效的邮箱！"), QMessageBox::tr("确定"));
            return false;
        }
        if(email->text().indexOf("@") == -1) {
            QMessageBox::warning(this, tr("提示"), tr("请输入有效的邮箱！"), QMessageBox::tr("确定"));
            return false;
        }
    }
    if(QQ->text() == NULL || !isDigitStr(QQ->text())) {
        QMessageBox::warning(this, tr("提示"), tr("请输入有效的QQ号！"), QMessageBox::tr("确定"));
        return false;
    }
    if(studentId->text() == NULL || !isDigitStr(studentId->text())) {
        QMessageBox::warning(this, tr("提示"), tr("请输入有效的学号！"), QMessageBox::tr("确定"));
        return false;
    }
    if(university->text() == NULL || !isNotDigitStr(university->text())) {
        QMessageBox::warning(this, tr("提示"), tr("请输入有效的学校！"), QMessageBox::tr("确定"));
        return false;
    }
    if(locateArea->text() == NULL || !isNotDigitStr(locateArea->text())) {
        QMessageBox::warning(this, tr("提示"), tr("请输入有效的地区！"), QMessageBox::tr("确定"));
        return false;
    }
    if(securityAnswer->text() == NULL) {
        QMessageBox::warning(this, tr("提示"), tr("请设置密保问题，输入密保问题答案！"), QMessageBox::tr("确定"));
        return false;
    }
    return true;
}

void RegisterDialog::BackBtnClicked()
{
    this->hide();
    LoginDialog *loginDlg = new LoginDialog;
    loginDlg->show();
}

//void RegisterDialog::OpenImage()
//{
//    QString filename;
//    filename=QFileDialog::getOpenFileName(this, tr("选择图像"), "", tr("Images (*.png *.bmp *.jpg *.tif *.GIF )"));
//    if(filename.isEmpty())
//    {
//        return;
//    }
//    else {
//        QImage* img=new QImage;
//        if(! ( img->load(filename) ) ){ //加载图像  {
//            QMessageBox::information(this,tr("打开图像失败"),tr("打开图像失败!"));
//            delete img;
//            return;
//        }
//        imageBtn->setText(filename.section('/',-1));
//            //mainLayout->addWidget(img,0,0,1,1);
//   }
//}
