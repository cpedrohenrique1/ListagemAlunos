#include "fm_inserircurso.h"
#include "ui_fm_inserircurso.h"
#include <QMessageBox>
#include <algorithm>
#include <list>

Fm_InserirCurso::Fm_InserirCurso(QWidget *parent, std::list<Pedro::Aluno> *listaAluno) :
    QDialog(parent),
    ui(new Ui::Fm_InserirCurso)
{
    ui->setupUi(this);
    std::list<int> Cursos;
    for (std::list<Pedro::Aluno>::iterator it = listaAluno->begin(); it != listaAluno->end(); ++it)
    {
        std::list<int>::iterator iterador = std::find(Cursos.begin(), Cursos.end(), it->getMatricula().getNCurso());
        if (iterador == Cursos.end())
            Cursos.push_back(it->getMatricula().getNCurso());
    }
    for (std::list<int>::iterator iterador = Cursos.begin(); iterador != Cursos.end(); ++iterador)
    {
        ui->comboBox->addItem(QString::number(*iterador));
    }
}

Fm_InserirCurso::~Fm_InserirCurso()
{
    delete ui;
}

void Fm_InserirCurso::on_pushButton_clicked()
{
    try {
        if (ui->comboBox->currentText().isEmpty())
        {
            throw QString("Erro, comboBox nao inicializada");
        }
        emit infoTransmitida(ui->comboBox->currentText().toInt());
        close();
    }
    catch (QString &erro) {
        QMessageBox::critical(this,"Erro", erro);
    }
    catch (...) {
        QMessageBox::critical(this,"Erro", "Erro ao entrar com o numero");
    }
}

