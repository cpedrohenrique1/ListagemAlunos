#include "fm_inserirmatricula.h"
#include "ui_fm_inserirmatricula.h"
#include <QMessageBox>

Fm_InserirMatricula::Fm_InserirMatricula(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Fm_InserirMatricula)
{
    ui->setupUi(this);
}

Fm_InserirMatricula::~Fm_InserirMatricula()
{
    delete ui;
}

void Fm_InserirMatricula::on_pushButton_clicked()
{
    try {
        if (ui->lineEdit_inputMatricula->text().isEmpty())
        {
            throw QString("Matricula nao pode estar vazia");
        }
        InserirMatricula inserirMatricula;
        emit infoTransmitida(inserirMatricula(ui->lineEdit_inputMatricula->text()));
        close();
    }
    catch (QString &erro) {
        QMessageBox::critical(this, "Erro", erro);
    }
    catch (...) {
        QMessageBox::critical(this, "Erro", "Erro ao enviar a matricula");
    }
}

