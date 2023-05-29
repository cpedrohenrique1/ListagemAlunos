#include "fm_inserirdisciplina.h"
#include "ui_fm_inserirdisciplina.h"
#include <QMessageBox>

Fm_InserirDisciplina::Fm_InserirDisciplina(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Fm_InserirDisciplina)
{
    ui->setupUi(this);
}

Fm_InserirDisciplina::~Fm_InserirDisciplina()
{
    delete ui;
}

void Fm_InserirDisciplina::on_pushButton_clicked()
{
    try {
        if (ui->lineEdit_inputCodigoDisciplina->text().isEmpty())
        {
            throw QString("Codigo disciplina nao pode estar vazio");
        }

        emit infoTransmitida(ui->lineEdit_inputCodigoDisciplina->text());
        close();
    }
    catch (QString &erro) {
        QMessageBox::critical(this, "Erro", erro);
    }
    catch (...) {
        QMessageBox::critical(this, "Erro", "Erro ao entrar com o codigo da disciplina");
    }
}

