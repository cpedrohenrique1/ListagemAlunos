#include "fm_inserirdisciplinaturma.h"
#include "ui_fm_inserirdisciplinaturma.h"
#include <QMessageBox>

Fm_InserirDisciplinaTurma::Fm_InserirDisciplinaTurma(QWidget *parent, std::list<Pedro::Aluno> *listaAluno) :
    QDialog(parent),
    ui(new Ui::Fm_InserirDisciplinaTurma)
{
    ui->setupUi(this);
    std::list<QString> listaDisciplinas;
    for (std::list<Pedro::Aluno>::iterator itAluno = listaAluno->begin(); itAluno != listaAluno->end(); ++itAluno)
    {
        for (std::list<Pedro::DisciplinaTurma>::iterator itDisciplina = itAluno->getListaDisciplinaTurma()->begin(); itDisciplina != itAluno->getListaDisciplinaTurma()->end(); ++itDisciplina)
        {
            auto itExiste = std::find(listaDisciplinas.begin(), listaDisciplinas.end(), itDisciplina->getDisciplinaTurma());
            if (itExiste == listaDisciplinas.end())
            {
                listaDisciplinas.push_back(itDisciplina->getDisciplinaTurma());
            }
        }
    }
    for (std::list<QString>::iterator itDisciplinas = listaDisciplinas.begin(); itDisciplinas != listaDisciplinas.end(); ++itDisciplinas)
    {
        ui->comboBox->addItem(*itDisciplinas);
    }
}

Fm_InserirDisciplinaTurma::~Fm_InserirDisciplinaTurma()
{
    delete ui;
}

void Fm_InserirDisciplinaTurma::on_pushButton_clicked()
{
    try
    {
        if (ui->comboBox->currentText().isEmpty())
        {
            throw QString("Erro, comboBox nao inicializada");
        }
        emit infoTransmitida(ui->comboBox->currentText());
        close();
    }
    catch (QString &erro) {
        QMessageBox::critical(this,"Erro", erro);
    }
    catch (...) {
        QMessageBox::critical(this,"Erro", "Erro ao entrar com o numero");
    }
}

