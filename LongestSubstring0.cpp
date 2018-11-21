#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int longestLength(0);
                                                            //begin成员返回指向第一个元素的迭代器，end成员返回指向尾元素的下一位置的迭代器
    for(auto iter1 = s.begin(); iter1 < s.end(); ++iter1) { //auto简化声明
                                                            //iter + n：与原来相比向前移动若干个元素
                                                            //find：指向首元素的迭代器，指向尾元素的下一个位置的迭代器，给定值
                                                            //搜索成功，返回指向第一个等于给定值的元素的迭代器；失败，返回第二个参数
        auto iter2 = find(iter1+1, s.end(), *iter1);
       
        auto iter3 = iter1+1;
        while(iter3 < iter2 ) {
            auto iter2Temp = find(iter3+1, iter2, *iter3);
            if(iter2Temp < iter2){
                iter2 = iter2Temp;
                ++iter3;
            }else if(iter2Temp == iter2){
                ++iter3;
            }
        }
        int length = iter3 - iter1;
        if(length > longestLength)
            longestLength = length;
    }
    return longestLength;
}
int main() {
    string str("pwwkew");
    int maxLength = lengthOfLongestSubstring(str);
    cout << maxLength;
    return 0;
}
