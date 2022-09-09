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

#ifdef WIN32
#define bzero(A, B) memset(A, 0, B)
#endif
int main()
{
  printf("test");
  return 0;
}
