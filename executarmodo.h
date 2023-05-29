#ifndef EXECUTARMODO_H
#define EXECUTARMODO_H

#include <QDialog>
#include <QObject>
#include "disciplinaturma.h"
#include "aluno.h"
#include <QTableWidget>
#include "fm_inserirdisciplina.h"
#include "fm_inserirmatricula.h"

namespace Pedro
{

class ExecutarModo : public QDialog
{
    Q_OBJECT

private:
    int infoCurso;
    Pedro::DisciplinaTurma infoDisciplinaTurma;
    Pedro::Aluno infoAluno;
    QString infoDisciplina;
    Pedro::Matricula infoMatricula;

private slots:
    void receberInfo(int infoCurso);
    void receberInfoDisciplinaTurma(Pedro::DisciplinaTurma disciplinaTurma);
    void receberInfoDisciplina(QString infoDisciplina);
    void receberInfoMatricula(Pedro::Matricula infoMatricula);

public:
    ExecutarModo();
    void operator ()(QString enderecoArquivo, QString textoComboBox, QTableWidget* parent, std::list<Pedro::Aluno> listaAlunos);
    int getInfoCurso() const;
    void setInfoCurso(int newInfoCurso);
    Pedro::DisciplinaTurma getInfoDisciplinaTurma() const;
    void setInfoDisciplinaTurma(Pedro::DisciplinaTurma newInfoDisciplinaTurma);
    Pedro::Aluno getInfoAluno() const;
    void setInfoAluno(Pedro::Aluno newInfoAluno);
};

}

#endif // EXECUTARMODO_H
