#include <stdio.h>

#define N 15

void calcElement(int);
int elementDiffCheck(int, int, int, int, int, int[], int[], int[], int);


int main(int argc, char const *argv[])
{
	int target;
	printf("input target -> ");
	scanf("%d",&target);
	calcElement(target);
	printf("finish\n");
	return 0;
}

void calcElement(int target) {
	int bottomFirst, bottomSecond, bottomThird, bottomFourth, bottomFifth, result, i, count = 0;
	int secondLine[4], thirdLine[3], fourthLine[2];

	printf("Calculating...\n");
	for (bottomFirst = 0; bottomFirst < target; bottomFirst++) {
		for (bottomSecond = 0; bottomSecond < target; bottomSecond++) {
			for (bottomThird = 0; bottomThird < target; bottomThird++) {
				for (bottomFourth = 0; bottomFourth < target; bottomFourth++) {
					for (bottomFifth = 0; bottomFifth < target; bottomFifth++) {
						secondLine[0] = bottomFirst + bottomSecond;
						secondLine[1] = bottomSecond + bottomThird;
						secondLine[2] = bottomThird + bottomFourth;
						secondLine[3] = bottomFourth + bottomFifth;
						thirdLine[0] = secondLine[0] + secondLine[1];
						thirdLine[1] = secondLine[1] + secondLine[2];
						thirdLine[2] = secondLine[2] + secondLine[3];
						fourthLine[0] = thirdLine[0] + thirdLine[1];
						fourthLine[1] = thirdLine[1] + thirdLine[2];
						result = fourthLine[0] + fourthLine[1];
						if (result == target) {
							if (elementDiffCheck(bottomFirst, bottomSecond, bottomThird, bottomFourth, bottomFifth, secondLine, thirdLine, fourthLine, result)){
								count++;
								// printf("%d %d %d %d %d\n", bottomFirst, bottomSecond, bottomThird, bottomFourth, bottomFifth);
							}
						}
					}
				}
			}
		}
	}

	if (count == 0) printf("false\n");
	printf("< %d >\n", count);
}

int elementDiffCheck(int bottomFirst, int bottomSecond, int bottomThird, int bottomFourth, int bottomFifth, int secondLine[], int thirdLine[], int fourthLine[], int result)
{
	int i, j, count = 0;
	int checkArray[N] =
		{
			bottomFirst, bottomSecond, bottomThird, bottomFourth, bottomFifth,
			secondLine[0], secondLine[1], secondLine[2], secondLine[3],
			thirdLine[0], thirdLine[1], thirdLine[2],
			fourthLine[0], fourthLine[1],
			result
		};

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (checkArray[i] == checkArray[j] && i != j) return 0;
		}
	}
	return 1;
}
