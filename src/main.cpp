#include <iostream>
#include <string>

#include "project/frigate.h";
#include "project/ship.h"
#include "spdlog/async.h"  //support for async logging.
#include "spdlog/common.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/daily_file_sink.h"
#include "spdlog/spdlog.h"
using namespace std;

<<<<<<< HEAD
#ifdef WIN32
#define bzero(A, B) memset(A, 0, B)
#endif
int main()
=======
int runtest()
>>>>>>> c5bf7f20954027e71f7eab222f6c41cc040d62d2
{
  printf("test");
  return 0;
}

