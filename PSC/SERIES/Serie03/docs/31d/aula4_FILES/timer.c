#include <stdio.h>
#include <time.h>

static struct timespec stTm;

void start_timer() {
  clock_gettime(CLOCK_MONOTONIC,&stTm);
}

/* returns the time elapsed since start_timer() call */
/* in micro seconds. */
long get_microtime() {
  struct timespec tm;
  clock_gettime(CLOCK_MONOTONIC,&tm);
  return ((long)(tm.tv_sec-stTm.tv_sec))*1000000+
         (tm.tv_nsec-stTm.tv_nsec)/1000;
}

/* returns the time elapsed since start_timer() call */
/* in nano seconds. */
long long get_nanotime() {
  struct timespec tm;
  clock_gettime(CLOCK_MONOTONIC,&tm);
  return ((long long)(tm.tv_sec-stTm.tv_sec))*1000000000+
         (tm.tv_nsec-stTm.tv_nsec);
}

