#ifndef BUSCARALUNO_H
#define BUSCARALUNO_H

#include <QString>
#include <QFileDialog>
#include "aluno.h"
#include "matricula.h"
#include "disciplinaturma.h"

namespace Pedro
{

class BuscarAluno
{
private:
    QString enderecoArquivo;
public:
    BuscarAluno();
    BuscarAluno(QString enderecoArquivo);
    QString operator ()(QWidget *parent, std::list<Pedro::Aluno> &aluno);
    QString getEnderecoArquivo() const;
    void setEnderecoArquivo(QString newEnderecoArquivo);
};

}

#endif // BUSCARALUNO_H
