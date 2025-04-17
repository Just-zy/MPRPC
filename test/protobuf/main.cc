#include "test.pb.h"
#include <string>
#include <iostream>
using namespace fixbug;

int main()
{
    LoginRequest req;
    req.set_name("zhangsan");
    req.set_pwd("123456");

    std::string send_str;
    if (req.SerializeToString(&send_str))
    {
        std::cout << send_str.c_str() << std::endl;
    }
    // g++ main.cc test.pb.cc -lprotobuf

    // 反序列化
    LoginRequest reqB;
    if (reqB.ParseFromString(send_str))
    {
        std::cout << reqB.name() << std::endl;
        std::cout << reqB.pwd() << std::endl;
    }

    return 0;
}