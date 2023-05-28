#ifndef EXECUTARMODO_H
#define EXECUTARMODO_H

#include "disciplinaturma.h"
#include "aluno.h"
#include <QTableWidget>
#include <QDialog>
#include <QObject>

namespace Pedro
{

class ExecutarModo : public QDialog
{
    Q_OBJECT

private:
    int infoCurso;
    Pedro::DisciplinaTurma infoDisciplinaTurma;
    Pedro::Aluno infoAluno;

private slots:
    void receberInfo(int infoCurso);
    void receberInfoDisciplina(Pedro::DisciplinaTurma disciplinaTurma);

public:
    ExecutarModo();
    void operator ()(QString textoComboBox, QTableWidget* parent, std::list<Pedro::Aluno> listaAlunos);
    int getInfoCurso() const;
    void setInfoCurso(int newInfoCurso);
    Pedro::DisciplinaTurma getInfoDisciplinaTurma() const;
    void setInfoDisciplinaTurma(Pedro::DisciplinaTurma newInfoDisciplinaTurma);
    Pedro::Aluno getInfoAluno() const;
    void setInfoAluno(Pedro::Aluno newInfoAluno);
};

}

#endif // EXECUTARMODO_H
