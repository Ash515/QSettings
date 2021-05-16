#include "widget.h"
#include "ui_widget.h"
#include<QColorDialog>
#include<QColor>
#include<QSettings>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);    

        for(int i=0;i<9;i++)

        {

            ColorList.append(Qt::black);

        }
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_Button_1_clicked()
{
    QColor color=QColorDialog::getColor(ColorList[0],this,"Choose Background color");

        if(color.isValid())

        {

            ColorList[0]=color;

            QString css=QString ("Background-color:%1").arg(color.name());

            ui->Button_1->setStyleSheet(css);
        }
}

void Widget::on_Button_2_clicked()
{
    QColor color=QColorDialog::getColor(ColorList[1],this,"Choose Background color");

        if(color.isValid())

        {

            ColorList[1]=color;

            QString css=QString ("Background-color:%1").arg(color.name());

            ui->Button_2->setStyleSheet(css);
        }
}

void Widget::on_Button_3_clicked()
{
    QColor color=QColorDialog::getColor(ColorList[1],this,"Choose Background color");

        if(color.isValid())

        {

            ColorList[2]=color;

            QString css=QString ("Background-color:%1").arg(color.name());

            ui->Button_3->setStyleSheet(css);
        }
}

void Widget::on_Button_4_clicked()
{
    QColor color=QColorDialog::getColor(ColorList[1],this,"Choose Background color");

        if(color.isValid())

        {

            ColorList[3]=color;

            QString css=QString ("Background-color:%1").arg(color.name());

            ui->Button_4->setStyleSheet(css);
        }
}

void Widget::on_Button_5_clicked()
{
    QColor color=QColorDialog::getColor(ColorList[1],this,"Choose Background color");

        if(color.isValid())

        {

            ColorList[4]=color;

            QString css=QString ("Background-color:%1").arg(color.name());

            ui->Button_5->setStyleSheet(css);
        }
}

void Widget::on_Button_6_clicked()
{
    QColor color=QColorDialog::getColor(ColorList[1],this,"Choose Background color");

        if(color.isValid())

        {

            ColorList[5]=color;

            QString css=QString ("Background-color:%1").arg(color.name());

            ui->Button_6->setStyleSheet(css);
        }
}

void Widget::on_Button_7_clicked()
{
    QColor color=QColorDialog::getColor(ColorList[1],this,"Choose Background color");

        if(color.isValid())

        {

            ColorList[6]=color;

            QString css=QString ("Background-color:%1").arg(color.name());

            ui->Button_7->setStyleSheet(css);
        }
}

void Widget::on_Button_8_clicked()
{
    QColor color=QColorDialog::getColor(ColorList[1],this,"Choose Background color");

        if(color.isValid())

        {

            ColorList[7]=color;

            QString css=QString ("Background-color:%1").arg(color.name());

            ui->Button_8->setStyleSheet(css);
        }
}

void Widget::on_Button_9_clicked()
{
    QColor color=QColorDialog::getColor(ColorList[1],this,"Choose Background color");

        if(color.isValid())

        {

            ColorList[8]=color;

            QString css=QString ("Background-color:%1").arg(color.name());

            ui->Button_9->setStyleSheet(css);
        }
}

void Widget::on_SaveColor_clicked()
{
    SaveColor("Button 1",ColorList[0]);
    SaveColor("Button 2",ColorList[1]);
    SaveColor("Button 3",ColorList[2]);
    SaveColor("Button 4",ColorList[3]);
    SaveColor("Button 5",ColorList[4]);
    SaveColor("Button 6",ColorList[5]);
    SaveColor("Button 7",ColorList[6]);
    SaveColor("Button 8",ColorList[7]);
    SaveColor("Button 9",ColorList[8]);
}


void Widget::on_LoadColor_clicked()
{
    setLoadedColor("button 1",0,ui->Button_1);
    setLoadedColor("button 2",0,ui->Button_2);
    setLoadedColor("button 3",0,ui->Button_3);
    setLoadedColor("button 4",0,ui->Button_4);
    setLoadedColor("button 5",0,ui->Button_5);
    setLoadedColor("button 6",0,ui->Button_6);
    setLoadedColor("button 7",0,ui->Button_7);
    setLoadedColor("button 8",0,ui->Button_8);
    setLoadedColor("button 9",0,ui->Button_9);
}

void Widget::SaveColor(QString key, QColor color)
{
    int red=color.red();

        int green=color.green();

        int blue=color.blue();

        QSettings settings("Blikoon","SettingsDemo");

        settings.beginGroup("ButtonColor");

        settings.setValue(key +"r",red);

        settings.setValue(key +"g",green);

        settings.setValue(key +"b",blue);

        settings.endGroup();
}

QColor Widget::loadColor(QString key)
{
    int red;

        int green;

        int blue;

        QSettings settings("Blikoon","SettingsDemo");

        settings.beginGroup("ButtonColor");

        red=settings.value(key+"r",QVariant(0)).toInt();

        green=settings.value(key+"g",QVariant(0)).toInt();

        blue=settings.value(key+"b",QVariant(0)).toInt();

        settings.endGroup();

        return QColor(red,green,blue);
}

void Widget::setLoadedColor(QString key, int index, QPushButton *button)
{
    QColor color=loadColor(key);

        ColorList[index]=color;

        QString css=QString ("Background-color:%1").arg(color.name());

        button->setStyleSheet(css);
}

