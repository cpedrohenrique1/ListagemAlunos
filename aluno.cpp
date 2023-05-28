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

std::list<Pedro::DisciplinaTurma> Aluno::getDisciplinaTurma() const
{
    return disciplinaTurma;
}

void Aluno::setDisciplinaTurma(std::list<Pedro::DisciplinaTurma> newDisciplinaTurma)
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

Aluno::Aluno(QString nomeCompleto, std::list<DisciplinaTurma> disciplinaTurma, Matricula matricula):
    nomeCompleto(nomeCompleto)
  , disciplinaTurma(disciplinaTurma)
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
