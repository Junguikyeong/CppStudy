#include <iostream>
#include <time.h>
//console input output 헤더파일이다. 콘솔창에서 입출력하는 기능을 구현한다.
#include <conio.h>

using namespace std;

int main()
{
    srand((unsigned int)time(0));

    int iNumber[25] = {};

    for (int i = 0; i < 24; ++i)
    {
        iNumber[i] = i + 1;
    }

    //가장 마지막 칸은 공백으로 비워둔다. 공백을 의미하는 값으로 특수한 값을
    //사용할건데 INT_MAX라는 값을 사용할 것이다. INT_MAX는 이미 정의되어 있는 값으로
    //int로 표현할 수 있는 최대값이다.
    iNumber[24] = INT_MAX;

    int iStarIndex = 24;

    int iTemp, idx1, idx2;

    for (int i = 0; i < 100; ++i)
    {
        idx1 = rand() % 24;
        idx2 = rand() % 24;

        iTemp = iNumber[idx1];
        iNumber[idx1] = iNumber[idx2];
        iNumber[idx2] = iTemp;
    }

    while (true)
    {
        //i for문이 세로줄을 의미한다.
        for (int i = 0; i < 5; ++i)
        {
            //j for문이 가로칸을 의미한다.
            for (int j = 0; j < 5; ++j)
            {
                //i가 0일때는 j는 0~4까지 반복한다. 이 경우 0*5+(0~4)를 더하게되서
                //인덱스는 0,1,2,3,4가 나오게된다.
                //i가 1일때는 j는 0~4까지 반복한다. 이 경우 1*5+(0~4)를 더하게되서
                //인덱스는 5,6,7,8,9가 나오게된다.
                //줄번호 * 가로개수 + 칸번호
                if (iNumber[i * 5 + j] == INT_MAX)
                    cout << "*\t";
                else
                    cout << iNumber[i * 5 + j] << "\t";
            }
            cout << endl;
        }

        cout << "w : 위 s : 아래 a : 왼쪽 d : 오른쪽 q : 종료 : " ;

        //_getch() 함수는 문자 1개를 입력받는 함수이다. 이 함수는 Enter를 치지
        //않더라도 문자를 누르는 순간 바로 그 문자를 반환하고 종료한다.
        char cInput = _getch();

        if (cInput == 'q' || cInput == 'Q')
            break;

        switch (cInput)
        {
        case 'w':
        case 'W':
            //가장 윗중일 때는 w를 눌러도 위로 움직이면 안된다.
            if (iStarIndex > 4)
            {
                //별이 있는 위치에 바로 위에 있는 값을 넣어준다.
                iNumber[iStarIndex] = iNumber[iStarIndex - 5];
                //위의 위치에 별을 넣어주어서 2개의 값을 서로 교체해준다.
                iNumber[iStarIndex - 5] = INT_MAX;
                //별이 한칸 위로 올라갔으므로 한칸 위에 인덱스로 만들어준다.
                iStarIndex -= 5;
            }
            break;
        case 's':
        case 'S':
            if (iStarIndex < 20)
            {
                iNumber[iStarIndex] = iNumber[iStarIndex + 5];
                iNumber[iStarIndex + 5] = INT_MAX;
                iStarIndex += 5;
            }
            break;
        case 'a':
        case 'A':
            if (iStarIndex % 5 != 0)
            {
                iNumber[iStarIndex] = iNumber[iStarIndex - 1];
                iNumber[iStarIndex - 1] = INT_MAX;
                --iStarIndex;
            }
            break;
        case 'd':
        case 'D':
            if (iStarIndex % 4 != 0)
            {
                iNumber[iStarIndex] = iNumber[iStarIndex + 1];
                iNumber[iStarIndex + 1] = INT_MAX;
                ++iStarIndex;
            }
            break;
        }
    }
    cout << "게임을 종료합니다." << endl;

    return 0;
}


/*
숙제 : 숫자빙고게임을 만들어보자.
1 ~ 25 까지의 숫자가 있고 이 숫자를 골고루 섞어서 5 x 5로 출력한다.
플레이어는 숫자를 입력받는다. 1 ~ 25 사이의 숫자를 입력받아야 한다.
0을 입력하면 게임을 종료한다.
 
숫자를 입력받았으면 숫자목록 중 숫자를 찾아서 *로 만들어준다.
숫자를 *로 만든 후에 빙고 줄 수를 체크한다. 5 x 5이기 때문에 
가로 5줄, 세로 5줄, 대각선 2줄이 나올 수 있다. 
빙고줄이 몇줄인지를 체크해서 화면에보여준다.
5줄 이상일 경우 게임을 종료한다.
*/