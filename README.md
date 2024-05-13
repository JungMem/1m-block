# 1m-block

### 환경 설정 ###
```
  sudo iptables -F
  sudo iptables -A OUTPUT -j NFQUEUE --queue-num 0
  sudo iptables -A INPUT -j NFQUEUE --queue-num 0
```

<br>

### 코드 구조 ###

![구조](https://github.com/JungMem/1m-block/assets/108099255/a2e076d6-e4c7-4731-90eb-bedf020e841a)

<br>

Domain이 있을 때, 처음으로 오는 Dot(".") 뒤의 값을 dictionary에 보관하고 Dot(".") 이전의 값을 해당 dictionary가 가리키는 Trie 구조에 저장하도록 구현함. Trie의 빠른 속도를 활용하고 큰 메모리 사용량을 줄이기 위해 구상한 형태.


<br><br>

### 메모리 사용량 ###

<img width="479" alt="top" src="https://github.com/JungMem/1m-block/assets/108099255/9be982ae-c95b-44f0-9183-78476a841564">

<br>

메모리 사용량을 줄이려고 노력했으나, Trie 구조의 한계로 메모리가 66프로 가까이 사용됨.

<br><br>

### Time Diff ###

<img width="199" alt="parsing time" src="https://github.com/JungMem/1m-block/assets/108099255/77a162ae-d6d0-4913-a1c3-d401244e4c31">

<br>

웹사이트들 파싱은 대략 2초가 걸림.

<br>

<img width="710" alt="test gilgilnet" src="https://github.com/JungMem/1m-block/assets/108099255/b981d4aa-9971-43fc-9901-60bddbeb7ac6">
<img width="769" alt="searching time" src="https://github.com/JungMem/1m-block/assets/108099255/4456a982-e0d8-4755-88f4-823090c8a3cb">

<br>

목록에 존재하지 않는 웹사이트와 존재하는 웹사이트 서칭에 모두 0초 가까이 걸림.

<br><br>

### 예외 상황 ###
![예외상황](https://github.com/JungMem/1m-block/assets/108099255/ac2aacba-d4e5-4de2-9904-49d56427ad6c)

<br>

특정 웹사이트의 경우, wget이 자동으로 Retrying을 하여 Domain 앞에 "www."을 붙여 패킷을 전달함(Ex: "naver.com" -> "www.naver.com"). 따라서 예외 상황 처리를 따로 구현함.
