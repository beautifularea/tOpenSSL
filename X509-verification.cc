#include <openssl/x509.h>
#include <openssl/x509_vfy.h>

X509_STORE_CTX *ctx;    //证书上下文
X509_STORE *cert_store; //证书库，存在证书链
X509* x509;             //待验证X509证书

ctx = X509_STORE_CTX_new();
X509_STORE_CTX_init(ctx,cert_store,x509,NULL);
int n = X509_verify_cert(ctx);
const char *verify_error_string = X509_verify_cert_error_string(n);

/*
X509_V_OK: ok 
the operation was successful. 
*/
