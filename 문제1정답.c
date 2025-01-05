// 문제 1 정답

#include <stdio.h>

int main(void) {
    char * names[] = {
        "KIM",
        "LEE",
        "PARK",
        "SONG",
        "CHOI"
    };
    int earnings[5][4]; // 5명의 4분기 실적을 저장할 2차원 배열

    for (int i = 0; i < 5; i++) {
        printf("%s의 판매실적을 입력하세요 (1/4, 2/4, 3/4, 4/4): ", names[i]);

    // 4개의 실적 입력
        for (int j = 0; j < 4; j++) {
            scanf("%d", & earnings[i][j]);
        }
    }

    printf("====================================================================\n");
    printf("%-10s %10s %10s %10s %10s %10s\n", "판매사원", "1/4분기", "2/4분기", "3/4분기", "4/4분기", "총합");
    printf("====================================================================\n");

    int q1Sum = 0, q2Sum = 0, q3Sum = 0, q4Sum = 0;

    for (int i = 0; i < 5; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            sum += earnings[i][j];
            if (j == 0) q1Sum += earnings[i][j];
            else if (j == 1) q2Sum += earnings[i][j];
            else if (j == 2) q3Sum += earnings[i][j];
            else if (j == 3) q4Sum += earnings[i][j];
        }
        printf("%-10s %10d %10d %10d %10d %10d\n", names[i], earnings[i][0], earnings[i][1], earnings[i][2], earnings[i][3], sum);
    }

    int totalSum = q1Sum + q2Sum + q3Sum + q4Sum;

    printf("====================================================================\n");
    printf("%-10s    %10d %10d %10d %10d %10d\n", "분기총합", q1Sum, q2Sum, q3Sum, q4Sum, totalSum);
    printf("====================================================================\n");
    printf("%-10s    %10.2f %10.2f %10.2f %10.2f %10.2f\n", "분기평균", (double) q1Sum / 5, (double) q2Sum / 5, (double) q3Sum / 5, (double) q4Sum / 5, (double) totalSum / 5);
    printf("====================================================================\n");


    double yearlyAvg = (double)totalSum / 5;
    double q1Avg = (double)q1Sum / 5;
    double q2Avg = (double)q2Sum / 5;
    double q3Avg = (double)q3Sum / 5;
    double q4Avg = (double)q4Sum / 5;
    // 별표 개수 계산
    int q1Stars = (int)((q1Avg * 100 / yearlyAvg) / 10);
    int q2Stars = (int)((q2Avg * 100 / yearlyAvg) / 10);
    int q3Stars = (int)((q3Avg * 100 / yearlyAvg) / 10);
    int q4Stars = (int)((q4Avg * 100 / yearlyAvg) / 10);

  // 출력
    printf("분기별 판매실적 그래프\n");
    printf("====================================================================\n");

    // y축 값부터 시작하여 세로로 출력
    int maxStars = (q1Stars > q2Stars ? (q1Stars > q3Stars ? (q1Stars > q4Stars ? q1Stars : q4Stars) : (q3Stars > q4Stars ? q3Stars : q4Stars)) : (q2Stars > q3Stars ? (q2Stars > q4Stars ? q2Stars : q4Stars) : (q3Stars > q4Stars ? q3Stars : q4Stars)));

    for (int i = maxStars; i > 0; i--) {
        printf("%4d | ", i * 10); // y축 값 표시
        printf("%-6s", (q1Stars >= i) ? "*" : " "); // 1/4분기
        printf("%-6s", (q2Stars >= i) ? "*" : " "); // 2/4분기
        printf("%-6s", (q3Stars >= i) ? "*" : " "); // 3/4분기
        printf("%-6s", (q4Stars >= i) ? "*" : " "); // 4/4분기
        printf("\n");
    }

    // x축 및 분기 레이블 추가
    printf("     +-------------------------------------------------\n");
    printf("%4s | ", ""); // y축 값 표시
        printf("%-6s", "1/4"); // 1/4분기
        printf("%-6s", "2/4"); // 2/4분기
        printf("%-6s", "3/4"); // 3/4분기
        printf("%-6s", "4/4"); // 4/4분기
    printf("\n");

  return 0;

}

