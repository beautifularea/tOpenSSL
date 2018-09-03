boost::asio::ssl::stream<boost::asio::ip::tcp::socke> ssl;
X509 * cert = SSL_get_peer_certificate(ssl);
