#ifndef EXECUTARMODO_H
#define EXECUTARMODO_H

#include "disciplinaturma.h"
#include "aluno.h"
#include <QTableWidget>

namespace Pedro
{

class ExecutarModo
{
private:
    int infoCurso;
    Pedro::DisciplinaTurma infoDisciplinaTurma;
    Pedro::Aluno infoAluno;

private slots:
    void receberInfo(int infoCurso);

public:
    ExecutarModo();
    QTableWidget* operator ()(QString textoComboBox);
    int getInfoCurso() const;
    void setInfoCurso(int newInfoCurso);
    Pedro::DisciplinaTurma getInfoDisciplinaTurma() const;
    void setInfoDisciplinaTurma(Pedro::DisciplinaTurma newInfoDisciplinaTurma);
    Pedro::Aluno getInfoAluno() const;
    void setInfoAluno(Pedro::Aluno newInfoAluno);
};

}

#endif // EXECUTARMODO_H
