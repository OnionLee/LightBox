#include "Turboc.h"
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SPACE 32

#define GRAY 7
#define RED 12
#define BLUE 9
#define GREEN 10

void printfc(int a)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
};

void Print_Main();
void _Init();
void GameEnd();
void MainGame();	//메인게임
void op();			//게임오프닝을 표시하는 함수
void R_Move();
void L_Move();
void cradit();		//크래딧
void RMf();
void LMf();
int GamePlay();
int cor_select();
bool KeySet();
void print_1p();
void print_2p();
int lose_point_1p();
int lose_point_2p();
void retry_game();


int Cgan;  //시간
int OldCgan = 0; // 이전 시간
int Gx;
int Gy;
int RectX=1;
int RM_Point=4;
int LM_Point=39;
char move;
int count=0;
int cor;
int Speed;
int box_cor_1p = GRAY;
int box_cor_2p = GRAY;
int lose_1p = 1;
int lose_2p = 1;
int start = 1;
int char_shot_1p;
int char_shot_2p;





void main()
{
	_Init();		//초기화

	GamePlay();		//게임 플레이

	GameEnd();		//게임 종료
}


void _Init()	//초기화
{
	Gx = 14;
	Gy = 8;
	RectX=1;
	RM_Point=4;
	LM_Point=39;
	count=0;
	Speed=20;
	box_cor_1p = GRAY;
	box_cor_2p = GRAY;
	lose_1p = 1;
	lose_2p = 1;
	start = 1;
	printfc(GRAY);

	randomize();
	Print_Main();


}

int GamePlay()
{
	gotoxy(Gx,Gy);
	bool GameLoop = true;

	//메인 부분
	while(GameLoop)
	{
		GameLoop = KeySet();
	}


	switch(Gy)
	{
	case 8:
		MainGame();
		break;
	case 9:
		cradit();
		break;
	case 10:
		return 1;
		break;
	}
}

void GameEnd()
{
	system("cls");

	printf("게임이 종료됩니다");
	delay(100);
	printf(".");
	delay(100);
	printf(".");
	delay(100);
	printf(".\n");
	getch();
}


//메인 출력
void Print_Main()
{
	clrscr();
	setcursortype(SOLIDCURSOR);
	printf("#######################################\n");
	printf("#                                     #\n");
	printf("#  ㅂㅣ    ㅅㅏㅈㅏ                   #\n");
	printf("#   ㅊ      ㅇ	                      #\n");
	printf("#                                     #\n");
	printf("#  ~선택지를 선택하세요               #\n");
	printf("#  ~선택지를 선택했다면 스페이스바!   #\n");
	printf("#                                     #\n");
	printf("#  1. 게임시작                        #\n");
	printf("#  2. 크래딧                          #\n");
	printf("#  3. 나가기                          #\n");
	printf("#                                     #\n");
	printf("#######################################\n");
}

bool KeySet()
{
	if(_kbhit())
	{
		move = getch();
		switch (move)
		{
		case DOWN:
			Gy++;
			break;
		case UP:
			Gy--;
			break;
		case SPACE:
			Gy = wherey();
			return false;
		}

		if(Gy <= 8)			//커서가 이동할수 있는 공간 제한
			Gy=8;
		if(Gy >= 10)
			Gy=10;					
	}
	gotoxy(Gx,Gy);		//커서이동

	return true;

}
void op()
{	

	setcursortype(NOCURSOR);
	printf("################<조작법>###############\n");
	printf("#                                     #\n");
	printf("#    < 1p >               < 2p >      #\n");
	printf("#                                     #\n");
	printf("#    Q = RED              U = RED     #\n");
	printf("#    W = BLUE             I = BLUE    #\n");
	printf("#    E = GREEN            O = GREEN   #\n");
	printf("#                                     #\n");
	printf("#    R = Shot!            P = Shot!   #\n");
	printf("#                                     #\n");
	printf("#######################################\n\n");
	printf("##############<게임 방법>##############\n");
	printf("#                                     #\n");
	printf("# 가로등([  ])사이로 상자가 지나갈 때 #\n");
	printf("# 상자의 색이 표시 되며 상자의 색을   #\n");
	printf("# 확인하고, 플레이어의 색을 바꿉니다. #\n");
	printf("# 플레이어 앞 shot line(++)에 상자가  #\n");
	printf("# 도달하였을 때 Shot버튼을 이용하면,  #\n");
	printf("# 상자를 밑으로 이동시키고,           #\n");
	printf("# 상자의 속도가 점점 빨라집니다.      #\n");
	printf("# 상자를 놓친쪽이 패배하게 됩니다.    #\n");
	printf("#                                     #\n");
	printf("#######################################\n");
	printf("~계속하시려면 아무버튼을, 뒤로 가시려면 x버튼을 입력해 주세요.\n");
	gotoxy(0,0);
	if(getch() == 'x')
	{
		main();
	}
}

void cradit()
{
	clrscr();
	setcursortype(NOCURSOR);
	printf("################<제작자>###############\n");
	printf("#                                     #\n");
	printf("# 제작자 : 이강희 (게임과 10기 13번)  #\n");
	printf("# 이메일 : rkdgml6332@naver.com       #\n");
	printf("#                                     #\n");
	printf("# 버전 : 1.02 (2012_7_6)              #\n");
	printf("# 도움을 주신 분 : 황성원 선배님      #\n");
	printf("#                : 김준호 선배님      #\n");
	printf("#######################################\n");
	printf("뒤로 가시려면 x버튼을 입력해 주세요.\n");
	gotoxy(0,0);
	if(getch() == 'x')
	{
		main();
	}
}

//게임의 메인 부분
void MainGame()
{



	clrscr();
	op();
	clrscr();

	printf("    ★---------------------------------++\n");
	printf("→                  [  ]                     \n");
	printf("    -----------------------------------++\n");
	printf("    ++-----------------------------------\n");
	printf("                    [  ]                   ←\n");
	printf("    ++----------------------------------★\n");
	print_1p();
	print_2p();
	gotoxy(2,1);

	while(1)
	{
		{	
			if(start == 1)
			{
				start--;
				cor_select();
				RMf();
				RM_Point=4;
				if(Speed > 6)
					Speed--;
			}
			if(lose_1p > 0)
			{
				lose_2p=1;
				cor_select();
				LMf();
				LM_Point=39;
				if(Speed > 6)
					Speed--;
			}
			else
				break;

			if(lose_2p > 0)
			{
				lose_1p=1;
				cor_select();
				RMf();
				RM_Point=4;
				if(Speed > 6)
					Speed--;
			}
			else
				break;


		}


	}
	retry_game();



}

void RMf()
{
	while(1)
	{
		if(lose_1p > 0)
		{

			Cgan = GetTickCount()/5; //초 단위

			if(OldCgan == 0)
			{
				OldCgan = Cgan;
			}

			if(Cgan - OldCgan >= Speed) //오른쪽 변수는 얼마만큼의 속도로 상자가 직이는지 조정 한다.
			{
				if(RM_Point <= 42)
					R_Move();
				else
				{
					gotoxy(RM_Point,1);
					printf("  ");
					break;
				}
				OldCgan = Cgan;
			}

			if (kbhit())
			{
				move = getch();
				switch(move)
				{
				case 'q':
					box_cor_1p = RED;
					break;
				case 'w':
					box_cor_1p = BLUE;
					break;
				case 'e':
					box_cor_1p = GREEN;
					break;
				case 'r':
					lose_point_1p();
					break;
				}
				print_1p();

			}
		}
		else
			break;
		if((RM_Point >= 42)&&(lose_1p == 1))
		{
			if(!kbhit())
				lose_1p--;

		}
		if(lose_1p == 2)
		{
			gotoxy(RM_Point,1);
			printf("  ");
			lose_1p =1;
			break;

		}

	}
}

void LMf()
{
	while(1)
	{

		if(lose_2p > 0)
		{
			Cgan = GetTickCount()/5;


			if(OldCgan == 0)
			{
				OldCgan = Cgan;
			}

			if(Cgan - OldCgan >= Speed)
			{
				if(LM_Point >= 1)
					L_Move();
				else
				{
					gotoxy(LM_Point,4);
					printf("  ");
					break;
				}
				OldCgan = Cgan;
			}

			if (kbhit())
			{
				move = getch();
				switch(move)
				{
				case 'u':
					box_cor_2p = RED;
					break;
				case 'i':
					box_cor_2p = BLUE;
					break;
				case 'o':
					box_cor_2p = GREEN;
					break;
				case 'p':
					lose_point_2p();
					break;
				}
				print_2p();
			}
		}
		else
			break;
		if((LM_Point <= 2)&&(lose_2p == 1))
		{
			if(!kbhit())
				lose_2p--;

		}
		if(lose_2p == 2)
		{
			gotoxy(LM_Point,4);
			printf("  ");
			lose_2p;
			break;
		}
	}
}



void R_Move()
{
	if((RM_Point <= 23)&&(RM_Point >= 22))
	{
		gotoxy(RM_Point++,1); 
		printfc(cor);
		printf("■");

		if(RM_Point == 23)
		{
			gotoxy(20,1);
			printfc(GRAY);
			printf("[");
		}
	}
	else
	{
		gotoxy(RM_Point++,1 );
		printfc(GRAY);
		printf("■");
	}
	if(RM_Point == 25)
	{
		gotoxy(23,1);
		printfc(GRAY);
		printf("]");
	}

}

void L_Move()
{
	if((LM_Point >= 19)&&(LM_Point <= 20))
	{
		gotoxy(LM_Point--,4);
		printfc(cor);
		printf("■");
		if(LM_Point ==19)
		{
			gotoxy(23,4);
			printfc(GRAY);
			printf("]");
		}
	}
	else
	{
		gotoxy(LM_Point--,4);
		printfc(GRAY);
		printf("■");
	}
	if(LM_Point == 17)
	{
		gotoxy(20,4);
		printfc(GRAY);
		printf("[");
	}
}

int cor_select()
{
	cor = random(3);
	switch(cor)
	{
	case 0:
		cor = RED;
		break;
	case 1:
		cor = BLUE;
		break;
	case 2:
		cor = GREEN;
		break;
	}
	return cor;
}

void print_1p()
{
	gotoxy(43,1);
	printfc(box_cor_1p);
	printf("▲");
}
void print_2p()
{
	gotoxy(0,4);
	printfc(box_cor_2p);
	printf("△");
}

int lose_point_1p()
{

	if((RM_Point >= 40) &&(RM_Point <= 42)&&(cor==box_cor_1p))
		lose_1p++;
	else
		lose_1p--;
	return lose_1p;
}


int lose_point_2p()
{ 
	if((LM_Point >= 3)&&(LM_Point <= 5)&&(cor==box_cor_2p))
		lose_2p++;
	else
		lose_2p--;
	return lose_2p;
}


void retry_game()
{
	int i=1;
	clrscr();
	printfc(GRAY);
	printf("################<메시지>###############\n");
	printf("#                                     #\n");
	printf("# 게임을 다시 시작하시겠습니까?       #\n");
	printf("#                                     #\n");
	printf("# 1.YES(SPACE)                        #\n");
	printf("# 2.NO(x)                             #\n");
	printf("#                                     #\n");
	printf("#######################################\n");
	gotoxy(0,0);
	
	while(1)
	{

		if(kbhit())
		{
			move = getch();
		}
		if(move == SPACE)
		{
			break;
		}
		else if(move == 'x')
		{
			
			break;
		}

	}	
	if(move == SPACE)
		main();
	else if(move == 'x')
		GameEnd();

}




