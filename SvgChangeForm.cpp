#include "SvgChangeForm.h"
#include "ui_SvgChangeForm.h"

SvgChangeForm::SvgChangeForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SvgChangeForm)
{
    ui->setupUi(this);   
//    _FileDir = "F:/Roboshop/seer/Roboshop-Pro/333";
    ui->lineEdit_dir_name->setReadOnly(true);
    ui->lineEdit_color_rgb->setPlaceholderText("#ff5500");
}
SvgChangeForm::~SvgChangeForm()
{
    delete ui;
}

void SvgChangeForm::on_pushButton_select_Dir_clicked()
{
    QString file= QFileDialog::getExistingDirectory(NULL," ",".");//只获取文件夹路径
    if(!file.isEmpty())
    {
        _FileDir=file;
        ui->lineEdit_dir_name->setText(_FileDir);
    }
}
//fill="#1296db"
void SvgChangeForm::on_pushButton_change_clicked()
{

//    QString displayString;
  if(!_FileDir.contains(".svg"))
  {

    QDir dir(_FileDir);
    int fileCount=0;
    if(!dir.exists()) //判断文件夹是否存在

    {

       qDebug()<<QStringLiteral("文件夹不存在!");

    }
    else
    {
       dir.setFilter(QDir::Files); //设置dir的过滤模式,表示只遍历本文件夹内的文件

       _FileInfoList = dir.entryInfoList();  //获取本文件夹内所有文件的信息
       fileCount = _FileInfoList.count();//获取文件夹内文件的个数


        if(fileCount!=0&&_FileInfoList.size()!=0)
           {
            for(int i=0;i<_FileInfoList.size();i++)

             {

               QFileInfo fileInfo = _FileInfoList[i]; //获取每个文件信息
               QString filePath = fileInfo.absoluteFilePath();//获取文件绝对路径即全路径
                 if(filePath.contains(".svg"))
                 {
//
                    writeFile(filePath,ui->lineEdit_color_rgb->text());

                }
            }

      }
   }
  }
  else
  {

      writeFile(_FileDir,ui->lineEdit_color_rgb->text());
  }
}
//
void SvgChangeForm::writeFile(QString filePath,QString colorRgb)
{
    QFile file(filePath);
    QByteArray needLine;
     if(!file.open(QIODevice::ReadOnly |QIODevice::Text| QIODevice:: WriteOnly))
     {
        qDebug()<<QStringLiteral("打开文件失败");
     }

     else
     {
         while(!file.atEnd())
         {
               QByteArray line = file.readLine();
               needLine = line;
               QString strRgb;
               int lineNum=needLine.indexOf("fill=",0);

               if(lineNum!=-1)
               {
                 strRgb= needLine.mid(lineNum+6,7);
                 needLine.replace(strRgb,ui->lineEdit_color_rgb->text().toLocal8Bit());
                 qDebug()<<needLine<<"needLine";
                 file.close();
                 file.open(QIODevice:: WriteOnly);
                 file.write(needLine);
                 file.close();
              }

         }
     }

}

void SvgChangeForm::on_pushButton_clicked()
{
    QColorDialog dialog;
      if (dialog.exec()) {
          QColor color = dialog.selectedColor();
          QString senderName = sender()->objectName();

          if ("pushButton_change" == senderName)
          {
//              ui->widget->setAutoFillBackground(true);//必须有这条语句
//              ui->widget->setPalette(QPalette(color));
//              qDebug()<<strRgb.toRgb()<<color;
          }
        }

//       QString newFile = QString(tr("%1").arg(_FileDir)+"/2.txt");
//       QByteArray needLine;
//       QFile file(newFile);
//      if(!file.open(QIODevice::ReadOnly|QIODevice::Text| QIODevice:: WriteOnly))
//      {
//          qDebug()<<QStringLiteral("打开文件失败");
//      }
//       QByteArray line = file.readLine();
//       needLine = line;

//      int a= needLine.indexOf("fill",0);
//      QString str= needLine.mid(a+6,3);
//      needLine.replace(str,"xxx");
//      file.close();
//      file.open(QIODevice:: WriteOnly);
//      file.write(needLine);
//       qDebug()<<a<<str<<"dddddddddddddddddddddddd";
}
void SvgChangeForm::on_pushButton_File_path_clicked()
{
    QString file= QFileDialog::getOpenFileName(NULL," ",".","*.zip *.svg");
    if(!file.isEmpty())
    {
        _FileDir=file;
        ui->lineEdit_dir_name->setText(_FileDir);
    }
}
