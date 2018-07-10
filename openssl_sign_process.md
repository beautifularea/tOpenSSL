
OK, for anyone finding this in the future, you need to create your certificates and sign them appropriately. Here are the commands for linux:  

//Generate a private key  

openssl genrsa -des3 -out server.key 1024  
//Generate Certificate signing request  

openssl req -new -key server.key -out server.csr  
//Sign certificate with private key  

openssl x509 -req -days 3650 -in server.csr -signkey server.key -out server.crt  
//Remove password requirement (needed for example)  

cp server.key server.key.secure  
openssl rsa -in server.key.secure -out server.key  
//Generate dhparam file  

openssl dhparam -out dh512.pem 512  
Once you've done that, you need to change the filenames in server.cpp and client.cpp.  

server.cpp  

context_.use_certificate_chain_file("server.crt");   
context_.use_private_key_file("server.key", boost::asio::ssl::context::pem);  
context_.use_tmp_dh_file("dh512.pem");  
client.cpp  
 
ctx.load_verify_file("server.crt");  
Then it should all work!  
