#include <iostream>
#include <string>
#include <vector> 

using namespace std;

vector<char> seriliaze(string s) {
    vector<char> src;
    src.emplace_back('#');
    src.emplace_back('_');

    for (auto c : s) {
        src.emplace_back(c);
        src.emplace_back('_');
    }

    src.emplace_back('!');

    cout << "SRC - " << s << endl << "SER - " << endl;
    for (auto i : src) {
        cout << i << " ";
    }
    cout << endl;

    return src;
}

int getPalindromeNum(vector<char> arr, int pos, int i, int count) {
    while (pos - i > 0 && pos + i < arr.size()) {
        if (arr[pos - i] == arr[pos + i]) {
            count++;
            i++;
        } else {
            break;
        }
    }

    return count;
}

string manacher_Impl(string str) {
    vector<char> arr = seriliaze(str);
    vector<int> vec(arr.size(), 0);

    int center = -1;
    int right = -1;
    int maxPalindrome = 0;
    int maxIndex;

    for (int i = 0; i < arr.size(); ++i) {
        if (i >= right) {
            vec[i] = getPalindromeNum(arr, i, 1, 1);
            center = i;
            right = i + vec[i] - 1;
        } else {
            vec[i] = vec[center * 2 - i];
            int newright = i + vec[i] - 1;

            if (newright == right) {
                vec[i] = getPalindromeNum(arr, i, right - i, right - i + 1);
                newright = i + vec[i] - 1;

                if (newright >= right) {
                    center = i;
                    right = newright;
                }
            } else if (newright > right) {
                vec[i] = right - i + 1;
            }
        }

        if (vec[i] > maxPalindrome) {
            maxPalindrome = vec[i];
            maxIndex = i;
        }
    }

    for (auto i : vec) {
        cout << i << " ";
    }
    cout << endl;


    int realLength = maxPalindrome;
    int realIndex = maxIndex / 2 - maxPalindrome / 2;
    cout << "maxIndex " << maxIndex << " maxPalindrome " << maxPalindrome << " realIndex " << realIndex << " realLength " << realLength << endl;

    return str.substr(realIndex, realLength);
}

string manacher(string s) {
    if (s.length() <= 1) {
        return s;
    }

    vector<char> src = seriliaze(s);
    vector<int> mnc(src.size(), 0);
    int center = 0;
    int right = -1;
    int maxIndex = -1;
    int maxRadio = -1;

    for (int i = 1; i < src.size() - 1; ++i) {
        if (i < right) {
            mnc[i] = mnc[2 * center - i] > right - i ? right - i : mnc[2 * center - i];
        } else {
            mnc[i] = 1;
        }

        while (src[i + mnc[i]] == src[i - mnc[i]]) {
            mnc[i]++;
        }

        if (i + mnc[i] > right) {
            right = i + mnc[i];
            center = i;
        }

        if (mnc[i] - 1 > maxRadio) {
            maxRadio = mnc[i] - 1;
            maxIndex = maxRadio % 2 == 0 ? 1 : 0;
            maxIndex += i / 2 - 1 - maxRadio / 2;
            cout << i << " maxRadio:" << maxRadio << " maxIndex:" << maxIndex << endl;
        }
    }

    cout << "MNC - " << endl;
    for (auto i : mnc) {
        cout << i << " ";
    }
    cout << endl;

    return s.substr(maxIndex, maxRadio);
}

//rm manacher.cpp && rz && g++ manacher.cpp  -o xxx -std=c++11 && ./xxx
int main() {
    cout << manacher("abccbahopxpo") << endl;

    cout << manacher("abbahopxpo") << endl;

    cout << manacher("abax") << endl;
    return 0;
}