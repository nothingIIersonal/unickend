#pragma once

/*
 * namespace WServer::WTypes::
 */

#include <cinttypes>
#include <cstring>
#include <iostream>

namespace WServer {

namespace WTypes {

namespace XSocket {
#ifdef _WIN32
#pragma warning(disable : 5039)
#endif
extern "C" {
#include <xsocket/xsocket.h>
}
}  // namespace XSocket
using namespace ::WServer::WTypes::XSocket;

typedef union {
  uint32_t raw;
  struct {
    uint8_t a;
    uint8_t b;
    uint8_t c;
    uint8_t d;
  } oct;
} ip4_t;

using ip4s_t = std::string;
using port_t = uint16_t;
using socket_t = std::string;

}  // namespace WTypes

}  // namespace WServer
