#ifndef __APPLICATION_H_
#define __APPLICATION_H_

#include <QApplication>

class Application
{
  private:
    QApplication *Qapp;
    void startApplication();

  public:
    explicit Application(int, char **);
    const QCoreApplication *getQtApplication() const;
    ~Application();

  public slots:
    void QuitAction();
};

#endif // __APPLICATION_H_