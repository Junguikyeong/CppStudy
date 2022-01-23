#include <iostream>
#include <time.h>

using namespace std;
//LottoGame
int main()
{
    srand((unsigned int)time(0));

    int iLotto[45]={};

    //1~45까지의 숫자를 차례대로  넣어준다.
    
    for (int i = 0; i <= 45; ++i)
    {
        iLotto[i] = i + 1;
    }
    //Swap 알고리즘
    /*int iNum1 = 1, iNum2 = 2, iNum3;
    iNum3 = iNum1;
    iNum1 = iNum2;
    iNum2 = iNum3;*/

    //Shuffle
    int iTemp, idx1, idx2;
    // 100번정도 골고루 섞어준다.
    for (int i = 0; i < 100; ++i)
    {
        idx1 = rand() % 45;
        idx2 = rand() % 45;

        iTemp = iLotto[idx1];
        iLotto[idx1] = iLotto[idx2];
        iLotto[idx2] = iTemp;
    }

    for (int i=0; i<6; ++i)
        cout << iLotto[i] << "\t";
    cout << "보너스번호 : " << iLotto[6] << endl;

    return 0;
}

/*
숙제 : 야구게임 만들기
1~9 사이의 랜덤한 숫자 3개를 얻어온다. 단, 숫자는 중복되어서는 안된다.
3개의 숫자는 ***의 형태로 출력되고 이 3개의 숫자를 맞추는 게임이다.
사용자는 이 3개의 숫자를 맞출때까지 계속해서 3개씩 숫자를 입력한다.

만약 맞춰야할 숫자가 7 3 8일 경우
사용자는 3개의 숫자를 계속 입력한다.
입력 : 1 2 4 를 입력했을 경우 1 2 4는 맞춰야할 숫자 중 아무것도 없으므로
Out을 출력한다.

입력 : 7 5 9 를 입력했을 경우 7은 맞춰야할 숫자 중 있고 위치도 같으므로
strike이다. 5 9는 없으므로 출력은 1strike 0ball을 출력한다.

입력 : 7 8 6 을 입력했을 경우 7은 1strike, 8은 숫자는 있지만 위치가 다르므로 ball이 된다.
1strike 1ball을 출력한다.

이렇게 출력을 하고 입력을 받으면서 최종적으로 3개의 숫자를 자리까지 모두 일치하게
입력하면 게임이 종료된다. 만약 입력받은 숫자 3개 중 한개라도 0이 있을 경우 게임을 종료한다.
*/
