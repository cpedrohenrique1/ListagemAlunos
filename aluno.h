#ifndef ALUNO_H
#define ALUNO_H

#include <QString>
#include "disciplinaturma.h"
#include "matricula.h"
#include <list>

namespace Pedro
{

class Aluno
{
private:
    QString nomeCompleto;
    std::list<Pedro::DisciplinaTurma> disciplinaTurma;
    Pedro::Matricula matricula;
public:
    Aluno();
    Aluno(QString nomeCompleto, std::list<Pedro::DisciplinaTurma> disciplinaTurma, Pedro::Matricula matricula);
    QString getNomeCompleto() const;
    void setNomeCompleto(QString newNomeCompleto);
    Pedro::Matricula getMatricula() const;
    void setMatricula(Pedro::Matricula newMatricula);
    std::list<Pedro::DisciplinaTurma> getDisciplinaTurma() const;
    void setDisciplinaTurma(std::list<Pedro::DisciplinaTurma> newDisciplinaTurma);
    Aluno getAluno() const;
};

}

#endif // ALUNO_H
