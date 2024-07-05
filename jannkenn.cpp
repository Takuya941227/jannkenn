#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main(void) {
	printf("じゃんけんプログラム\n");
	/*** 変数定義 ***/
	int player = 0;									//プレイヤーの手
	int com = 0;									//コンピュータの手
	int result = 0;									//勝敗結果
	int streak = 0;									//連勝記録
	int continuity = 0;								//続投フラグ
	char newline[2];								//数値チェック用
	srand((unsigned int)time(NULL));				//ランダムシード
	
	/*** 実行処理 ***/
	//つづけるを選べば繰り返し
	do {
		//あいこであれば繰り返し
		do {
			//プレイヤーが出す手を入力(正しい入力をするまで繰り返し)
			do	{
				printf("グー：1　チョキ：2　パー：3\n");
				printf("あなたの出す手を入力してください：");
				const int m = scanf("%d%1[\n]", &player, newline);					//入力時に数値であるかを判定するための変数（2=数値、1=少数or数値＋記号、0=数値として解釈できないもの）
				if (m != 2) {
					(void)scanf("%*[^\n]");
					printf("規定外の入力です もう一度入力してください\n\n");
				}
				else if (player > 3 || player <= 0) {
					printf("規定外の入力です もう一度入力してください\n\n");
				}
				else {
					player -= 1;													//データでの管理は0,1,2のほうが管理しやすいので調整
					break;
				}
			} while (true);

			//コンピューターが出す手を作成
			com = rand() % 3;

			//入力した手を表示
			printf("あなたが出した手：");
			if (player == 0) {
				printf("グー\n");
			}
			else if (player == 1) {
				printf("チョキ\n");
			}
			else if (player == 2) {
				printf("パー\n");
			}

			printf("ＣＰＵが出した手：");
			if (com == 0) {
				printf("グー\n");
			}
			else if (com == 1) {
				printf("チョキ\n");
			}
			else if (com == 2) {
				printf("パー\n");
			}
			printf("\n");

			//勝敗を判定する
			if (player == com) {
				result = 0;                //あいこ
			}
			else if (
				player == 0 && com == 1 ||
				player == 1 && com == 2 ||
				player == 2 && com == 0
				) {
				result = 1;                //勝ち
			}
			else {
				result = 2;                //負け
			}

			//勝敗を表示させる
			printf("結果は・・・");
			if (result == 0) {
				printf("引き分けです!!!\n");
			}
			else if (result == 1) {
				printf("あなたの勝ちです!!!\n");
				streak += 1;
			}
			else {
				printf("あなたの負けです...\n");
				streak = 0;
			}
			printf("\n");
		} while (result == 0);
		printf("つづける：１　おわる：１以外");
		if (streak > 1) {
			printf("\t%d連勝中", streak);
		}
		printf("\nつづけますか：");
		const int n = scanf("%d%1[\n]", &continuity, newline);						//入力時に数値であるかを判定するための変数（2=数値、1=少数or数値＋記号、0=数値として解釈できないもの）
		if (n != 2 || continuity != 1) {
			break;
		}

	} while (true);

	return 0;
}