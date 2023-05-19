# stockholm
Encrypts / decrypts all files in folder  _infection_  found in user's $HOME directory.  
This script will only try to encrypt files with extensions targeted by the ransomware WannaCry ([documented here](https://logrhythm.com/blog/a-technical-analysis-of-wannacry-ransomware/))  
For the encryption logic, stockholm uses the Fernet cryptography Python library.  
  

Have fun!  

## usage
Set up victim environment:
```
./start.sh
```

Launch this from another terminal :
```
docker cp Stockholmfiles stockholm:/home
```
In your docker, do this :
```
cd home/Stockholmfiles && apt update && apt install python3 -y && apt install python3-pip -y && pip3 install -r requirement.txt
```

Ransomware script:
```
python3 stockholm.py [-h | -s | -v | -r DECRYPT_KEY | -w | -o] 
```

if you launch :
python3 stockholm.py : encrypt as 42 recommendation
-h --help : display help
-s --silent : silent log
-v --version : display version
-r --reverse : reverse 42encryption
-w --wannacry : encrypt like wannacry
-o --wannacrydecrypt : reverse wannacry
