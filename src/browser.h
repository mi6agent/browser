#ifndef BROWSER_H
#define BROWSER_H

#include "view.h"
#include "layer.h"
#include "ui.h"

#include <QApplication>
#include <QEvent>
#include <QKeyEvent>

namespace Ui {
class Browser;
}

class Browser : public QWidget
{
    Q_OBJECT

public:
    Browser(QWidget *parent = 0);
    ~Browser();

protected:
    bool eventFilter(QObject *o, QEvent *e);

private:
    View *view;
    Layer *layer;

    QUrl url;
    std::vector<View *> views;

    int row;
    int col;
    int current_view;
    bool is_link_to_miniature;

    Ui::Browser *ui;

private slots:
    void create_view(QUrl url, bool is_link = false);
    void handler_view(int view_to = 0, bool rotate = false, bool is_link = false);
};

#endif // BROWSER_H
