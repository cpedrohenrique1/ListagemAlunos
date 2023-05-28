#ifndef FM_INSERIRCURSO_H
#define FM_INSERIRCURSO_H

#include <QDialog>

namespace Ui {
class Fm_InserirCurso;
}

class Fm_InserirCurso : public QDialog
{
    Q_OBJECT

public:
    explicit Fm_InserirCurso(QWidget *parent = nullptr);
    ~Fm_InserirCurso();

signals:
    void infoTransmitida(int infoCurso);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Fm_InserirCurso *ui;
};

#endif // FM_INSERIRCURSO_H
