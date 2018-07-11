1 查看证书序列号  
openssl x509 -in server.crt -noout -serial  

2 查看证书内容  
openssl x509 -in server.crt -noout -text  

3 查看拥有者信息  
openssl x509 -in server.crt -noout -subject  

4 验证key  
openssl rsa -in server.key -check  

5 验证csr  
openssl req -text -noout -verify -in server.csr  

