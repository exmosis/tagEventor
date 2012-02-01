/*
  rulesTable.h - C source code for tagEventor

  Copyright 2009 Autelic Association (http://www.autelic.org)

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

#include "tagReader.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <syslog.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>       /* for umask() */
#include <limits.h>

#include "constants.h"
#include "tagReader.h"

#define SCRIPT_DOES_NOT_EXIST (127)

/************* VARIABLES STATIC TO THIS FILE  ********************/
/*
 * this is the list of built-in commands, in the reverse order of which they
 * will be tried
 */
#define NUM_DEFAULT_COMMANDS   (4)

#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif

#define MAX_DESCRIPTION_LENGTH  (80)

/* different options for matching script names */
#define TAG_ID_MATCH	    (1)
#define GENERIC_MATCH	    (2)

/* where to save this type of config stuff???? via GConf or something */
typedef struct {
   	char		*IDRegex;         /* specific ID or a regular expression - Max size = sizeof(uid) */
	char		*folder;          /* folder where to look for script     - Max size = PATH_MAX */
	int		scriptMatchType;  /* type of match to use for script name */
	char		*description;     /* Max size = MAX_DESCRIPTION_LENGTH */
	char		enabled;
} tRulesTableEntry;

/*************** RULES TABLE *************/
extern int                      rulesTableAddEntry( void );
extern void                     rulesTableSave( void );
extern int                      rulesTableNumber( void );
extern int                      rulesTableRead( void );
extern void                     rulesTableEntryEnable( int index, char enable );
extern const tRulesTableEntry   *rulesTableEntryGet( int index );
extern unsigned char            rulesTableEventDispatch( tEventType eventType, const tTag *pTag );
extern tReaderManager  readerManager;
