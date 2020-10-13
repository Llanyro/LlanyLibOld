#pragma once
#ifndef SOCKETS_HEADERS_NET_HPP_
#define SOCKETS_HEADERS_NET_HPP_

#ifdef __unix__
//#include <arpa/inet.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <unistd.h>
//#include <sys/types.h>
#include <windows.h>
#include <winsock2.h>
#include <Ws2tcpip.h>
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")
#elif _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winsock2.h>
#include <Ws2tcpip.h>
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")
#endif // __unix__

#define RED AF_INET

#endif // !SOCKETS_HEADERS_NET_HPP_
