/***************************************************************************
 *   Copyright (C) 2004-2008 by Michael Zugaro                             *
 *   michael.zugaro@college-de-france.fr                                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program. If not, see <http://www.gnu.org/licenses/>.  *
 *                                                                         *
 ***************************************************************************/
#ifndef SONERROR_H
#define SONERROR_H

#include <exception>
#include <string>

using namespace std;

/**
@author Michael Zugaro
*/
class SONError : public exception
{
	public:
		/**
			Error types
		*/
		typedef enum {READ_ERROR,WRITE_ERROR,WRONG_CHANNEL_TYPE,EMPTY_CHANNEL} ErrorType;

		/**
			Constructor
			
			@param	type type of error
			@param	message error message
		*/
		SONError(ErrorType type,string message);
		/**
			Destructor
		*/
		virtual ~SONError() throw ();
		/**
			Report error
			
			@return	error message
		*/
		virtual string report() const;
		/**
			Get error type
			
		@return	error type
		 */
		virtual ErrorType getType() const;
		
	private:
	
		ErrorType	type;
		string		message;
};

#endif
