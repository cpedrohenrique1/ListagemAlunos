#include "disciplinaturma.h"




namespace Pedro {

DisciplinaTurma::DisciplinaTurma():
        codigoDisciplina("")
      , codigoTurma("")
{}

DisciplinaTurma::DisciplinaTurma(QString codigoDisciplina, QString codigoTurma):
        codigoDisciplina(codigoDisciplina)
      , codigoTurma(codigoTurma)
{}

QString DisciplinaTurma::getCodigoTurma() const
{
    return codigoTurma;
}

void DisciplinaTurma::setCodigoTurma(QString newCodigoTurma)
{
    codigoTurma = newCodigoTurma;
}

DisciplinaTurma::operator QString() const
{
    return codigoDisciplina + "-" + codigoTurma;
}

QString DisciplinaTurma::getCodigoDisciplina() const
{
    return codigoDisciplina;
}

void DisciplinaTurma::setCodigoDisciplina(QString newCodigoDisciplina)
{
    codigoDisciplina = newCodigoDisciplina;
}

}
