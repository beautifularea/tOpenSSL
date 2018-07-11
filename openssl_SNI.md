SNI（Server Name Indication）

用来解决一个服务器拥有多个域名的情况  

之前的 SSL 握手信息中并没有携带客户端要访问的目标地址。这样会导致一个问题，如果一台服务器有多个虚拟主机，且每个主机的域名不一样，使用了不一样的证书，该返回哪一个给客户端？  

做法就是在 Client Hello 中补上 Host 信息，SNI 在 TLSv1.2 开始得到协议的支持，当然还需要服务端和客户端都支持。  

比如抓的一个 Client Hello 包中有这样的信息：  

Extension: server_name  
    Type: server_name (0x0000)  
    Length: 16  
    Server Name Indication extension  
        Server Name list length: 14  
        Server Name Type: host_name (0)  
        Server Name length: 11  
        Server Name: nex.163.com  

这个扩展信息就指定了该 SSL 握手信息的目标域名为 nex.163.com 。  

有了它，拥有多域名的服务器就不用再迷茫了。  

从 OpenSSL 0.9.8 版本开始支持。  

