/**
 * @file        abacus.h
 * @authors     Jamie Oaks
 * @package     ABACUS (Approximate BAyesian C UtilitieS)
 * @brief       Package info.
 * @copyright   Copyright (C) 2013 Jamie Oaks.
 *   This file is part of msBayes.  msBayes is free software; you can
 *   redistribute it and/or modify it under the terms of the GNU General Public
 *   License as published by the Free Software Foundation; either version 2 of
 *   the License, or (at your option) any later version.
 * 
 *   msBayes is distributed in the hope that it will be useful, but WITHOUT ANY
 *   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 *   FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 *   details.
 * 
 *   You should have received a copy of the GNU General Public License along
 *   with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ABACUS_H
#define ABACUS_H

#include <stdio.h>
#include <stdlib.h>

#define ABACUS_NAME "ABACUS"
#define ABACUS_DESCRIPTION "Approximate BAysian C UtilitieS"
#define ABACUS_VERSION "0.1.0"
#define ABACUS_AUTHORS "Jamie Oaks"
#define ABACUS_COPYRIGHT "Copyright (C) 2013 Jamie Oaks"
#define ABACUS_LICENSE \
    "ABACUS comes with ABSOLUTELY NO WARRANTY. ABACUS is free software:\n" \
    "you can redistribute and/or modify it under the terms of the GNU GPL\n" \
    "version 3 or later."

char * abacus_preamble();

#endif /* ABACUS_H */

