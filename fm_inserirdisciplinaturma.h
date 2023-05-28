#ifndef FM_INSERIRDISCIPLINATURMA_H
#define FM_INSERIRDISCIPLINATURMA_H

#include <QDialog>
#include "disciplinaturma.h"

namespace Ui {
class Fm_InserirDisciplinaTurma;
}

class Fm_InserirDisciplinaTurma : public QDialog
{
    Q_OBJECT

public:
    explicit Fm_InserirDisciplinaTurma(QWidget *parent = nullptr);
    ~Fm_InserirDisciplinaTurma();

signals:
    void infoTransmitida(Pedro::DisciplinaTurma disciplinaTurma);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Fm_InserirDisciplinaTurma *ui;
};

#endif // FM_INSERIRDISCIPLINATURMA_H
