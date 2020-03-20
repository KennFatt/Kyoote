#ifndef __WINDOW_H_
#define __WINDOW_H_

#include "application.h"

#include <QLabel>
#include <QPushButton>
#include <QWidget>

class Window : public QWidget
{
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
    const Application *getApplication() const
    {
        return appDriver;
    }
  public slots:
    void onButtonClick();

  signals:
    void counterReached();
};

#endif // __WINDOW_H_