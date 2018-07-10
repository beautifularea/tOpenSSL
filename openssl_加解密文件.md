To Encrypt:  
openssl enc -aes-256-cbc -in un_encrypted.data -out encrypted.data  

To Decrypt:  
openssl enc -d -aes-256-cbc -in encrypted.data -out un_encrypted.data  
