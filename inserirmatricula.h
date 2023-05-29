#ifndef INSERIRMATRICULA_H
#define INSERIRMATRICULA_H

#include <QString>
#include "matricula.h"

class InserirMatricula
{
public:
    InserirMatricula();
    Pedro::Matricula operator ()(QString matriculaText);
};

#endif // INSERIRMATRICULA_H
