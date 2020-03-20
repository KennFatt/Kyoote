#include "application.h"
#include "window.h"
#include <iostream>

void Application::startApplication()
{
    if (Qapp != nullptr)
    {
        Qapp->exec();
    }
}

Application::Application(int argc, char **argv)
{
    std::cout << "Application has been created!" << std::endl;

    // Create new QApplication instance
    Qapp = new QApplication(argc, argv);

    // Initialize main window
    Window window(this, 480, 640);
    window.show();

    // Start QApplication
    startApplication();
}

const QCoreApplication *Application::getQtApplication() const
{
    return QApplication::instance();
}

Application::~Application()
{
    std::cout << "Application being destroyed!" << std::endl;
    delete Qapp;
}

void Application::QuitAction()
{
    std::cout << "QuitAction signal has been emmited!" << std::endl;
}