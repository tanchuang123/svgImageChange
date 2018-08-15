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

private:
    Ui::SvgChangeForm *ui;
    QString _FileDir;
    QFileInfoList _FileInfoList;
};

#endif // SVGCHANGEFORM_H
