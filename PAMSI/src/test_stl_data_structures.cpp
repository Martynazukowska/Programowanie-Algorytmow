#include "catch2/catch.hpp"

#include <list>
#include <queue>
#include <stack>


using namespace std::string_literals;
TEST_CASE("Stl_List/pushFront")
{
    std::list<int> list;

    list.push_front(1);
    list.push_front(2);

    std::list<int>::iterator Iterator;
    Iterator=list.begin(); //iterator na miejscu 0
    REQUIRE(*Iterator == 2);
    advance(Iterator,1); //przenies iterator na 1 miesce 
    REQUIRE(*Iterator == 1);
}

TEST_CASE("Stl_List/pushBack")
{
    std::list<int> list;

    list.push_back(1);
    list.push_back(2);
    std::list<int>::iterator Iterator;
    Iterator=list.begin();
    REQUIRE(*Iterator == 1);
    advance(Iterator,2);
    REQUIRE(*Iterator == 2);
}

TEST_CASE("Stl_List/insert")
{
    std::list<int> list;

    list.push_back(1);
    list.push_back(2);

    std::list<int>::iterator Iterator;
    Iterator=list.begin();

    list.insert(Iterator, 3);
    Iterator=list.begin();
    list.insert(Iterator, 4);
    Iterator=list.begin();

    REQUIRE(*Iterator == 4);
    advance(Iterator,1);
    REQUIRE(*Iterator == 3);
    advance(Iterator,2);
    REQUIRE(*Iterator == 2);
}

TEST_CASE("Std_List/remove")
{
    std::list<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    std::list<int>::iterator Iterator;
    Iterator=list.begin();

    list.remove(2);

    REQUIRE(*Iterator == 1);
    advance(Iterator,1);
    REQUIRE(*Iterator == 3);

    list.remove(1);
    Iterator=list.begin();
    REQUIRE(*Iterator == 3);
}

TEST_CASE("Std_List/pop")
{
    std::list<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    std::list<int>::iterator Iterator;

    list.pop_back();
    list.pop_front();
    Iterator=list.begin();
    REQUIRE(*Iterator == 2);
}
TEST_CASE("Stl_Stack")
{
    std::stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    REQUIRE(stack.top() == 3);
    stack.pop();
    REQUIRE(stack.top() == 2);
    stack.pop();
    REQUIRE(stack.top() == 1);
    stack.pop();
}

TEST_CASE("Stl_Queue")
{
    std::queue<int> queue;

    queue.push(1);
    queue.push(2);
    queue.push(3);

    REQUIRE(queue.front()== 1);
    
    queue.pop();
    REQUIRE(queue.front() == 2);
    REQUIRE(queue.back() == 3);
}

TEST_CASE("Stl_PriorityQueue")
{
    std::priority_queue<int> queue;

    queue.push(1);
    queue.push(3);
    queue.push(2);

    REQUIRE(queue.top()== 3);
    queue.pop();
    REQUIRE(queue.top() == 2);
    queue.pop();
    REQUIRE(queue.top() == 1);
    queue.pop();
}

