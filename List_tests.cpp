// Project UID c1f28c309e55405daf00c565d57ff9ad

#include "List.h"
#include "unit_test_framework.h"

using namespace std;

// Add your test cases here

TEST(test_stub) {
    // Add test code here
    ASSERT_TRUE(true);
    
}
TEST(test_list_default_ctor_string) {
    List<string> empty_list;
    ASSERT_TRUE(empty_list.empty());
}

//TEST(test_list_default_ctor_string) {
//    List<int> empty_list;
//    ASSERT_TRUE(0, empty.size);
//}

TEST(test_list_default_ctor_double) {
    List<double> empty_list;
    ASSERT_TRUE(empty_list.empty());
}

TEST(test_list_default_ctor_bool) {
    List<bool> empty_list;
    ASSERT_TRUE(empty_list.empty());
}
TEST(test_list_default_ctor3) {
    List<int> test;
    test.push_front(20);
    ASSERT_FALSE(test.empty());
}

//TEST SIZE OF LIST IS CORRECT AFTER A LOT OF FUNCTION CALLS

TEST(test_size_of_list){
    List<int> my_list;

    my_list.empty();
    my_list.size();
    ASSERT_EQUAL(my_list.size(), 0);
    
    my_list.push_front(42);
    my_list.push_back(42);
    ASSERT_EQUAL(my_list.size(), 2);
    
    my_list.front() = 73;
    my_list.back() = 73;
    ASSERT_EQUAL(my_list.front(), 73);
    ASSERT_EQUAL(my_list.back(), 73);
    
    my_list.pop_front();
    my_list.pop_back();
    ASSERT_TRUE(my_list.empty());
}

TEST(test_size_of_list_not_empty){
    List<int> my_list;

    my_list.empty();
    my_list.size();

    my_list.push_front(42);
    my_list.push_back(42);

    my_list.front() = 73;
    my_list.back() = 73;


    ASSERT_TRUE(!my_list.empty());
    ASSERT_EQUAL(my_list.size(), 2);
}

TEST(test_list) {
    List<int> my_list;
    my_list.push_front(2);
    my_list.push_back(73);
    my_list.pop_back();
    ASSERT_TRUE(my_list.size() == 1);

}
TEST(test_list_2) {
    List<int> test;
    test.push_front(10);
    test.push_back(3);
    ASSERT_TRUE(test.back() == 3);
    
}
TEST(test_list3) {
    List<int> my_list;
    my_list.push_front(22);
    my_list.push_back(99);
    my_list.pop_front();
    ASSERT_FALSE(my_list.size() != 1);

}


//TEST FRONT AND BACK RETURNS CORRECT INFO

TEST(test_front_return){
    List<int> my_list;
    
    my_list.empty();
    my_list.size();

    my_list.push_front(42);
    my_list.push_back(42);

    my_list.front() = 73;
    my_list.back() = 73;
    
    ASSERT_EQUAL(my_list.front(), 73);
    my_list.clear();
}

TEST(test_back_return){
    List<int> my_list;

    my_list.empty();
    my_list.size();

    my_list.push_front(42);
    my_list.push_back(42);

    my_list.front() = 73;
    my_list.back() = 12;
    
    ASSERT_EQUAL(my_list.back(), 12);
    my_list.clear();
}



//PUSH FRONT AND PUSH BACK

TEST(test_push_front){
    List<int> my_list;
    
    my_list.empty();
   

    my_list.push_front(42);
    my_list.push_front(1);
    my_list.push_front(298);
    my_list.push_front(-40000);
    my_list.push_front(23);
    
    ASSERT_EQUAL(my_list.front(), 23);
}

TEST(test_push_back){
    List<int> my_list;
    
    my_list.empty();
   

    my_list.push_back(42);
    my_list.push_back(1);
    my_list.push_back(298);
    my_list.push_back(-40000);
    
    ASSERT_EQUAL(my_list.back(), -40000);
    my_list.clear();
}

//POP FRONT AND POP BACK
TEST(test_pop_front){
    List<int> my_list;
    
    my_list.empty();
    my_list.size();

    my_list.push_front(42);
    my_list.push_front(429);
    my_list.push_front(4895479);
    
    my_list.push_back(12);
    my_list.push_back(9);

    my_list.pop_front();
    my_list.pop_front();
    
    ASSERT_EQUAL(my_list.front(), 42);
}

TEST(test_pop_back){
    List<int> my_list;
    
    my_list.empty();
    my_list.size();

    my_list.push_front(42);
    my_list.push_front(429);
    my_list.push_front(4895479);
    
    my_list.push_back(12);
    my_list.push_back(9);

    my_list.pop_back();
    
    
    ASSERT_EQUAL(my_list.back(), 12);
}

//CLEAR
TEST(test_clear){
    List<int> my_list;
    
    my_list.empty();
    my_list.size();

    my_list.push_front(42);
    my_list.push_front(429);
    my_list.push_front(4895479);
    
    my_list.push_back(12);
    my_list.push_back(9);

    my_list.pop_front();
    my_list.pop_back();

    my_list.clear();
    
    ASSERT_TRUE(my_list.empty());
}

TEST(test_clear_more){
    List<int> my_list;
    
    my_list.empty();
    my_list.size();

    my_list.push_front(42);
    my_list.push_front(429);
    my_list.push_front(4895479);
    
    my_list.push_back(12);
    my_list.push_back(9);

    my_list.push_back(128);
    my_list.push_back(79);
    
    my_list.push_front(42);
    my_list.push_front(429);
    my_list.push_front(4895479);

    my_list.clear();
    
    ASSERT_TRUE(my_list.empty());
}
TEST(test_insert){
    List<int> my_list;
    
    my_list.empty();
    my_list.size();

    my_list.push_front(42);
    my_list.push_front(429);
    my_list.push_front(4895479);
    
    my_list.push_back(12);
    my_list.push_back(9);

    List<int>::Iterator a = my_list.begin();
    const int z = 2;
    my_list.insert(a, z);
    a = my_list.begin();
    ++a;
    ++a;
    my_list.insert(a, z);
    a = my_list.end();
    my_list.insert(a, z);
    a = my_list.begin();
    ASSERT_EQUAL(*a, 2);
    ++a;
    ASSERT_EQUAL(*a, 4895479);
    ++a;
    ASSERT_EQUAL(*a, 2);
    ++a;
    ASSERT_EQUAL(*a, 429);
    ++a;
    ASSERT_EQUAL(*a, 42);
    ++a;
    ASSERT_EQUAL(*a, 12);
    ++a;
    ASSERT_EQUAL(*a, 9);
    ++a;
    ASSERT_EQUAL(*a, 2);
    
    ASSERT_EQUAL(my_list.front(), 2);
    ASSERT_EQUAL(my_list.back(), 2);


    my_list.clear();
    
}

TEST(test_compile){
    List<int> my_list;

    my_list.empty();
    my_list.size();

    my_list.push_front(42);
    my_list.push_back(42);

    my_list.front() = 73;
    my_list.back() = 73;

    my_list.pop_front();
    my_list.pop_back();

    List<int> list2(my_list);
    list2 = my_list;

    List<int>::Iterator iter = my_list.begin();
    my_list.insert(iter, 42);
    iter = my_list.begin();
    my_list.erase(iter);
    iter = my_list.begin();

    List<int>::Iterator iter2 = my_list.end();
    const List<int>::Iterator iter3 = iter2;
    

    bool b = iter == iter2;
    ASSERT_TRUE(iter == iter2);
    
    b = iter3 == my_list.end();
    b = my_list.end() == iter3;
    my_list.push_front(42);
    my_list.push_back(42);
    iter = my_list.begin();
    b = iter != iter2;
    b = iter3 != my_list.end();
    b = my_list.end() != iter3;
    ++iter;

    List<int>::Iterator iter_cpy(iter);
    iter_cpy = iter;

    my_list.insert(my_list.begin(), 3);
    ASSERT_EQUAL(my_list.front(), 3);
    
    my_list.erase(my_list.begin());
    
    List<int> list3;
    list3.push_back(3);

    List<int> list4;
    list4.push_back(4);
  
    ASSERT_EQUAL( list4.back(), 4);
    ASSERT_EQUAL( list3.back(), 3);
    
    my_list.clear();
}
TEST_MAIN()
