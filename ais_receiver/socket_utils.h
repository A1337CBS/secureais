//
//  socket_utils.h
//  3CAT-2_COMMS_SOCKET
//
//  Created by Juan Fran Muñoz Martin on 01/10/14.
//  Copyright (c) 2014 Juan Fran Muñoz Martin. All rights reserved.
//

#ifndef ___CAT_2_COMMS_SOCKET__socket_utils__
#define ___CAT_2_COMMS_SOCKET__socket_utils__

#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/time.h>
#include <time.h>
#include <arpa/inet.h>


#define BACKLOG 5 /* El número de conexiones permitidas */
#define MAXDATASIZE 256

int read_kiss_from_socket(int fd, char * buffer);
int socket_init(int port);

#endif /* defined(___CAT_2_COMMS_SOCKET__socket_utils__) */
