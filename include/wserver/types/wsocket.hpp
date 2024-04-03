#pragma once

/*
 * namespace WServer::WTypes::
 */

#include <cstring>
#include <format>
#include <iostream>
#include <regex>
#include <wserver/types/common.hpp>

namespace WServer {

namespace WTypes {

#ifdef _WIN32
#pragma warning(disable : 4514)
#pragma warning(disable : 4820)
#endif
class WSocket {
 public:
  WSocket() = delete;
  WSocket(const WSocket &) = delete;
  WSocket(WSocket &&) = delete;
  WSocket &operator=(const WSocket &) = delete;
  WSocket &operator=(WSocket &&) = delete;

  ~WSocket();

  explicit WSocket(const std::string &socket);

  ip4_t getIp4N() const { return ip_; };
  ip4s_t getIp4S() const {
    return std::format("{}.{}.{}.{}", ip_.oct.a, ip_.oct.b, ip_.oct.c,
                       ip_.oct.d);
  };
  socket_t getSocket() const { return socket_; };
  port_t getPort() const { return port_; };
  xsocket_t getFD() const { return sockfd_; };

 private:
  std::smatch socket_sm_;
  xsocket_t sockfd_;
  socket_t socket_;
  ip4_t ip_;
  port_t port_;
  const std::regex socket_rgx_{
      "^([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\\.([0-9]|[1-9][0-9]|1["
      "0-9]{2}|2[0-4][0-9]|25[0-5])\\.([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|"
      "25[0-5])\\.([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5]):(0|[1-9][0-"
      "9]{0,3}|[1-5][0-9]{4}|6[0-4][0-9]{3}|65[0-4][0-9]{2}|655[0-2][0-9]|6553["
      "0-5])$"};
};

}  // namespace WTypes

}  // namespace WServer
