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
    operator QString() const;
};

}

#endif // DISCIPLINATURMA_H
