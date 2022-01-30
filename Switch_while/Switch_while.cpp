#include <iostream>
#include <time.h>
#include <typeinfo>

using namespace std;

/*
열거체 : 연속된 숫자에 이름을 부여할 수 있는 기능이다.
enum 열거체명 {} 의 형태로 구성된다.
열거체명을 이용해서 열거체 타입의 변수를 선언도 가능하다.
즉, 열거체 자체가 사용자정의 변수 타입이 될 수도 있다.
열거체는 숫자에 이름을 붙여주는 기능이다.
*/
enum NUM
{
    NUM_0, // 아무것도 부여하지 않을 경우 0부터 1씩 차례로 값이 부여된다.
    NUM_1,
    NUM_2,
    NUM_3
};

enum SRP
{
    SRP_S = 1,
    SRP_R,
    SRP_P,
    SRP_END

};

#define NUM_4 4

int main()
{
    /*
    switch문 : 분기문의 한 종류이다. if문이 조건을 체크하는 분기문이라면
    switch문은 값이 뭔지를 체크하는 분기문이다.
    형태 : switch(변수) {}의 형태로 구성된다. 코드벌럭 안에는 
    case break구문이 들어가게된다. case 상수 : 의 형태로 처리가 되고 변수값이 무엇인지에 따라서
    case 뒤에 오는 상수를 비교하게 된다.*/

    int iNumber;

    cout << "숫자를 입력하세요 : ";
    cin >> iNumber;

    switch (iNumber)
    {
    case NUM_1: //iNumber값이 무엇인지에 따라서 실행되는 case구문이 결정된다.
        cout << "입력한 숫자는 1입니다." << endl;
        break; //break를 만나게 되면 switch문을 빠져나가게 된다.
    case NUM_2:
        cout << "입력한 숫자는 2입니다." << endl;
        //여기처럼 break가 없게 된다면 바로 아래에 있는 case구문도 강제로
        //실행이 되게 된다.
        //break;
    case NUM_3:
        cout << "입력한 숫자는 3입니다." << endl;
        break;
    case NUM_4:
        cout << "입력한 숫자는 4입니다." << endl;
        break;
    default: // case로 지정하지 않은
        cout << "그 외의 숫자입니다." << endl;
        break;
    }

    //열거체 타입의 변수를 선언했다. 열거체 타입 변수는 무조건
    //4byte를 차지하게 된다.
    NUM eNum = (NUM)10;

    //sizeof(타입 or 변수) 를 하게 되면 해당 타입 혹은 변수의 메모리 크기를
    // 구해준다.
    cout << sizeof(NUM) << endl;
    //typeid(타입 or 변수).name()을 하게 되면 타입 혹은 변수의 타입을 문자열로
    //반환해준다.
    cout << typeid(eNum).name() << endl;
    cout << eNum << endl;

    /*
    반복문 : 특정 작업을 반복해서 수행해주는 기능이다.
    종류 : for, while, do while 3종류가 존재한다.
    while(조건식) {}의 형태로 구성된다.
    while문은 조건식이 true일 경우 코드블럭안의 코드가 동작되고
    조건식이 false일 경우 while문을 빠져나오게 된다.
    반복문 안에서 break를 만나게 되면 해당 반복문을 빠져나오게 된다.*/

    iNumber = 0;
    while (iNumber < 10)
    {
        cout << iNumber << endl;
        ++iNumber;

        if (iNumber == 4)
            break;
    }

    //화면을 깨끗히 지워준다.
//    system("cls");

    //난수테이블 생성
    srand((unsigned int)time(0));

    int iPlayer, iAI;

    while (false) //true
    {
        cout << "1. 가위" << endl;
        cout << "2. 바위" << endl;
        cout << "3. 보" << endl;
        cout << "4. 종류" << endl;
        cout << "메뉴를 선택하세요 : " << endl;
        cin >> iPlayer;

        if (iPlayer < SRP_S || iPlayer > SRP_END)
        {
            cout << "잘못된 값을 입력하였습니다." << endl;
            //일시정지
            system("pause");
            //continue : 반복문의 시적점으로 이동시켜주는 기능이다.
            continue;
        }
        else if (iPlayer == SRP_END)
            break;

        //봇이 선택을 한다.
        iAI = rand() % 3 + SRP_S;

        switch (iAI)
        {
        case SRP_S:
            cout << "AI : 가위" << endl;
            break;
        case SRP_R:
            cout << "AI : 바위" << endl;
            break;
        case SRP_P:
            cout << "AI : 보" << endl;
            break;
        }
        
        int iWin = iPlayer - iAI;
        /*
        if(iWin == 1 || iWin == -2)
            cout << "Player 승리" << endl;
        else if (iWin == 0)
            cout << "비김" << endl;
        else   
            cout << "AI 승리" << endl;*/ 

        switch (iWin)
        {
        case 1:
        case -2:
            cout << "Player 승리" << endl;
            break;
        case 0:
            cout << "비김" << endl;
            break;        
        default:
            cout << "AI 승리" << endl;
            break;
        }
        system("pause");
    }

    /*
    for (int i=0; i<100; ++i)
    {
        cout <<rand() % 701 + 1000 << endl;
    }
    */

    /*
    for문 : 반복문의 한 종류이다.
    형태 : for (초기값; 조건식; 증감값){}의 형태로 구성이도니다.
    조건식이 true이면 코드블럭의 코드가 동작된다.
    무한루프를 돌릴때는 for(;;){} 을 해주면 된다.
    for문에서 초기값은 처음 for문에 진입할때 딱 1번만 동작된다.
    조건이 false이거나 break를 만나게되면 빠져나가게 된다.*/

    for (int i = 0; i < 10; ++i)
    {
        cout << i << endl;
    }
    //구구단 2단을 출력해보자
    for(int i=1; i<10; ++i)
    {
        cout << "2 * " << i << " = " << 2 * i << endl;
    }
    
    //1~100사이의 숫자중 짝수만 출력하는 for문을 작성해보자.
    for(int i=2; i<=100; i += 2)
    {
        cout << i << endl;
    }

    //1~100 사이의 숫자 중 3과 7의 공배수만 출력하는 if문을 만들어보자
    for (int i=1; i<=100; ++i)
    {
        if (i % 3 == 0 && i % 7 == 0)
            cout << i << endl;
    }
    
    

    return 0;
}