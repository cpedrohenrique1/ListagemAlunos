#ifndef DISCIPLINATURMA_H
#define DISCIPLINATURMA_H

#include <QString>

namespace Pedro
{

class DisciplinaTurma
{
private:
    QString codigoDisciplina;
    QString codigoTurma;
public:
    DisciplinaTurma();
    DisciplinaTurma(QString codigoDisciplina, QString codigoTurma);

    QString getCodigoDisciplina() const;
    void setCodigoDisciplina(QString newCodigoDisciplina);
    QString getCodigoTurma() const;
    void setCodigoTurma(QString newCodigoTurma);
    bool operator==(Pedro::DisciplinaTurma otherDisciplinaTurma) const;
    operator QString()const;
    QString getDisciplinaTurma() const;
};

}

#endif // DISCIPLINATURMA_H
