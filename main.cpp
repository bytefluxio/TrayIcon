#include <QApplication>
#include <QIcon>
#include <QSystemTrayIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QIcon icon(":/icons/icon.svg");
    QSystemTrayIcon trayIcon(icon);
    trayIcon.show();

    return a.exec();
}
