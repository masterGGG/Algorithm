/*
vlan是一种对局域网进逻辑划分的技术，为了标识不同的VLAN，引入VLAN ID（1-4094）之间的整数的概念。
定义一个VLANID的资源池，池中连续的VLAN用VALN开始-VLAN结束，
不连续的用单个整数表示
所有的VLAN用英文逗号连接起来，现有有个VLAN资源池，业务需要从资源池中申请一个VLAN，
需要你输出从VLAN资源池中移除申请的VLAN资源后的资源池
输入描述：第一行为字符串格式的VLAN资源池，第二行为业务需要申请的VLAN，VLAN取值为（1-4094的整数）
输出描述：输出申请之后 升序的资源池
*/

#include <vector>
#include <string>
#include <iostream>

struct Comp {
  bool operator() (std::pair<int, int> lhs, std::pair<int, int> rhs) {
    return lhs.second < rhs.first;
  }
} comp;

class Solution {
public:
  std::vector<std::pair<int, int> > vec_;

  void parseVlanId(std::string str) {
    int pos = str.find('-');

    if (pos == std::string::npos) {
      int value = atoi(str.c_str());
      vec_.emplace_back(std::pair<int, int>(value, value));

      return ;
    }

    vec_.emplace_back(std::pair<int, int>(atoi(str.c_str() + 4), atoi(str.c_str() + pos + 1)));
  }

  std::string seriliazeVlanPool() {
    std::string str;
    for (auto s : vec_) {
      if (s.first == s.second) {
        str += std::to_string(s.first) + ",";
      } else {
        str += "VLAN" + std::to_string(s.first) + "-" + std::to_string(s.second) + "VLAN,";
      }
    }

    std::cout << "Pool: " << str << std::endl;
    return str;
  }

  void initVlanPool(std::string str) {
    int pos = 0;

    do {
      int tail = str.find(',', pos);
      parseVlanId(str.substr(pos, tail - pos));

      if (tail == std::string::npos) {
        break;
      }

      pos = tail + 1;
    } while (pos < str.length());

    std::sort(vec_.begin(), vec_.end(), comp);

    seriliazeVlanPool();
  }

  void dispatchVlanId(int id) {
    for (auto it = vec_.begin(); it != vec_.end(); ++it) {
      if (id >= it->first && id <= it->second) {
        std::cout << "dispatchVlanId " << id << " from " << it->first << " - " << it->second << std::endl;
        
        if (it->first == it->second) {
          vec_.erase(it);
          break;
        } else if (id == it->first) {
          it->first = id + 1;
          break;
        } else if (id == it->second) {
          it->second = id - 1;
          seriliazeVlanPool();
          break;
        } else {
          int max = it->second;
          it->second = id - 1;
          it++;
          vec_.emplace(it, std::pair<int, int>(id + 1, max));
          break;
        }
      }
    }

    seriliazeVlanPool();
  }
};

//g++ VLAN划分.cpp -o xxx -std=c++11
int main() {
  Solution s;
  s.initVlanPool("1,4,5,VLAN11-20VLAN,10,21,30");
  s.dispatchVlanId(7);
  s.dispatchVlanId(10);
  s.dispatchVlanId(13);
  return 0;
}