#include "test.pb.h"
#include <string>
#include <iostream>
using namespace fixbug;

int main()
{
    // LoginResponse rsp;
    // ResultCode *rc = rsp.mutable_result();
    // rc->set_errcode(1);
    // rc->set_errmsg("登录失败");
    // rc->set_success(false);

    GetFriendListResponse rsp;
    ResultCode *rc = rsp.mutable_result();
    rc->set_errcode(0);
    
    User *user = rsp.add_friend_list();
    user->set_name("zhangsan");
    user->set_age(18);
    user->set_sex(User::MALE);
 
    User *user2 = rsp.add_friend_list();
    user2->set_name("zhangsi");
    user2->set_age(11);
    user2->set_sex(User::MALE);

    std::cout << rsp.friend_list_size() << std::endl;

    

    return 0;
}






int main1()
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