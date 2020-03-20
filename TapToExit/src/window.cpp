#include "window.h"
#include <iostream>

Window::Window(Application *_appDriver, int _w, int _h)
    : QWidget(nullptr), appDriver(_appDriver), weight(_w), height(_h)
{
    // Set window's size
    setFixedSize(weight, height);

    // Create a lable
    mLabel = new QLabel("Label", this);
    mLabel->setGeometry(weight / 4, height / 2, weight, 50);
    mLabel->show();

    // Create a button
    mButton = new QPushButton("Click me!", this);
    mButton->setGeometry(weight / 4, height - 65, weight / 2, 50);
    mButton->show();

    // Update counter
    mCounter = 5;

    // Connection mButton::clicked() -> Window::onButtonClick()
    connect(mButton, SIGNAL(clicked()), this, SLOT(onButtonClick()));

    // Connectiion Window::counterReached() -> QApplication::quit()
    connect(this, SIGNAL(counterReached()), getApplication()->getQtApplication(), SLOT(quit()));
}

void Window::onButtonClick()
{
    if (mCounter <= 0)
    {
        emit counterReached();
    }

    mLabel->setText("Exit after: " + QString(std::to_string(mCounter).c_str()));
    if (mCounter > 0)
    {
        --mCounter;
    }
}