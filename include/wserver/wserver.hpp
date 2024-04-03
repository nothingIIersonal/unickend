#pragma once

/*
 * namespace WServer::
 */

#include <wserver/types/types.hpp>

namespace WServer {

using namespace ::WServer::WTypes::XSocket;

class WServer {
 public:
  WServer() = delete;
  WServer(const WServer &) = delete;
  WServer(WServer &&) = delete;
  WServer &operator=(const WServer &) = delete;
  WServer &operator=(WServer &&) = delete;

  virtual ~WServer() = default;

  explicit WServer(const std::string &socket) : socket_(socket){};

  virtual int start() = 0;

 protected:
  ::WServer::WTypes::WSocket socket_;
};

}  // namespace WServer
