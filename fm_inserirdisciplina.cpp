#include "fm_inserirdisciplina.h"
#include "ui_fm_inserirdisciplina.h"
#include <QMessageBox>
#include <list>

Fm_InserirDisciplina::Fm_InserirDisciplina(QWidget *parent, std::list<Pedro::Aluno> *listaAluno) :
    QDialog(parent),
    ui(new Ui::Fm_InserirDisciplina)
{
    ui->setupUi(this);
    std::list<QString> Disciplinas;
    for (std::list<Pedro::Aluno>::iterator it = listaAluno->begin(); it != listaAluno->end(); ++it)
    {
        for (std::list<Pedro::DisciplinaTurma>::iterator itDisciplina = it->getListaDisciplinaTurma()->begin(); itDisciplina != it->getListaDisciplinaTurma()->end(); ++itDisciplina)
        {
            auto itExiste = std::find(Disciplinas.begin(), Disciplinas.end(), itDisciplina->getCodigoDisciplina());
            if (itExiste == Disciplinas.end())
            {
                Disciplinas.push_back(itDisciplina->getCodigoDisciplina());
            }
        }
    }
    for (std::list<QString>::iterator iterador = Disciplinas.begin(); iterador != Disciplinas.end(); ++iterador)
    {
        ui->comboBox->addItem(*iterador);
    }
}

Fm_InserirDisciplina::~Fm_InserirDisciplina()
{
    delete ui;
}

void Fm_InserirDisciplina::on_pushButton_clicked()
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
        QMessageBox::critical(this, "Erro", "Erro ao entrar com o codigo da disciplina");
    }
}

