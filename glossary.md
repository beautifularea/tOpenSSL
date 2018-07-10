PKCS#12标准  
Public Key Cryptography Standards #12，   

CA机构，又称为证书授权  
Certificate Authority  

证书吊销列表 CRL  
Certification Revocation List  

pem  
Printable Encoded Message  

CSR  
证书请求文件(Certificate Signing Request)。  
这个并不是证书，而是向权威证书颁发机构获得签名证书的申请，其核心内容是一个公钥(当然还附带了一些别的个人信息)。  

完美前向保密（perfect forward secrecy）  
pfs保护过去的会话以免在未来秘钥或密码的（泄露）造成的危害。  
拥有前向保密属性的公钥系统，能为每一个session生成一个随机的公钥来完成一个秘钥协定，不使用一个确定性算法  

OCSP(Online Certificate Status Protocol，在线证书状态协议)  

OCSP Stapling :  
Nginx会在客户端的HELLO握手信息中返回OCSP记录,并且只有当客户端对Nginx发出OCSP信息请求的情况下,Nginx才会发送缓存的OCSP 权威记录到客户端。  


