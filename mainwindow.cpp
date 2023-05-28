#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "buscaraluno.h"
#include "executarmodo.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_buscarArquivo_clicked()
{
    try {
        Pedro::BuscarAluno buscarAluno;
        ui->lineEdit_inputEnderecoArquivo->setText(buscarAluno(this, listaAluno));
    }
    catch (QString &erro) {
        QMessageBox::critical(this, "Erro", erro);
    }
    catch (...) {
        QMessageBox::critical(this, "Erro", "Erro ao buscar o arquivo");
    }
}


void MainWindow::on_pushButton_executarModo_clicked()
{
    try {
        Pedro::ExecutarModo executarModo;
        ui->tableWidget_output = executarModo(ui->comboBox_inputModo->currentText());
    }
    catch (QString &erro) {
        QMessageBox::critical(this, "Erro", erro);
    }
    catch (...) {
        QMessageBox::critical(this, "Erro", "Erro ao selecionar o modo");
    }
}

