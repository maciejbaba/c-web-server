// SERVER.C

#include "Server.h"
#include <stdio.h>

struct Server server_constructor(int domain, int service, int protocol, unsigned long interface, int port, int backlog, void (*launch)(void))
{
  struct Server server;

  server.domain = domain;
  server.service = service;
  server.protocol = protocol;
  server.interface = interface;
  server.port = port;
  server.backlog = backlog;

  server.address.sin_family = domain;
  server.address.sin_port = htons(port); // htons() makes sure that the number is in network byte order - first byte is the most significant byte. prevents from common little-endian format.
  server.address.sin_addr.s_addr = htonl(interface); // the same as htons() but for long integers.

  server.socket = socket(domain, service, protocol); // creates socket connection - enables our server to communicate with the outside world.

  if (server.socket == 0) {
    perror("Failed to connect socket...\n");
    exit(1);
  }

  return server;
};