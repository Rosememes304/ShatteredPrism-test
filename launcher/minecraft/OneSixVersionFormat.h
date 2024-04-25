#pragma once

#include <ProblemProvider.h>
#include <minecraft/Library.h>
#include <minecraft/PackProfile.h>
#include <minecraft/VersionFile.h>
#include <QJsonDocument>

class OneSixVersionFormat {
   public:
    // version files / profile patches
    static VersionFilePtr versionFileFromJson(const QJsonDocument& doc, const QString& filename, bool requireOrder);
    static QJsonDocument versionFileToJson(const VersionFilePtr& patch);

    // libraries
    static LibraryPtr libraryFromJson(ProblemContainer& problems, const QJsonObject& libObj, const QString& filename);
    static QJsonObject libraryToJson(Library* library);

    // DEPRECATED: old 'plus' jar mods generated by the application
    static LibraryPtr plusJarModFromJson(ProblemContainer& problems,
                                         const QJsonObject& libObj,
                                         const QString& filename,
                                         const QString& originalName);

    // new jar mods derived from libraries
    static LibraryPtr jarModFromJson(ProblemContainer& problems, const QJsonObject& libObj, const QString& filename);
    static QJsonObject jarModtoJson(Library* jarmod);

    // mods, also derived from libraries
    static LibraryPtr modFromJson(ProblemContainer& problems, const QJsonObject& libObj, const QString& filename);
    static QJsonObject modtoJson(Library* jarmod);
};