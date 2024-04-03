#include <wserver/wserverext/wserverhttp/wserverhttp.hpp>

//// TODO
// WServer::WServerHTTP serv(
//     "127.0.0.1:25565", {WServer::WProtocol::HTTP::Get("/index", getIndex)});

// auto getIndex(WServer::WProtocol::HTTP::Resp resp) -> void {
//   resp(200)
//       ->set({"Content-Type", "application/json"})
//       ->resp({"Hello", "World"});
// }

// auto getIndex(WServer::WProtocol::HTTP::Resp resp) -> void {
//   resp(200)
//       ->set({"Content-Type", "application/json"})
//       ->resp({{"0", "zero"},
//               {"1", "one"},
//               {"2", "two"},
//               {"3", "three"},
//               {"4", "four"}});
// }
// WServer::WProtocol::HTTP::Get("/hello", getHello);

// auto getIndex(WServer::WProtocol::HTTP::Resp resp) -> void {
//   resp(404)
//       ->set({"Content-Type", "application/json"})
//       ->resp({"message", "Page not found"});
// }
// WServer::WProtocol::HTTP::Default(getDefault);

WServer::WServerHTTP serv("127.0.0.1:25565", {"/index", "/hello"});

int main() { return serv.start(); }
