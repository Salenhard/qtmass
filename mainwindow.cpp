#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logic.h"      //подключение собственного модуля
#include <QMessageBox> //подключение окна с сообщением

bool number_check(QString str) //Функция проверки числа
{
    if(str.toInt() <= 0 or str.toInt() == false) //если введено не число или число <= 0 то возращает false
        return false;
    else
        return true;
}

MainWindow::MainWindow(QWidget *parent)//вызывается при включение программы
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    arr = nullptr;
}

MainWindow::~MainWindow() //вызывается при завершение программы
{
    delete ui;
    if(arr != nullptr)      //проверка заполнен ли массив если да то удаляет массив
    delete[]arr;            //очищение памяти
}

void MainWindow::on_pushButton_inputn_clicked() //Кнопка создающая и выводящая в plainTextEdit рандомный массив (имя кнопки: создать массив)
{
    QString str;
    if(number_check(ui->lineEdit_inputn->text()) == false){  //проверка введенных данных если введены не верно то выводит сообщение об этом в lindEdit
        ui->lineEdit_inputn->setText("Неверный формат числа!");
        return;
    }
    else
    {
    n = ui->lineEdit_inputn->text().toInt(); //Ввод размера массива из строки lineEdit_inputn
    }
    if(arr != nullptr)      //проверка заполнен ли массив если да то удаляет массив
    delete[]arr;            //очищение памяти
    arr = new int[n];       //Создание массива arr размером n
    logic::fill_mass_rand(arr,n);                    //Функция заполнения массива рандомными числами
    for(int i = 0; i < n; i++)      //Цикл вывода массива в plainTextEdit
    {
        ui->plainTextEdit->appendPlainText(str.setNum(arr[i])); //добавляет строку с числом в plainTextEdit
    }
     ui->plainTextEdit->appendPlainText("");   //добавляет строку в plainTextEdit для разделения массивов
}

void MainWindow::on_pushButton_calcSumm_clicked()  //Кнопка вычисления и вывода суммы чисел массива (имя: вычислить сумму)
{
    QString str;
    ui->label_SummOutput->setText( str.setNum( logic::mass_summ( arr,n ) ) ); //вывод суммы в label
}

void MainWindow::on_action_about_triggered() //Меню Справка -> О разрабочике. Выводит информацию о разработчике в окне
{
    QMessageBox::about(this, "О разработчике", "Гурбатов Владислав ИВТ-20"); //Окно с сообщением
}


