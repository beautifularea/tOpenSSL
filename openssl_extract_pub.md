openssl genrsa -out mykey.pem 1024  
will actually produce a public - private key pair. The pair is stored in the generated mykey.pem file.

openssl rsa -in mykey.pem -pubout > mykey.pub  
will extract the public key and print that out. Here is a link to a page that describes this better.
