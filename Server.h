// Server.h, header file for class Server.

#include <sys/socket.h>
#include <netinet/in.h> // sockaddr_in

#ifndef SERVER_H
#define SERVER_H

struct Server
{
  int domain;
  int service;
  int protocol;
  unsigned long interface;
  int port;
  int backlog;

  struct sockaddr_in address;

  int socket;

  void (*launch)(void);
};

struct Server server_constructor(int domain, int service, int porotocol, unsigned long interface, int port, int backlog, void (*launch)(void));

#endif // SERVER_H
