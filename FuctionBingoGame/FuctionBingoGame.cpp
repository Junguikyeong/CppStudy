#include <iostream>
#include <time.h>

using namespace std;

void SetNumber(int *pArray);
void SuffleNumber(int *pArray);
void OutputBingotabel(int *pArray);
void ChangeNumber(int *pArray,int PlayerNumber);
int BingoCheck(int *pArray,int Bingoline);

int Starnumber = 1000;

int main()
{
    srand((unsigned int)time(0));

    int bingoNumber[25]={};

    SetNumber(bingoNumber);
    SuffleNumber(bingoNumber);
    OutputBingotabel(bingoNumber);

    while(1)
    {   
        int PlayerNumber;
        cout << "1~25 사이의 숫자를 입력하세요.(0 : 종료) : " << endl; // 빙고 숫자 입력
        cin >> PlayerNumber ;

        ChangeNumber(bingoNumber,PlayerNumber);

        if(PlayerNumber == 0) // 0입력시 종료
            break; 

        int Bingoline = 0;
        Bingoline = BingoCheck(bingoNumber,Bingoline);
        cout << Bingoline << " 빙고 " << endl << endl;

        if(Bingoline >=5) // 5빙고시 종료
            break; 
    }
}

void SetNumber(int *pArray)
{
    for (int i=0; i<25; ++i)
    {
        pArray[i] = i+1;
    }
}

void SuffleNumber(int *pArray)
{
    int idx1, idx2, tmp;
    for (int i = 0; i<100; ++i)
    {
        idx1 = rand() % 25;
        idx2 = rand() % 25;

        tmp = pArray[idx1];
        pArray[idx1] = pArray[idx2];
        pArray[idx2] = tmp;
    }
}

void OutputBingotabel(int  *pArray)
{
    for (int i=0; i< 5; ++i)
    {
        for(int j=0; j<5; ++j)
        {
            cout << pArray[i*5+j] << "\t" ;
        }
        cout << endl;
    }
}

void ChangeNumber(int *pArray, int PlayerNumber)
{
    for (int i=0; i<25; ++i) // 입력 숫자 StarNumber로 변경
    {
        if(PlayerNumber == pArray[i])
            pArray[i] = Starnumber;
    }
}

int BingoCheck(int *pArray, int Bingoline)
{
    int LRdaegakBingo = 0, RLdaegakBingo = 0;

    for (int i=0; i< 5; ++i)
    {
        int garoBingo = 0, seroBingo = 0;

        for(int j=0; j<5; ++j)
        {
            if(pArray[i*5+j] == Starnumber)
                    cout << "*" << "\t";
            else
                cout << pArray[i*5+j] << "\t" ;

            if(pArray[i*5+j] == Starnumber) // 가로체크
                garoBingo += 1;
            if(pArray[j*5+i] == Starnumber) // 세로체크
                seroBingo += 1;
            if((i*5+j)%6 == 0 && pArray[i*5+j] == Starnumber) // 좌상대각체크
                LRdaegakBingo += 1;
            if((i*5+j) != 0 && (i*5+j) != 24 && (i*5+j)%4 == 0 && pArray[i*5+j] == Starnumber) // 우상대각체크
                RLdaegakBingo += 1;
        }

        cout << endl;

        if(garoBingo == 5)
            Bingoline += 1;
        if(seroBingo == 5)
            Bingoline += 1;
        if(LRdaegakBingo == 5)
            Bingoline += 1;
        if(RLdaegakBingo == 5)
            Bingoline += 1;
    }
    return Bingoline;
}