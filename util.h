/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: util.h
 *
 * @breaf: 常见小算法的声明
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2017/02/22 10时30分04秒
 *
 **/

// int类型的数转换为C风格的字符串
// 1234 -> "1234"
// -1234 -> "-1234"
const char *Itoa(char buf[], int value);

// 将c风格字符串尽可能多的转换为数字
// [1] "1234" -> 1234
// [2] "+1234" -> 1234
// [3] "-1234" -> -1234
// [4] "    1234" -> 1234 
// [5] "   -1234" -> 1234 
// [6] " ab cd 1234def a" -> 1234 
//
// 注意:算法不支持八进制和十六进制的问题
int Atoi(char buf[]);

// 移除字符串中连续的指定的字符(默认是空格' ')
// 只保留一个空格
// 例如 world   world! -> hello world!
const char *RemoveContinuousSpaces(char *buf, char c = ' ');
// version 2
const char *RemoveContinuousSpaces(std::string &str, char c = ' ');

// 生成全排列的算法
std::vector<std::string> Perm(std::string &);

// 字符串s中长度为m的子串的全排列
std::vector<std::string> Perm(std::string &s, std::size_t m);

char *reverse(char *str, int begin, int end);

void movn(char *str, int pos, int n);
