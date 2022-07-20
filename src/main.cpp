#include <stdio.h>
#include <stdlib.h>
#include <uv.h>

#include <iostream>

int64_t counter = 0;

void wait_for_a_while(uv_idle_t* handle)
{
  counter++;

  if (counter >= 10e6)
    uv_idle_stop(handle);
}
int main()
{
  uv_idle_t idler;

  uv_idle_init(uv_default_loop(), &idler);
  uv_idle_start(&idler, wait_for_a_while);

  printf("Idling...\n");
  uv_run(uv_default_loop(), UV_RUN_DEFAULT);

  uv_loop_close(uv_default_loop());
  return 0;
  // return 0;
  int x = 1;
  int y = 0;
  int z = 2;
  int a = -1;
  if (x)
  {
    printf("x");
  }
  if (y)
  {
    printf("y");
  }
  if (z)
  {
    printf("z");
  }
  if (a)
  {
    printf("a");
  }

  // printf("test");
  return 0;
}