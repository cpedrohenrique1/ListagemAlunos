#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "aluno.h"
#include <list>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_buscarArquivo_clicked();

    void on_pushButton_executarModo_clicked();

private:
    Ui::MainWindow *ui;
    std::list<Pedro::Aluno> listaAluno;
};
#endif // MAINWINDOW_H
