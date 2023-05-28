#include "fm_inserircurso.h"
#include "ui_fm_inserircurso.h"
#include <QMessageBox>

Fm_InserirCurso::Fm_InserirCurso(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Fm_InserirCurso)
{
    ui->setupUi(this);
}

Fm_InserirCurso::~Fm_InserirCurso()
{
    delete ui;
}

void Fm_InserirCurso::on_pushButton_clicked()
{
    try {
        if (ui->lineEdit_inputNCurso->text().isEmpty())
        {
            throw QString("numero esta vazio");
        }
        QString teste = ui->lineEdit_inputNCurso->text();
        for (int i = 0; i < teste.size(); i++)
        {
            if (teste[i] > '9' || teste[i] < '0')
            {
                throw QString("Somente numeros inteiros positivos serao aceitos");
            }
        }
        emit infoTransmitida(ui->lineEdit_inputNCurso->text().toInt());
        close();
    }
    catch (QString &erro) {
        QMessageBox::critical(this,"Erro", erro);
    }
    catch (...) {
        QMessageBox::critical(this,"Erro", "Erro ao entrar com o numero");
    }
}

