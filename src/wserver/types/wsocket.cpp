/*
 * namespace WServer::WTypes::
 */

#include <spdlog/spdlog.h>

#include <wserver/debug.hpp>
#include <wserver/types/types.hpp>

namespace WServer {

namespace WTypes {

WSocket::~WSocket() {
  __xsocket_cleanup();
  xsocket_close(sockfd_);
};

WSocket::WSocket(const std::string &socket) {
  if (std::regex_search(socket, socket_sm_, socket_rgx_)) {
    if (socket_sm_.size() != 6) {
      throw std::runtime_error(WServer::WDebug::WMessage{
          WServer::WDebug::WPrefix,
          "WSocket(const std::string &socket) failed"
          ", regular expression groups error (ip:port)"});
    }

    socket_ = socket;
    ip_.oct.a = (uint8_t)std::stoull(socket_sm_[1].str());
    ip_.oct.b = (uint8_t)std::stoull(socket_sm_[2].str());
    ip_.oct.c = (uint8_t)std::stoull(socket_sm_[3].str());
    ip_.oct.d = (uint8_t)std::stoull(socket_sm_[4].str());
    port_ = (uint16_t)std::stoull(socket_sm_[5].str());
  } else {
    throw std::runtime_error(
        WServer::WDebug::WMessage{WServer::WDebug::WPrefix,
                                  "WSocket(const std::string &socket) failed"
                                  ", invalid socket format (ip:port)"});
  }

  if (__xsocket_init()) {
    throw std::runtime_error(
        WServer::WDebug::WMessage{WServer::WDebug::WPrefix,
                                  "WSocket(const std::string &socket) failed"
                                  ", __xsocket_init() caused an error"});
  }

  struct sockaddr_in addr;
  const socklen_t addr_len = sizeof(addr);
  memset(&addr, 0, addr_len);

  addr.sin_family = AF_INET;
  addr.sin_port = htons(port_);
  inet_pton(AF_INET, getIp4S().data(), &addr.sin_addr);

  sockfd_ = xsocket(addr.sin_family, SOCK_STREAM, IPPROTO_TCP);
  if (sockfd_ == -1) {
    __xsocket_cleanup();
    throw std::runtime_error(
        WServer::WDebug::WMessage{WServer::WDebug::WPrefix,
                                  "WSocket(const std::string &socket) failed"
                                  ", xsocket() caused an error"});
  }

  bind(sockfd_, (struct sockaddr *)&addr, addr_len);
  listen(sockfd_, INT_MAX);

  spdlog::info("{}Initialized socket '{}'", WServer::WDebug::WPrefix, socket_);
}

}  // namespace WTypes

}  // namespace WServer
