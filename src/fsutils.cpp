#include "fsutils.h"

void FSUtils::copyLicenseFile() {
    const static auto s_configFolderName = QString("R7DocumentsLicense");

    const auto licensePath = QStringLiteral("%1/%2")
            .arg(Aurora::Application::organizationPathTo("").toString())
            .arg(s_configFolderName).remove("file://");

    const auto cachePath = QStringLiteral("%1/%2").arg(Aurora::Application::cacheDir(false).path(), "license");
    QDir licenseDir(cachePath);
    qDebug() << "Create license dir" << cachePath;
    if (!licenseDir.exists() || !licenseDir.mkpath(cachePath)) {
        qDebug() << "Error create license dir" << cachePath;
        return;
    }

    const static auto licenseFileName = QStringLiteral("%1/%2").arg(licensePath, "license.lickey");
    QFile license(licenseFileName);
    if (license.exists())
        license.copy(QStringLiteral("%1/license.lickey").arg(cachePath));
    else
        qDebug() << "Error: license file not exists" << licenseFileName;
}
