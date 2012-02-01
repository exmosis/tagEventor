//
//  daemonControl.h
//  tagEventor
//
//  Created by Eric Betts on 1/31/12.
//  Copyright 2012 ADP. All rights reserved.
//

#ifndef tagEventor_daemonControl_h
#define tagEventor_daemonControl_h

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <syslog.h>

#include <signal.h>
#include <sys/stat.h>  /* for umask() */
#include <limits.h>

#include "constants.h"
#include "tagReader.h"

void stopDaemon( const tReaderManager   *pManager );
static void getLockOrDie( const tReaderManager *pManager );
void daemonTerminate( const tReaderManager *pManager );
void daemonize( tReaderManager *pManager );

#endif
