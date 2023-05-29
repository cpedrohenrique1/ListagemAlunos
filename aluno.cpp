#include "aluno.h"

namespace Pedro {

Pedro::Matricula Aluno::getMatricula() const
{
    return matricula;
}

void Aluno::setMatricula(Pedro::Matricula newMatricula)
{
    matricula = newMatricula;
}

QString Aluno::getDisciplinaTurma()
{
    std::list<Pedro::DisciplinaTurma>::iterator disciplinat;
    QString saida = "";
    for (disciplinat = disciplinaTurma->begin(); disciplinat != disciplinaTurma->end(); disciplinat++)
    {
        saida += disciplinat->getDisciplinaTurma() + " ";
    }
    return saida;
}

std::list<DisciplinaTurma> *Aluno::getListaDisciplinaTurma()
{
    return disciplinaTurma;
}

void Aluno::setDisciplinaTurma(std::list<Pedro::DisciplinaTurma> *newDisciplinaTurma)
{
    disciplinaTurma = newDisciplinaTurma;
}

Aluno Aluno::getAluno() const
{
    return *this;
}

Aluno::Aluno():
    nomeCompleto("")
  , disciplinaTurma()
  , matricula()
{}

Aluno::Aluno(QString nomeCompleto, std::list<DisciplinaTurma> *newDisciplinaTurma, Matricula matricula):
    nomeCompleto(nomeCompleto)
  , disciplinaTurma(newDisciplinaTurma)
  , matricula(matricula)
{}

QString Aluno::getNomeCompleto() const
{
    return nomeCompleto;
}

void Aluno::setNomeCompleto(QString newNomeCompleto)
{
    nomeCompleto = newNomeCompleto;
}

}
