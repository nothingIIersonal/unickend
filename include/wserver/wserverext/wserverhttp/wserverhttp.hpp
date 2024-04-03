#pragma once

/*
 * namespace WServer::
 */

#include <wserver/wserver.hpp>
#include <wserver/wserverext/wserverhttp/types/types.hpp>

namespace WServer {

class WServerHTTP : public WServer {
 public:
  WServerHTTP() = delete;
  WServerHTTP(const WServerHTTP&) = delete;
  WServerHTTP(WServerHTTP&&) = delete;
  WServerHTTP& operator=(const WServerHTTP&) = delete;
  WServerHTTP& operator=(WServerHTTP&&) = delete;

  virtual ~WServerHTTP() = default;

  explicit WServerHTTP(
      const std::string& socket,
      const std::vector<::WServer::WTypes::endpoint_t>& endpoints)
      : WServer(socket), endpoints_(endpoints){};

  int start();

 private:
  std::vector<::WServer::WTypes::endpoint_t> endpoints_;

  void process_(xsocket_t clientfd);
};

}  // namespace WServer
