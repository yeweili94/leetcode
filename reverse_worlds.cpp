#include <string>
#include <vector>
#include <iostream>

void reverse(std::string &str, int slow, int fast) {
    while (slow <= fast ) {
        char temp = str[slow];
        str[slow] = str[fast];
        str[fast] = temp;
        slow++;
        fast--;
    }
}

int main() {
    std::string str = "the sky is blue";
    std::cout << "before the reverse:" << std::endl;
    std::cout << str << std::endl;
    int size = str.size();
    reverse(str, 0, size - 1);
    int slow = 0, fast = 0;
    while (slow < size) {
        if (fast < size && str[fast] == ' ' && str[slow] == ' ') {
            fast++;
            slow++;
        }
        else if (fast >= size || str[fast] == ' ') {
            fast--;
            reverse(str, slow, fast);
            fast++;
            slow = fast;
        }
        else {
            fast++;
        }
    }
    std::cout << "after the reverse:" << std::endl;
    std::cout << str << std::endl;
}
