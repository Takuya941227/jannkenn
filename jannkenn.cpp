#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main(void) {
	printf("����񂯂�v���O����\n");
	/*** �ϐ���` ***/
	int player = 0;									//�v���C���[�̎�
	int com = 0;									//�R���s���[�^�̎�
	int result = 0;									//���s����
	int streak = 0;									//�A���L�^
	int continuity = 0;								//�����t���O
	char newline[2];								//���l�`�F�b�N�p
	srand((unsigned int)time(NULL));				//�����_���V�[�h
	
	/*** ���s���� ***/
	//�Â����I�ׂΌJ��Ԃ�
	do {
		//�������ł���ΌJ��Ԃ�
		do {
			//�v���C���[���o��������(���������͂�����܂ŌJ��Ԃ�)
			do	{
				printf("�O�[�F1�@�`���L�F2�@�p�[�F3\n");
				printf("���Ȃ��̏o�������͂��Ă��������F");
				const int m = scanf("%d%1[\n]", &player, newline);					//���͎��ɐ��l�ł��邩�𔻒肷�邽�߂̕ϐ��i2=���l�A1=����or���l�{�L���A0=���l�Ƃ��ĉ��߂ł��Ȃ����́j
				if (m != 2) {
					(void)scanf("%*[^\n]");
					printf("�K��O�̓��͂ł� ������x���͂��Ă�������\n\n");
				}
				else if (player > 3 || player <= 0) {
					printf("�K��O�̓��͂ł� ������x���͂��Ă�������\n\n");
				}
				else {
					player -= 1;													//�f�[�^�ł̊Ǘ���0,1,2�̂ق����Ǘ����₷���̂Œ���
					break;
				}
			} while (true);

			//�R���s���[�^�[���o������쐬
			com = rand() % 3;

			//���͂������\��
			printf("���Ȃ����o������F");
			if (player == 0) {
				printf("�O�[\n");
			}
			else if (player == 1) {
				printf("�`���L\n");
			}
			else if (player == 2) {
				printf("�p�[\n");
			}

			printf("�b�o�t���o������F");
			if (com == 0) {
				printf("�O�[\n");
			}
			else if (com == 1) {
				printf("�`���L\n");
			}
			else if (com == 2) {
				printf("�p�[\n");
			}
			printf("\n");

			//���s�𔻒肷��
			if (player == com) {
				result = 0;                //������
			}
			else if (
				player == 0 && com == 1 ||
				player == 1 && com == 2 ||
				player == 2 && com == 0
				) {
				result = 1;                //����
			}
			else {
				result = 2;                //����
			}

			//���s��\��������
			printf("���ʂ́E�E�E");
			if (result == 0) {
				printf("���������ł�!!!\n");
			}
			else if (result == 1) {
				printf("���Ȃ��̏����ł�!!!\n");
				streak += 1;
			}
			else {
				printf("���Ȃ��̕����ł�...\n");
				streak = 0;
			}
			printf("\n");
		} while (result == 0);
		printf("�Â���F�P�@�����F�P�ȊO");
		if (streak > 1) {
			printf("\t%d�A����", streak);
		}
		printf("\n�Â��܂����F");
		const int n = scanf("%d%1[\n]", &continuity, newline);						//���͎��ɐ��l�ł��邩�𔻒肷�邽�߂̕ϐ��i2=���l�A1=����or���l�{�L���A0=���l�Ƃ��ĉ��߂ł��Ȃ����́j
		if (n != 2 || continuity != 1) {
			break;
		}

	} while (true);

	return 0;
}