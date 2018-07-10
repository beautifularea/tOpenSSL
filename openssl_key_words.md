证书标准  
X.509 是一种证书标准  

证书编码  
PEM privacy Enhanced Mail Base64编码  
查看格式：  
openssl x509 -in dh512.pem -text -noout  

DER distinguished Encoding Rules 二进制编码  
查看格式：  
openssl x509 -in dh512.der -inform der -noout  

相关文件扩展名：  
crt certificate 证书。  
cer certificate 证书，常见Windows系统。  
key 保存公钥或者私钥。  

csr Certificate Signing Request 证书签名请求。  
查看格式:  
openssl req -noout -text -in xx.csr    


