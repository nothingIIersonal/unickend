#pragma once

/*
 * namespace WServer::WDebug::
 */

#include <cstring>
#include <iostream>

namespace WServer {

namespace WDebug {

constexpr auto WPrefix = "[WServer] ";

class WMessage {
 public:
  WMessage() = delete;
  ~WMessage() = default;

  explicit WMessage(const std::string &what) : what_(what){};

  explicit WMessage(std::initializer_list<std::string> args) {
    for (const auto &arg : args) {
      what_ += arg;
    }
  }

  operator std::string() const { return what_; }

 private:
  std::string what_;
};

}  // namespace WDebug

}  // namespace WServer
