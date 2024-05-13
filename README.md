# 1m-block

### Environment Setting
```
  sudo iptables -F
  sudo iptables -A OUTPUT -j NFQUEUE --queue-num 0
  sudo iptables -A INPUT -j NFQUEUE --queue-num 0
```

### 메모리 사용량 ###

<img width="412" alt="top" src="https://github.com/JungMem/1m-block/assets/108099255/a8f636e0-ec21-45e5-9f23-9ce57bc9c743">
