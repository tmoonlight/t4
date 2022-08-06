#include <event2/event.h>

#include <iostream>
#include "spdlog/common.h"
#include "spdlog/sinks/daily_file_sink.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/spdlog.h"
#include "spdlog/async.h" //support for async logging.
#include "project/ship.h"
#include "project/frigate.h";
using namespace std;

int runtest()
{
 
	Frigate dri;
  event_base *ebase = event_base_new();
  event_config *cfg = event_config_new();


  auto my_logger = spdlog::basic_logger_mt("basic_logger", "logs/basic.txt");
  auto logger = spdlog::daily_logger_mt("daily_logger", "logs/daily.txt", 2, 30);
  auto async_file = spdlog::basic_logger_mt<spdlog::async_factory>("async_file_logger", "logs/async_log.txt");
  
  spdlog::info("welcome!!!");
  //.async_file.
  my_logger->error("testerror");
  logger->error("testerror333");
  async_file->error("output");
  //logger
  event_config_free(cfg);
  event_base_free(ebase);
  return 0;
}
