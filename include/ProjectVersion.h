/*
 * ProjectVersion.h - version compared in import upgrades
 *
 * Copyright (c) 2007 Javier Serrano Polo <jasp00/at/users.sourceforge.net>
 *
 * This file is part of LMMS - http://lmms.io
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 */


#ifndef PROJECT_VERSION_H
#define PROJECT_VERSION_H

#include <QtCore/QString>
#include "export.h"

class ProjectVersion : public QString
{
public:
	ProjectVersion( const QString & s ) : 
		QString( s ), 
		major( section( '.', 0, 0 ).toInt() ) ,
		minor( section( '.', 1, 1 ).toInt() ) ,
		release( section( '.', 2 ).section( '-', 0, 0 ).toInt() ) ,
		build( section( '.', 2 ).section( '-', 1 ) )
	{
	}

	static int compare( const ProjectVersion & v1,
						const ProjectVersion & v2 );
	const int majorVersion() const { return major; }
	const int minorVersion() const { return minor; }
	const int releaseVersion() const { return release; }
	const QString buildVersion() const { return build; }
private:
	const int major;
	const int minor;
	const int release;
	const QString build;
} ;




inline bool operator<( const ProjectVersion & v1, const char * str )
{
	return ProjectVersion::compare( v1, ProjectVersion( str ) ) < 0;
}




#endif
