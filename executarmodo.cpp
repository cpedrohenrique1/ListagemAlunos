#include "executarmodo.h"
#include "fm_inserircurso.h"

namespace Pedro
{

int ExecutarModo::getInfoCurso() const
{
    return infoCurso;
}

void ExecutarModo::setInfoCurso(int newInfoCurso)
{
    infoCurso = newInfoCurso;
}

Pedro::DisciplinaTurma ExecutarModo::getInfoDisciplinaTurma() const
{
    return infoDisciplinaTurma;
}

void ExecutarModo::setInfoDisciplinaTurma(Pedro::DisciplinaTurma newInfoDisciplinaTurma)
{
    infoDisciplinaTurma = newInfoDisciplinaTurma;
}

Pedro::Aluno ExecutarModo::getInfoAluno() const
{
    return infoAluno;
}

void ExecutarModo::setInfoAluno(Pedro::Aluno newInfoAluno)
{
    infoAluno = newInfoAluno;
}

void ExecutarModo::receberInfo(int infoCurso)
{
    this->infoCurso = infoCurso;
}

ExecutarModo::ExecutarModo():
    infoCurso(0)
  , infoDisciplinaTurma()
  , infoAluno()
{}

QTableWidget* ExecutarModo::operator ()(QString textoComboBox)
{
    if (textoComboBox == "Selecionar Modo...")
    {
        throw QString("Selecione um modo primieiro");
    }
    if (textoComboBox == "Todos os alunos de um curso")
    {
        QTableWidget* tabela = new QTableWidget;
        Fm_InserirCurso f_inserirCurso;
        QObject::connect(&f_inserirCurso, );
        f_inserirCurso.exec();
        tabela->setRowCount(1);
        tabela->setColumnCount(1);
        tabela->setItem(0, 0, new QTableWidgetItem(infoCurso));
        return tabela;
    }
    if (textoComboBox == "Alunos de uma turma")
    {

    }
    if (textoComboBox == "Alunos de uma disciplina")
    {

    }
    if (textoComboBox == "Todas as disciplinas de um aluno")
    {

    }
    return nullptr;
}

}
