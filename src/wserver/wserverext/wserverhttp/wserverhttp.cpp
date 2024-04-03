
/*
 * namespace WServer::
 */

#include <spdlog/spdlog.h>

#include <thread>
#include <vector>
#include <wserver/debug.hpp>
#include <wserver/wserverext/wserverhttp/wserverhttp.hpp>

namespace WServer {

int WServerHTTP::start() {
  spdlog::info("{}Start listening...", ::WServer::WDebug::WPrefix);
  while (xsocket_t clientfd = accept(socket_.getFD(), nullptr, nullptr)) {
    (std::thread(&WServerHTTP::process_, this, clientfd)).detach();
  }
  return EXIT_SUCCESS;
}

void WServerHTTP::process_(xsocket_t clientfd) {
  spdlog::info("{}New connection", ::WServer::WDebug::WPrefix);
  char buf[16] = {0};
  int ret = 0;

  while (true) {
    ret = recv((int)clientfd, buf, sizeof(buf), 0);
    if (ret <= 0) {
      break;
    }
    spdlog::info("{}New message '{}'", ::WServer::WDebug::WPrefix, buf);
  };
}

}  // namespace WServer
