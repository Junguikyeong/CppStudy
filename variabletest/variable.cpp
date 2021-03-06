#include <iostream>

using namespace std;

int main()
{
    // C++표준 기능의 대부분은 std라는 namespace안에 존재하고 있다. 이름이 겹치는것을 방지해주기 위해서이다.
    // cout : 콘솔창에 출력해주는기능 뒤에있는 ""안에 있는 문자들을 출력
    // 문자하나늘 쓸때는 작은따운표 ''
    // 문자 여러개를 사용할때는 반드시 ""안에 넣어주고 이런것들을 문자열이라고한다.
    // emdl : 개행기능이다.
    
    std::cout << "Test Output"<< std::endl;
    std::cout << "가나다라"<< std::endl;
    
    cout << "std namespace 사용" << endl;
    
    /*
    변수 : 변하는 수. 값이 바뀔수 있다.
    용량의 최소단위 : bit
    1byte = 8bit
    1kbyte = 1024byte
    1mbyte = 1024kbyte
    1gbyte = 1024mbyte
    1tbyte = 1024gbyte

    false : 0 , true : 0 이 아닌 모든수
    unsigned : 부호가 없다.
    문자를 표현하는 방법 : ASCII 코드 표를 가지고 있다.
    종류    |   용량     |   데이터  |    표현범위        |    unsigned      |
    char    |   1byte   |   문자    |   -128 ~ 127      |    0 ~ 255       |
    bool    |   1byte   |   참/거짓 |   true/false      |   true/false     |       
    short   |   2byte   |   정수    |   -32768 ~ 32767  |   0 ~ 65535      |
    int     |   4byte   |   정수    |   약 -22억 ~ 21억  |  0 ~ 약 43억     |
    float   |   4byte   |   실수    |
    double  |   8byte   |   실수    |
    */


    int Number = 10;

    cout << Number << endl;

    bool bTest = true;
    bTest = false;

    cout << bTest << endl;
    //영문이나 숫자는 1byte를 차지한다. 하지만 한글이나 한문 드으이 문자들은 2byte를 
    //차지하기 때문에 char 변수 하나에 저장하기가 힘들다.

    char cTest = 't';
    cout << cTest << endl;

    float fNumber = 3.14f;
    cout << fNumber << endl;

    double dNumber = 123.4567;
    cout << dNumber << endl;

    /*
    사칙 연산자 : +, -, *, /, %(나머지 연산자)
    관계 연산자 : 값대 값을 연산하여 참/거짓으로 결과를 반환한다.
    >, >=, <, <=, ==, !=

    논리연산자 : 참/거짓 대 참/거짓 연산하여 참/거짓으로 결과를 반환한다.
    AND(&&), OR(||), NOT(!)
    A    B   AND OR
    0    0   0   0
    1    0   0   1
    0    1   0   1
    1    1   1   1

    A    NOT
    0    1
    1    0
    
    진수 : 2진수, 8진수, 10진수, 16진수
    2진수 : 0 ~ 1
    8진수 : 0 ~ 7
    10진수 : 0 ~ 9
    16진수 : 0 ~ 15    0 ~ 9 / 10 ~ 15 : a ~ f
    진수들은 서로 다른 진수로 변환이 가능하다.

    87을 2진수, 16진루소 변환해보다.

    먼저 2진수로 변환한다.
    87 / 2 = 43 -- 1
    43 / 2 = 21 -- 1
    21 / 2 = 10 -- 1
    10 / 2 = 5 --- 0
    5 / 2 = 2 ---- 1
    2 / 2 = 1 ---- 0
    가장 마지막에 나온 몫부터 역순으로 나머지값을 읽는다.
    1010111 이 된다.

    16진수로 변환해보자. 10짖수를 바로 16진수로 변환하는것보다
    2진수로 변환한 후에 16진수로 변환하는것이 쉽다.

    1010111 을 오른쪽으로부터 4자리씩 끊어서 계산한다. 16진수 1자리는 2진수 4자리다.
    0101 0111
    8421 8421

    2진수가 1인 부분의 값들을 더한다.
    4+1  4+2+1
    16진수 57이 된다.

    비트단위 논리연산자 : 2진수 단위의 연산을 한다. 값대 값을 연산하여 값으로 나온다.
    종류 : AND(&), OR(|), NOT(~)틸드, XOR(^)
    A   B   XOR
    0   0   0
    1   0   1
    0   1   1
    1   1   0

    87 : 1010111
    53 : 110101
    먼저 위처럼 2진수로 바꾼 후에 각 자리별로 논리연산을 실행한다.
    87 & 53 = 21
     1010111
    &0110101
     0010101
    10101 이 나온다.
    16진수는 15
    10진수로 변환하면 21이 나온다.

    */

    cout << "10 < 20 =" << (10 < 20) << endl;
    cout << "10 <= 20 =" << (10 <= 20) << endl;
    cout << "10 > 20 =" << (10 > 20) << endl;
    cout << "10 >= 20 =" << (10 >= 20) << endl;
    cout << "10 == 20 =" << (10 == 20) << endl;
    cout << "10 != 20 =" << (10 != 20) << endl;

    cout << "숫자를 입력하세요 : ";
    cin >> Number;

    cout << "10 ~ 20 = " << (10 <= Number && Number <=20) << endl;

    cout << "87 & 53 = " << (87 & 53) << endl;
    
    return 0;
}