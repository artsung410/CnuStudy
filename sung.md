# 컴퓨터 공학 개론


> **컴퓨터의 3대 요소**  

메모리, I/O, CPU  
- 메모리 : 데이터 저장 공간
    - Little Endian / Big Endian


> **중앙처리 장치 3대 요소**  

산술논리 장치, 레지스터(cpu가 데이터를 저장하는 곳), 제어장치


> **기계어 처리 과정**  

1100/0001/0100  
명령어 / 피연산자1 / 피연산자2  
ADD / 1 / 4  
연산자 : ADD(0001), SUB(0010), MUL(0011)   

> **컴퓨터 언어의 역사**  

기계어 -> 어셈블리어 -> C언어 -> C++ // 　　c#, java, python  
　　　　[메모리 관리 o]　　　　　　　　 // 　[메모리 관리 x]


> **컴퓨터 아키텍처**  

폰노이만, 하버드

> **쓰레드 / 프로세스**

**쓰레드** : 작업단위 (실제 코드 실행, cpu에 보내지는것)  
 - 쓰레드는 메모리를 공유한 형태이다.

 - race condition : 쓰레드 끼리 충돌

**프로세스** :  데이터 컨테이너(하나의 프로세스당 하나의 쓰레드가 존재, )


> **프로세스 메모리 배치**

**힙** : 동적 할당 영역 (실행중에 사용되는 공간, 작성한 변수들)  
**스택** : 정적 할당 영역(컴퓨터가 얼마나 메모리를 사용해야할지 
알고있어야한다.)  
**데이터** : 정적 데이터가 들어있는 영역 (string, int,  struct..)  
**텍스트** : 프로그램 실행을 위한 코드들이 들어있는 공간


> **mutex**

특정 메모리를 잠궈서 0으로 만든다.  
 - 같은 메모리에는 하나만 접근할 수 있다

> **osi 7 layer**

[osi 7 계층 사진](https://images.velog.io/images/dyllis/post/7a6679e2-26e0-4d3e-b792-c866b9012226/%EB%8B%A4%EC%9A%B4%EB%A1%9C%EB%93%9C.png)


 > 프로그래밍의 시작  


함수 / 서브루틴 / 프로시저   



1. type   

    비트를 해석하는 방법 + 그에 적용 할 수 있는 연산.   

    primitive Type 

    built-in Type  

2. control statement   

    Conditional Statement (조건문)　　if / else / switch 

    Iteration Statement (반복문)　　for / while / do while

3. function   

    정의역에 있는 어떤 값을 대입시켰을 때, 그에 대응되는 공역의 값이 나온다.  
    f(x) = x   



4. 추상화 : 현실세계의 문제를 프로그램으로 끌고 온다.

strucht Account   
{
    
    이름 
    string Name;   

    계좌번호 
    int AccountNumber;  

    잔액
    int Balance;  

    이율
    float Interest  

}

 > 프로그래밍의 언어의 구성

core : 언어의 핵심 => 

문법, 변수, 조건문, 반복문, 함수,  
 구조체, 열거형, 배열, 포인터,  
공용체, 매크로, 타입 재정의

Library 
함수의 모음  

[라이브러리 모음 사이트](https://en.cppreference.com/w/c/header)




> 유용한 사이트  

[c++레퍼런스](https://en.cppreference.com/w/)



> 출처

[성권문](https://github.com/artsung410), [홍승완](https://github.com/usrrt)


