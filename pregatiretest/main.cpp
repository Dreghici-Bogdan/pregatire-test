#include <QApplication>
#include <QPushButton>
#include "repository.h"
#include "service.h"
#include "GUI.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    repository repo;
    Service service(repo);
    GUI window(service);
    //window.show();
    return QApplication::exec();
}
