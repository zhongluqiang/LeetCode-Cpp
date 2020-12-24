#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1114 lang=cpp
 *
 * [1114] 按序打印
 */

// @lc code=start
class Foo {
    pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_t mutex3 = PTHREAD_MUTEX_INITIALIZER;
public:
    Foo() {
        pthread_mutex_lock(&mutex2);
        pthread_mutex_lock(&mutex3);
    }

    void first(function<void()> printFirst) {
        pthread_mutex_lock(&mutex1);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        pthread_mutex_unlock(&mutex2);
    }

    void second(function<void()> printSecond) {
        pthread_mutex_lock(&mutex2);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        pthread_mutex_unlock(&mutex3);
    }

    void third(function<void()> printThird) {
        pthread_mutex_lock(&mutex3);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        pthread_mutex_unlock(&mutex1);
    }
};
// @lc code=end

