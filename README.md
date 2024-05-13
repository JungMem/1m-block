# 1m-block

### 환경 설정 ###
```
  sudo iptables -F
  sudo iptables -A OUTPUT -j NFQUEUE --queue-num 0
  sudo iptables -A INPUT -j NFQUEUE --queue-num 0
```

<br>

### 코드 요약 ###

![구조](https://github.com/JungMem/1m-block/assets/108099255/a2e076d6-e4c7-4731-90eb-bedf020e841a)

<br><br>

### 메모리 사용량 ###

<img width="479" alt="top" src="https://github.com/JungMem/1m-block/assets/108099255/9be982ae-c95b-44f0-9183-78476a841564">

<br><br>

### 예외 상황 ###
![예외상황](https://github.com/JungMem/1m-block/assets/108099255/ac2aacba-d4e5-4de2-9904-49d56427ad6c)
