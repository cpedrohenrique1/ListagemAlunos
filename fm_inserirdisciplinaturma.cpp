#include "fm_inserirdisciplinaturma.h"
#include "ui_fm_inserirdisciplinaturma.h"
#include <QMessageBox>

Fm_InserirDisciplinaTurma::Fm_InserirDisciplinaTurma(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Fm_InserirDisciplinaTurma)
{
    ui->setupUi(this);
}

Fm_InserirDisciplinaTurma::~Fm_InserirDisciplinaTurma()
{
    delete ui;
}

void Fm_InserirDisciplinaTurma::on_pushButton_clicked()
{
    try
    {
        if (ui->lineEdit_inputCodigoDisciplina->text().isEmpty())
        {
            throw QString("Nao pode estar vazio");
        }
        emit infoTransmitida(Pedro::DisciplinaTurma(ui->lineEdit_inputCodigoDisciplina->text(), ui->lineEdit_inputCodigoTurma->text()));
        close();
    }
    catch (QString &erro) {
        QMessageBox::critical(this,"Erro", erro);
    }
    catch (...) {
        QMessageBox::critical(this,"Erro", "Erro ao entrar com o numero");
    }
}

