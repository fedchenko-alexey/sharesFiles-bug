#include <auroraapp.h>
#include <QtQuick>

#include "fsutils.h"

int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> application(Aurora::Application::application(argc, argv));
    application->setOrganizationName(QStringLiteral("ru.r7office"));
    application->setApplicationName(QStringLiteral("sharedFilesTest"));

    FSUtils::copyLicenseFile();

    QScopedPointer<QQuickView> view(Aurora::Application::createView());
    view->setSource(Aurora::Application::pathTo(QStringLiteral("qml/sharedFilesTest.qml")));
    view->show();

    return application->exec();
}
