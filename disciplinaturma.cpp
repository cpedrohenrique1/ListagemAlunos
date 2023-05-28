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

bool DisciplinaTurma::operator==(DisciplinaTurma otherDisciplinaTurma) const
{
    if (this->getCodigoDisciplina() == otherDisciplinaTurma.getCodigoDisciplina() && this->getCodigoTurma() == otherDisciplinaTurma.getCodigoTurma())
    {
        return true;
    }
    else
    {
        return false;
    }
}

DisciplinaTurma::operator QString() const
{
    return getDisciplinaTurma();
}

QString DisciplinaTurma::getDisciplinaTurma() const
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
