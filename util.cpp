/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: util.h
 *
 * @breaf:  常见算法的实现
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2017/02/22 10时30分04秒
 *
 **/


#include <algorithm>
#include <cctype>
#include <string>
#include <vector>

const char *Itoa(char buf[], int value) {
    static char digits[19] = {
        '9', '8', '7', '6', '5', '4', '3', '2', '1', '0',
        '1', '2', '3', '4', '5', '6', '7', '8', '9'
    };
    static const char *zero = digits + 9;

    char *p = buf;
    int i = value;
    do {
        int lsd = i % 10;
        i /= 10;
        *p++ = zero[lsd];
    } while (i != 0);
    if (value < 0) {
        *p++ = '-';
    }
    *p = '\0';

    std::reverse(buf, p);

    return buf;
}

int Atoi(char buf[]) {
    char *p = buf;
    int value = 0;
    int sig = 1;
    // trim whilespaces at front of string buf
    while (isspace(*p)) ++p;
    while (!isdigit(*p) && *p != '+' && *p != '-') ++p;
    if (*p == '-') {
        sig = -1;
        ++p;
    } else if (*p == '+') {
        ++p;
    }

    while (::isdigit(*p)) {
        value = value * 10;
        value += *p - '0';
        ++p;
    }

    return sig * value;
}

const char *RemoveContinuousSpaces(char *buf, char c) {
    char *p = buf;
    char *q = p + 1;
    // skip begin
    while (!(*p == c && *q == c)) {
        ++p;
        ++q;
    }
    while (*q != '\0') {
        if (!(*p == c && *q == c)) {
            *(++p) = *q;
        }
        ++q;
    }
    *(++p) = '\0';
    
    return buf;
}

// version 2
const char *RemoveContinuousSpaces(std::string &str, char c) {
    std::string::iterator uniq_iter = std::unique(str.begin(), str.end(),
            [c](const char &c1, const char &c2) {
            return (c1 == c && c2 == c);
            });
    str.erase(uniq_iter, str.end());

    return str.c_str();
}

std::vector<std::string> Perm(std::string &s) {
    std::vector<std::string> perms;
    std::sort(s.begin(), s.end());
    do {
        perms.push_back(s);
    } while (std::next_permutation(s.begin(), s.end()));

    return perms;
}

std::vector<std::string> Perm(std::string &s, std::size_t m) {
    std::vector<std::string> perms;
    if (m > s.size()) {
        return perms;
    }
    std::sort(s.begin(), s.end());
    std::string substr;
    do {
        substr = s.substr(0, m);
        auto it = std::find(perms.begin(), perms.end(), substr);
        if (it == perms.end()) {
            perms.push_back(substr);
        }
    } while (std::next_permutation(s.begin(), s.end()));

    return perms;
}


char *reverse(char *str, int begin, int end) {
    char *p = str + begin;
    char *q = str + end;
    while (p < q) {
        std::swap(*p, *q);
        ++p;
        --q;
    }
    return str;
}

void movn(char *str, int pos, int n) {
    int epos = strlen(str);
    for (int i = epos; i >= pos; i--) {
        str[i + n] = str[i];
    }

    for (int i = pos; i < pos + n; ++i) {
        str[i] = '_';
    }
}

char *ReplaceSpace(char *str, uint32_t len) {
    uint32_t space_count = 0;
    for (int i = 0; i < len; ++i) {
        if (str[i] == ' ') ++space_count;
    }

    uint32_t new_len = len + 2 * space_count;
    int i = len - 1;
    int j = new_len - 1;
    while (j >= 0 && j >= 0) {
        if (str[i] == ' ') {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
            i--;
        } else {
            str[j--] = str[i--];
        }
    }

    str[new_len] = '\0';

    return str;
}

