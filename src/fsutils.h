#ifndef FSUTILS_H
#define FSUTILS_H

#include <QDir>
#include <auroraapp.h>

namespace FSUtils
{
[[maybe_unused]] static void copyLicenseFile() {
    const static auto s_configFolderName = QString("R7DocumentsLicense");

    const auto licensePath = QStringLiteral("%1/%2")
            .arg(Aurora::Application::organizationPathTo("").toString())
            .arg(s_configFolderName).remove("file://");

    const auto cachePath = QStringLiteral("%1/%2").arg(Aurora::Application::cacheDir(false).path(), "license");
    QDir licenseDir(cachePath);
    if (!licenseDir.exists()) {
        if (!licenseDir.mkpath(cachePath)) {
            qDebug() << "Error create license dir" << cachePath;
            return;
        } else {
            qDebug() << "Created license dir" << cachePath;
        }
    } else {
        qDebug() << "License dir exists" << cachePath;
    }

    const static auto licenseFileName = QStringLiteral("%1/%2").arg(licensePath, "license.lickey");
    QFile license(licenseFileName);

    if (license.exists()) {
        qDebug() << "Error: license file not exists" << licenseFileName;
        return;
    }

    if (license.open(QIODevice::ReadOnly)) {
        qDebug() << "Error read license file" << licenseFileName;
        return;
    }

    if (license.copy(QStringLiteral("%1/license.lickey").arg(cachePath)))
        qDebug() << "Error: license file not exists" << licenseFileName;
}
};

#endif // FSUTILS_H
