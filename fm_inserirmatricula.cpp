#include "fm_inserirmatricula.h"
#include "ui_fm_inserirmatricula.h"
#include <QMessageBox>

Fm_InserirMatricula::Fm_InserirMatricula(QWidget *parent, std::list<Pedro::Aluno> *listaAluno) :
    QDialog(parent),
    ui(new Ui::Fm_InserirMatricula)
{
    ui->setupUi(this);
    std::list<QString> listaMatricula;
    for (std::list<Pedro::Aluno>::iterator itAluno = listaAluno->begin(); itAluno != listaAluno->end(); ++itAluno)
    {
        auto itExiste = std::find(listaMatricula.begin(), listaMatricula.end(), itAluno->getMatricula());
        if (itExiste == listaMatricula.end())
        {
            listaMatricula.push_back(itAluno->getMatricula());
        }
    }
    for (std::list<QString>::iterator itListaMatricula = listaMatricula.begin(); itListaMatricula != listaMatricula.end(); ++itListaMatricula)
    {
        ui->comboBox->addItem(*itListaMatricula);
    }
}

Fm_InserirMatricula::~Fm_InserirMatricula()
{
    delete ui;
}

void Fm_InserirMatricula::on_pushButton_clicked()
{
    try {
        if (ui->comboBox->currentText().isEmpty())
        {
            throw QString("Erro, comboBox nao inicializada");
        }
        emit infoTransmitida(ui->comboBox->currentText());
        close();
    }
    catch (QString &erro) {
        QMessageBox::critical(this, "Erro", erro);
    }
    catch (...) {
        QMessageBox::critical(this, "Erro", "Erro ao enviar a matricula");
    }
}

