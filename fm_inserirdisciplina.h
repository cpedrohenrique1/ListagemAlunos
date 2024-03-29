#ifndef FM_INSERIRDISCIPLINA_H
#define FM_INSERIRDISCIPLINA_H

#include <QDialog>
#include "aluno.h"

namespace Ui {
class Fm_InserirDisciplina;
}

class Fm_InserirDisciplina : public QDialog
{
    Q_OBJECT

public:
    explicit Fm_InserirDisciplina(QWidget *parent = nullptr, std::list<Pedro::Aluno> *listaAluno = nullptr);
    ~Fm_InserirDisciplina();

signals:
    void infoTransmitida(QString infoCodigoDisciplina);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Fm_InserirDisciplina *ui;
};

#endif // FM_INSERIRDISCIPLINA_H
