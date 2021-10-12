#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);  //вызывается при включение программы
    ~MainWindow();  //вызывается при завершение программы

private slots:
    void on_pushButton_inputn_clicked(); //Кнопка создающая рандомный массив (имя кнопки: создать массив)

    void on_pushButton_calcSumm_clicked(); //Кнопка вычисления суммы чисел массива

    void on_action_about_triggered(); //Меню Справка -> О разрабочике. Выводит информацию о разработчике в окне

private:
    int *arr;
    int n;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
