#include<stdio.h>
#include<string.h>

int judge(int a) {
    //判断是否为质数
    if (a == 1 || a == 0)
        return 0;
    for (int i = 2; i < a; i++) {
        if (a % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int i = 0;
    char str[100];
    gets(str);
    int letter[26] = {0};
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z')
            letter[str[i] - 'a']++;
        i++;
    }
    int max = 0, min = 100;
    for (i = 0; i < 26; i++) {
        if (letter[i] == 0)
            continue;
        max = letter[i] > max ? letter[i] : max;
        min = letter[i] < min ? letter[i] : min;
    } //计算最大值和最小值
    int a = max - min;
    if (judge(a)) {
        printf("Lucky Word\n");
        printf("%d", a);
    } else {
        printf("No Answer\n");
        printf("%d", 0);
    }
    return 0;
}