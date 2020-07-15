#include <stdio.h>
#include <string.h>

//MrHaddis
//https://github.com/MrHaddis/PAT1028

//定义一个结构体
struct People {
    char name[6];
    char time[11];
};

int main() {
    //定义一下年龄的最大时间 和 最小时间
    char minTime[11] = "1814/09/06";
    char maxTime[11] = "2014/09/06";
    //记录数量
    int number;
    //记录符合要求的数字
    int index = 0;
    scanf("%d", &number);
    //定义一个年龄最大的数据
    struct People peopleBig;
    //定义一个年龄最小的数据
    struct People peopleSmall;
    //循环获取数据
    for (int i = 0; i < number; ++i) {
        struct People people;
        scanf("%s %s", &people.name, &people.time);
        //strcmp函数用于比较两个字符串并根据比较结果返回整数。
        // 基本形式为strcmp(str1,str2)，若str1=str2，则返回零；
        // 若str1<str2，则返回负数；若str1>str2，则返回正数。 [1-2]
        if (strcmp(people.time, minTime) >= 0 && strcmp(maxTime, people.time) >= 0) {
            //第一次有效值的时候 初始化赋值
            if (index == 0) {
                peopleBig = peopleSmall = people;
            }
            //有效值次数加一
            index++;
            //如果输入数据的时间 数值上小于 当前的最大年龄的时间
            //那么说明 这个值对应的年龄值是大于当前的最大年龄
            //那么刷新最大年龄对象
            if (strcmp(people.time, peopleBig.time) <= 0) {
                peopleBig = people;
            } else if (strcmp(peopleSmall.time, people.time) <= 0) {
                //如果小于等于0 那么说明当前的最小年龄时间值 不是最小的
                //刷新最小年龄对象
                peopleSmall = people;
            }
        }
    }
    //index 为0 时则没有符合规则的值
    if (index > 0) {
        printf("%d %s %s", index, &peopleBig.name, &peopleSmall.name);
    } else {
        printf("%d", index);
    }
    return 0;
}
