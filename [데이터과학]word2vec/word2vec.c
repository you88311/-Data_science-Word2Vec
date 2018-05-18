#define _CRT_SECURE_NO_WARNINGS
#define VOCAB_CNT 1000000
#define MIN_LIMIT 2

#include <stdio.h>
#include <string.h>

typedef struct vocab_set{
	int total_cnt;
	char name[VOCAB_CNT][17];
	int cnt[VOCAB_CNT];
}Vocab_set;

typedef struct vector {
	char one_hot[VOCAB_CNT];
}Vector;

int main(void) {
	Vocab_set v_set;
	Vector vec;
	v_set.total_cnt = 0;
	int i = 0;
	int is_eof = 0;
	memset(v_set.name, NULL, sizeof(v_set.name) / sizeof(char));
	memset(v_set.cnt, 0, sizeof(v_set.cnt) / sizeof(int));
	memset(vec.one_hot, 0, sizeof(vec.one_hot) / sizeof(char));
	is_eof = EOF;
	if (is_eof)
		printf("된다");

	FILE* fp = NULL;
	fp = fopen("./real_vocab_set_sorted.txt", "rt");
	if (fp == NULL) {
		printf("파일 불러오기 실패\n");
		return 0;
	}
	else
		printf("파일 불러오기 성공\n");


	i = 0;
	int a = 0;
	while(1){
		is_eof = fscanf(fp, "%s %d", v_set.name[i], &v_set.cnt[i]);
		if (is_eof)
			break;
		if (v_set.cnt[i] >= MIN_LIMIT) {
			v_set.total_cnt += 1;
			/*
			printf("%d: ", i);
			printf(" %s %d\n", v_set.name[i], v_set.cnt[i]);
			*/
			i++;
		}
	}
	
	for (i = 0; i < 100; i++) {
		printf("vocab: %s cnt: %d \n", v_set.name[i], v_set.cnt[i]);
	}
	printf("1: CBOW  2: Skip - Gram\n");
	//scanf()
	
	return 0;
}