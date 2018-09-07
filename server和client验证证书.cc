openssl s_server -msg -verify -tls1_2 -state -cert server.crt -key server.key -CAfile ca.pem -accept 18444
openssl s_client -msg -verify -tls1_2  -state -showcerts -cert server.crt -key server.key -CAfile ca.pem -connect IP:18444

