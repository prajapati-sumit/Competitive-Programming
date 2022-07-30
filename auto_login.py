import requests
import time
s=requests.session()
while True:
    resp=s.get("http://www.google.com")
    if "Firewall" in resp.text:
        print("login page detected")
        magic=resp.url[-16:]
        print(magic)
        params={"magic":magic,
                "username":"LDAP_USERNAME",
                "password":"LDAP_PASSWORD",
                "4Tredir":"http://www.google.com",
                "":""
                }
        loggedIn=s.post(resp.url+"/",data=params)
    elif resp.status_code==200:
        print("Everything is functioning well!")
    else:
        print("Something is wrong and it is not that damn login page this time")
    time.sleep(15*60)    