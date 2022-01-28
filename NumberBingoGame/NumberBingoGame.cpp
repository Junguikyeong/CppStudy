#include <iostream>
#include <time.h>

using namespace std;

void SetNumber(int *pArray);
void SuffleNumber(int *pArray);
void OutputBingotabel(int *pArray);

int main()
{
    srand((unsigned int)time(0));

    int bingoNumber[25]={};

    SetNumber(bingoNumber);
    SuffleNumber(bingoNumber);
    OutputBingotabel(bingoNumber);

    int Bingoline, garoBingo, seroBingo;
    int PlayerNumber;
    int Starnumber = 1000;

    while(1)
    {   
        cout << "1~25 사이의 숫자를 입력하세요." << endl; // 빙고 숫자 입력
        cin >> PlayerNumber ;

        if(PlayerNumber == 0) 
            break;

        for (int i=0; i<25; ++i) // 입력 숫자 StarNumber로 변경
        {
            if(PlayerNumber == bingoNumber[i])
                bingoNumber[i] = Starnumber;
        }

        Bingoline = 0;


        int LRdaegakBingo = 0;
        int RLdaegakBingo = 0;

        for (int i=0; i< 5; ++i)
        {
            garoBingo = 0;
            seroBingo = 0;

            for(int j=0; j<5; ++j)
            {
                if(bingoNumber[i*5+j] == Starnumber)
                        cout << "*" << "\t";
                else
                    cout << bingoNumber[i*5+j] << "\t" ;

                if(bingoNumber[i*5+j] == Starnumber)
                    garoBingo += 1;
                
                if(bingoNumber[j*5+i] == Starnumber)
                    seroBingo += 1;

                if((i*5+j)%6 == 0 && bingoNumber[i*5+j] == Starnumber)
                    LRdaegakBingo += 1;
                if((i*5+j) != 0 && (i*5+j) != 24 && (i*5+j)%4 == 0 && bingoNumber[i*5+j] == Starnumber)
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

        cout << Bingoline << " 빙고" << endl;

        if(Bingoline >= 5)
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
    for (int i=0; i< 5; ++i) // 먼저 빙고판 출력
    {
        for(int j=0; j<5; ++j)
        {
            cout << pArray[i*5+j] << "\t" ;
        }
        cout << endl;
    }
}