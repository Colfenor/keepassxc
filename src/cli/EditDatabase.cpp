/*
 *  Copyright (C) 2019 KeePassXC Team <team@keepassxc.org>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 or (at your option)
 *  version 3 of the License.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <cstdlib>
#include <stdio.h>

#include <QString>
#include <QTextStream>

#include "Create.h"
#include "EditDatabase.h"

EditDatabase::EditDatabase()
{
    name = QString("db-edit");
    description = QObject::tr("Create a new database.");
    positionalArguments.append({QString("database"), QObject::tr("Path of the database."), QString("")});
    options.append(Create::SetKeyFileOption);
    options.append(Create::SetPasswordOption);
    options.append(Create::DecryptionTimeOption);
}

int EditDatabase::execute(const QStringList& arguments)
{
    QSharedPointer<QCommandLineParser> parser = getCommandLineParser(arguments);
    if (parser.isNull()) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}