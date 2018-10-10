#ifndef SVGCHANGEFORM_H
#define SVGCHANGEFORM_H

#include <QMainWindow>
#include <QFileDialog>
#include <QtDebug>
#include <QDir>
#include <QFileInfo>
#include <QColorDialog>
namespace Ui {
class SvgChangeForm;
}

class SvgChangeForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit SvgChangeForm(QWidget *parent = 0);
    ~SvgChangeForm();
    void writeFile(QString filePath,QString colorRgb);
private slots:
    void on_pushButton_select_Dir_clicked();

    void on_pushButton_change_clicked();

    void on_pushButton_clicked();

    void on_pushButton_File_path_clicked();

private:
    Ui::SvgChangeForm *ui;
    QString _FileDir;//需要修改的svg文件或文件夹
    QFileInfoList _FileInfoList;//遍历文件
};

#endif // SVGCHANGEFORM_H
