#include <future>
#include <iostream>

int main()
{
  auto func = []() { std::this_thread::sleep_for(std::chrono::seconds(2)); return 10; };
  auto func2 = []() { std::this_thread::sleep_for(std::chrono::seconds(4)); return 20; };
  std::cout << "begin\n";
  std::future<int> res = std::async(func);
  std::cout << "func1 launched\n";
  std::future<int> res2 = std::async(func2);
  std::cout << "func2 launched\n";
  std::cout << "waiting for sub-thread2 ...\n";
  // res.wait();
  std::cout << "func1 finished\n";
  // res2.wait();
  std::cout << "got it !\n";
  std::cout << res2.get() << "\n";
  std::cout << res.get() << "\n";
  return 0;
}