
From : https://stackoverflow.com/questions/32577725/difference-between-lowest-layer-and-next-layer-from-boost-asio-ssl-stream  


To answer this, first thing to remember is that boost::asio::ssl::stream is a template class. Usually it look like boost::asio::ssl::stream<boost::asio::ip::tcp::socket>. Thus is implemented using boost::asio::ip::tcp::socket. That will be next_layer for boost::asio::ssl::stream. On other side, lowest_layer is always will be a basic_socket (its described in the docs).  

Its little ambiguous especially when you see in the headers tcp::socket is typedef to basic_stream_socket<Tcp>, which is directly inherited from basic_socket. And.. In OOP terms you can say "next_layer IS the lowest_layer"..  

But lets take another case where you create a ssl::stream< MyOwnClass >. In this case next_layer is MyOwnClass, which should control data reads/writes. And lowest_layer will be be whatever MyOwnClass will say in its typedef.  

UPD: When to use each. Use next_layer for read/writes (you don't need this for SSL connection, but before starttls session its required). And use lowest_layer to control underlying socket.  
