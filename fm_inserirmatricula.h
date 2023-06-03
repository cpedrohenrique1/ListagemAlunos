#ifndef FM_INSERIRMATRICULA_H
#define FM_INSERIRMATRICULA_H

#include <QDialog>
#include "matricula.h"
#include "aluno.h"

namespace Ui {
class Fm_InserirMatricula;
}

class Fm_InserirMatricula : public QDialog
{
    Q_OBJECT

public:
    explicit Fm_InserirMatricula(QWidget *parent = nullptr, std::list<Pedro::Aluno> *listaAluno = nullptr);
    ~Fm_InserirMatricula();

signals:
    void infoTransmitida(QString matricula);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Fm_InserirMatricula *ui;
};

#endif // FM_INSERIRMATRICULA_H
