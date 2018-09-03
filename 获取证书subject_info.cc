bool compare_X509_Subject_Info(X509* peer)
{
    X509_NAME *pSubName = X509_get_subject_name(peer);
    if(! pSubName)
    {
        WriteLog(lsINFO, SSL) << "CERT_ERR_FAILED";
        return false;
    }

    char szOutCN[256] = {};
    X509_NAME_get_text_by_NID(pSubName,NID_commonName,szOutCN,256);

    //zhtian next_layer vs.lowest_layer区别
    boost::asio::ip::tcp::endpoint endpoint = stream_.next_layer().remote_endpoint();
    std::string addressFromCert = szOutCN;
    std::string addressFromRemt = endpoint.address().to_v4().to_string();

    if(addressFromCert.compare(addressFromRemt) == 0)
    {
        return true;
    }

    return false;
}
