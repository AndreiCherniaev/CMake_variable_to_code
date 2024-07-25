#include <QCoreApplication>
#include <signal.h>
#include <QCommandLineParser>
#include "main.h"

void SigInt_Handler(int n_signal){
    printf("interrupted with code %u\n", n_signal); //Ctrl+C
    QCoreApplication::instance()->quit(); //exit(1);
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCoreApplication::setApplicationName(QUOTE(MYPROJECT_NAME));
    QCoreApplication::setApplicationVersion(QUOTE(CMAKE_PROJECT_VERSION));
    QCommandLineParser parser;
    parser.setApplicationDescription(QUOTE(MYPROJECT_DESCRIPTION));
    parser.addHelpOption();
    parser.addVersionOption();
    parser.process(a);

    signal(SIGINT, &SigInt_Handler); //thanks https://github.com/AndreiCherniaev/QCoreApplication_quit_example

    return a.exec();
}
