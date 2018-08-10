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

6 验证证书  
openssl verify -CAfile ca.crt  

7 生成CRL  
openssl ca -gencrl -out server.crl -cert ca.crt -keyfile ca.key -config /usr/lib/ssl/openssl.cnf  

8 CRL格式：　DER　转换为　PEM   
openssl crl -in gds1-64.crl -inform der -out crl.pem  

