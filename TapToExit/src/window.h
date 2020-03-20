#ifndef __WINDOW_H_
#define __WINDOW_H_

#include <QLabel>
#include <QPushButton>
#include <QWidget>

#include "application.h"

class Window : public QWidget {
    Q_OBJECT
private:
    Application *appDriver;
    QLabel *mLabel;
    QPushButton *mButton;
    int weight;
    int height;
    int mCounter;

public:
    explicit Window(Application *appDriver, int _w = 480, int _h = 640);
    const Application *getApplication() const;
public slots:
    void onButtonClick();

signals:
    void counterReached();
};

#endif    // __WINDOW_H_