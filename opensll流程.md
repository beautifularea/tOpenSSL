(参考)[https://blog.csdn.net/xs574924427/article/details/17240793]  

openssl使用流程  

1 初始化  
SSL_library_init();  

2 选择会话协议  
协议包括TLSv1.0、SSLv2、SSLv3、SSLv2/v3  

3 创建会话环境  
SSL_CTX *SSL_CTX_new(SSL_METHOD * method);  

4 需要设置CTX的属性，通常的设置是指定SSL握手阶段证书的验证方式和加载自己的证书  
制定证书验证方式的函数是：  
int SSL_CTX_set_verify(SSL_CTX *ctx,int mode,int(*verify_callback),int(X509_STORE_CTX *));  

为SSL会话环境加载CA证书的函数是：  
SSL_CTX_load_verify_location(SSL_CTX *ctx,const char *Cafile,const char *Capath);  

为SSL会话加载用户证书的函数是：  
SSL_CTX_use_certificate_file(SSL_CTX *ctx, const char *file,int type);  

为SSL会话加载用户私钥的函数是：  
SSL_CTX_use_PrivateKey_file(SSL_CTX *ctx,const char* file,int type);  

在将证书和私钥加载到SSL会话环境之后，就可以调用下面的函数来验证私钥和证书是否相符：  
int SSL_CTX_check_private_key(SSL_CTX *ctx);  

5 建立SSL socket  
SSL套接字是建立在普通的TCP套接字基础之上，在建立SSL套接字时可以使用下面的一些函数：  

SSL *SSl_new(SSL_CTX *ctx);  
//申请一个SSL套接字  

int SSL_set_fd(SSL *ssl,int fd);)  
//绑定读写套接字  

int SSL_set_rfd(SSL *ssl,int fd);  
//绑定只读套接字  

int SSL_set_wfd(SSL *ssl,int fd);  
//绑定只写套接字  

6 SSL 握手  
在成功创建SSL套接字后，客户端应使用函数SSL_connect( )替代传统的函数connect( )来完成握手过程:  
int SSL_connect(SSL *ssl);  

而对服务器来讲，则应使用函数SSL_ accept ( )替代传统的函数accept ( )来完成握手过程:  
int SSL_accept(SSL *ssl);  

7 获取信息  
该函数可以从SSL套接字中提取对方的证书信息，这些信息已经被SSL验证过了。  
X509 *SSL_get_peer_certificate(SSL *ssl);  

该函数得到证书所用者的名字。  
X509_NAME *X509_get_subject_name(X509 *a);  

8 数据传输  
int SSL_read(SSL *ssl,void *buf,int num);  
int SSL_write(SSL *ssl,const void *buf,int num);  

9 结束SSL通信  
//关闭SSL套接字  
int SSL_shutdown(SSL *ssl);  

//释放SSL套接字  
void SSl_free(SSL *ssl);  

//释放SSL会话环境  
void SSL_CTX_free(SSL_CTX *ctx);   


eg  
服务器结构:  

meth = SSLv23_server_method();  
ctx = SSL_CTX_new (meth);  
ssl = SSL_new(ctx);  
fd = socket();  
bind();  
listen();  
accept();  
SSL_set_fd(ssl,fd);  
SSL_connect(ssl);  
SSL_read (ssl, buf, sizeof(buf));  

客户端结构:  

meth = SSLv23_client_method();  
ctx = SSL_CTX_new (meth);  
ssl = SSL_new(ctx);  
fd = socket();  
connect();  
SSL_set_fd(ssl,fd);  
SSL_connect(ssl);  
SSL_write(ssl,"Hello world",strlen("Hello World!"));  




