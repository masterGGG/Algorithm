/*
求麻将清一色和牌问题
题目
题目描述：
清一色是麻将番种之一，指由一种花色的序数牌组成的和牌.
数字1-9，每个数字最多有4张牌
我们不考虑具体花色，我们只看数字组合。
刻子：三张一样的牌；如: 111, 222, 333, …, 999
顺子：三张连续的牌；如: 123, 234, 345, …, 789
对子：两张相同的牌；如: 11, 22, 33, …, 99
需要实现一个程序，判断给定牌，是否可以和牌（胡牌）。
和牌要求：

麻将牌张数只能是 2, 5, 8, 11, 14
给定牌可以组合成，除1个对子以外其他都是刻子或顺子
举例： - “11” -> “11”, 1对子，可以和牌
“11122233” -> “111”+“222”+“33”, 2刻子，1对子，可以
“11223344567” -> “11”+“234”+“234”+“567”, 1对子，3顺子，可以
-> “123”+“123”+“44”+“567”, 另一种组合，也可以
输入描述:
合法C字符串，只包含’1’-‘9’，且已经按从小到大顺序排好；字符串长度不超过15。同一个数字最多出现4次，与实际相符。
输出描述:
C字符串，“yes"或者"no”
示例1
输入
2244
输出
24 //此处是试题原本模样,应该输出no
*/
#include <iostream>
#include <vector>

bool isWin(std::vector<int> vec, int pos, int len);

/*
 * 获取指定值的牌所在的位置，不存在返回-1
 */
int getIndex(std::vector<int> vec, int pos, int key) {
  if (pos < 1) {
    return -1;
  }

  while (pos < vec.size()) {
    if (vec[pos] == key) {
      return pos;
    }

    pos++;
  }

  return -1;
}

/*
 * 2. 去除当前位置值的有效顺子，无效则返回false
 */
bool siftOrder(std::vector<int> vec, int pos, int len) {
  if (len == 3) {
    //  2.1 刚好只剩当前顺子，能胡牌，返回true
    return vec[pos + 1] == vec[pos] + 1 && vec[pos + 2] == vec[pos] + 2;
  } else if (len > 3) {
    int first = pos, second, third;
    second = getIndex(vec, pos + 1, vec[pos] + 1);
    third = getIndex(vec, second + 1, vec[pos] + 2);

    if (third == -1) {
      // 2.2 当前位置无法形成有效顺子，不能胡牌，返回false
      // 例如: 1,3,4;  2,3,5
      return false;
    }

    // 移除有效顺子
    //          |->................->| 
    //          |      |->................->|          
    //          |      |              ->................->|   
    //          |      |             |      V             V        
    //   2      2      2      3      3      3      4      4
    //   |                    |                    |
    // first                second               third
    vec[third] = vec[second];
    vec[second] = vec[pos];
    vec[second + 1] = vec[pos];

    // 2.3 当前位置形成有效顺子，检查剩余序列
    return isWin(vec, pos + 3, len - 3);
  }
  
  return false;
}

/*
 * 1. 去除当前位置值的有效刻字，无效则返回false
 */
bool siftTriple(std::vector<int> vec, int pos, int len) {
  if (len > 2 && vec[pos] == vec[pos + 2]) {
    // 存在有效刻字，此时存在两种情况：
    //  1.1 刚好只剩当前刻字，能胡牌，返回true
    //  1.2 还有剩余序列，检查剩余序列
    return len == 3 ? true : isWin(vec, pos + 3, len - 3);
  }

  return false;
}

/*
 * 3. 去除当前位置值的有效对字，无效则返回false
 */
bool siftPair(std::vector<int> vec, int pos, int len) {
  if (len > 1 && vec[pos + 1] == vec[pos]) {
    // 存在有效对子，此时存在两种情况：
    //  3.1 刚好只剩当前对子，能胡牌，返回true
    //  3.2 还有剩余序列，检查剩余序列
    return len == 2 ? true : isWin(vec, pos + 2, len - 2);
  }

  return false;
}

bool isWin(std::vector<int> vec, int pos, int len) {
  //从当前序列中去除一个有效序列，再对剩下来的序列进行有效性检验
  //其中有效序列共分为三种情况：
  //  1. 去除当前位置值的有效刻字，无效则返回false
  //  2. 去除当前位置值的有效顺子，无效则返回false
  //  3. 去除当前位置值的有效对字，无效则返回false
  return siftTriple(vec, pos, len) || siftOrder(vec, pos, len) || siftPair(vec, pos, len);
}

bool isWin(std::vector<int> vec) {
  if (vec.size() != 2 && vec.size() != 5 && vec.size() != 8 && 
      vec.size() != 11 && vec.size() != 14) {
#ifdef DEBUG
    std::cout << "Invalid len " << vec.size() << " (must 2/5/8/11/14): " << std::endl;
#endif
    return false;
  }

#ifndef DEBUG
  return isWin(vec, 0, vec.size());
#else
  std::cout << "current serilization ";
  for (auto i : vec) {
    std::cout << i << " ";
  }

  if (isWin(vec, 0, vec.size())) {
    std::cout << "Winner!" << std::endl;
    return true;
  }

  std::cout << "Loser!" << std::endl;
  return true;
#endif
}

//g++ 麻将胡牌.cpp -o xxx -std=c++11 -DDEBUG
int main() {
  isWin({2, 2, 4, 4});
  isWin({2, 2, 4, 4, 4});
  isWin({1,1,1,2,2,2,3,3});
  isWin({1,1,2,2,3,3,4,4,5,6,7});
  isWin({1,2,3,4,4,5,6,7});
  isWin({1,3,4,5,5});
  isWin({1,1,1,3,4,5,6, 9});
  return 0;
}